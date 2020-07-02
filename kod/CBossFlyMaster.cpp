#include "CBossFlyMaster.h"
#include "CFly.h"

const double CBossFlyMaster::czasPomiedzyTworzeniem = 2;
const double CBossFlyMaster::predkoscPoruszania = 0.1;
const double CBossFlyMaster::czasChodzenie = 1.5;

CBossFlyMaster::CBossFlyMaster(int x, int y) : CPrzeciwnik(x, y, 150, 150, 85, 85, 't') {
	katPoruszania = rand() % 360;
	odliczanieChodzenie = czasChodzenie + 0.5 * ((double(rand()) / double((RAND_MAX))));
	odliczaniePomiedzyTworzeniami = czasPomiedzyTworzeniem + 2 * ((double(rand()) / double((RAND_MAX))));
}

void CBossFlyMaster::zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek) {
	odliczaniePomiedzyTworzeniami -= elapsed.asSeconds();
	odliczanieChodzenie -= elapsed.asSeconds();

	if (odliczaniePomiedzyTworzeniami > 0) {
		if (odliczanieChodzenie < 0) {
			katPoruszania = rand() % 360;
			odliczanieChodzenie = czasChodzenie + 0.5 * ((double(rand()) / double((RAND_MAX))));
		}
		if (((polozeniePrzeciwnika.pozycjaX + (cos(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds())) < wymiarXPlanszyMax-90) && ((polozeniePrzeciwnika.pozycjaX + (cos(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds())) > wymiarXPlanszyMin+90)) {
			polozeniePrzeciwnika.pozycjaX += (cos(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds());
		}
		else {
			katPoruszania += 2 * (90 - katPoruszania);
		}
		if (((polozeniePrzeciwnika.pozycjaY - (sin(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds())) < wymiarYPlanszyMax-90) && ((polozeniePrzeciwnika.pozycjaY - (sin(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds())) > wymiarYPlanszyMin+90)) {
			polozeniePrzeciwnika.pozycjaY -= (sin(katPoruszania * 3.141592 / 180) * predkoscPoruszania * elapsed.asMilliseconds());
		}
		else {
			katPoruszania += 2 * (180 - katPoruszania);
		}
	}
	else {
		for (int i = 0; i < (1 + rand() % 3); ++i) {
			int tmp = rand() % 360;
			wek.push_back(new CFly(polozeniePrzeciwnika.pozycjaX + 85*cos(tmp * 3.141592 / 180), polozeniePrzeciwnika.pozycjaY  + 85*sin(tmp * 3.141592 / 180)));
		}
		odliczaniePomiedzyTworzeniami = czasPomiedzyTworzeniem + 1.5 * ((double(rand()) / double((RAND_MAX))));
	}
}