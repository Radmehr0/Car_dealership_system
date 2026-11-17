#ifndef LUXURYCAR_H
#define LUXURYCAR_H

#include "Car.h"
#include <iostream>
#include <string>
#include <iomanip>

class LuxuryCar : public Car
{
public:
    LuxuryCar();
    LuxuryCar(int ID_of_car, const std::string& type_of_car,  bool availbility_of_car);
    LuxuryCar(const LuxuryCar& otherCar);
    ~LuxuryCar() override;

    void print() const override;

};


#endif //LUXURYCAR_H