

class nothingToDispenseException: public std::exception
{
public:
  virtual const char* what() const throw() // std call
  {
  return "Dispense called on an empty slot"; // error message
  }
};  //<-this is just a lazy way to create an object
