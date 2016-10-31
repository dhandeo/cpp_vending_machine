#ifndef DJ_MACHINE_H_
#define DJ_MACHINE_H_

#include <string>

#define ERROR 1
#define SUCCESS 0

class AbstractMachine {
protected:
  bool started;

public:
  virtual int Start() = 0;
  virtual int Stop() = 0;
  AbstractMachine(): started(false) {}
  bool isStarted();
};

class SecureDevice {
  private:
    std::string key;
    bool locked;

  public:
    SecureDevice();
    SecureDevice(const std::string & key);
    bool isLocked() { return this->locked; }
    int Lock();
    int UnLock(const std::string & key);
};

#endif  // DJ_MACHINE_H_
