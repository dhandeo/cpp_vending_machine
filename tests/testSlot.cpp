#include "Slot.h"
#include <iostream>

void testSlot() {
  // Create slots
  Slot<int> a;
  std::cout << "Empty Slot: " << a << std::endl;

  Slot<int> b(5);
  std::cout << "Dollar Slot: " << b << std::endl;

  // Deposit
  int *some = new int(99);
  b.Deposit(some);
  std::cout << "After Deposition: " << b << std::endl;

  // Dispense
  int *other = b.Dispense();
  std::cout << "Dispensed: " << *other << std::endl;
  std::cout << "After Dispense: " << b << std::endl;
  delete other;

  other = b.Dispense();
}

int main() {
  testSlot();
}
