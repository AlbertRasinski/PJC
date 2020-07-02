#include "CHeadless.h"

const double CHeadless::czasPomiedzySkokami = 1;
const double CHeadless::predkosc = 0.5;
const int CHeadless::zasieg = 400;

CHeadless::CHeadless(int x, int y) : CPrzeciwnik(x, y, 25, 25, 50, 50, 'x') {
	podczasSkoku = true;
	pozX = polozeniePrzeciwnika.pozycjaX;
	pozY = polozeniePrzeciwnika.pozycjaY;
	odliczanie = czasPomiedzySkokami + 2 * ((double(rand()) / double((RAND_MAX))));
}

void CHeadless::zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek) {
	odliczanie -= elapsed.asSeconds();
	if (odliczanie <= 0 && podczasSkoku == false) {
		do {
			pozX = polozeniePrzeciwnika.pozycjaX + (rand() % (zasieg * 2) - zasieg);
		} while (pozX>wymiarXPlanszyMax || pozX<wymiarXPlanszyMin);

		do {
			pozY = polozeniePrzeciwnika.pozycjaY + (rand() % (zasieg * 2) - zasieg);
		} while (pozY > wymiarYPlanszyMax || pozY < wymiarYPlanszyMin);
		podczasSkoku = true;
	}
	else if (podczasSkoku == true) {
		if (polozeniePrzeciwnika.pozycjaX < pozX) {
			polozeniePrzeciwnika.pozycjaY += (sin(atan((polozeniePrzeciwnika.pozycjaY - pozY) / (polozeniePrzeciwnika.pozycjaX - pozX))) * predkosc * elapsed.asMilliseconds());
			polozeniePrzeciwnika.pozycjaX += (cos(atan((polozeniePrzeciwnika.pozycjaY - pozY) / (polozeniePrzeciwnika.pozycjaX - pozX))) * predkosc * elapsed.asMilliseconds());
		}
		else if (polozeniePrzeciwnika.pozycjaX > pozX) {
			polozeniePrzeciwnika.pozycjaY -= (sin(atan((polozeniePrzeciwnika.pozycjaY - pozY) / (polozeniePrzeciwnika.pozycjaX - pozX))) * predkosc * elapsed.asMilliseconds());
			polozeniePrzeciwnika.pozycjaX -= (cos(atan((polozeniePrzeciwnika.pozycjaY - pozY) / (polozeniePrzeciwnika.pozycjaX - pozX))) * predkosc * elapsed.asMilliseconds());
		}
		else {
			polozeniePrzeciwnika.pozycjaY -= (sin(3.14 / 2) * predkosc * elapsed.asMilliseconds());
			polozeniePrzeciwnika.pozycjaX -= (cos(3.14 / 2) * predkosc * elapsed.asMilliseconds());
		}

		if (polozeniePrzeciwnika.pozycjaX > (pozX - 15) && polozeniePrzeciwnika.pozycjaX < (pozX + 15) && polozeniePrzeciwnika.pozycjaY >(pozY - 15) && polozeniePrzeciwnika.pozycjaY < (pozY + 15)) {
			odliczanie = czasPomiedzySkokami + ((double(rand()) / double((RAND_MAX))));
			podczasSkoku = false;
		}
	}
}