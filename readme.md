# Assignment

Design an API for a **vending machine** that dispenses items of your choice using **object oriented design principles**. Please provide a main.cpp with your API. You may use any programming language, but I would prefer if you **use C++** and the code compiles. List any **assumptions** in your design. I am not looking for an exhaustive design here, and you **may skip over internal the implementation** of some your member functions.

# Assumptions (WIP)

- Vending Machine is serving items, i.e. not for fractional measurements like medium / large drinks
- The number of slots are fixed at the time of creation, and the items are loaded after
- Machine has a display for character string, rolling marquee for more number of characters
- Each slot has items of equal price, Items can be free
- It is not allowed to call Dispense when the slot is not ready, exception is raised
- Each slot has a dispense button which implicitly selects the product

# Use cases (requirements discussion)

(Consumer of API is the customer or operator)

## for operator

- Operator starts the machine, stops the machine
- Operator tries to unlock with password
- Operator unlocks the machine, loads products, unloads money

## for customer

- Customer comes, inserts a dollar bill, selects an item slot (cake) that is worth exact $1 presses dispense
- Customer selects dispense without inserting money and machine displays "Insert more money"
- User inserts a dollar bill and cancels the transaction, gets change back
- After Dispense operation, receives item, and is able to retrieve remaining change

## For remote

- Transaction is logged on paper with timestamp and further to some remote server if connected
- When connected the server requests for status and inventory, currency and status (ready or not) is reported

# Actors / Objects

- Machine
- InteractiveMachine
- VendingMachine
- Slot
- Item
- Cake
- MiniPretzel
- Currency
- DollarBill
- Quarter
- Logger
- PaperLogger
- RemoteLogger

# Relationships

- VendingMachine is an AbstractMachine
- VendingMachine is a SecureDevice
- VendingMachine has multiple Slot that can dispense
- VendingMachine accepts Logger
