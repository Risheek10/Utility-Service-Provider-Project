# Utility-Service-Provider-Project
# Overview
- A C++ application that manages utility services (Natural Gas, Internet, Hydro, etc...) for multiple providers and customers, tracking billing, payments, and service subscriptions over a 6-month period.

# Features
- Manages 10 utility providers and 100 customers

- Tracks 8 different utility services with meter rates

- Handles billing with 30-day overdue payment tracking

- Generates reports on sales and payment statuses

- Simulates 6 months of utility service data

# Compiling the code
- Make sure to be in the "Backend" folder while you compile

  **g++ billing.cpp data.cpp -o ../cgi-bin/billing.cgi**

- After compiling, do "**cd ..**" back to the project diretory

- Do "**python server.py**" to get the local host running

# Usage
- Run the compiled program and follow the menu-driven interface to:

- View provider/customer records

- Generate billing reports

# Data Structure
- Uses object-oriented design with classes for Providers, Customers, and UtilityServices

- Implements proper data encapsulation and relationships

