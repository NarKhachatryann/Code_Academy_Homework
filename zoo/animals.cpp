#include "animals.h"

Animal::Animal(const std::string& name) : m_name(name) {}
std::string Animal::getName() const { return m_name; }

Dog::Dog(const std::string& name, const std::string& breed, const std::string& color,
         double height, double weight, int age)
    : Animal(name), m_breed(breed), m_color(color),
      m_height(height), m_weight(weight), m_age(age), sound("Woof!") {}

void Dog::makeSound() const { std::cout << sound << std::endl; }

Cat::Cat(const std::string& name, const std::string& breed, const std::string& color,
         double height, double weight, int age)
    : Animal(name), m_breed(breed), m_color(color),
      m_height(height), m_weight(weight), m_age(age), sound("Meow!") {}

void Cat::makeSound() const { std::cout << sound << std::endl; }

Bird::Bird(const std::string& name, const std::string& breed, const std::string& color,
           double height, double weight, int age)
    : Animal(name), m_breed(breed), m_color(color),
      m_height(height), m_weight(weight), m_age(age), sound("Chirik!") {}

void Bird::makeSound() const { std::cout << sound << std::endl; }

Fish::Fish(const std::string& name, const std::string& breed, const std::string& color,
           double height, double weight, int age)
    : Animal(name), m_breed(breed), m_color(color),
      m_height(height), m_weight(weight), m_age(age), sound("Blub!") {}

void Fish::makeSound() const { std::cout << sound << std::endl; }

Horse::Horse(const std::string& name, const std::string& breed, const std::string& color,
             double height, double weight, int age)
    : Animal(name), m_breed(breed), m_color(color),
      m_height(height), m_weight(weight), m_age(age), sound("Neigh!") {}

void Horse::makeSound() const { std::cout << sound << std::endl; }

Snake::Snake(const std::string& name, const std::string& breed, const std::string& color,
             double height, double weight, int age)
    : Animal(name), m_breed(breed), m_color(color),
      m_height(height), m_weight(weight), m_age(age), sound("Shhhh!") {}

void Snake::makeSound() const { std::cout << sound << std::endl; }
