# Assignment

Design an API for a **vending machine** that dispenses items of your choice using **object oriented design principles**. Please provide a main.cpp with your API. You may use any programming language, but I would prefer if you **use C++** and the code compiles. List any **assumptions** in your design. I am not looking for an exhaustive design here, and you **may skip over internal the implementation** of some your member functions.

# Assumptions (WIP)

- Vending Machine is serving items, i.e. not for fractional measurements like medium / large drinks
- Machine has fixed number of slots in which items can be loaded, defined at the creation
- Machine senses if a slot is loaded, in addition to maintaining inventory
- Machine has a display for character string, rolling marquee for more number of characters
- Items are free, there is only one dispense button
- It is not allowed to call Dispense when the machine is not ready, exception is raised

# Use cases (requirements discussion)

(Consumer of API is the customer or operator)

## for operator

- Operator starts the machine, stops the machine
- Operator tries to unlock, fails if the machine is on
- Operator stops machine off, Unlocks the machine, loads cakes
- Operator Locks the machine, turns the machine on

## for customer

- Customer comes, inserts a dollar bill, selects an item slot (cake) that is worth exact $1 presses dispense
- Customer presses dispense, machine displays "Please select the slot first"
- Customer selects "cake" and presses Dispense machine displays "$1 more needed for cake"
- Customer selects "cake" and adds $.50 and presses dispense machine displays "$.50 more needed for cake"
- User inserts two dollar bills selects bigcake item worth $1.50, presses dispense and gets two quarters back
- User inserts a dollar bill and cancels the transaction, gets change back
- After Dispense operation, receives item from bin, and currency from currency bin

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
