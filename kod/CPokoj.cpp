#include "CPokoj.h"

CPokoj::CPokoj() {
	obecnosc = false;
	odkryty = false;
	boss = false;
	treasure = false;
}

CPokoj::~CPokoj() {
	for (auto a : przeciwnicy) {
		delete a;
	}
	przeciwnicy.clear();
}