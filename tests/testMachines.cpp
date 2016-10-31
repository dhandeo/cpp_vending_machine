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

void testVendingMachine() {
  VendingMachine v("secret");
  std::cout << "Default Locked: " << v.isLocked() << std::endl;
  std::cout << "Wrong unlock: " << v.UnLock("wrong") << std::endl;
  std::cout << "Correct Unlock: " << v.UnLock("secret") << std::endl;
  std::cout << "Lock Status: " << v.isLocked() << std::endl;
  v.Lock();
  std::cout << "After Locking: " << v.isLocked() << std::endl;
}


void testMachines() {
  // Create Vending Machine
  VendingMachine a("");
  std::cout << "Default start: " << a.isStarted() << std::endl;
  a.Start();
  std::cout << "After starting: " << a.isStarted() << std::endl;
  a.Stop();
  std::cout << "After stopping: " << a.isStarted() << std::endl;
}

int main() {
  testDevices();
  testVendingMachine();
  testMachines();
}
