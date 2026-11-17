#ifndef RENTAL_H
#define RENTAL_H

#include "Car.h"
#include <iostream>
#include <string>
#include <iomanip>


class Rental
{
private:
    Car* car;
    std::string Rent_Date;
    std::string Return_Date;

public:
    Rental();
    Rental(Car* carPtr, const std::string& rentDate, const std::string& returnDate);
    Rental(const Rental& otherRental);
    ~Rental();

    //getters
    Car* get_Car() const;
    int get_Car_ID() const;
    std::string get_Car_Type() const;
    std::string get_Rent_Date() const;
    std::string get_Return_Date() const;

    //setters
    void set_Rent_Date(const std::string& rentDate);
    void set_Return_Date(const std::string& returnDate);

    // status verification
    bool is_Active() const; //check
    bool is_Returned() const;

    void closing_Rental(const std::string& returnDate); // just in case if return date is sooner than proposed return date

    void print() const; //print info

};


#endif //RENTAL_H