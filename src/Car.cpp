#include "Car.h"

//Constructors
Car::Car() : car_ID(0), type(""), available(true) {}
Car::Car(int ID_of_car, const std::string& type_of_car, bool availability_of_car) : car_ID(ID_of_car), type(type_of_car), available(availability_of_car) {}
Car::Car(const Car& otherCar) : car_ID(otherCar.car_ID), type(otherCar.type), available(otherCar.available) {}
Car::~Car(){} // There is Car::~Car() = default which is compiler generated destructor

//getters
int Car::get_car_ID() const
{
    return car_ID;
}
std::string Car::get_type() const
{
    return type;
}
bool Car::get_available() const
{
    return available;
}

//setters
void Car::set_car_ID(int set_car_identification)
{
    car_ID = set_car_identification;
}
void Car::set_type(const std::string& set_car_type)
{
    type = set_car_type;
}
void Car::set_available(bool set_available)
{
    available = set_available;
}






