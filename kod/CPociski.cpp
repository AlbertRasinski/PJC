#include "CPociski.h"

CPociski::CPociski(int ppx, int ppy, int opx, int opy, int kierunek_) : poczatkowePolozeniePociskow(ppx, ppy), obecnePolozeniePociskow(opx, opy) {
	kierunek = kierunek_;
}