#ifndef DJ_ITEMS_H_
#define DJ_ITEMS_H_

#include <string>
#include <iostream>

class Item {
  public:
    virtual std::string Name() {return "Item";};
};

// Products have a price
class Product : public Item {
  public:
    virtual std::string Name() {return "Product";};
};

class Cake : public Product {
  public:
    virtual std::string Name() {return "Cake";};
};

class Cookie : public Product {
  public:
    virtual std::string Name() {return "Cookie";};
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
