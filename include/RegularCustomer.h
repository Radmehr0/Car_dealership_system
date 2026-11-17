#ifndef REGULARCUSTOMER_H
#define REGULARCUSTOMER_H

#include "Customer.h"
#include <string>
#include <iomanip>

class RegularCustomer : public Customer
{
public:
    RegularCustomer();
    RegularCustomer(int number, const std::string& name, const std::string& address, const std::string& telephone);
    RegularCustomer(const RegularCustomer& otherRC);
    ~RegularCustomer() override;

    void print() const override;
};


#endif //REGULARCUSTOMER_H