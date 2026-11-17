#ifndef COMPANY_H
#define COMPANY_H

#include "Car.h"
#include "Customer.h"

#include <iostream>
#include <string>

class Company
{
private:
    std::string Company_name;

    Car** Cars; // pointer to pointer of cars obj in other word all Company's cars
    int Car_counter; // total number of Cars in Company
    int Car_capacity; // 1000

public:
    Company();
    Company(const std::string& name, int capacity = 1000); // in implementation also user able to
    Company(const Company& otherComp);
    ~Company();

    //methods
    bool addCar(Car* carPtr);
    Car* findCar(int carID) const;

    void print_ALL_Cars() const;
    void print_Available_Cars() const;
    void print_Rented_Cars() const;

    bool renting_Car_to_Customer(int carID, Customer* customerPtr, const std::string& rentDate);
    bool returning_Car_from_Customer(int carID, Customer* customerPtr, const std::string& returnDate);


};


#endif //COMPANY_H