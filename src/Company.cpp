#include "Company.h"

//Constructors
Company::Company() : Company_name("CoenCars"), Cars(nullptr), Car_counter(0), Car_capacity(1000)
{
    Cars = new Car*[Car_capacity];
    for (int i = 0; i < Car_capacity; i++)
        Cars[i] = nullptr; //allocating all space for cars
}

Company::Company(const std::string& name, int capacity) : Company_name(name), Cars(nullptr), Car_counter(0), Car_capacity(capacity)
{
    if (Car_capacity <= 0 || Car_capacity > 1000)
        Car_capacity = 1000;
    Cars = new Car*[Car_capacity];
    for (int i = 0; i < Car_capacity; i++)
        Cars[i] = nullptr;
}

Company::Company(const Company& otherCompany): Company_name(otherCompany.Company_name), Cars(nullptr), Car_counter(0),Car_capacity(otherCompany.Car_capacity)
{
    Cars = new Car*[Car_capacity];
    for (int i = 0; i < Car_capacity; i++)
        Cars[i] = nullptr;

    Car_counter = 0; //  to avoid double delete we don't copy car pointer
}

Company::~Company()
{
    for (int i = 0; i < Car_counter; i++)
    {
        delete Cars[i];
        Cars[i] = nullptr;
    }
    delete[] Cars;
    Cars = nullptr;
}

bool Company::addCar(Car* carPtr)
{
    if (!carPtr)
        return false;
    if (Car_counter >= Car_capacity)
        return false;
    if (findCar(carPtr->get_car_ID()) != nullptr)
        return false; // you have the car so it doesn't need to add again

    Cars[Car_counter] = carPtr;
    Car_counter++;
    return true;
}

Car* Company::findCar(int carID) const
{
    for (int i = 0; i < Car_counter; i++)
    {
        if (Cars[i] && Cars[i]->get_car_ID() == carID)
            return Cars[i];
    }
    return nullptr; // if nothing found just return null is better than random address
}



//printing stocks
void Company::print_ALL_Cars() const
{
    std::cout <<"===== "<< Company_name  << " - list of All Cars (#"<< Car_counter <<") ====="<<std::endl;
    for (int i = 0; i < Car_counter; i++)
    {
        if (Cars[i])
        {
            Cars[i]->print();
            std::cout<<std::endl;
        }
    }
}

void Company::print_Available_Cars() const
{
    std::cout << "===== " << Company_name << " - list of Available Cars =====\n";
    for (int i = 0; i < Car_counter; i++) {
        if (Cars[i] && Cars[i]->get_available()) {
            Cars[i]->print();
            std::cout << std::endl;
        }
    }
}

void Company::print_Rented_Cars() const
{
    std::cout << "===== " << Company_name << " - list of Rented Cars =====\n";
    for (int i = 0; i < Car_counter; i++) {
        if (Cars[i] && !Cars[i]->get_available()) {
            Cars[i]->print();
            std::cout << std::endl;
        }
    }
}

bool Company::renting_Car_to_Customer(int carID, Customer* customerPtr, const std::string& rentDate)
{
    if (!customerPtr)
        return false;

    Car* carPtr = findCar(carID); // find the car
    if (!carPtr)
        return false;
    if (!carPtr->get_available()) // check availability
        return false;

    carPtr->set_available(false);

    bool good_to_go = customerPtr->addRental(carPtr, rentDate);

    if (!good_to_go) // just in case if failed
    {
        carPtr->set_available(true);
        return false;
    }
    return true;
}

bool Company::returning_Car_from_Customer(int carID, Customer* customerPtr, const std::string& returnDate)
{
    if (!customerPtr)
        return false;

    Car* carPtr=findCar(carID);
    if (!carPtr)
        return false;
    bool good_to_go = customerPtr->returnRental(carID, returnDate);
    if (!good_to_go)
        return false;

    carPtr->set_available(true); // again the car is available
    return true;
}







