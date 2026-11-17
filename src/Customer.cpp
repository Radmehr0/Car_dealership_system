#include "Customer.h"

Customer::Customer() : Customer_Number(0), Name(""), Address(""), Telephone(""), Car_Rent(nullptr), Rental_counter(0), Rental_capacity(0)
{
    expanding_Rental_capacity();
}

Customer::Customer(int number, const std::string& name, const std::string& address, const std::string& telephone) : Customer_Number(number), Name(name), Address(address), Telephone(telephone), Car_Rent(nullptr), Rental_counter(0), Rental_capacity(0)
{
    expanding_Rental_capacity();
}

Customer::Customer(const Customer& otherCustomer) : Customer_Number(otherCustomer.Customer_Number),
                                                    Name(otherCustomer.Name), Address(otherCustomer.Address),
                                                    Telephone(otherCustomer.Telephone), Car_Rent(nullptr),
                                                    Rental_counter(otherCustomer.Rental_counter),
                                                    Rental_capacity(otherCustomer.Rental_capacity)
{
    Car_Rent = new Rental*[Rental_capacity];
    for (int i = 0; i < Rental_capacity; i++)
        Car_Rent[i] = nullptr;

    for (int i = 0 ; i < Rental_counter; i++)
        Car_Rent[i] = new Rental(*otherCustomer.Car_Rent[i]);
}

Customer::~Customer()
{
    for (int i = 0; i < Rental_counter; i++)
    {
        delete Car_Rent[i];
        Car_Rent[i] = nullptr;
    }
    delete [] Car_Rent;
    Car_Rent = nullptr;
}

void Customer::expanding_Rental_capacity()
{
    int newCapacity = (Rental_capacity == 0) ? 2 : Rental_capacity * 2; // if it is zero it would be 0 multiplication so make it 2 by default

    Rental** newRentals = new Rental*[newCapacity];
    for (int i = 0; i < newCapacity; i++) newRentals[i] = nullptr;

    for (int i = 0; i < Rental_counter; i++)
        newRentals[i] = Car_Rent[i];

    delete[] Car_Rent;
    Car_Rent = newRentals;
    Rental_capacity = newCapacity;
}


//getters
int Customer::get_Customer_Number() const
{
    return Customer_Number;
}
std::string Customer::get_Name() const
{
    return Name;
}
std::string Customer::get_Address() const
{
    return Address;
}
std::string Customer::get_Telephone() const
{
    return Telephone;
}

//setters
void Customer::set_Customer_Number(int number)
{
    Customer_Number = number;
}
void Customer::set_Name(const std::string& name)
{
    Name = name;
}
void Customer::set_Address(const std::string& address)
{
    Address = address;
}
void Customer::set_Telephone(const std::string& telephone)
{
    Telephone = telephone;
}

bool Customer::addRental(Car* carPtr, const std::string& rentDate)
{
    if (!carPtr) return false;

    // Prevent renting the same car twice at the same time (if you have it why you want to add it again?)
    for (int i = 0; i < Rental_counter; i++) {
        if (Car_Rent[i] && Car_Rent[i]->is_Active() && Car_Rent[i]->get_Car() == carPtr) {
            return false;
        }
    }

    if (Rental_counter >= Rental_capacity) {
        expanding_Rental_capacity();
    }

    Car_Rent[Rental_counter] = new Rental(carPtr, rentDate, "");
    Rental_counter++;
    return true;
}

bool Customer::returnRental(int carID, const std::string& returnDate)
{
    for (int i = 0; i < Rental_counter; i++) {
        if (Car_Rent[i] && Car_Rent[i]->is_Active() && Car_Rent[i]->get_Car_ID() == carID) {
            Car_Rent[i]->closing_Rental(returnDate);
            return true;
        }
    }
    return false;
}
void Customer::print() const
{
        std::cout << std::left
         << std::setw(16) << "Customer Number:" << Customer_Number << '\n'
         << std::setw(16) << "Name:" << Name << '\n'
         << std::setw(16) << "Address:" << Address << '\n'
         << std::setw(16) << "Telephone:"  << Telephone << '\n';
}

