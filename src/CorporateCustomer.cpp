#include "CorporateCustomer.h"

CorporateCustomer::CorporateCustomer() : Customer(){}

CorporateCustomer::CorporateCustomer(int number, const std::string& name, const std::string& address, const std::string& telephone) : Customer(number, name, address, telephone){}

CorporateCustomer::CorporateCustomer(const CorporateCustomer& otherCC) : Customer(otherCC){}

CorporateCustomer::~CorporateCustomer() = default; // = default is compiler destructor and could be better instead of {} since it shows error if something goes wrong

void CorporateCustomer::print() const
{
    std::cout << "===== Corporate Customer =====\n"<< std::left
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



