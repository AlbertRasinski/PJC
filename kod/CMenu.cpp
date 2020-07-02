#include "CMenu.h"

CMenu::CMenu() {
	kontrola = true;
	tryb = 0;
	wybor = 0;
}

CMenu::~CMenu() {
	delete gra;
}

void CMenu::kontrolaSterowania() {
	if (klaw.up || klaw.down || klaw.left || klaw.right || klaw.shootUp || klaw.shootDown || klaw.shootLeft || klaw.shootRight || klaw.space || klaw.esc || klaw.enter) {
		kontrola = false;
	}
	else {
		kontrola = true;
	}
}

void CMenu::poruszaniePoMenu() {
	klaw.sczytajPrzyciski();

	if (tryb == 3) {
		gra->dzialanie();
		if (gra->postac.zyciePostaci.obecneZycie <= 0) {
			tryb = 4;
			delete gra;
			gra = nullptr;
			remove("img\\save.txt");
		}
	}

	if (kontrola == true) {
		if (tryb == 0) {
			if (klaw.space || klaw.enter) {
				tryb = 1;
			}
			else if (klaw.esc) {
				tryb = 2;
			}
		}
		else if (tryb == 1) {
			if (klaw.esc) {
				tryb = 0;
			}
			if (klaw.shootDown || klaw.down) {
				if (wybor == 2) {
					wybor = 0;
				}
				else {
					++wybor;
				}
			}
			else if (klaw.shootUp || klaw.up) {
				if (wybor == 0) {
					wybor = 2;
				}
				else {
					--wybor;
				}
			}
			if ((klaw.space || klaw.enter) && wybor == 2) {
				tryb = 2;
			}
			if ((klaw.space || klaw.enter) && wybor == 1) {
				if (gra == nullptr) {
					gra = new CGra();
					std::ifstream plik("img\\save.txt");
					if (plik.good()) {
						gra->wczytaj();
					}
					plik.close();
				}
				tryb = 3;
				gra->clock.restart();
			}
			if ((klaw.space || klaw.enter) && wybor == 0) {
				delete gra;
				gra = new CGra();
				tryb = 3;
			}
		}
		else if (tryb == 3) {
			if (klaw.esc) {
				tryb = 1;
				gra->zapisz();
			}
		}
		else if (tryb == 4) {
			if (klaw.space || klaw.enter) {
				tryb = 1;
			}
		}
	}

	kontrolaSterowania();
}