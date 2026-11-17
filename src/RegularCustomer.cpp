#include "RegularCustomer.h"

RegularCustomer::RegularCustomer() : Customer(){}
RegularCustomer::RegularCustomer(int number, const std::string& name, const std::string& address, const std::string& telephone) : Customer(number, name, address, telephone){}
RegularCustomer::RegularCustomer(const RegularCustomer& otherRC) : Customer(otherRC){}
RegularCustomer::~RegularCustomer() = default;


void RegularCustomer::print() const
{
    std::cout << "===== Regular Customer =====\n"<< std::left
         << std::setw(18) << "Customer Number:" << Customer_Number << '\n'
         << std::setw(18) << "Name:"            << Name << '\n'
         << std::setw(18) << "Address:"         << Address << '\n'
         << std::setw(18) << "Telephone:"       << Telephone << '\n'
         << std::setw(18) << "Total Rentals:"   << Rental_counter << "\n\n";

    for (int i = 0; i < Rental_counter; i++) {
        if (Car_Rent[i]) {
            Car_Rent[i]->print();
        }
    }
}
