#include "Bank.h"
#include <iostream>
#include <iomanip>

using namespace std;

Bank::Bank() : nextAccountNumber(101) {}

Customer* Bank::findCustomer(int accNo) {
    for (auto& c : customers) {
        if (c.getAccountNumber() == accNo) {
            return &c;
        }
    }
    return nullptr;
}

void Bank::adminMenu() {
    int choice;
    do {
        cout << "\n--- ADMIN CONTROL PANEL ---\n";
        cout << "1. Create New Customer Account\n";
        cout << "2. Review & Approve KYC\n";
        cout << "3. Generate Master Customer Report\n";
        cout << "4. Logout\n";
        cout << "Enter your choice: "; cin >> choice;

        if (choice == 1) {
            string name, pass; double dep;
            cout << "Enter customer full name: "; cin.ignore(); getline(cin, name);
            cout << "Set Password: "; cin >> pass;
            cout << "Initial Deposit: "; cin >> dep;
            customers.push_back(Customer(name, nextAccountNumber++, pass, dep));
            cout << string(5,'*') << "\nAccount successfully created for " << name << string(5,'*') << ".\n";
            cout << string(5,'*') << name << "'s Account number is "<< nextAccountNumber - 1 << string(5,'*') << "\n";
        } 
        else if (choice == 2) {
            int acc; cout << "Enter A/C Number: "; cin >> acc;
            Customer* c = findCustomer(acc);
            if (c) {
                c->approveKYC();
                cout << string(5,'*') << "KYC Approved for A/C: " << acc << string(5,'*') << "\n";
            } else {
                cout << "Account not found.\n";
            }
        }
        else if (choice == 3) {
            cout << "\n" << string(60, '=') << "\n";
            cout << left << setw(12) << "Acc No" << setw(18) << "Name" 
                 << setw(15) << "Balance" << setw(15) << "KYC Status" << "\n";
            cout << string(60, '-') << "\n";
            for (auto& c : customers) {
                c.displayDetails();
            }
            cout << string(60, '=') << "\n";
        }
    } while (choice != 4);
}

void Bank::customerMenu(Customer* c) {
    int choice;
    do {
        cout << "\n--- WELCOME, " << c->getName() << " ---\n";
        cout << "1. Submit KYC for Review\n";
        cout << "2. Deposit Funds\n";
        cout << "3. Withdraw Funds\n";
        cout << "4. Check Balance\n";
        cout << "5. View Transaction History\n";
        cout << "6. Logout\n";
        cout << "Enter your choice: "; cin >> choice;

        switch(choice) {
            case 1: c->submitKYC(); break;
            case 2: { double a; cout << "Amount: "; cin >> a; c->deposit(a); break; }
            case 3: { double a; cout << "Amount: "; cin >> a; c->withdraw(a); break; }
            case 4: cout << "\n" << string(5,'*') << "Balance: Rs. " << c->getBalance() << "\n"; break;
            case 5: c->viewTransactionHistory(); break;
        }
    } while (choice != 6);
}

void Bank::loginPage() {
    int mode;
    while (true) {
        cout << "\n==============================\n";
        cout << "   ANNE DIGITAL BANKING\n";
        cout << "==============================\n";
        cout << "1. Admin Login\n2. Customer Login\n3. Shut Down\nEnter your choice: ";
        cin >> mode;

        if (mode == 1) {
            string user, password;
            cout << "Enter admin username: "; cin >> user; 
            cout << "Password: "; cin >> password;
            if (user == "admin" && password == "admin123"){ 
                adminMenu();
            } else {
                cout << "\nAccess Denied.\n";
            } 
        } else if (mode == 2) {
            int acc;
            string password;
            cout << "Enter your account number: "; cin >> acc; 
            cout << "Password: "; cin >> password;
            Customer* customer = findCustomer(acc);
            if (customer && customer->verifyPassword(password)) customerMenu(customer);
            else cout << string(5,'*') << "Invalid Credentials.\n" << string(5,'*');
        } else if (mode == 3) {
            break;
        }
    }
}