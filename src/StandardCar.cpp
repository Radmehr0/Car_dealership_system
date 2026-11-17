#include "StandardCar.h"

StandardCar::StandardCar() : Car(0, "Standard", true) {}
StandardCar::StandardCar(int ID_of_car, const std::string& type_of_car, bool availbility_of_car): Car(ID_of_car, type_of_car, availbility_of_car){}
StandardCar::StandardCar(const StandardCar& otherCar) : Car(otherCar){}

StandardCar::~StandardCar(){}

void StandardCar::print() const
{
    std::cout << "----- \"Standard Car Info:\" -----\n"<< std::left
         << std::setw(16) << "ID number:"    << car_ID << '\n'
         << std::setw(16) << "Type of Car:"  << type << '\n'
         << std::setw(16) << "Availability:" << (available ? "YES" : "NO") << '\n';
}


