#ifndef RENTAL_H
#define RENTAL_H

#include "Vehicle.h"
#include "Customer.h"

class Rental
{
private:
    Vehicle* vehicle;
    Customer* customer;
    int days;
    bool returned;

public:
    Rental(Vehicle* v,
           Customer* c,
           int d)
        : vehicle(v),
          customer(c),
          days(d),
          returned(false) {}

    double getCost() const
    {
        return vehicle->calculateCost(days);
    }

    bool isReturned() const
    {
        return returned;
    }

    void closeRental()
    {
        returned = true;
    }

    Vehicle* getVehicle() const
    {
        return vehicle;
    }

    Customer* getCustomer() const
    {
        return customer;
    }

    int getDays() const
    {
        return days;
    }
};

#endif