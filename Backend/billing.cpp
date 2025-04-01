#include <iostream>
#include "features/features.h"
#include <vector>

void displayCustomerData(const std::string& customer) {
    // Placeholder function to simulate customer data display
    std::cout << "Displaying data for " << customer << "...\n";
    std::cout << "Customer details: [Name, Address, Email, etc.]\n"; // Example data
}

void displayCustomerList() {
    std::vector<std::string> customerList = {"customer1", "customer2", "customer3"};

    std::cout << "Available customers:\n";
    for (const auto& customer : customerList) {
        std::cout << customer << "\n";
    }

    std::cout << "Enter the username of the customer you want to view: ";
    std::string selectedCustomer;
    std::cin >> selectedCustomer;
    
    // Validate if the customer exists in the list
    bool found = false;
    for (const auto& customer : customerList) {
        if (customer == selectedCustomer) {
            found = true;
            displayCustomerData(selectedCustomer);
            break;
        }
    }
    if (!found) {
        std::cout << "Customer not found.\n";
    }
}

int main() {
    std::string role = login();
    
    if (role == "customer") {
        std::cout << "Welcome, Customer! You can view your data here.\n";
        // Here, for now, just display customer data
        displayCustomerData("customer1"); // Assuming the logged-in customer is "customer1"
    } else if (role == "auditor") {
        std::cout << "Welcome, Auditor! Here is the list of customers.\n";
        // Display the list of customers and let the auditor select one
        displayCustomerList();
    } else {
        std::cout << "Unauthorized access.\n";
    }
    
    return 0;
}
