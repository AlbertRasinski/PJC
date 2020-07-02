#include "CFly.h"

const double CFly::PredkoscFly = 0.1;

CFly::CFly(int x, int y) : CPrzeciwnik(x, y, 15, 15, 50,45, 'z') {

}

void CFly::zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek) {
	if (polozeniePrzeciwnika.pozycjaX < graczX) {
		polozeniePrzeciwnika.pozycjaY += (sin(atan((polozeniePrzeciwnika.pozycjaY - graczY) / (polozeniePrzeciwnika.pozycjaX - graczX))) * PredkoscFly * elapsed.asMilliseconds());
		polozeniePrzeciwnika.pozycjaX += (cos(atan((polozeniePrzeciwnika.pozycjaY - graczY) / (polozeniePrzeciwnika.pozycjaX - graczX))) * PredkoscFly * elapsed.asMilliseconds());
	}
	else if (polozeniePrzeciwnika.pozycjaX > graczX) {
		polozeniePrzeciwnika.pozycjaY -= (sin(atan((polozeniePrzeciwnika.pozycjaY - graczY) / (polozeniePrzeciwnika.pozycjaX - graczX))) * PredkoscFly * elapsed.asMilliseconds());
		polozeniePrzeciwnika.pozycjaX -= (cos(atan((polozeniePrzeciwnika.pozycjaY - graczY) / (polozeniePrzeciwnika.pozycjaX - graczX))) * PredkoscFly * elapsed.asMilliseconds());
	}
	else {
		polozeniePrzeciwnika.pozycjaY -= (sin(3.14 / 2) * PredkoscFly * elapsed.asMilliseconds());
		polozeniePrzeciwnika.pozycjaX -= (cos(3.14 / 2) * PredkoscFly * elapsed.asMilliseconds());
	}
}