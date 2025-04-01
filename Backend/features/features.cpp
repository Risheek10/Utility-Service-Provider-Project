/* features/features.cpp */
#include "features.h"
#include <iostream>
#include <map>

std::map<std::string, std::string> users = {
    {"customer1", "customer"},
    {"auditor1", "auditor"}
};

std::string login() {
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;
    
    if (users.find(username) != users.end()) {
        return users[username];
    } else {
        return "unauthorized";
    }
}
