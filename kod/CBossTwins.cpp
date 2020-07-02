#include "CBossTwins.h"
#include "CFly.h"

const double CBossTwins::czasPomiedzySzarzami = 3;
const double CBossTwins::predkoscPoruszania = 0.2;
const double CBossTwins::czasSzarzy = 1;
const double CBossTwins::predkoscSzarzy = 0.6;
const double CBossTwins::czasChodzenie = 0.8;

CBossTwins::CBossTwins(int x, int y) : CPrzeciwnik(x, y, 100, 100, 70, 70, 'u') {
	katPoruszania = rand() % 360;
	odliczanieChodzenie = czasChodzenie + 0.5* ((double(rand()) / double((RAND_MAX))));
	odliczaniePomiedzySzarzami = czasPomiedzySzarzami + 2 * ((double(rand()) / double((RAND_MAX))));
	odliczanieSzarza = czasSzarzy + ((double(rand()) / double((RAND_MAX))));
	namierzenie = false;
}

void CBossTwins::zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek) {
	odliczaniePomiedzySzarzami -= elapsed.asSeconds();
	odliczanieChodzenie -= elapsed.asSeconds();

	if (odliczaniePomiedzySzarzami > 0) {
		if (odliczanieChodzenie < 0) {
			katPoruszania = rand() % 360;
			odliczanieChodzenie = czasChodzenie + 0.5 * ((double(rand()) / double((RAND_MAX))));
		}
		if (((polozeniePrzeciwnika.pozycjaX + (cos(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds())) < wymiarXPlanszyMax) && ((polozeniePrzeciwnika.pozycjaX + (cos(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds())) > wymiarXPlanszyMin)) {
			polozeniePrzeciwnika.pozycjaX += (cos(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds());
		}
		else {
			katPoruszania += 2 * (90 - katPoruszania);
		}
		if (((polozeniePrzeciwnika.pozycjaY - (sin(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds())) < wymiarYPlanszyMax) && ((polozeniePrzeciwnika.pozycjaY - (sin(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds())) > wymiarYPlanszyMin)) {
			polozeniePrzeciwnika.pozycjaY -= (sin(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds());
		}
		else {
			katPoruszania += 2 * (180 - katPoruszania);
		}
	}
	else {
		odliczanieSzarza -= elapsed.asSeconds();
		if (namierzenie == false) {
			namierzenie = true;
			if (graczY > polozeniePrzeciwnika.pozycjaY && graczX > polozeniePrzeciwnika.pozycjaX) {
				katPoruszania = 360 - atan((graczY - polozeniePrzeciwnika.pozycjaY) / (graczX - polozeniePrzeciwnika.pozycjaX)) * 180 / 3.141592;
			}
			else if (graczY < polozeniePrzeciwnika.pozycjaY && graczX > polozeniePrzeciwnika.pozycjaX) {
				katPoruszania = atan((polozeniePrzeciwnika.pozycjaY - graczY) / (graczX - polozeniePrzeciwnika.pozycjaX)) * 180 / 3.141592;
			}
			else if (graczY < polozeniePrzeciwnika.pozycjaY && graczX < polozeniePrzeciwnika.pozycjaX) {
				katPoruszania = 180 - atan((graczY - polozeniePrzeciwnika.pozycjaY) / (graczX - polozeniePrzeciwnika.pozycjaX)) * 180 / 3.141592;
			}
			else if (graczY > polozeniePrzeciwnika.pozycjaY && graczX < polozeniePrzeciwnika.pozycjaX) {
				katPoruszania = 180 - atan((graczY - polozeniePrzeciwnika.pozycjaY) / (graczX - polozeniePrzeciwnika.pozycjaX)) * 180 / 3.141592;
			}
		}
		if (odliczanieSzarza > 0) {
			if (((polozeniePrzeciwnika.pozycjaX + (cos(katPoruszania * 3.141592 / 180) * predkoscSzarzy * elapsed.asMilliseconds())) < wymiarXPlanszyMax) && ((polozeniePrzeciwnika.pozycjaX + (cos(katPoruszania * 3.141592 / 180) * predkoscSzarzy * elapsed.asMilliseconds())) > wymiarXPlanszyMin)) {
				polozeniePrzeciwnika.pozycjaX += (cos(katPoruszania * 3.141592 / 180) * predkoscSzarzy * elapsed.asMilliseconds());
			}
			else {
				katPoruszania += 2 * (90 - katPoruszania);
			}
			if (((polozeniePrzeciwnika.pozycjaY - (sin(katPoruszania * 3.141592 / 180) * predkoscSzarzy * elapsed.asMilliseconds())) < wymiarYPlanszyMax) && ((polozeniePrzeciwnika.pozycjaY - (sin(katPoruszania * 3.141592 / 180) * predkoscSzarzy * elapsed.asMilliseconds())) > wymiarYPlanszyMin)) {
				polozeniePrzeciwnika.pozycjaY -= (sin(katPoruszania * 3.141592 / 180) * predkoscSzarzy * elapsed.asMilliseconds());
			}
			else {
				katPoruszania += 2 * (180 - katPoruszania);
			}
		}
		else {
			odliczaniePomiedzySzarzami = czasPomiedzySzarzami + 3 * ((double(rand()) / double((RAND_MAX))));
			odliczanieSzarza = czasSzarzy + ((double(rand()) / double((RAND_MAX))));
			namierzenie = false;
		}
	}
}