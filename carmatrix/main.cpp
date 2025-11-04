#include "matrix.h"

int main() {
    Matrix garage(2);
    garage.init();
    garage.print();
    garage.startAllEngines();
    garage.changeColorAll("Red");
    garage.print();
    return 0;
}
