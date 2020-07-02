#include "CTurret.h"

const double CTurret::czasPomiedzyStrzalami = 1.3;
const double CTurret::predkoscLezkiPrzeciwnika = 0.6;

CTurret::CTurret(int x, int y) : CPrzeciwnik(x, y, 35, 35, 70, 70, 'v') {
	odliczanie = (czasPomiedzyStrzalami + 4 * (double(rand()) / double((RAND_MAX))));
}

void CTurret::zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek) {
	odliczanie -= elapsed.asSeconds();
	if (odliczanie <= 0) {
		pociskiPrzeciwnika.push_back(CPociski(polozeniePrzeciwnika.pozycjaX, polozeniePrzeciwnika.pozycjaY, polozeniePrzeciwnika.pozycjaX, polozeniePrzeciwnika.pozycjaY, 0));
		poczatkowePolozenieGracza.push_back(CPolozenie(graczX, graczY));
		odliczanie = (czasPomiedzyStrzalami + 4 * (double(rand()) / double((RAND_MAX))));
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