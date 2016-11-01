#include "Devices.h"
#include "VendingMachine.h"
#include <iostream>

void testSecureDevices() {
  SecureDevice d("secret");
  std::cout << "Default Locked: " << d.isLocked() << std::endl;
  std::cout << "Wrong unlock: " << d.UnLock("wrong") << std::endl;
  std::cout << "Correct Unlock: " << d.UnLock("secret") << std::endl;
  std::cout << "Lock Status: " << d.isLocked() << std::endl;
  d.Lock();
  std::cout << "After Locking: " << d.isLocked() << std::endl;

  VendingMachine v("secret");
  std::cout << "VM Default Locked: " << v.isLocked() << std::endl;
  std::cout << "VM Wrong unlock: " << v.UnLock("wrong") << std::endl;
  std::cout << "VM Correct Unlock: " << v.UnLock("secret") << std::endl;
  std::cout << "VM Lock Status: " << v.isLocked() << std::endl;
  v.Lock();
  std::cout << "VM After Locking: " << v.isLocked() << std::endl;

}

void testVendingMachine() {
  VendingMachine a("c++11", 2);

  // Add some stuff
  a.Start();
  a.UnLock("c++11");
  Cake *cake = new Cake;
  a.Deposit(0, cake, 4);
  a.PrintStatus();

  // User requests something
  // a.SelectSlot(0);
  Dollar *dollar = new Dollar;
  a.InsertBill(dollar);
  a.PrintStatus();

  // Item *snack = a.Dispense();
  // Currency *

  // It is now responsibility of this function
  // To deal with Items obtained
  // Anticipated failures
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
  // testSecureDevices();
  testVendingMachine();
  // testMachines();
}
