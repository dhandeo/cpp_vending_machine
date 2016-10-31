#include "Slot.h"
#include <iostream>

void testSlot() {
  Slot<int> a();
  std::cout << "Slot: " << a << std::endl;
}

int main() {
  testSlot();
}
