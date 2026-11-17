#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iomanip>
#include "Rental.h"

class Customer
{
protected:
    int Customer_Number;
    std::string Name;
    std::string Address;
    std::string Telephone;
    Rental** Car_Rent; //pointer to pointer
    int Rental_counter; // number of rents per customer
    int Rental_capacity;

    void expanding_Rental_capacity(); //to expand slots the array currently using


public:
    Customer();
    Customer(int number, const std::string& name, const std::string& address,const  std::string& telephone);
    Customer(const Customer& otherCustomer);
    virtual ~Customer();

    //getters
    int get_Customer_Number() const;
    std::string get_Name() const;
    std::string get_Address() const ;
    std::string get_Telephone() const ;

    //setters
    void set_Customer_Number(int number);
    void set_Name(const std::string& name);
    void set_Address(const std::string& address);
    void set_Telephone(const std::string& telephone);


    bool addRental(Car* carPtr, const std::string& rentDate);
    bool returnRental (int carID, const std::string& returnDate);

    virtual void print() const;
};


#endif //CUSTOMER_H