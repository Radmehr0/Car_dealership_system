#include <iostream>
#include "Car.h"
#include "StandardCar.h"
#include "LuxuryCar.h"

int main() {
    const int SIZE = 4;
    Car* cars[SIZE];

    // Dynamic allocation
    cars[0] = new StandardCar(1001, "Toyota Standard", true);
    cars[1] = new LuxuryCar(1002, "Bentley Luxury", false);
    cars[2] = new StandardCar(1003, "Nissan Standard", true);
    cars[3] = new LuxuryCar(1004, "Pagani Luxury", true);

    std::cout << "===== Question 1 Test =====\n\n";
    std::cout << "===== Cars INFO =====\n\n";


    for (int i = 0; i < SIZE; i++) {
        std::cout << "Car #" << i + 1 << ": ";
        cars[i]->print();                   // Dynamic binding
        std::cout << std::endl;
    }

    // Cleanup
    std::cout << "===== Cars Delete and Deallocation =====\n";
    for (int i = 0; i < SIZE; i++) {
        delete cars[i];
        cars[i] = nullptr;
    }
    std::cout << "\n===== All cars deleted successfully! =====\n";
    return 0;
}