#ifndef STANDARDCAR_H
#define STANDARDCAR_H

#include "Car.h"
#include <iostream>
#include <string>
#include <iomanip>

class StandardCar : public Car
{
public:
    StandardCar();
    StandardCar(int ID_of_car, const std::string& type_of_car,  bool availbility_of_car);
    StandardCar(const StandardCar& otherCar);
    ~StandardCar() override;

    void print() const override;

};


#endif //STANDARDCAR_H