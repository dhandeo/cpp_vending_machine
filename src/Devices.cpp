#include "Devices.h"
#include <string>

bool AbstractMachine::isStarted() {
  return(this->started);
}

int SecureDevice::UnLock(const std::string &key) {
  // Returns
  if(key.compare(this->key) == 0) {
    this->locked = false;
    return SUCCESS;
  } else {
    this->locked = true;
    return ERROR;
  }
}

SecureDevice::SecureDevice(const std::string &newkey): key(newkey), locked(true) {

}


int SecureDevice::Lock() {
  // idempotent returns SUCCESS or 0 on success
  this->locked = true;
  return SUCCESS;
}
