#ifndef DJ_VENDING_MACHINE_H_
#define DJ_VENDING_MACHINE_H_

#include "Devices.h"
#include "Items.h"
#include "Slot.h"
#include <vector>

class VendingMachine: public AbstractMachine, public SecureDevice {
public:
  // Actions for user
  Item* Dispense(unsigned int slot);
  std::vector<Currency *> DispenseMoney(int quarters);
  // Wrapper around DispenseMoney which
  // also cancels the transaction
  std::vector<Currency *> Cancel();
  const std::string & ReadDisplay() { return this->status;} ;
  int InsertQuarter(Quarter *money);
  int InsertBill(Dollar *money);

  // Reimplements actions for operator
  virtual int Start();
  virtual int Stop();

  // TODO: Add methods for operator to add / remove items once the machine is unlocked
  int Deposit(int slot, Item * item, unsigned int priceInQuarters);
  // int Deposit(int slot, Item * item);
  // virtual UpdateDollarBills(int newcount);
  // virtual UpdateQuarters(int newcount);

  void PrintStatus();
  VendingMachine(const std::string & key, unsigned int numSlots=0);


private:

  // TODO: This can go into its own Display module
  std::string status;
  unsigned int transactionQuarters;
  // // Selection module
  // InputModule selectpad;
  //
  // // Currency module
  // MoneyModule moneybin;

  std::vector<Slot<Item> > slots;

  // TODO: This could go into its own MoneyModule
  Slot<Dollar> bills;
  Slot<Quarter> quarters;
};

#endif  // DJ_VENDING_MACHINE_H_
