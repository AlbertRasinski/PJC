#include "CFlyShooting.h"

const double CFlyShooting::PredkoscFly = 0.01;
const double CFlyShooting::czasPomiedzyStrzalami = 1.8;
const double CFlyShooting::predkoscLezkiPrzeciwnika = 0.4;

CFlyShooting::CFlyShooting(int x, int y) : CPrzeciwnik(x, y, 20, 20, 50, 70, 'w') {
	odliczanie = (czasPomiedzyStrzalami + 2 * (double(rand()) / double((RAND_MAX))));
}

void CFlyShooting::zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek) {
	if (polozeniePrzeciwnika.pozycjaX < graczX) {
		polozeniePrzeciwnika.pozycjaY -= (sin(atan((polozeniePrzeciwnika.pozycjaY - graczY) / (polozeniePrzeciwnika.pozycjaX - graczX))) * PredkoscFly * elapsed.asMilliseconds());
		polozeniePrzeciwnika.pozycjaX -= (cos(atan((polozeniePrzeciwnika.pozycjaY - graczY) / (polozeniePrzeciwnika.pozycjaX - graczX))) * PredkoscFly * elapsed.asMilliseconds());
	}
	else if (polozeniePrzeciwnika.pozycjaX > graczX) {
		polozeniePrzeciwnika.pozycjaY += (sin(atan((polozeniePrzeciwnika.pozycjaY - graczY) / (polozeniePrzeciwnika.pozycjaX - graczX))) * PredkoscFly * elapsed.asMilliseconds());
		polozeniePrzeciwnika.pozycjaX += (cos(atan((polozeniePrzeciwnika.pozycjaY - graczY) / (polozeniePrzeciwnika.pozycjaX - graczX))) * PredkoscFly * elapsed.asMilliseconds());
	}
	else {
		polozeniePrzeciwnika.pozycjaY += (sin(3.14 / 2) * PredkoscFly * elapsed.asMilliseconds());
		polozeniePrzeciwnika.pozycjaX += (cos(3.14 / 2) * PredkoscFly * elapsed.asMilliseconds());
	}

	if (polozeniePrzeciwnika.pozycjaX < wymiarXPlanszyMin) {
		polozeniePrzeciwnika.pozycjaX += (0.05 * elapsed.asMilliseconds());
	}
	if (polozeniePrzeciwnika.pozycjaX > wymiarXPlanszyMax) {
		polozeniePrzeciwnika.pozycjaX -= (0.05 * elapsed.asMilliseconds());
	}
	if (polozeniePrzeciwnika.pozycjaY < wymiarYPlanszyMin) {
		polozeniePrzeciwnika.pozycjaY += (0.05 * elapsed.asMilliseconds());
	}
	if (polozeniePrzeciwnika.pozycjaY > wymiarYPlanszyMax) {
		polozeniePrzeciwnika.pozycjaY -= (0.05 * elapsed.asMilliseconds());
	}

	odliczanie -= elapsed.asSeconds();
	if (odliczanie <= 0) {
		pociskiPrzeciwnika.push_back(CPociski(polozeniePrzeciwnika.pozycjaX, polozeniePrzeciwnika.pozycjaY, polozeniePrzeciwnika.pozycjaX, polozeniePrzeciwnika.pozycjaY, 0));
		poczatkowePolozenieGracza.push_back(CPolozenie(graczX,graczY));
		odliczanie = (czasPomiedzyStrzalami + 2 * (double(rand()) / double((RAND_MAX))));
	}

	std::vector<int> numeryDoUsuniecia;

	for (int i = 0; i < pociskiPrzeciwnika.size(); ++i) {
		if (pociskiPrzeciwnika[i].poczatkowePolozeniePociskow.pozycjaX < poczatkowePolozenieGracza[i].pozycjaX) {
			pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaY += (sin(atan((pociskiPrzeciwnika[i].poczatkowePolozeniePociskow.pozycjaY - poczatkowePolozenieGracza[i].pozycjaY) / (pociskiPrzeciwnika[i].poczatkowePolozeniePociskow.pozycjaX - poczatkowePolozenieGracza[i].pozycjaX))) * predkoscLezkiPrzeciwnika * elapsed.asMilliseconds());
			pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaX += (cos(atan((pociskiPrzeciwnika[i].poczatkowePolozeniePociskow.pozycjaY - poczatkowePolozenieGracza[i].pozycjaY) / (pociskiPrzeciwnika[i].poczatkowePolozeniePociskow.pozycjaX - poczatkowePolozenieGracza[i].pozycjaX))) * predkoscLezkiPrzeciwnika * elapsed.asMilliseconds());
		}
		else if (pociskiPrzeciwnika[i].poczatkowePolozeniePociskow.pozycjaX > poczatkowePolozenieGracza[i].pozycjaX) {
			pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaY -= (sin(atan((pociskiPrzeciwnika[i].poczatkowePolozeniePociskow.pozycjaY - poczatkowePolozenieGracza[i].pozycjaY) / (pociskiPrzeciwnika[i].poczatkowePolozeniePociskow.pozycjaX - poczatkowePolozenieGracza[i].pozycjaX))) * predkoscLezkiPrzeciwnika * elapsed.asMilliseconds());
			pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaX -= (cos(atan((pociskiPrzeciwnika[i].poczatkowePolozeniePociskow.pozycjaY - poczatkowePolozenieGracza[i].pozycjaY) / (pociskiPrzeciwnika[i].poczatkowePolozeniePociskow.pozycjaX - poczatkowePolozenieGracza[i].pozycjaX))) * predkoscLezkiPrzeciwnika * elapsed.asMilliseconds());
		}
		else {
			pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaY -= (sin(3.14 / 2) * predkoscLezkiPrzeciwnika * elapsed.asMilliseconds());
			pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaX -= (cos(3.14 / 2) * predkoscLezkiPrzeciwnika * elapsed.asMilliseconds());
		}

		if (pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaX > (wymiarXPlanszyMax + 15) || pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaX < (wymiarXPlanszyMin - 15) || pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaY>(wymiarYPlanszyMax + 15) || pociskiPrzeciwnika[i].obecnePolozeniePociskow.pozycjaY < (wymiarYPlanszyMin - 15)) {
			numeryDoUsuniecia.push_back(i);
		}
	}
	
	int j = 0;
	for (int i = 0; i < numeryDoUsuniecia.size(); ++i) {
		pociskiPrzeciwnika.erase(pociskiPrzeciwnika.begin() + numeryDoUsuniecia[i] - j);
		poczatkowePolozenieGracza.erase(poczatkowePolozenieGracza.begin() + numeryDoUsuniecia[i] - j);
		++j;
	}
}