#include <iostream>
#include <string>
#include <chrono>
#include <thread>

class car {
    private:
    bool m_engine;
    std::string m_model;
    std::string m_pistons;
    std::string m_drive;
    std::string m_color;
    std::string m_fuel;

    public:
    car(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel) : m_model(model), m_pistons(pistons),
    m_drive(drive), m_color(color), m_fuel(fuel), m_engine(false) {
        std::cout << "Car created!" << std::endl;
    }

    void change_color(std::string color) {
        m_color = color;
    }

    void print() {
        std::cout << "Car model: " << m_model << std::endl;
        std::cout << "Number of Pistons of the Car: " << m_pistons << std::endl;
        std::cout << "Car Drive: " << m_drive << std::endl;
        std::cout << "Color: " << m_color << std::endl;
        std::cout << "Fuel type: " << m_fuel << std::endl;
        if(m_engine) {
            std::cout << "The Engine is running" << std::endl;
        } else {
            std::cout << "The engine is turned off" << std::endl;
        }
    }

    void engine(bool engine) {
        if(engine && m_engine) {
            std::cout << "The Engine is already running" << std::endl;
            m_engine = true;
        } else if(!m_engine && engine) {
            std::cout << "The engine starts..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            m_engine = true;
            std::cout << "The Engine is running" << std::endl;
        } else if(m_engine && !engine) {
            std::cout << "The engine turns off" << std::endl;
        }
    }

    ~car() {
        std::cout << "Car is deleted" << std::endl;
    }
};

class driver {
    private:
    std::string m_name;
    int m_age;
    car& m_car;

    public:
    driver(std::string name, int age, car& car) : m_name(name), m_age(age), m_car(car) {
        std::cout << "Driver created!" << std::endl;
    }

    void printInfo() {
        std::cout << "Driver Name: " << m_name << std::endl;
        std::cout << "Driver age: " << m_age << std::endl;
        m_car.print();
    }
    ~driver() {
        std::cout << "Drivers info is deleted" << std::endl;
    }
};

int main() {
    car mercedes("Mercedes-Benz W124", "4", "RWD", "Black", "Benzine");
    driver Narek("Narek", 21, mercedes);
    Narek.printInfo();
}