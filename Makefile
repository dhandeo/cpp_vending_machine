default: all

all: slottest machinestest

testSlot.o: Slot.o
testMachines.o: Devices.o VendingMachine.o Items.o

VendingMachine.o: src/VendingMachine.cpp src/VendingMachine.h Devices.o Items.o

Items.o: src/Items.cpp src/Items.h

Devices.o: src/Devices.cpp src/Devices.h

Slot.o: src/Slot.h

slottest: testSlot.o
	g++ -I src/ tests/testSlot.cpp -o slottest

machinestest: testMachines.o
		g++ -I src/ tests/testMachines.cpp src/VendingMachine.cpp src/Devices.cpp src/Items.cpp -o machinestest

clean:
	rm -f slottest
