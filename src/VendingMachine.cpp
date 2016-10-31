#include "VendingMachine.h"
#include "Devices.h"
#include "Items.h"

VendingMachine::VendingMachine() {
}

int VendingMachine::Start() {
  // TODO: Consider failures
  std::cout << "VendingMachine Starting" << std::endl;
  this->started = true;
  return SUCCESS;
}

int VendingMachine::Stop() {
  // TODO: Consider failures
  std::cout << "VendingMachine Stopped" << std::endl;
  this->started = true;
  return SUCCESS;
}


Item * VendingMachine::Dispense() {
  // Dispenses an item from selected slot, and remaining change
  // Expects the machine to be is ready, raises
  // an exception if called while not ready

  // Selected slot should be ready

  // Verify that enough currency is loaded

  // Check that enough change is available

  // Dispense the change

  // Dispense the item

  Item *item = new Cake();
  // Log the transaction success
  return(item);
}
