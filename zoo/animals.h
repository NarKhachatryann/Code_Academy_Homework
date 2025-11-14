#include <iostream>
#include <string>

class Animal {
    protected:
    std::string m_name;
public:
    Animal() {}
    virtual ~Animal() = default;

    virtual void makeSound() const = 0;

    std::string getName() const {
        return m_name;
    }
};

class Dog : public Animal {
    private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    double m_weight;
    int m_age;
    std::string sound;

    public:
    Dog(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age) : m_breed(breed), m_color(color), m_height(height), 
            m_weight(weight), m_age(age),sound("Woof!")
        {
            m_name = name;
        }

    void makeSound() const override {
        std::cout << sound << std::endl;
    }
};

class Cat : public Animal {
    private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    double m_weight;
    int m_age;
    std::string sound;

    public:
    Cat(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age) : m_breed(breed), m_color(color), m_height(height), 
            m_weight(weight), m_age(age), sound("Meow!")
        {
            m_name = name;
        }

    void makeSound() const override {
        std::cout << sound << std::endl;
    }
};

class Bird : public Animal {
    private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    double m_weight;
    int m_age;
    std::string sound;

    public:
    Bird(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age) : m_breed(breed), m_color(color), m_height(height), 
            m_weight(weight), m_age(age), sound("Chirik!")
        {
            m_name = name;
        }

    void makeSound() const override {
        std::cout << sound << std::endl;
    }
};

class Fish : public Animal {
    private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    double m_weight;
    int m_age;
    std::string sound;

    public:
    Fish(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age) : m_breed(breed), m_color(color), m_height(height), 
            m_weight(weight), m_age(age), sound("Blub!")
        {
            m_name = name;
        }

    void makeSound() const override {
        std::cout << sound << std::endl;
    }
};

class Horse : public Animal {
    private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    double m_weight;
    int m_age;
    std::string sound;

    public:
    Horse(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age) : m_breed(breed), m_color(color), m_height(height), 
            m_weight(weight), m_age(age), sound("Neigh!")
        {
            m_name = name;
        }

    void makeSound() const override {
        std::cout << sound << std::endl;
    }
};

class Snake : public Animal {
    private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    double m_weight;
    int m_age;
    std::string sound;

    public:
    Snake(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age) : m_breed(breed), m_color(color), m_height(height), 
            m_weight(weight), m_age(age), sound("shhhh!")
        {
            m_name = name;
        }

    void makeSound() const override {
        std::cout << sound << std::endl;
    }
};

/* int main() {
    Dog dog("Buddy", "Golden Retriever", "Golden", 60.0, 30.0, 3);
    Cat cat("Whiskers", "Siamese", "Cream", 25.0, 5.0, 2);
    Bird bird("Tweety", "Canary", "Yellow", 15.0, 0.2, 1);
    Fish fish("Nemo", "Clownfish", "Orange", 10.0, 0.5, 1);
    Horse horse("Star", "Arabian", "Brown", 160.0, 400.0, 5);
    Snake snake("Slither", "Python", "Green", 200.0, 50.0, 4);

    dog.makeSound();
    cat.makeSound();
    bird.makeSound();
    fish.makeSound();
    horse.makeSound();
    snake.makeSound();

    return 0;
} */