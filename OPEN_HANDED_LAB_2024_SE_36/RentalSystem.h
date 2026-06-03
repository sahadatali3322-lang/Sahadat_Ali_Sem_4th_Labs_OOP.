#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include <vector>
#include "Rental.h"

class RentalSystem
{
private:
    vector<Vehicle*> vehicles;
    vector<Customer*> customers;
    vector<Rental*> rentals;

public:

    void addVehicle(Vehicle* v)
    {
        vehicles.push_back(v);
    }

    void addCustomer(Customer* c)
    {
        customers.push_back(c);
    }

    bool rentVehicle(
        Vehicle* vehicle,
        Customer* customer,
        int days)
    {
        if (!vehicle->isAvailable())
        {
            cout << "Vehicle already rented!\n";
            return false;
        }

        if (customer->hasActiveRental())
        {
            cout << "Customer already has rental!\n";
            return false;
        }

        vehicle->setAvailable(false);
        customer->setActiveRental(true);

        rentals.push_back(
            new Rental(vehicle,
                       customer,
                       days));

        return true;
    }

    void returnVehicle(Vehicle* vehicle)
    {
        for (auto rental : rentals)
        {
            if (rental->getVehicle() == vehicle &&
                !rental->isReturned())
            {
                rental->closeRental();

                vehicle->setAvailable(true);

                rental->getCustomer()
                    ->setActiveRental(false);

                cout << "Vehicle Returned\n";
            }
        }
    }

    void printSummary()
    {
        cout << "\nACTIVE RENTALS\n";

        for (auto rental : rentals)
        {
            if (!rental->isReturned())
            {
                cout << rental->getCustomer()->getName()
                     << " -> "
                     << rental->getVehicle()->getModel()
                     << " Days: "
                     << rental->getDays()
                     << " Cost: "
                     << rental->getCost()
                     << endl;
            }
        }

        int available = 0;
        int rented = 0;

        for (auto v : vehicles)
        {
            if (v->isAvailable())
                available++;
            else
                rented++;
        }

        cout << "\nAvailable Vehicles: "
             << available << endl;

        cout << "Rented Vehicles: "
             << rented << endl;
    }

    ~RentalSystem()
    {
        for (auto v : vehicles)
            delete v;

        for (auto c : customers)
            delete c;

        for (auto r : rentals)
            delete r;
    }
};

#endif