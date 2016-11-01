#include "VendingMachine.h"
#include "Devices.h"
#include "Items.h"
#include <string>
#include <typeinfo>

VendingMachine::VendingMachine(const std::string & key, unsigned int numSlots):
  SecureDevice(key), bills(4), quarters(1), transactionQuarters(0) {
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
    this->transactionQuarters += 1;
    return SUCCESS;
  }
  else {
    return ERROR;
  }
}

int VendingMachine::InsertBill(Dollar *money) {
  if(this->isStarted()) {
    this->bills.Deposit((Dollar*) money);
    this->transactionQuarters += 4;
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

std::vector<Currency *>  VendingMachine::Cancel() {
  //TODO: Return any deposited money and reset
  if(this->transactionQuarters > 0) {
    // Reset
    this->transactionQuarters = 0;
    return this->DispenseMoney(this->transactionQuarters);
  }
  std::vector<Currency *> result;
  return result; 
}

Item * VendingMachine::Dispense(unsigned int slot) {
  // Dispenses an item from selected slot, and remaining change
  // Dispenss NULL and changes status message
  // Expects the machine to be is ready, raises
  if(!this->isStarted()) {
    this->status = "Machine not ready";
    return NULL;
  }

  // Selected slot should be ready
  if(this->slots[slot].getAvailable() < 1) {
    this->status = "Nothing in that slot";
    return NULL;
  }

  // Compute cost
  int quarters = this->slots[slot].getPriceInQuarters();
  if(this->transactionQuarters < quarters) {
    this->status = "Need more money";
    return NULL;
  }

  // TODO: Check that enough change is available

  // Dispense the change
  this->DispenseMoney(this->transactionQuarters - quarters);
  // TODO: Log the transaction success

  // Dispense the item
  return(this->slots[slot].Dispense());
}
