#include "CPrzeciwnik.h"

CPrzeciwnik::CPrzeciwnik(int x, int y, int max, int obecne, int rozmiarX_, int rozmiarY_, char typPrzeciwnika_) : polozeniePrzeciwnika(x, y), zyciePrzeciwnika(max, obecne) {
	rozmiarX = rozmiarX_;
	rozmiarY = rozmiarY_;
}

void CPrzeciwnik::setZyciePrzeciwnika(int zycie) {
	zyciePrzeciwnika.obecneZycie = zycie;
};

double CPrzeciwnik::getPolozeniePrzeciwnikaX() {
	return polozeniePrzeciwnika.pozycjaX;
};

double CPrzeciwnik::getPolozeniePrzeciwnikaY() {
	return polozeniePrzeciwnika.pozycjaY;
};

int CPrzeciwnik::getZyciePrzeciwnika() {
	return zyciePrzeciwnika.obecneZycie;
};

int CPrzeciwnik::getRozmiarPrzeciwnikaX() {
	return rozmiarX;
};

int CPrzeciwnik::getRozmiarPrzeciwnikaY() {
	return rozmiarY;
};

int CPrzeciwnik::getPociskiSize() {
	return pociskiPrzeciwnika.size();
};

double CPrzeciwnik::getPociskPozycjaX(int i) {
	return pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaX;
};

double CPrzeciwnik::getPociskPozycjaY(int i) {
	return pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaY;
};