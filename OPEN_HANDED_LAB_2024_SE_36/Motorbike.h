#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"

class Motorbike : public Vehicle
{
private:
    int engineCC;

public:
    Motorbike(string model,
              double rate,
              int cc)
        : Vehicle(model, rate),
          engineCC(cc) {}

    double calculateCost(int days) const override
    {
        double cost = dailyRate * days;

        if (days > 7)
            cost *= 0.90;

        return cost;
    }

    void display() const override
    {
        cout << "Motorbike: "
             << model
             << " Engine: "
             << engineCC
             << "cc" << endl;
    }
};

#endif