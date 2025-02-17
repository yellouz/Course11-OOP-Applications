# Bank Management System

A comprehensive C++ banking system developed as part of the "OOP as it should be" course by Programming Advices. This object-oriented application implements core banking functionalities with a focus on clean, maintainable code and security.

## Features

### Client Management
- Add new clients with detailed profiles
- View complete client list
- Search for specific clients
- Update client information
- Delete client records
- Manage client account balances

### Account Transactions
- Deposit funds
- Withdraw funds
- Transfer money between accounts
- View total balances
- Transaction logging
- Transfer history tracking

### User Management
- Multi-user support with different access levels
- User authentication and login system
- Login attempt tracking
- User activity logging
- User permissions management

### Currency Exchange
- List available currencies
- Find specific currency rates
- Update exchange rates
- Currency conversion calculator
- Support for multiple currencies

### Security Features
- Password-protected access
- User permissions system
- Failed login attempt tracking
- Session management
- Encrypted data storage

## Technical Implementation

### Core Classes
- `clsBankClient`: Manages client data and operations
- `clsUser`: Handles user authentication and permissions
- `clsCurrency`: Manages currency exchange functionality
- `clsScreen`: Base class for UI screens
- `clsPerson`: Base class for person-related data

### File Structure
```
├── HeaderFiles/
│   ├── Global.h
│   └── Utils/
├── Core/
│   ├── clsPerson.h
│   ├── clsBankClient.h
│   ├── clsUser.h
│   └── clsCurrency.h
├── Screens/
│   ├── Client/
│   ├── User/
│   ├── Transactions/
│   └── Currencies/
└── TextFiles/
    ├── Clients.txt
    ├── Users.txt
    └── Currencies.txt
```

### Data Storage
- Utilizes text files for persistent data storage
- Data is stored in a structured format using separators
- Implements file handling for read/write operations

## Getting Started

### Prerequisites
- C++ compiler (supporting C++11 or later)
- Basic understanding of OOP concepts
- Text editor or IDE

### Installation
1. Clone the repository
2. Compile the source files
3. Run the compiled executable
4. Default login credentials can be found in the Users.txt file

### First Time Setup
1. Launch the application
2. Log in using admin credentials
3. Set up initial currency rates
4. Create user accounts as needed
5. Begin adding clients

## Usage

### Main Menu Options
1. Show Client List
2. Add New Client
3. Delete Client
4. Update Client Info
5. Find Client
6. Transactions
7. Manage Users
8. Login Register
9. Currency Exchange
10. Logout

### Transaction Menu
1. Deposit
2. Withdraw
3. Total Balances
4. Transfer
5. Transfer Log
6. Main Menu

### Currency Exchange Menu
1. List Currencies
2. Find Currency
3. Update Rate
4. Currency Calculator
5. Main Menu

## Project Structure

The project follows object-oriented principles and implements various design patterns:
- Inheritance (Person → Client/User)
- Encapsulation (private data members with public interfaces)
- Screen handling system for UI management
- Modular design with separated concerns
- File-based persistence layer

## Security Considerations

- Password encryption for stored credentials
- Permission-based access control
- Login attempt limiting
- Session management
- Data validation and sanitization

## Course Information

This project was developed as part of the "OOP as it should be" course by Programming Advices, which focuses on practical implementation of object-oriented programming principles in C++.

## Contributing

While this is a course project, suggestions and improvements are welcome. Please feel free to:
1. Fork the repository
2. Create a feature branch
3. Submit a pull request

## License

This project is for educational purposes. Please check with Programming Advices for usage rights and restrictions.
