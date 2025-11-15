#ifndef ZOO_H
#define ZOO_H

#include "animals.h"

class zoo {
private:
    Animal** m_animals;
    int m_animalCount;
    int m_currentIndex;

public:
    zoo(int animalCount = 100);
    void addAnimal(Animal* animal);
    void makeAllSounds() const;

    ~zoo();
};

#endif