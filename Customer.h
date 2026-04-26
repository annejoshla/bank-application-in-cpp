#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Models.h"

class Customer : public Person {
private:
    int accountNumber;
    std::string password;
    double balance;
    std::string kycStatus;
    std::vector<Transaction> history;

public:
    Customer(std::string n, int accNo, std::string pass, double initialBal);
    int getAccountNumber();
    std::string getName();
    double getBalance();
    std::string getKycStatus();
    bool verifyPassword(std::string pass);
    void submitKYC();
    void approveKYC();
    void deposit(double amount);
    void withdraw(double amount);
    void viewTransactionHistory();
    void displayDetails() override;
};

#endif