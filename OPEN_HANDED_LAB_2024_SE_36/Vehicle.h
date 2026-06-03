#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string model;
    double dailyRate;
    bool available;

public:
    Vehicle(string m, double rate)
        : model(m), dailyRate(rate), available(true) {}

    virtual ~Vehicle() {}

    string getModel() const
    {
        return model;
    }

    bool isAvailable() const
    {
        return available;
    }

    void setAvailable(bool status)
    {
        available = status;
    }

    virtual double calculateCost(int days) const
    {
        return dailyRate * days;
    }

    virtual void display() const = 0;
};

#endif