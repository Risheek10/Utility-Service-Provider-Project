#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <cstdlib> // for getenv()
#include <algorithm>

using namespace std;

class Provider {
public:
    string name;
    map<string, double> serviceRates;
    
    Provider(string n) : name(n) {}
    void addService(string service, double rate) {
        serviceRates[service] = rate;
    }
};

class Customer {
public:
    string name;
    int id;
    map<string, double> usage;
    double balance;
    
    Customer(int i, string n) : id(i), name(n), balance(0.0) {}
    
    void useService(string service, double units) {
        usage[service] += units;
    }
    
    void payBill(double amount) {
        balance -= amount;
    }
};

class BillingSystem {
public:
    vector<Customer> customers;
    vector<Provider> providers;
    
    void addCustomer(Customer c) {
        customers.push_back(c);
    }
    
    void addProvider(Provider p) {
        providers.push_back(p);
    }
    
    string generateBillJson(int customerId) {
        for (auto &c : customers) {
            if (c.id == customerId) {
                double total = 0.0;
                map<string, double> usageCosts;
                
                for (auto &p : providers) {
                    for (auto &service : c.usage) {
                        if (p.serviceRates.count(service.first)) {
                            double cost = service.second * p.serviceRates[service.first];
                            usageCosts[service.first] = cost;
                            total += cost;
                        }
                    }
                }
                c.balance += total;
                
                // Generate JSON
                stringstream json;
                json << "{";
                json << "\"name\":\"" << c.name << "\",";
                json << "\"id\":" << c.id << ",";
                json << "\"balance\":" << c.balance << ",";
                json << "\"usage\":{";
                
                bool first = true;
                for (auto &service : c.usage) {
                    if (!first) json << ",";
                    json << "\"" << service.first << "\":" << service.second;
                    first = false;
                }
                
                json << "},";
                json << "\"costs\":{";
                
                first = true;
                for (auto &cost : usageCosts) {
                    if (!first) json << ",";
                    json << "\"" << cost.first << "\":" << cost.second;
                    first = false;
                }
                
                json << "}";
                json << "}";
                return json.str();
            }
        }
        return "{\"error\":\"Customer not found\"}";
    }
};

int main() {
    // Initialize system with sample data
    BillingSystem system;
    
    Provider hydro("Hydro One");
    hydro.addService("Electricity", 0.12);
    hydro.addService("Water", 0.05);
    system.addProvider(hydro);
    
    Provider telecom("Telecom Plus");
    telecom.addService("Internet", 45.99);
    telecom.addService("TV", 29.99);
    system.addProvider(telecom);
    
    Customer hal(1001, "Hal Jordan");
    hal.useService("Electricity", 120);
    hal.useService("Water", 50);
    hal.useService("Internet", 1);
    system.addCustomer(hal);
    
    Customer barry(1002, "Barry Allen");
    barry.useService("Electricity", 85);
    barry.useService("TV", 1);
    system.addCustomer(barry);

    // Handle CGI request
    cout << "Content-type: application/json\n\n";
    
    // Get customer ID from query string
    char* query = getenv("QUERY_STRING");
    string queryStr = query ? query : "";
    int customerId = -1;
    
    size_t idPos = queryStr.find("id=");
    if (idPos != string::npos) {
        try {
            customerId = stoi(queryStr.substr(idPos + 3));
        } catch (...) {
            // Invalid ID format
        }
    }
    
    if (customerId > 0) {
        cout << system.generateBillJson(customerId);
    } else {
        cout << "{\"error\":\"Invalid customer ID\"}";
    }
    
    return 0;
}