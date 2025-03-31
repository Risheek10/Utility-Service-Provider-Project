#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

// ================ Data Models ================
struct Service {
    string name;
    double variable_rate; // per unit
    double fixed_rate;    // monthly
};

class Provider {
public:
    string name;
    map<string, Service> services;
    
    Provider(string n) : name(n) {}
    
    void addService(string service_name, double var_rate, double fixed_rate) {
        services[service_name] = {service_name, var_rate, fixed_rate};
    }
};

class Customer {
public:
    int id;
    string name;
    string address;
    map<string, pair<Provider*, double>> subscriptions; // service_name -> (provider, usage)
    vector<pair<time_t, double>> payment_history;      // (timestamp, amount)
    
    Customer(int i, string n, string addr) : id(i), name(n), address(addr) {}
    
    void subscribe(Provider* p, string service_name) {
        subscriptions[service_name] = {p, 0.0};
    }
    
    void recordUsage(string service_name, double units) {
        if (subscriptions.count(service_name)) {
            subscriptions[service_name].second += units;
        }
    }
    
    void makePayment(double amount) {
        payment_history.emplace_back(time(nullptr), amount);
    }
    
    double getBalanceDue() const {
        double total = 0.0;
        for (const auto& sub : subscriptions) {
            Service s = sub.second.first->services[sub.first];
            total += s.fixed_rate + (s.variable_rate * sub.second.second);
        }
        return total - getTotalPaid();
    }
    
    double getTotalPaid() const {
        double total = 0.0;
        for (const auto& payment : payment_history) {
            total += payment.second;
        }
        return total;
    }
};

// ================ Core System ================
class BillingSystem {
    vector<Provider> providers;
    vector<Customer> customers;
    
public:
    void initializeSampleData() {
        // Create providers
        providers.emplace_back("Hydro One");
        providers.back().addService("Electricity", 0.12, 10.00);
        providers.back().addService("Water", 0.05, 8.00);
        
        providers.emplace_back("GasCo");
        providers.back().addService("Natural Gas", 0.08, 15.00);
        
        providers.emplace_back("TelPlus");
        providers.back().addService("Internet", 0.00, 45.99);
        providers.back().addService("TV", 0.00, 29.99);
        
        // Create customers
        customers.emplace_back(1001, "John Doe", "123 Main St");
        customers.back().subscribe(&providers[0], "Electricity");
        customers.back().subscribe(&providers[1], "Natural Gas");
        customers.back().recordUsage("Electricity", 120);
        customers.back().recordUsage("Natural Gas", 50);
        
        customers.emplace_back(1002, "Jane Smith", "456 Oak Ave");
        customers.back().subscribe(&providers[2], "Internet");
        customers.back().subscribe(&providers[2], "TV");
    }
    
    void generateMonthlyBills() {
        time_t now = time(nullptr);
        for (auto& customer : customers) {
            double amount_due = 0.0;
            map<string, tuple<Provider*, double, double, double>> bill_details;
            
            for (const auto& sub : customer.subscriptions) {
                Service s = sub.second.first->services[sub.first];
                double cost = s.fixed_rate + (s.variable_rate * sub.second.second);
                bill_details[sub.first] = {
                    sub.second.first, 
                    sub.second.second,
                    s.variable_rate,
                    cost
                };
                amount_due += cost;
            }
            
            printBill(customer, bill_details, amount_due, now);
            customer.subscriptions.clear(); // Reset usage for next month
        }
    }
    
    void printBill(const Customer& cust, 
                  const map<string, tuple<Provider*, double, double, double>>& details,
                  double total, time_t bill_date) {
        cout << "\n============= BILL STATEMENT =============\n";
        cout << "Customer: " << cust.name << " (ID: " << cust.id << ")\n";
        cout << "Billing Date: " << ctime(&bill_date);
        cout << "--------------------------------------------\n";
        cout << left << setw(20) << "Service" 
             << setw(15) << "Provider" 
             << setw(10) << "Usage" 
             << setw(10) << "Rate" 
             << setw(10) << "Cost\n";
        
        for (const auto& item : details) {
            auto [provider, usage, rate, cost] = item.second;
            cout << left << setw(20) << item.first
                 << setw(15) << provider->name
                 << setw(10) << fixed << setprecision(2) << usage
                 << "$" << setw(9) << rate
                 << "$" << cost << "\n";
        }
        
        cout << "--------------------------------------------\n";
        cout << "TOTAL DUE: $" << total << "\n";
        cout << "PAYMENT DUE BY: " << formatDueDate(bill_date) << "\n";
        cout << "============================================\n\n";
    }
    
    string formatDueDate(time_t bill_date) {
        tm* due_date = localtime(&bill_date);
        due_date->tm_mday += 30; // Add 30 days for due date
        mktime(due_date);
        
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", due_date);
        return string(buffer);
    }
    
    void run() {
        initializeSampleData();
        
        // Simulate 6 months of billing
        for (int month = 1; month <= 6; month++) {
            cout << "\n=== Processing Month " << month << " ===\n";
            
            // Simulate usage
            for (auto& customer : customers) {
                for (auto& sub : customer.subscriptions) {
                    // Random usage between 50-150% of base
                    double usage = (50 + rand() % 101) / 100.0 * 100.0;
                    customer.recordUsage(sub.first, usage);
                }
            }
            
            generateMonthlyBills();
            
            // Simulate payments (50% chance of payment)
            for (auto& customer : customers) {
                if (rand() % 2 == 0) {
                    double payment = customer.getBalanceDue() * 0.8; // Partial payment
                    customer.makePayment(payment);
                    cout << customer.name << " paid: $" << payment << "\n";
                }
            }
        }
    }
};

// ================ Main Function ================
int main() {
    srand(time(nullptr)); // Seed random numbers
    
    BillingSystem system;
    system.run();
    
    return 0;
}