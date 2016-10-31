#ifndef DJ_VENDING_MACHINE_H_
#define DJ_VENDING_MACHINE_H_

#include "Devices.h"
#include "Items.h"
#include "Slot.h"
#include <vector>

class VendingMachine: public AbstractMachine, public SecureDevice {
public:
  // Actions for user
  virtual Item* Dispense();
  // virtual std::string ReadDisplay();
  // virtual void SelectSlot(int index);
  // virtual LoadCurrency(Currency *money);

  // Reimplements actions for operator
  virtual int Start();
  virtual int Stop();

  // TODO: Add methods that would come from SecureDevice
  // virtual void Lock() {};
  // virtual void Unlock(std::string key) {};

  // TODO: Add methods for operator to add / remove items once the machine is unlocked
  // virtual void UpdateSlot(int slot, Item item, int newcount);
  // virtual UpdateDollarBills(int newcount);
  // virtual UpdateQuarters(int newcount);

  // virtual int GetStatus();
  VendingMachine(const std::string & key);

private:

  // Display module
  std::string status;

  // // Selection module
  // InputModule selectpad;
  //
  // // Currency module
  // MoneyModule moneybin;

  std::vector<Slot<Item *> > slots;

  // Security module
  std::string key;


};

#endif  // DJ_VENDING_MACHINE_H_
