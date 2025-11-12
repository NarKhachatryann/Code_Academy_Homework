#ifndef CAR_H
#define CAR_H

#include <string>

class car {
private:
    bool m_engine;
    std::string m_model;
    std::string m_pistons;
    std::string m_drive;
    std::string m_color;
    std::string m_fuel;

public:
    car(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel);
    car(const car& other);
    car& operator=(const car& other);

    void change_color(std::string color);
    void print();
    void engine(bool engine);

    ~car();
};

#endif