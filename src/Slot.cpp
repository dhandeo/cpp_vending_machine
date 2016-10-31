#include "Slot.h"
#include <iostream>
#include <iomanip>
#include <typeinfo>

template<class T> Slot<T>::Slot(): quarters(0), available(0), name(typeid(T).name()) {

}

template<class T> Slot<T>::Slot(int priceInQuarters, unsigned int howMany):
    quarters(priceInQuarters), available(howMany), name(typeid(T).name()) {
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Slot<T>& it)
{
    os << it.getName() << "@$" << std::setprecision(2) << it.getPrice();
    return os;
}
