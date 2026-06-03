#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle
{
private:
    double payload;

public:
    Truck(string model,
          double rate,
          double payload)
        : Vehicle(model, rate),
          payload(payload) {}

    double calculateCost(int days) const override
    {
        return dailyRate * days * 1.20;
    }

    void display() const override
    {
        cout << "Truck: "
             << model
             << " Payload: "
             << payload
             << " Tons" << endl;
    }
};

#endif