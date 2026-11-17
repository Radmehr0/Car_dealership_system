cmake_minimum_required(VERSION 3.20)
project(CarDealershipSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Car hierarchy (used by both questions)
set(CAR_SOURCES
        src/Car.cpp
        src/StandardCar.cpp
        src/LuxuryCar.cpp
)

# Company, customers and rentals (Question 2 only)
set(RENTAL_SOURCES
        src/Company.cpp
        src/Rental.cpp
        src/Customer.cpp
        src/RegularCustomer.cpp
        src/CorporateCustomer.cpp
)

# Question 1: polymorphism demo with Standard/Luxury cars
add_executable(Question1 src/Question1_driver.cpp ${CAR_SOURCES})
target_include_directories(Question1 PRIVATE include)

# Question 2: interactive rental management menu
add_executable(Question2 src/Question2_driver.cpp ${CAR_SOURCES} ${RENTAL_SOURCES})
target_include_directories(Question2 PRIVATE include)
