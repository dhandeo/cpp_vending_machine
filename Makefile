default: all

all: slottest

testSlot.o: Slot.o

Slot.o: src/Slot.h

slottest: testSlot.o
	g++ -I src/ tests/testSlot.cpp -o slottest

clean:
	rm -f slottest
