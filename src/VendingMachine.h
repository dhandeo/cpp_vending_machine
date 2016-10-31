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
  int InsertQuarter(Quarter *money);
  int InsertBill(Dollar *money);

  // Reimplements actions for operator
  virtual int Start();
  virtual int Stop();

  // TODO: Add methods for operator to add / remove items once the machine is unlocked
  // virtual void UpdateSlot(int slot, Item item, int newcount);
  // virtual UpdateDollarBills(int newcount);
  // virtual UpdateQuarters(int newcount);

  void PrintStatus();
  VendingMachine(const std::string & key);

private:

  // TODO: This can go into its own Display module
  std::string status;

  // // Selection module
  // InputModule selectpad;
  //
  // // Currency module
  // MoneyModule moneybin;

  std::vector<Slot<Item *> > slots;

  // TODO: This could go into its own MoneyModule
  Slot<Dollar> bills;
  Slot<Quarter> quarters;
};

#endif  // DJ_VENDING_MACHINE_H_
