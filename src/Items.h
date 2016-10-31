#ifndef DJ_ITEMS_H_
#define DJ_ITEMS_H_

#include <string>
#include <iostream>

class Item {
};

class Product : public Item {

};

class Cake : public Product {

};

class Cookie : public Product {

};

// Base class for two money items
class Currency: public Item {
  protected:
    double value;
  public:
    Currency(double newvalue): value(newvalue) {};
};

class Dollar: public Currency {
public:
  Dollar(): Currency(1.0) {};
};

class Quarter: public Currency {
public:
  Quarter(): Currency(0.25) {};
};

#endif  // DJ_ITEMS_H_
