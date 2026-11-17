#include "LuxuryCar.h"

LuxuryCar::LuxuryCar() : Car(0, "Luxury", true){}
LuxuryCar::LuxuryCar(int ID_of_car, const std::string& type_of_car, bool availbility_of_car) : Car(ID_of_car, type_of_car, availbility_of_car){}
LuxuryCar::LuxuryCar(const LuxuryCar& otherCar) : Car(otherCar){}
LuxuryCar::~LuxuryCar(){}

void LuxuryCar::print() const
{
    std::cout << "----- \"Luxury Car Info:\" -----\n"<< std::left
         << std::setw(16) << "ID number:"    << car_ID << '\n'
         << std::setw(16) << "Type of Car:"  << type << '\n'
         << std::setw(16) << "Availability:" << (available ? "YES" : "NO") << '\n';
}

