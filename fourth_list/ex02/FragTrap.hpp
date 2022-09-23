#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap(void);
  FragTrap(FragTrap const &);
  FragTrap(std::string);
  FragTrap &operator=(FragTrap const &);
  ~FragTrap(void);

  void highFivesGuys(void);
  void attack(std::string const &);
  void takeDamage(unsigned int);
  void beRepaired(unsigned int);

private:
  unsigned int _hit;
  unsigned int _energy;
  unsigned int _attack;
  std::string _name;
};

#endif // !FRAGTRAP_HPP
