#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <ctime>
#include "features/features.h"
#include "data.h"

using namespace std;

// 6 months of randomized usage for each customer-service pair
map<int, map<string, vector<int>>> monthlyUsage; // customerId -> service -> [6 values]

double calculateMonthlyCost(const Service& svc, int usage) {
    return svc.fixedRate + svc.unitRate * usage;
}

void generateMonthlyUsage() {
    srand(time(0));
    for (const auto& customer : customers) {
        for (const auto& [service, usage] : customer.usage) {
            vector<int> usageValues;
            for (int m = 0; m < 6; ++m) {
                int varied = usage + (rand() % 11 - 5); // ±5
                if (varied < 0) varied = 0;
                usageValues.push_back(varied);
            }
            monthlyUsage[customer.id][service] = usageValues;
        }
    }
}

void outputJsonForCustomer(int customerId) {
    cout << "Content-Type: application/json\n\n";

    for (const auto& customer : customers) {
        if (customer.id == customerId) {
            double balance = 0.0;
            cout << "{";
            cout << "\"id\":" << customer.id << ",";
            cout << "\"name\":\"" << customer.name << "\",";
            cout << "\"email\":\"" << customer.email << "\",";
            cout << "\"address\":\"" << customer.address << "\",";

            cout << "\"services\":{";
            bool first = true;
            for (const auto& [service, usage] : customer.usage) {
                int providerId = customer.providerSelection.at(service);
                const Service& svc = providers[providerId].services.at(service);
                double cost = calculateMonthlyCost(svc, usage);
                balance += cost;

                if (!first) cout << ",";
                cout << "\"" << service << "\":{";
                cout << "\"provider\":\"" << providers[providerId].name << "\",";
                cout << "\"usage\":" << usage << ",";
                cout << "\"rate\":" << svc.unitRate << ",";
                cout << "\"fixed\":" << svc.fixedRate << ",";
                cout << "\"cost\":" << cost;
                cout << "}";
                first = false;
            }
            cout << "},";
            cout << "\"balance\":" << balance;
            cout << "}";
            return;
        }
    }

    cout << "{\"error\":\"Customer not found\"}";
}

void outputMonthlyProviderData(int providerId, int month) {
    cout << "Content-Type: application/json\n\n";

    double totalIncome = 0.0;
    cout << "{";
    cout << "\"provider\":\"" << providers[providerId].name << "\",";
    cout << "\"month\":" << month << ",";
    cout << "\"customers\":[";

    bool firstCustomer = true;
    for (const auto& customer : customers) {
        vector<pair<string, double>> matchedServices;

        for (const auto& [service, pid] : customer.providerSelection) {
            if (pid == providerId) {
                int usage = monthlyUsage[customer.id][service][month - 1];
                const Service& svc = providers[pid].services.at(service);
                double cost = calculateMonthlyCost(svc, usage);
                matchedServices.emplace_back(service, cost);
                totalIncome += cost;
            }
        }

        if (!matchedServices.empty()) {
            if (!firstCustomer) cout << ",";
            cout << "{";
            cout << "\"name\":\"" << customer.name << "\",";
            cout << "\"email\":\"" << customer.email << "\",";
            cout << "\"services\":[";
            for (size_t i = 0; i < matchedServices.size(); ++i) {
                if (i > 0) cout << ",";
                cout << "{";
                cout << "\"name\":\"" << matchedServices[i].first << "\",";
                cout << "\"cost\":" << matchedServices[i].second;
                cout << "}";
            }
            cout << "]";
            cout << "}";
            firstCustomer = false;
        }
    }

    cout << "],";
    cout << "\"totalIncome\":" << totalIncome;
    cout << "}";
}

void outputFullProviderData(int providerId) {
    cout << "Content-Type: application/json\n\n";

    double totalIncome = 0.0;
    cout << "{";
    cout << "\"provider\":\"" << providers[providerId].name << "\",";
    cout << "\"customers\":[";

    bool firstCustomer = true;
    for (const auto& customer : customers) {
        vector<pair<string, double>> matchedServices;

        for (const auto& [service, pid] : customer.providerSelection) {
            if (pid == providerId) {
                int usage = customer.usage.at(service);
                const Service& svc = providers[pid].services.at(service);
                double cost = calculateMonthlyCost(svc, usage);
                matchedServices.emplace_back(service, cost);
                totalIncome += cost;
            }
        }

        if (!matchedServices.empty()) {
            if (!firstCustomer) cout << ",";
            cout << "{";
            cout << "\"name\":\"" << customer.name << "\",";
            cout << "\"email\":\"" << customer.email << "\",";
            cout << "\"services\":[";
            for (size_t i = 0; i < matchedServices.size(); ++i) {
                if (i > 0) cout << ",";
                cout << "{";
                cout << "\"name\":\"" << matchedServices[i].first << "\",";
                cout << "\"cost\":" << matchedServices[i].second;
                cout << "}";
            }
            cout << "]";
            cout << "}";
            firstCustomer = false;
        }
    }

    cout << "],";
    cout << "\"totalIncome\":" << totalIncome;
    cout << "}";
}

int main() {
    string query = getenv("QUERY_STRING") ? getenv("QUERY_STRING") : "";
    map<string, string> params;

    istringstream ss(query);
    string pair;
    while (getline(ss, pair, '&')) {
        size_t eq = pair.find('=');
        if (eq != string::npos) {
            string key = pair.substr(0, eq);
            string value = pair.substr(eq + 1);
            params[key] = value;
        }
    }

    generateMonthlyUsage();

    if (params.count("id")) {
        int id = stoi(params["id"]);
        outputJsonForCustomer(id);
    } else if (params.count("provider")) {
        int pid = stoi(params["provider"]);
        if (params.count("month")) {
            int m = stoi(params["month"]);
            if (m >= 1 && m <= 6) {
                outputMonthlyProviderData(pid, m);
            } else {
                cout << "Content-Type: application/json\n\n{\"error\":\"Invalid month\"}";
            }
        } else {
            outputFullProviderData(pid);
        }
    } else {
        cout << "Content-Type: text/plain\n\nMissing query parameter.\n";
    }

    return 0;
}
