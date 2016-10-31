default: slottest

slottest:
	g++ -I src/ src/Slot.cpp tests/testSlot.cpp -o slottest

clean:
	rm -f slottest
