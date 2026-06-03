#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
private:
    int seats;

public:
    Car(string model, double rate, int seats)
        : Vehicle(model, rate), seats(seats) {}

    void display() const override
    {
        cout << "Car: " << model
             << " Seats: " << seats << endl;
    }
};

#endif