#include "RentalSystem.h"
//#include "Car.h"
//#include "Motorbike.h"
//#include "Truck.h"

int main()
{
    RentalSystem system;

    Vehicle* car =
        new Car("Toyota Corolla",
                50,
                5);

    Vehicle* bike =
        new Motorbike("Honda 125",
                      20,
                      125);

    Vehicle* truck =
        new Truck("Isuzu Truck",
                  100,
                  8);

    system.addVehicle(car);
    system.addVehicle(bike);
    system.addVehicle(truck);

    Customer* c1 =
        new Customer("Ali", 101);

    Customer* c2 =
        new Customer("Ahmed", 102);

    system.addCustomer(c1);
    system.addCustomer(c2);

    system.rentVehicle(car, c1, 5);
    system.rentVehicle(truck, c2, 3);

    system.returnVehicle(car);

    system.printSummary();

    return 0;
}