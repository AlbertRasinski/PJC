#include "CPostacGracza.h"

const double CPostacGracza::czasNiewrazliwosci = 1;
const double CPostacGracza::stalaPredkoscPostaci = 0.08;

CPostacGracza::CPostacGracza():polozeniePostaci(640,360),zyciePostaci(10,10), polozeniePostaciPoczatkowe(640, 360) {
	predkosc = 5;
	wygladPostaci = 0;
	silaAtakow = 10;
	szybkostrzelnosc = 12;
	zasieg = 500;
	predkoscPociskow = 5;
	odliczanieNiewrazliwosci = 0;
	obecnePomieszczenieX = 7;
	obecnePomieszczenieY = 7;
	flying = 0;
	shootsThroughWalls = 0;
	stanHiperBomb = 1;
}

void CPostacGracza::poruszaniePostaci(CSterowanie klaw, sf::Time elapsed) {
	polozeniePostaciPoczatkowe.pozycjaX = polozeniePostaci.pozycjaX;
	polozeniePostaciPoczatkowe.pozycjaY = polozeniePostaci.pozycjaY;

	if (klaw.left == true && klaw.right == false) {
		if (klaw.up == true || klaw.down == true) {
			polozeniePostaci.pozycjaX = (polozeniePostaci.pozycjaX - (predkosc * stalaPredkoscPostaci * elapsed.asMilliseconds()) / 1.4);
		}
		else {
			polozeniePostaci.pozycjaX = (polozeniePostaci.pozycjaX - (predkosc * stalaPredkoscPostaci * elapsed.asMilliseconds()));
			wygladPostaci = 3;
		}
	}

	if (klaw.left == false && klaw.right == true) {
		if (klaw.up == true || klaw.down == true) {
			polozeniePostaci.pozycjaX = (polozeniePostaci.pozycjaX + (predkosc * stalaPredkoscPostaci * elapsed.asMilliseconds()) / 1.4);
		}
		else {
			polozeniePostaci.pozycjaX = (polozeniePostaci.pozycjaX + (predkosc * stalaPredkoscPostaci * elapsed.asMilliseconds()));
			wygladPostaci = 2;
		}
	}

	if (klaw.up == true && klaw.down == false) {
		if (klaw.left == true || klaw.right == true) {
			polozeniePostaci.pozycjaY = (polozeniePostaci.pozycjaY - (predkosc * stalaPredkoscPostaci * elapsed.asMilliseconds()) / 1.4);
		}
		else {
			polozeniePostaci.pozycjaY = (polozeniePostaci.pozycjaY - (predkosc * stalaPredkoscPostaci * elapsed.asMilliseconds()));
		}
		wygladPostaci = 1;
	}

	if (klaw.up == false && klaw.down == true) {
		if (klaw.left == true || klaw.right == true) {
			polozeniePostaci.pozycjaY = (polozeniePostaci.pozycjaY + (predkosc * stalaPredkoscPostaci * elapsed.asMilliseconds()) / 1.4);
		}
		else {
			polozeniePostaci.pozycjaY = (polozeniePostaci.pozycjaY + (predkosc * stalaPredkoscPostaci * elapsed.asMilliseconds()));
		}
		wygladPostaci = 0;
	}
}

void CPostacGracza::granicePokoju() {
	if (polozeniePostaci.pozycjaX > wymiarXPlanszyMax || polozeniePostaci.pozycjaX < wymiarXPlanszyMin) {
		polozeniePostaci.pozycjaX = polozeniePostaciPoczatkowe.pozycjaX;
	}
	if (polozeniePostaci.pozycjaY > wymiarYPlanszyMax || polozeniePostaci.pozycjaY < (wymiarYPlanszyMin - 30)) {
		polozeniePostaci.pozycjaY = polozeniePostaciPoczatkowe.pozycjaY;
	}
}

bool CPostacGracza::kolizjaPrzeciwnik(int przeciwnikX, int przeciwnikY, int rozmiarX, int rozmiarY) {
	if ((polozeniePostaci.pozycjaX > (przeciwnikX - rozmiarX)) && (polozeniePostaci.pozycjaX < (przeciwnikX + rozmiarX) && (polozeniePostaci.pozycjaY > (przeciwnikY - rozmiarY))) && (polozeniePostaci.pozycjaY < (przeciwnikY + rozmiarY))) {
		--zyciePostaci.obecneZycie;
		odliczanieNiewrazliwosci = czasNiewrazliwosci;
		return true;
	}
	return false;
}
