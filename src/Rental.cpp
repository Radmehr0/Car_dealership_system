#include "Rental.h"

Rental::Rental() : car(nullptr), Rent_Date(""), Return_Date("") {}
Rental::Rental(Car* carPtr, const std::string& rentDate, const std::string& returnDate) : car(carPtr), Rent_Date(rentDate), Return_Date(returnDate) {}
Rental::Rental(const Rental& otherRental) : car(otherRental.car), Rent_Date(otherRental.Rent_Date), Return_Date(otherRental.Return_Date) {}
Rental::~Rental(){}

//getters
Car* Rental::get_Car() const
{
    return car;
}
int Rental::get_Car_ID() const
{
    return (car ? car->get_car_ID() : -1);

}
std::string Rental::get_Car_Type() const
{
    return (car ? car->get_type() : "");
}
std::string Rental::get_Rent_Date() const
{
    return Rent_Date;
}
std::string Rental::get_Return_Date() const
{
    return Return_Date;
}

//setters
void Rental::set_Rent_Date(const std::string& rentDate)
{
    Rent_Date = rentDate;
}

void Rental::set_Return_Date(const std::string& returnDate)
{
    Return_Date = returnDate;
}

//Methods
bool Rental::is_Active() const
{
    return !Rent_Date.empty() && Return_Date.empty();

}
bool Rental::is_Returned() const
{
    return !Return_Date.empty();
}

void Rental::closing_Rental(const std::string& returnDate) // just in case if return date is sooner than proposed return date
{
    if (is_Active()) {
        Return_Date = returnDate;
    }
}


void Rental::print() const
{
    if (!get_Car())
    {
        std::cerr << "Rental Error: NOT able to find a car"<<std::endl;
        return;
    }

    std::cout << "===== \"Rental Info:\" =====\n"<< std::left
         << std::setw(16) << "Car ID:"      << car->get_car_ID() << '\n'
         << std::setw(16) << "Car Type:"    << get_Car_Type() << '\n'
         << std::setw(16) << "Rent Date:"   << get_Rent_Date() << '\n'
         << std::setw(16) << "Return Date:" << (Return_Date.empty() ? "NOT RETURNED" : Return_Date) << "\n\n";

}




