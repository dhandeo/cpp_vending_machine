#include "Slot.h"
#include <iostream>

void testSlot() {
  // Slot<int> a(5,1);
  Slot<int> a;
  std::cout << "Empty Slot: " << a << std::endl;

  Slot<int> b(5,4);
  std::cout << "Dollar Slot: " << b << std::endl;
}

int main() {
  testSlot();
}
