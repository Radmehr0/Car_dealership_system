#ifndef CORPORATECUSTOMER_H
#define CORPORATECUSTOMER_H
#include "Customer.h"
#include <string>
#include <iomanip>


class CorporateCustomer : public Customer
{
public:
    CorporateCustomer();
    CorporateCustomer(int number, const std::string& name, const std::string& address, const std::string& telephone);
    CorporateCustomer(const CorporateCustomer& otherCC);
    ~CorporateCustomer() override;

    void print() const override;
};


#endif //CORPORATECUSTOMER_H