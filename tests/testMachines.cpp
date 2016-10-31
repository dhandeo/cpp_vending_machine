#include "Devices.h"
#include "VendingMachine.h"
#include <iostream>

void testDevices() {
  SecureDevice d("secret");
  std::cout << "Default Locked: " << d.isLocked() << std::endl;
  std::cout << "Wrong unlock: " << d.UnLock("wrong") << std::endl;
  std::cout << "Correct Unlock: " << d.UnLock("secret") << std::endl;
  std::cout << "Lock Status: " << d.isLocked() << std::endl;
  d.Lock();
  std::cout << "After Locking: " << d.isLocked() << std::endl;

}

void testMachines() {
  // Create Vending Machine
  VendingMachine a;
}

int main() {
  testDevices();
  testMachines();
}
