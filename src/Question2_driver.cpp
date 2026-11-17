#include <iostream>
#include <string>
#include <limits>

#include "Company.h"
#include "StandardCar.h"
#include "LuxuryCar.h"
#include "RegularCustomer.h"
#include "CorporateCustomer.h"

// a function for int input to avoid input stream bug like if user input char instead of int
int read_Int(const std::string& prompt);

// a function for line input to avoid input stream bug especially in reading space in line!
std::string read_Line(const std::string& prompt);

//for finding Customer info here we made a function to search them based on their customer number
Customer* find_Customer_By_Number(Customer** customers, int customerCount, int number);

int main() {
    std::cout << "===== CoenCars Rental Management System =====\n";

    Company company("CoenCars", 1000);


    const int MAX_CUSTOMERS = 300;  // Customers storage
    Customer* customers[MAX_CUSTOMERS];
    int customerCount = 0;
    for (int i = 0; i < MAX_CUSTOMERS; i++) customers[i] = nullptr;

    //Menu structure
    bool running = true;
    while (running) {
        std::cout << "\n========== MENU ==========\n"
                  << "1) Add Standard Car\n"
                  << "2) Add Luxury Car\n"
                  << "3) Add Regular Customer\n"
                  << "4) Add Corporate Customer\n"
                  << "5) Rent Car to Customer\n"
                  << "6) Return Car from Customer\n"
                  << "7) Print ALL Cars\n"
                  << "8) Print AVAILABLE Cars\n"
                  << "9) Print RENTED Cars\n"
                  << "10) Print a Customer (info + rentals)\n"
                  << "11) Exit\n";

        int choice = read_Int("Choose: ");

        switch (choice) {
            case 1: {
                int id = read_Int("Enter Standard Car ID: ");
                std::string type = read_Line("Enter Car Type (string): ");
                int available_Int = read_Int("Available? (1 = Yes, 0 = No): ");
                bool available = (available_Int == 1);

                Car* car = new StandardCar(id, type, available);
                if (company.addCar(car))
                    std::cout << "Standard car added.\n";
                else {
                    std::cerr << "Add car failed (duplicate ID or capacity full).\n";
                    delete car; // avoid leak if not stored
                }
                break;
            }

            case 2: {
                int id = read_Int("Enter Luxury Car ID: ");
                std::string type = read_Line("Enter Car Type (string): ");
                int availInt = read_Int("Available? (1 = Yes, 0 = No): ");
                bool available = (availInt == 1);

                Car* car = new LuxuryCar(id, type, available);
                if (company.addCar(car)) {
                    std::cout << "Luxury car added.\n";
                } else {
                    std::cerr << "Add car failed (duplicate ID or capacity full).\n";
                    delete car;
                }
                break;
            }

            case 3: {
                if (customerCount >= MAX_CUSTOMERS) {
                    std::cout << "Customer limit reached.\n";
                    break;
                }

                int number = read_Int("Enter Customer Number: ");
                if (find_Customer_By_Number(customers, customerCount, number)) {
                    std::cerr << "Customer number already exists.\n";
                    break;
                }

                std::string name = read_Line("Enter Name: ");
                std::string address = read_Line("Enter Address: ");
                std::string phone = read_Line("Enter Telephone: ");
                customers[customerCount] = new RegularCustomer(number, name, address, phone);
                customerCount++;
                std::cout << "Regular customer added.\n";
                break;
            }

            case 4: {
                if (customerCount >= MAX_CUSTOMERS) {
                    std::cerr << "Customer limit reached.\n";
                    break;
                }

                int number = read_Int("Enter Customer Number: ");
                if (find_Customer_By_Number(customers, customerCount, number)) {
                    std::cout << "Customer number already exists.\n";
                    break;
                }

                std::string name = read_Line("Enter Name: ");
                std::string address = read_Line("Enter Address: ");
                std::string phone = read_Line("Enter Telephone: ");

                customers[customerCount] = new CorporateCustomer(number, name, address, phone);
                customerCount++;
                std::cout << "Corporate customer added.\n";
                break;
            }

            case 5: {
                int custNum = read_Int("Enter Customer Number: ");
                Customer* customer_find = find_Customer_By_Number(customers, customerCount, custNum);
                if (!customer_find) {
                    std::cerr << "Customer not found.\n";
                    break;
                }

                int carId = read_Int("Enter Car ID to rent: ");
                std::string rentDate = read_Line("Enter Rent Date (e.g., 2026-01-01): ");

                bool ok = company.renting_Car_to_Customer(carId, customer_find, rentDate);
                if (ok) std::cout << "Rent successful! Car is now UNAVAILABLE.\n";
                else std::cerr << "Rent failed (car not found / not available / rental not added).\n";
                break;
            }

            case 6: {
                int custNum = read_Int("Enter Customer Number: ");
                Customer* cust = find_Customer_By_Number(customers, customerCount, custNum);
                if (!cust) {
                    std::cout << "Customer not found.\n";
                    break;
                }

                int carId = read_Int("Enter Car ID to return: ");
                std::string returnDate = read_Line("Enter Return Date (e.g., 2026-01-01): ");

                bool ok = company.returning_Car_from_Customer(carId, cust, returnDate);
                if (ok) std::cout << "Return successful. Car is now AVAILABLE.\n";
                else std::cerr << "Return failed (no active rental for this car - car not found).\n";
                break;
            }

            case 7:
                company.print_ALL_Cars();
                break;

            case 8:
                company.print_Available_Cars();
                break;

            case 9:
                company.print_Rented_Cars();
                break;

            case 10: {
                int custNum = read_Int("Enter Customer Number: ");
                Customer* customer_find = find_Customer_By_Number(customers, customerCount, custNum);
                if (!customer_find) {
                    std::cout << "Customer not found.\n";
                } else {
                    customer_find->print();
                }
                break;
            }

            case 11:
                running = false;
                break;

            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    }

    // cleanup customers (company destructor cleans up cars)
    for (int i = 0; i < customerCount; i++) {
        delete customers[i];
        customers[i] = nullptr;
    }

    std::cout << "\nSystem closed. Goodbye! We hope you enjoy it!!\n";
    return 0;
}

int read_Int(const std::string& prompt) {
    int number;
    while (true) {
        std::cout << prompt;
        std::cin >> number;
        if (std::cin) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //removing leftover
            return number;
        }
        //Fail state
        std::cin.clear(); //clean the line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid number! Try again\n";
    }
}

std::string read_Line(const std::string& prompt) {
    std::string str;
    std::cout << prompt;
    std::getline(std::cin, str);
    return str;
}

Customer* find_Customer_By_Number(Customer** customers, int customerCount, int number) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i] && customers[i]->get_Customer_Number() == number) {
            return customers[i];
        }
    }
    return nullptr;
}