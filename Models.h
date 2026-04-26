#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <vector>

struct Transaction {
    std::string type;
    double amount;
};

class Person {
protected:
    std::string name;
public:
    Person(std::string n) : name(n) {}
    virtual void displayDetails() = 0; 
    virtual ~Person() {} 
};

#endif