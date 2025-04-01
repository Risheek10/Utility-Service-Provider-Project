#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <map>

using namespace std;

// Structure representing a utility service offered by providers.
struct Service {
    string name;      // e.g., "Natural Gas", "Electric", etc.
    double fixedRate; // Fixed meter or connection charge
    double unitRate;  // Rate per unit of consumption
};

// Structure representing a utility service provider.
struct Provider {
    int id;                          // Unique provider ID (e.g., 0 through 9)
    string name;                     // Provider name
    map<string, Service> services;   // Services offered mapped by service name
};

// Structure representing a customer.
struct Customer {
    int id;                          // Unique customer ID (e.g., 1 through 100)
    string name;                     // Customer name
    string email;                    // Customer email address
    string address;                  // Customer physical address
    // Records the usage for each service (e.g., "Electric" -> units consumed)
    map<string, double> usage;
    // Records which provider (by provider ID) the customer chose for each service.
    map<string, int> providerSelection;
    // The current balance (accumulated bill) for the customer.
    double balance;
};

// Global vectors that will store all providers and customers.
extern vector<Provider> providers;
extern vector<Customer> customers;

#endif // DATA_H
