#pragma once
#include "Board.h"

class HumanBoard : public Board {
	// object members

	enum {kbup, kbdown};
	const char* kbChars;

public: // public functions
	HumanBoard(const Point& left1, const Point& right1, const int& side1, const char*& kbChars1) : 
		Board(left1, right1, side1), kbChars(kbChars1) {}

	virtual void handleKey(char c);

	const char* getKbChars() {
		return kbChars;
	}
	
};