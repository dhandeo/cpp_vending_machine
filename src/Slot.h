#ifndef DJ_SLOT_H_
#define DJ_SLOT_H_

#include <string>
#include <iostream>
#include <typeinfo>
#include <vector>
#include <iomanip>

#include "Exceptions.h"

/// A Slot represents the module keeping track of objects that can be dispensed
/// Provides a simple api to add, remove objects or to dispense a single object
/// Maintains the count of available objects and price
/// Does not create objects, only stores those deposited by the operator

template <class T> class Slot {
  private:
    std::vector<T *> store;
    std::string name; // Item name stored in this slot
    unsigned int quarters; // item price in quarters

  public:
    // Constructors
    Slot();
    Slot(int priceInQuarters);

    // Accessors
    // Getters
    std::string getName() const {return this->name;};
    unsigned int getPriceInQuarters() const {return this->quarters;};
    double getPrice() const {return this->quarters * 0.25;};
    unsigned int getAvailable() const {return this->store.size();};

    // Setters
    void Deposit(T*);
    T* Remove(unsigned int howMany);

    unsigned int setPriceInQuarters(int quarters) {this->quarters = quarters;};

    // Single object Dispense
    T* Dispense();

    // Streaming, for e.g. to cout
    template<class U> friend std::ostream& operator<<(std::ostream& os, const Slot<U>& it);
};

template<class T> Slot<T>::Slot(): quarters(0), name(typeid(T).name()) {

}

template<class T> Slot<T>::Slot(int priceInQuarters):
    quarters(priceInQuarters), name(typeid(T).name()) {
}

template<class T> void Slot<T>::Deposit(T *some) {
  this->store.push_back(some);
}

template<class T> T* Slot<T>::Dispense() {
  if(this->store.size() > 0) {
      T *item = this->store.back();
      this->store.pop_back();
      return item;
  }
  else {
    // TODO: Raise some error
    throw(nothingToDispenseException());
  }

}


template<class U> std::ostream& operator<<(std::ostream& os, const Slot<U>& it) {
    os << it.getAvailable() << " of " << it.getName() << " @ $" << std::fixed << std::setprecision(2) << it.getPrice();
    return os;
}

#endif  // DJ_SLOT_H_
