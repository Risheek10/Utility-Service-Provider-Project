#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include "features/features.h"
#include "data.h"

using namespace std;

void outputJsonForCustomer(int customerId) {
    cout << "Content-Type: application/json\n\n";

    for (const auto& customer : customers) {
        if (customer.id == customerId) {
            cout << "{";
            cout << "\"id\":" << customer.id << ",";
            cout << "\"name\":\"" << customer.name << "\",";
            cout << "\"email\":\"" << customer.email << "\",";
            cout << "\"address\":\"" << customer.address << "\",";
            cout << "\"balance\":" << customer.balance << ",";

            cout << "\"services\":{";
            bool first = true;
            for (const auto& [service, usage] : customer.usage) {
                int providerId = customer.providerSelection.at(service);
                const Service& svc = providers[providerId].services.at(service);
                double cost = svc.fixedRate + svc.unitRate * usage;

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
            cout << "}";

            cout << "}";
            return;
        }
    }

    cout << "{\"error\":\"Customer not found\"}";
}

void outputJsonForProvider(int providerId) {
    cout << "Content-Type: application/json\n\n";

    if (providerId < 0 || providerId >= providers.size()) {
        cout << "{\"error\":\"Provider not found\"}";
        return;
    }

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
                const Service& svc = providers[providerId].services.at(service);
                double cost = svc.fixedRate + svc.unitRate * usage;
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

    if (params.count("id")) {
        int id = stoi(params["id"]);
        outputJsonForCustomer(id);
    } else if (params.count("provider")) {
        int pid = stoi(params["provider"]);
        outputJsonForProvider(pid);
    } else {
        cout << "Content-Type: text/plain\n\nMissing query parameter.\n";
    }

    return 0;
}
