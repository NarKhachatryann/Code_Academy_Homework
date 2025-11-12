#include <iostream>
#include "car.h"

class Mercedes : public car {
public:
    Mercedes(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel)
        : car(model, pistons, drive, color, fuel) {
        std::cout << "Mercedes created!" << std::endl;
    }

    ~Mercedes() {
        std::cout << "Mercedes destroyed!" << std::endl;
    }
};

class BMW : public car {
public:
    BMW(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel)
        : car(model, pistons, drive, color, fuel) {
        std::cout << "BMW created!" << std::endl;
    }
    ~BMW() {
        std::cout << "BMW destroyed!" << std::endl;
    }
};

class Audi : public car {
public:
    Audi(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel)
        : car(model, pistons, drive, color, fuel) {
        std::cout << "Audi created!" << std::endl;
    }
    ~Audi() {
        std::cout << "Audi destroyed!" << std::endl;
    }
};

int main() {
    Mercedes myMercedes("w124 E500", "4", "RWD", "Black", "Gasoline");
    std::cout << std::endl;
    myMercedes.print();
    myMercedes.engine(true);
    myMercedes.change_color("Red");
    myMercedes.print();
    std::cout << std::endl;
    myMercedes.engine(false);
    std::cout << std::endl;

    BMW myBMW("M3 E92", "6", "RWD", "Blue", "Gasoline");
    std::cout << std::endl;
    myBMW.print();
    myBMW.engine(true);
    myBMW.change_color("White");
    myBMW.print();
    std::cout << std::endl;
    myBMW.engine(false);
    std::cout << std::endl;

    Audi myAudi("A4 B8", "4", "AWD", "Gray", "Gasoline");
    std::cout << std::endl;
    myAudi.print();
    myAudi.engine(true);
    myAudi.change_color("Silver");
    myAudi.print();
    std::cout << std::endl;
    myAudi.engine(false);
    std::cout << std::endl;
}