#include "animals.h"

class zoo {
private:
    Animal** m_animals;
    int m_animalCount;
    int m_currentIndex;

public:
    zoo(int animalCount = 100) : m_animalCount(animalCount), m_currentIndex(0) {
        m_animals = new Animal*[m_animalCount];
    }

    void addAnimal(Animal* animal) {
        if(m_currentIndex < m_animalCount) {
            m_animals[m_currentIndex++] = animal;
        }
    }

    void makeAllSounds() const {
        for(int i = 0; i < m_currentIndex; ++i) {
            m_animals[i]->makeSound();
        }
    }

    ~zoo() {
        for(int i = 0; i < m_currentIndex; ++i) {
            delete m_animals[i];
        }
        delete[] m_animals;
    }
};