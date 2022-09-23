#include "FragTrap.hpp"

FragTrap::FragTrap(void) : _hit(100), _energy(100), _attack(30), _name("") {
  std::cout << "Default Constructor from FragTrap was called." << std::endl;
  return;
}

FragTrap::FragTrap(std::string name)
    : _hit(100), _energy(100), _attack(30), _name(name) {
  std::cout << "FragTrap know as " << name << " prepared for combat.";
  std::cout << std::endl;
  return;
}

FragTrap::FragTrap(FragTrap const &other) {
  *this = other;
  return;
}

FragTrap::~FragTrap(void) {
  std::cout << "Destructor from FragTrap called." << std::endl;
  return;
}

 FragTrap& FragTrap::operator=(FragTrap const &other) {
  this->_name = other._name;
  this->_hit = other._hit;
  this->_attack = other._attack;
  this->_energy = other._energy;
  return *this;
}

void FragTrap::highFivesGuys(void) {
  std::cout << this->_name <<  ": Do you wanna a highfive ?" << std::endl;
  return;
}

void FragTrap::attack(std::string const &target) {
  if (this->_hit == 0) {
    this->deadObject("FragTrap");
  }
  if (this->_energy == 0) {
    this->outOfEnergyWarning("FragTrap");
  }
  std::cout << "FragTrap " << this->_name;
  std::cout << " attacks " << target << ", with " << this->_attack;
  std::cout << " points of damage!" << std::endl;
  --this->_energy;
}

void FragTrap::takeDamage(unsigned int amount) {
  if (this->_hit == 0) {
    this->deadObject("FragTrap");
  }
  this->_hit -= amount > this->_hit ? this->_hit : amount;
  if (this->_hit == 0) {
    std::cout << "FragTrap die !!!" << std::endl;
  }
  return;
}
