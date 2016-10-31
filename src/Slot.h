#ifndef DJ_SLOT_H_
#define DJ_SLOT_H_

#include <string>
#include <iostream>
#include <typeinfo>
#include <vector>

/// A Slot represents the module keeping track of objects that can be dispensed
/// Provides a simple api to add, remove objects or to dispense a single object
/// Maintains the count of available objects and price
/// Does not create objects, only stores those deposited by the operator

template <class T>
class Slot {
private:
  std::vector<T *> store;
  std::string name; // Item name stored in this slot
  unsigned int quarters; // item price in quarters
  unsigned int available; // Number available

public:
  // Constructors
  Slot();
  Slot(int priceInQuarters, unsigned int howMany);

  // Accessors
  // Getters
  std::string getName() const {return this->name;};
  unsigned int getAvailable() const {return this->available;};
  unsigned int getPriceInQuarters() const {return this->quarters;};
  double getPrice() const {return this->quarters * 0.25;};

  // Setters
  void Deposit(std::vector<T*>);
  std::vector<T*> Remove(unsigned int howMany);

  unsigned int setPriceInQuarters(int quarters) {this->quarters = quarters;};

  // Single object Dispense
  T* Dispense();

  // Streaming, for e.g. to cout
  template<class U> friend std::ostream& operator<<(std::ostream& os, const Slot<U>& it);

};


#endif  // DJ_SLOT_H_
