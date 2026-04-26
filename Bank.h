#ifndef BANK_H
#define BANK_H

#include "Customer.h"

class Bank {
private:
    std::vector<Customer> customers;
    int nextAccountNumber;
    Customer* findCustomer(int accNo);

public:
    Bank();
    void adminMenu();
    void customerMenu(Customer* c);
    void loginPage();
};

#endif
