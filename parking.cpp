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
    car() : m_engine(false), m_model(""), m_pistons(""), m_drive(""), m_color(""), m_fuel("") {}

    car(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel) : m_model(model), m_pistons(pistons),
    m_drive(drive), m_color(color), m_fuel(fuel), m_engine(false) {
        std::cout << "Car created!" << std::endl;
    }
    
    car(const car& other) {
        m_engine = other.m_engine;
        m_model = other.m_model;
        m_pistons = other.m_pistons;
        m_drive = other.m_drive;
        m_color = other.m_color;
        m_fuel = other.m_fuel;
    }

    void init(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel) {
        m_model = model;
        m_pistons = pistons;
        m_drive = drive;
        m_color = color;
        m_fuel = fuel;
        m_engine = false;
        std::cout << "Car created!" << std::endl;
    }

    car& operator= (const car& other) {
        if(this != &other) {
            m_engine = other.m_engine;
            m_model = other.m_model;
            m_pistons = other.m_pistons;
            m_drive = other.m_drive;
            m_color = other.m_color;
            m_fuel = other.m_fuel;
        }
        return *this;
    }

    bool operator== (const car& other) const {
        return (m_model == other.m_model &&
                m_pistons == other.m_pistons &&
                m_drive == other.m_drive &&
                m_color == other.m_color &&
                m_fuel == other.m_fuel);
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

class parking {
    private:
    car* m_cars;
    int m_capacity;
    int m_size;

    public:
    parking(int capacity) : m_capacity(capacity), m_size(0) {
        m_cars = new car[capacity];
    }

    bool addcar(const car& newcar) {
        if(m_size < m_capacity) {
            m_cars[m_size] = newcar;
            m_size++;
            return true;
        } else {
            std::cout << "Parking is full!" << std::endl;
            return false;
        }
    }

    bool removecar(const car& oldcar) {
        for(int i = 0; i < m_size; ++i) {
            if(m_cars[i] == oldcar) {
                for(int j = i; j < m_size - 1; ++j) {
                    m_cars[j] = m_cars[j + 1];
                }
                m_size--;
                return true;
            }
        }
        return false;
    }

    ~parking() {
        delete[] m_cars;
    }
};

int main() {
    parking myParking(2);

    car car1("Toyota", "4", "FWD", "Red", "Gasoline");
    car car2("Honda", "4", "AWD", "Blue", "Diesel");
    car car3("Ford", "6", "RWD", "Black", "Gasoline");

    myParking.addcar(car1);
    myParking.addcar(car2);
    myParking.addcar(car3);

    myParking.removecar(car1);
    myParking.addcar(car3);

    return 0;
}