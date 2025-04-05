# Utility-Service-Provider-Project
# Overview
- A C++ application that manages utility services (Natural Gas, Internet, Hydro, etc...) for multiple providers and customers, tracking billing, payments, and service subscriptions over a 6-month period.

# Features
- Manages 10 utility providers and 100 customers

- Tracks 8 different utility services with meter rates

- Handles billing with 30-day overdue payment tracking

- Generates reports on sales and payment statuses

- Simulates 6 months of utility service data

# Compiling and running the code
- Make sure to be in the "Backend" folder while you compile

- Do **g++ billing.cpp data.cpp -o ../cgi-bin/billing.cgi**

- After compiling, go back to the project root diretory

- Do "**python server.py**" to get the local host running. If the server does not start go into the server.py code and change the port to 4000 or an unused port.
  
- Click the Localhost link and follow the menu-driven interface to:

- View provider/customer records

- Generate billing reports

# Data Structure
- Uses object-oriented design with classes for Providers, Customers, and UtilityServices

- Implements proper data encapsulation and relationships

# Contributions
- Tayo Alalade (Billing.cpp, Billing.h, Index.html, Search.html, Server.py)
- Risheek Jayakumar (Server.py)
- Jola Amusat (Index.html)

