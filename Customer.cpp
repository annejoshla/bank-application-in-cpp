#include "Customer.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
Customer::Customer(string n, int accNo, string pass, double initialBal) 
    : Person(n), accountNumber(accNo), password(pass), balance(initialBal), kycStatus("Not Submitted") {
    if (initialBal > 0) {
        history.push_back({"Initial Deposit", initialBal});
    }
}

// Getters
int Customer::getAccountNumber() { return accountNumber; }
string Customer::getName() { return name; }
double Customer::getBalance() { return balance; }
string Customer::getKycStatus() { return kycStatus; }

bool Customer::verifyPassword(string pass) { return password == pass; }

void Customer::submitKYC() {
    if (kycStatus == "Approved") {
        cout << "[System] KYC is already approved!\n";
    } else {
        kycStatus = "Pending";
        cout << "[System] KYC details submitted. Awaiting Admin approval.\n";
    }
}

void Customer::approveKYC() {
    kycStatus = "Approved";
}

void Customer::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        history.push_back({"Deposit", amount});
        cout << "[Success] Deposited Rs. " << amount << ". New Balance: Rs. " << balance << "\n";
    } else {
        cout << "[Error] Invalid deposit amount!\n";
    }
}

void Customer::withdraw(double amount) {
    if (amount <= 0) {
        cout << "[Error] Invalid amount!\n";
    } else if (amount > balance) {
        cout << "[Error] Insufficient balance! Transaction declined.\n";
    } else {
        balance -= amount;
        history.push_back({"Withdrawal", amount});
        cout << "[Success] Withdrew Rs. " << amount << ". New Balance: Rs. " << balance << "\n";
    }
}

void Customer::viewTransactionHistory() {
    cout << "\n--- Transaction History for " << name << " ---\n";
    if (history.empty()) {
        cout << "No transaction records found.\n";
        return;
    }
    cout << left << setw(20) << "Type" << " | " << "Amount (Rs.)" << "\n";
    cout << "------------------------------------------\n";
    for (const auto& txn : history) {
        cout << left << setw(20) << txn.type << " | " << txn.amount << "\n";
    }
}

void Customer::displayDetails() {
    cout << left << setw(12) << accountNumber 
         << setw(18) << name 
         << setw(15) << balance 
         << setw(15) << kycStatus << "\n";
}