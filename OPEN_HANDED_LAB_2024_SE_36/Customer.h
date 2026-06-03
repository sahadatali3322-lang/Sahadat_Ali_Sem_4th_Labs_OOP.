#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer
{
private:
    string name;
    int customerID;
    bool activeRental;

public:
    Customer(string n, int id)
        : name(n),
          customerID(id),
          activeRental(false) {}

    string getName() const
    {
        return name;
    }

    int getID() const
    {
        return customerID;
    }

    bool hasActiveRental() const
    {
        return activeRental;
    }

    void setActiveRental(bool status)
    {
        activeRental = status;
    }
};

#endif