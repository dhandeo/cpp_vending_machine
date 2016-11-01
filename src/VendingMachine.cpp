#include "VendingMachine.h"
#include "Devices.h"
#include "Items.h"
#include <string>
#include <typeinfo>

VendingMachine::VendingMachine(const std::string & key, unsigned int numSlots):
  SecureDevice(key), bills(4), quarters(1) {
    // Initialize the slots
    for(int i=0; i < numSlots; i++) {
      Slot<Item> aslot;
      slots.push_back(aslot);
    }
}

int VendingMachine::Deposit(int slot, Item * item, unsigned int priceInQuarters) {

  if(this->slots[slot].getAvailable() == 0) {
    // Slot clean, can be defined
    this->slots[slot].setPriceInQuarters(priceInQuarters);
    this->slots[slot].setName(item->Name());
    this->slots[slot].Deposit(item);
  }
  else {
    if(this->slots[slot].getName() == typeid(item).name()) {
      // Same items
      this->slots[slot].Deposit(item);
    }
    else {
      // Incompatible types
      return ERROR;
    }
  }
  return SUCCESS;
}



int VendingMachine::InsertQuarter(Quarter *money) {
  if(this->isStarted()) {
    this->quarters.Deposit((Quarter *) money);
    return SUCCESS;
  }
  else {
    return ERROR;
  }
}

int VendingMachine::InsertBill(Dollar *money) {
  if(this->isStarted()) {
    this->bills.Deposit((Dollar*) money);
    return SUCCESS;
  }
  else {
    return ERROR;
  }
}

void VendingMachine::PrintStatus() {
  std::cout << "   Dollars: " << this->bills << std::endl;
  std::cout << "   Quarters: " << this->quarters << std::endl;

  // TODO: Iterate over slots
  for(std::vector<Slot<Item> >::iterator it = slots.begin(); it != slots.end(); ++it) {
    std::cout << *it << std::endl;
  }
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

std::vector<Currency *> VendingMachine::DispenseMoney(int quarters) {
  // Returns money equal to the value presented in quarters
  // Always full dollars and remaining quarters or all quarters needed
  // TODO: Implement the full logic

  std::vector<Currency *> result;
  return result;
}

Item * VendingMachine::Dispense() {
  // Dispenses an item from selected slot, and remaining change
  // Expects the machine to be is ready, raises
  // an exception if called while not ready

  // Selected slot should be ready

  // Verify that enough currency is loaded

  // Check that enough change is available

  // Dispense the change
  int change=2;
  this->DispenseMoney(2);

  // Dispense the item

  Item *item = new Cake();
  // Log the transaction success
  return(item);
}
