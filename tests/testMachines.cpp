#include "Devices.h"
#include "VendingMachine.h"
#include <iostream>

void testDevices() {
  SecureDevice d("secret");
  std::cout << "Default Locked: " << d.isLocked() << std::endl;
}

void testMachines() {
  // Create Vending Machine
  VendingMachine a;
}

int main() {
  testDevices();
  testMachines();
}
