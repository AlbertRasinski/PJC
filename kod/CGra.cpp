#include "CGra.h"

const double CGra::stalaPredkoscPociskow = 0.12;

CGra::CGra() {
	poziom.generujPoziom();
	poziom.wczytajPoziom();
	czasPomiedzyLezkami = 0;
	poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].odkryty = true;
}

CGra::~CGra() {
	zapisz();
}

void CGra::dzialanie() {
	elapsed = clock.getElapsedTime();
	clock.restart();
	klaw.sczytajPrzyciski();
	poruszanieKolizjaPostaci();

	wystrzel();
	poruszanieLezki();

	for (int i = 0; i < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.size(); ++i) {
		poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i]->zachowaniePrzeciwnika(postac.polozeniePostaci.pozycjaX, postac.polozeniePostaci.pozycjaY, elapsed, poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy);
	}

	podniesieniePrzedmiotu();
	wygrana();
	hiperBomba();
}

void CGra::poruszanieKolizjaPostaci() {
	postac.poruszaniePostaci(klaw, elapsed);

	if (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.size() == poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow) {
		if (postac.polozeniePostaci.pozycjaY > wymiarYPlanszyMax && postac.polozeniePostaci.pozycjaX > 590 && postac.polozeniePostaci.pozycjaX < 690 && poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY+1].obecnosc) {
			lezki.clear();
			postac.obecnePomieszczenieY += 1;
			postac.polozeniePostaci.pozycjaX = 640;
			postac.polozeniePostaci.pozycjaY = wymiarYPlanszyMin + 1;
			poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].odkryty = true;
		}
		else if (postac.polozeniePostaci.pozycjaY < wymiarYPlanszyMin && postac.polozeniePostaci.pozycjaX > 590 && postac.polozeniePostaci.pozycjaX < 690 && poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY-1].obecnosc) {
			lezki.clear(); 
			postac.obecnePomieszczenieY -= 1;
			postac.polozeniePostaci.pozycjaX = 640;
			postac.polozeniePostaci.pozycjaY = wymiarYPlanszyMax - 1;
			poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].odkryty = true;
		}
		else if (postac.polozeniePostaci.pozycjaX > wymiarXPlanszyMax && postac.polozeniePostaci.pozycjaY > 300 && postac.polozeniePostaci.pozycjaY < 400 && poziom.poziom[postac.obecnePomieszczenieX+1][postac.obecnePomieszczenieY].obecnosc){
			lezki.clear(); 
			postac.obecnePomieszczenieX += 1;
			postac.polozeniePostaci.pozycjaX = wymiarXPlanszyMin + 1;
			postac.polozeniePostaci.pozycjaY = 350;
			poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].odkryty = true;
		}
		else if (postac.polozeniePostaci.pozycjaX < wymiarXPlanszyMin && postac.polozeniePostaci.pozycjaY > 300 && postac.polozeniePostaci.pozycjaY < 400 && poziom.poziom[postac.obecnePomieszczenieX-1][postac.obecnePomieszczenieY].obecnosc){
			lezki.clear(); 
			postac.obecnePomieszczenieX -= 1;
			postac.polozeniePostaci.pozycjaX = wymiarXPlanszyMax - 1;
			postac.polozeniePostaci.pozycjaY = 350;
			poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].odkryty = true;
		}
	}

	postac.granicePokoju();

	if (postac.flying == false) {
		for (int i = 0; i < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie.size(); ++i) {
			if (postac.polozeniePostaci.pozycjaX >= (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaX - 45) && postac.polozeniePostaci.pozycjaX <= (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaX + 45) && postac.polozeniePostaci.pozycjaY >= (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaY - 70) && postac.polozeniePostaci.pozycjaY <= (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaY + 35)) {
				if ((klaw.left == true || klaw.right == true) && (klaw.up == true || klaw.down == true) && (postac.polozeniePostaciPoczatkowe.pozycjaY <= (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaY - 70) || postac.polozeniePostaciPoczatkowe.pozycjaY >= (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaY + 35))) {
					postac.polozeniePostaci.pozycjaY = postac.polozeniePostaciPoczatkowe.pozycjaY;
				}
				if ((klaw.up == true || klaw.down == true) && (klaw.left == true || klaw.right == true) && (postac.polozeniePostaciPoczatkowe.pozycjaX <= (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaX - 45) || postac.polozeniePostaciPoczatkowe.pozycjaX >= (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaX + 45))) {
					postac.polozeniePostaci.pozycjaX = postac.polozeniePostaciPoczatkowe.pozycjaX;
				}
				if ((klaw.left == true || klaw.right == true) && (klaw.up == false && klaw.down == false)) {
					postac.polozeniePostaci.pozycjaX = postac.polozeniePostaciPoczatkowe.pozycjaX;
				}
				if ((klaw.up == true || klaw.down == true) && (klaw.left == false && klaw.right == false)) {
					postac.polozeniePostaci.pozycjaY = postac.polozeniePostaciPoczatkowe.pozycjaY;
				}
			}
		}
	}	

	if (postac.odliczanieNiewrazliwosci <= 0) {
		for (int i = 0; i < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.size(); ++i) {
			if (postac.kolizjaPrzeciwnik(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaX(), poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaY(), poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i]->getRozmiarPrzeciwnikaX(), poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i]->getRozmiarPrzeciwnikaY())) {
				break;
			}
			for (int j = 0; j < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i]->getPociskiSize(); ++j) {
				if (postac.kolizjaPrzeciwnik(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i]->getPociskPozycjaX(j), poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i]->getPociskPozycjaY(j), 30, 40));
			}
		}
	}
	else {
		postac.odliczanieNiewrazliwosci -= elapsed.asSeconds();
	}
}

void CGra::wystrzel() {
	czasPomiedzyLezkami -= elapsed.asSeconds();
	if (klaw.shootDown == true && klaw.shootUp == false && klaw.shootLeft == false && klaw.shootRight == false) {
		postac.wygladPostaci = 0;
	}
	else if (klaw.shootDown == false && klaw.shootUp == true && klaw.shootLeft == false && klaw.shootRight == false) {
		postac.wygladPostaci = 1;
	}
	else if (klaw.shootDown == false && klaw.shootUp == false && klaw.shootLeft == true && klaw.shootRight == false) {
		postac.wygladPostaci = 3;
	}
	else if (klaw.shootDown == false && klaw.shootUp == false && klaw.shootLeft == false && klaw.shootRight == true) {
		postac.wygladPostaci = 2;
	}

	if (klaw.shootUp == true || klaw.shootDown == true || klaw.shootLeft == true || klaw.shootRight == true) {
		if ((czasPomiedzyLezkami - elapsed.asSeconds()) <= 0) {
			czasPomiedzyLezkami = (postac.szybkostrzelnosc / 20);
			if (klaw.shootDown == true && klaw.shootUp == false && klaw.shootLeft == false && klaw.shootRight == false) {
				lezki.push_back(CPociski(postac.polozeniePostaci.pozycjaX, postac.polozeniePostaci.pozycjaY, postac.polozeniePostaci.pozycjaX, postac.polozeniePostaci.pozycjaY, 0));
			}
			else if (klaw.shootDown == false && klaw.shootUp == true && klaw.shootLeft == false && klaw.shootRight == false) {
				lezki.push_back(CPociski(postac.polozeniePostaci.pozycjaX, postac.polozeniePostaci.pozycjaY, postac.polozeniePostaci.pozycjaX, postac.polozeniePostaci.pozycjaY, 1));
			}
			else if (klaw.shootDown == false && klaw.shootUp == false && klaw.shootLeft == true && klaw.shootRight == false) {
				lezki.push_back(CPociski(postac.polozeniePostaci.pozycjaX, postac.polozeniePostaci.pozycjaY, postac.polozeniePostaci.pozycjaX, postac.polozeniePostaci.pozycjaY, 3));
			}
			else if (klaw.shootDown == false && klaw.shootUp == false && klaw.shootLeft == false && klaw.shootRight == true) {
				lezki.push_back(CPociski(postac.polozeniePostaci.pozycjaX, postac.polozeniePostaci.pozycjaY, postac.polozeniePostaci.pozycjaX, postac.polozeniePostaci.pozycjaY, 2));
			}
		}
	}
}

void CGra::poruszanieLezki() {
	if (lezki.size() != 0) {
		switch (lezki[0].kierunek) {
		case 0:
			if ((lezki[0].obecnePolozeniePociskow.pozycjaY - lezki[0].poczatkowePolozeniePociskow.pozycjaY) > postac.zasieg) {
				lezki.erase(lezki.begin());
			}
			break;
		case 1:
			if ((lezki[0].poczatkowePolozeniePociskow.pozycjaY - lezki[0].obecnePolozeniePociskow.pozycjaY) > postac.zasieg) {
				lezki.erase(lezki.begin());
			}
			break;
		case 2:
			if ((lezki[0].obecnePolozeniePociskow.pozycjaX - lezki[0].poczatkowePolozeniePociskow.pozycjaX) > postac.zasieg) {
				lezki.erase(lezki.begin());
			}
			break;
		case 3:
			if ((lezki[0].poczatkowePolozeniePociskow.pozycjaX - lezki[0].obecnePolozeniePociskow.pozycjaX) > postac.zasieg) {
				lezki.erase(lezki.begin());
			}
			break;
		}
	}
	
	std::vector<int> numerDoUsuniecia;
	int tmp = 0;
	for (int i = 0; i < lezki.size(); ++i) {
		switch (lezki[i].kierunek) {
		case 0:
			tmp = lezki[i].obecnePolozeniePociskow.pozycjaY + (postac.predkoscPociskow * stalaPredkoscPociskow * elapsed.asMilliseconds());
			if (tmp > (wymiarYPlanszyMax + 15)) {
				numerDoUsuniecia.push_back(i);
			}
			else {
				if (postac.shootsThroughWalls == false) {
					for (int j = 0; j < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie.size(); ++j) {
						if ((tmp < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaY + 35)) && (tmp > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaY - 35)) && (lezki[i].obecnePolozeniePociskow.pozycjaX > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaX - 35)) && (lezki[i].obecnePolozeniePociskow.pozycjaX < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaX + 35))) {
							numerDoUsuniecia.push_back(i);
							goto end;
						}
					}
				}
				for (int j = 0; j < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.size(); ++j) {
					if ((tmp < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaY() + poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaY() / 2)) && (tmp > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaY() - poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaY() / 2)) && (lezki[i].obecnePolozeniePociskow.pozycjaX > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaX() - poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaX() / 2)) && (lezki[i].obecnePolozeniePociskow.pozycjaX < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaX() + poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaX() / 2))) {
						numerDoUsuniecia.push_back(i);
						poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->setZyciePrzeciwnika(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getZyciePrzeciwnika() - postac.silaAtakow);
						if (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getZyciePrzeciwnika() <= 0) {
							if (dynamic_cast<COgien*>(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i])) {
								--poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow;
							}
							delete poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j];
							poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.erase(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.begin() + j);
						}
						goto end;
					}
				}
				lezki[i].obecnePolozeniePociskow.pozycjaY = tmp;
			}
			break;
		case 1:
			tmp = lezki[i].obecnePolozeniePociskow.pozycjaY - (postac.predkoscPociskow * stalaPredkoscPociskow * elapsed.asMilliseconds());
			if (tmp < (wymiarYPlanszyMin - 15)) {
				numerDoUsuniecia.push_back(i);
			}
			else {
				if (postac.shootsThroughWalls == false) {
					for (int j = 0; j < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie.size(); ++j) {
						if ((tmp > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaY - 35)) && (tmp < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaY + 35)) && (lezki[i].obecnePolozeniePociskow.pozycjaX > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaX - 35)) && (lezki[i].obecnePolozeniePociskow.pozycjaX < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaX + 35))) {
							numerDoUsuniecia.push_back(i);
							goto end;
						}
					}
				}
				for (int j = 0; j < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.size(); ++j) {
					if ((tmp < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaY() + poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaY() / 2)) && (tmp > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaY() - poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaY() / 2)) && (lezki[i].obecnePolozeniePociskow.pozycjaX > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaX() - poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaX() / 2)) && (lezki[i].obecnePolozeniePociskow.pozycjaX < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaX() + poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaX() / 2))) {
						numerDoUsuniecia.push_back(i);
						poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->setZyciePrzeciwnika(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getZyciePrzeciwnika() - postac.silaAtakow);
						if (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getZyciePrzeciwnika() <= 0) {
							if (dynamic_cast<COgien*>(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i])) {
								--poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow;
							}
							delete poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j];
							poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.erase(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.begin() + j);
						}
						goto end;
					}
				}
				lezki[i].obecnePolozeniePociskow.pozycjaY = tmp;
			}
			break;
		case 2:
			tmp = lezki[i].obecnePolozeniePociskow.pozycjaX + (postac.predkoscPociskow * stalaPredkoscPociskow * elapsed.asMilliseconds());
			if (tmp > (wymiarXPlanszyMax + 15)) {
				numerDoUsuniecia.push_back(i);
			}
			else {
				if (postac.shootsThroughWalls == false) {
					for (int j = 0; j < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie.size(); ++j) {
						if ((tmp < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaX + 35)) && (tmp > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaX - 35)) && (lezki[i].obecnePolozeniePociskow.pozycjaY < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaY + 35)) && (lezki[i].obecnePolozeniePociskow.pozycjaY > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaY - 35))) {
							numerDoUsuniecia.push_back(i);
							goto end;
						}
					}
				}
				for (int j = 0; j < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.size(); ++j) {
					if ((tmp < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaX() + poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaX()/2)) && (tmp > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaX() - poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaX()/2)) && (lezki[i].obecnePolozeniePociskow.pozycjaY > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaY() - poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaY()/2)) && (lezki[i].obecnePolozeniePociskow.pozycjaY < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaY() + poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaY()/2))) {
						numerDoUsuniecia.push_back(i);
						poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->setZyciePrzeciwnika(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getZyciePrzeciwnika() - postac.silaAtakow);
						if (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getZyciePrzeciwnika() <= 0) {
							if (dynamic_cast<COgien*>(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i])) {
								--poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow;
							}
							delete poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j];
							poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.erase(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.begin() + j);
						}
						goto end;
					}
				}
				lezki[i].obecnePolozeniePociskow.pozycjaX = tmp;
			}
			break;
		case 3:
			tmp = lezki[i].obecnePolozeniePociskow.pozycjaX - (postac.predkoscPociskow * stalaPredkoscPociskow * elapsed.asMilliseconds());
			if (tmp < (wymiarXPlanszyMin - 15)) {
				numerDoUsuniecia.push_back(i);
			}
			else {
				if (postac.shootsThroughWalls == false) {
					for (int j = 0; j < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie.size(); ++j) {
						if ((tmp > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaX - 35)) && (tmp < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaX + 35)) && (lezki[i].obecnePolozeniePociskow.pozycjaY < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaY + 35)) && (lezki[i].obecnePolozeniePociskow.pozycjaY > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].otoczenie[j].polozenieOtoczenia.pozycjaY - 35))) {
							numerDoUsuniecia.push_back(i);
							goto end;
						}
					}
				}
				for (int j = 0; j < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.size(); ++j) {
					if ((tmp < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaX() + poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaX() / 2)) && (tmp > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaX() - poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaX() / 2)) && (lezki[i].obecnePolozeniePociskow.pozycjaY > (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaY() - poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaY() / 2)) && (lezki[i].obecnePolozeniePociskow.pozycjaY < (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getPolozeniePrzeciwnikaY() + poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getRozmiarPrzeciwnikaY() / 2))) {
						numerDoUsuniecia.push_back(i);
						poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->setZyciePrzeciwnika(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getZyciePrzeciwnika() - postac.silaAtakow);
						if (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j]->getZyciePrzeciwnika() <= 0) {
							if (dynamic_cast<COgien*>(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i])) {
								--poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow;
							}
							delete poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[j];
							poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.erase(poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.begin() + j);
						}
						goto end;
					}
				}
				lezki[i].obecnePolozeniePociskow.pozycjaX = tmp;
			}
			break;
		}
	}
end:
	int j = 0;
	for (int i = 0; i < numerDoUsuniecia.size(); ++i) {
		lezki.erase(lezki.begin() + numerDoUsuniecia[i] - j);
		++j;
	}
}

void CGra::zapisz() {
	std::ofstream file;
	file.open("img\\save.txt");
	file << postac.polozeniePostaci.pozycjaX << '\n';
	file << postac.polozeniePostaci.pozycjaY << '\n';
	file << postac.polozeniePostaciPoczatkowe.pozycjaX << '\n';
	file << postac.polozeniePostaciPoczatkowe.pozycjaY << '\n';
	file << postac.zyciePostaci.maksymalneZycie << '\n';
	file << postac.zyciePostaci.obecneZycie << '\n';
	file << postac.predkosc << '\n';
	file << postac.silaAtakow << '\n';
	file << postac.zasieg << '\n';
	file << postac.szybkostrzelnosc << '\n';
	file << postac.predkoscPociskow << '\n';
	if (postac.flying == true) {
		file << '1' << '\n';
	}
	else {
		file << '0' << '\n';
	}
	if (postac.shootsThroughWalls == true) {
		file << '1' << '\n';
	}
	else {
		file << '0' << '\n';
	}
	file << postac.obecnePomieszczenieX << '\n';
	file << postac.obecnePomieszczenieY << '\n';
	file << poziom.liczbaPokoi << '\n';
	file << poziom.rodzajPrzedmiotu << '\n';

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			file << poziom.poziom[i][j].liczbaNiePrzeciwnikow << '\n';
			if (poziom.poziom[i][j].obecnosc == true) {
				file << '1' << '\n';
			}
			else {
				file << '0' << '\n';
			}
			if (poziom.poziom[i][j].odkryty == true) {
				file << '1' << '\n';
			}
			else {
				file << '0' << '\n';
			}
			if (poziom.poziom[i][j].boss == true) {
				file << '1' << '\n';
			}
			else {
				file << '0' << '\n';
			}
			if (poziom.poziom[i][j].treasure == true) {
				file << '1' << '\n';
			}
			else {
				file << '0' << '\n';
			}
			file << poziom.poziom[i][j].otoczenie.size() << '\n';
			for (int k = 0; k < poziom.poziom[i][j].otoczenie.size(); ++k) {
				file << poziom.poziom[i][j].otoczenie[k].polozenieOtoczenia.pozycjaX << '\n';
				file << poziom.poziom[i][j].otoczenie[k].polozenieOtoczenia.pozycjaY << '\n';
				file << poziom.poziom[i][j].otoczenie[k].typOtoczenia << '\n';
			}
			file << poziom.poziom[i][j].przeciwnicy.size() << '\n';
			for (int k = 0; k < poziom.poziom[i][j].przeciwnicy.size(); ++k) {
				file << poziom.poziom[i][j].przeciwnicy[k]->getPolozeniePrzeciwnikaX() << '\n';
				file << poziom.poziom[i][j].przeciwnicy[k]->getPolozeniePrzeciwnikaY() << '\n';
				if (dynamic_cast<CFly*>(poziom.poziom[i][j].przeciwnicy[k])) {
					file << "z" << '\n';
				}
				else if (dynamic_cast<COgien*>(poziom.poziom[i][j].przeciwnicy[k])) {
					file << "y" << '\n';
				}
				else if (dynamic_cast<CHeadless*>(poziom.poziom[i][j].przeciwnicy[k])) {
					file << "x" << '\n';
				}
				else if (dynamic_cast<CFlyShooting*>(poziom.poziom[i][j].przeciwnicy[k])) {
					file << "w" << '\n';
				}
				else if (dynamic_cast<CTurret*>(poziom.poziom[i][j].przeciwnicy[k])) {
					file << "v" << '\n';
				}
				else if (dynamic_cast<CBossTwins*>(poziom.poziom[i][j].przeciwnicy[k])) {
					file << "u" << '\n';
				}
				else if (dynamic_cast<CBossFlyMaster*>(poziom.poziom[i][j].przeciwnicy[k])) {
					file << "t" << '\n';
				}
			}
		}
	}
	file << postac.stanHiperBomb;
	file.close();
}

void CGra::wczytaj() {
	std::ifstream plik("img\\save.txt");
	std::string linia;

	std::getline(plik, linia);
	postac.polozeniePostaci.pozycjaX = std::stod(linia);
	std::getline(plik, linia);
	postac.polozeniePostaci.pozycjaY = std::stod(linia);
	std::getline(plik, linia);
	postac.polozeniePostaciPoczatkowe.pozycjaX = std::stod(linia);
	std::getline(plik, linia);
	postac.polozeniePostaciPoczatkowe.pozycjaY = std::stod(linia);
	std::getline(plik, linia);
	postac.zyciePostaci.maksymalneZycie = std::stoi(linia);
	std::getline(plik, linia);
	postac.zyciePostaci.obecneZycie = std::stoi(linia);
	std::getline(plik, linia);
	postac.predkosc = std::stod(linia);
	std::getline(plik, linia);
	postac.silaAtakow = std::stod(linia);
	std::getline(plik, linia);
	postac.zasieg = std::stoi(linia);
	std::getline(plik, linia);
	postac.szybkostrzelnosc = std::stod(linia);
	std::getline(plik, linia);
	postac.predkoscPociskow = std::stod(linia);
	std::getline(plik, linia);
	if (linia == "1") {
		postac.flying = true;
	}
	else {
		postac.flying = false;
	}
	std::getline(plik, linia);
	if (linia == "1") {
		postac.shootsThroughWalls = true;
	}
	else {
		postac.shootsThroughWalls = false;
	}
	std::getline(plik, linia);
	postac.obecnePomieszczenieX = std::stoi(linia);
	std::getline(plik, linia);
	postac.obecnePomieszczenieY = std::stoi(linia);
	std::getline(plik, linia);
	poziom.liczbaPokoi = std::stoi(linia);
	std::getline(plik, linia);
	poziom.rodzajPrzedmiotu = std::stoi(linia);

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			poziom.poziom[i][j].otoczenie.clear();
			std::getline(plik, linia);
			poziom.poziom[i][j].liczbaNiePrzeciwnikow = std::stoi(linia);
			std::getline(plik, linia);
			if (linia == "1") {
				poziom.poziom[i][j].obecnosc = true;
			}
			else {
				poziom.poziom[i][j].obecnosc = false;
			}
			std::getline(plik, linia);
			if (linia == "1") {
				poziom.poziom[i][j].odkryty = true;
			}
			else {
				poziom.poziom[i][j].odkryty = false;
			}
			std::getline(plik, linia);
			if (linia == "1") {
				poziom.poziom[i][j].boss = true;
			}
			else {
				poziom.poziom[i][j].boss = false;
			}
			std::getline(plik, linia);
			if (linia == "1") {
				poziom.poziom[i][j].treasure = true;
			}
			else {
				poziom.poziom[i][j].treasure = false;
			}

			std::getline(plik, linia);
			int tmp = std::stoi(linia);
			for (int k = 0; k < tmp; ++k) {
				std::getline(plik, linia);
				int px = std::stod(linia);
				std::getline(plik, linia);
				int py = std::stod(linia);
				std::getline(plik, linia);
				char typ = linia[0];
				poziom.poziom[i][j].otoczenie.push_back(CelementOtoczenia(typ,px,py));
			}
			std::getline(plik, linia);
			tmp = std::stoi(linia);
			for (auto a : poziom.poziom[i][j].przeciwnicy) {
				delete a;
			}
			poziom.poziom[i][j].przeciwnicy.clear();
			poziom.poziom[i][j].liczbaNiePrzeciwnikow = 0;
			for (int k = 0; k < tmp; ++k) {
				std::getline(plik, linia);
				int px = std::stod(linia);
				std::getline(plik, linia);
				int py = std::stod(linia);
				std::getline(plik, linia);
				char typ = linia[0];
				if (typ == 'z') {
					poziom.poziom[i][j].przeciwnicy.push_back(new CFly(px, py));
				}
				else if (typ == 'y') {
					poziom.poziom[i][j].przeciwnicy.push_back(new COgien(px, py));
					++poziom.poziom[i][j].liczbaNiePrzeciwnikow;
				}
				else if (typ == 'x') {
					poziom.poziom[i][j].przeciwnicy.push_back(new CHeadless(px, py));
				}
				else if (typ == 'w') {
					poziom.poziom[i][j].przeciwnicy.push_back(new CFlyShooting(px, py));
				}
				else if (typ == 'v') {
					poziom.poziom[i][j].przeciwnicy.push_back(new CTurret(px, py));
				}
				else if (typ == 'u') {
					poziom.poziom[i][j].przeciwnicy.push_back(new CBossTwins(px,py));
				}
				else if (typ == 't') {
					poziom.poziom[i][j].przeciwnicy.push_back(new CBossFlyMaster(px, py));
				}
			}
		}
	}
	std::getline(plik, linia);
	postac.stanHiperBomb = std::stoi(linia);
	plik.close();
}

void CGra::wygrana() {
	if (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].boss == true && poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.size() == poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow) {
		if (postac.polozeniePostaci.pozycjaX < 683 && postac.polozeniePostaci.pozycjaX >597 && postac.polozeniePostaci.pozycjaY < 264 && postac.polozeniePostaci.pozycjaY > 178) {
			postac.obecnePomieszczenieX = 7;
			postac.obecnePomieszczenieY = 7;
			poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].odkryty = true;
			postac.polozeniePostaci.pozycjaX = 640;
			postac.polozeniePostaci.pozycjaY = 360;
			poziom.liczbaPokoi += 3;
			if (poziom.liczbaPokoi > 150) {
				poziom.liczbaPokoi = 150;
			}
			poziom.generujPoziom();
			poziom.wczytajPoziom();
		}
	}
}

void CGra::podniesieniePrzedmiotu() {

	if (poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].treasure == true && postac.polozeniePostaci.pozycjaX < 680 && postac.polozeniePostaci.pozycjaX > 590 && postac.polozeniePostaci.pozycjaY < 360 && postac.polozeniePostaci.pozycjaY > 275) {
		switch (poziom.rodzajPrzedmiotu) {
		case 0:
		case 11:
			postac.zyciePostaci.maksymalneZycie += 2;
			postac.zyciePostaci.obecneZycie += 2;
			break;
		case 1:
			postac.zyciePostaci.obecneZycie = postac.zyciePostaci.maksymalneZycie;
			break;
		case 2:
		case 12:
			postac.silaAtakow *= 1.2;
			break;
		case 3:
			postac.predkosc *= 1.2;
			break;
		case 4:
			postac.predkoscPociskow *= 1.2;
			break;
		case 5:
		case 13:
			postac.szybkostrzelnosc *= 0.8;
			break;
		case 6:
			postac.zasieg *= 1.2;
			break;
		case 7:
			postac.zasieg = 2000;
			break;
		case 8:
			postac.flying = 1;
			break;
		case 9:
			postac.shootsThroughWalls = 1;
			break;
		case 10:
			postac.zyciePostaci.maksymalneZycie += 4;
			postac.zyciePostaci.obecneZycie += 4;
		}
		poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].treasure = false;
	}
}

void CGra::hiperBomba() {
	if (klaw.space == true && postac.stanHiperBomb == 1 && poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.size() != 0) {
		for (int i = 0; i < poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.size(); ++i) {
			delete poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy[i];
		}
		poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].przeciwnicy.clear();
		postac.stanHiperBomb = 0;
		poziom.poziom[postac.obecnePomieszczenieX][postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow = 0;
	}
}