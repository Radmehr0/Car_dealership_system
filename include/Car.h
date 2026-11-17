#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>


class Car
{
protected:
    int car_ID;
    std::string type;
    bool available;

public:
    //Constructors
    Car();
    Car(int ID_of_car, const std::string& type_of_car,  bool availability_of_car);
    Car(const Car& otherCar);
    virtual ~Car();

    //getters
    int get_car_ID() const;
    std::string get_type() const;
    bool get_available() const;

    //setters
    void set_car_ID(int set_car_identification);
    void set_type(const std::string& set_car_type);
    void set_available(bool set_available);

    //pure abstract for dynamic binding for concrete classes
    virtual void print() const = 0;
};


#endif //CAR_H