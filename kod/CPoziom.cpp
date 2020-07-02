#include "CPoziom.h"

const int CPoziom::liczbaPrzedmiotow = 12;

CPoziom::CPoziom() {
	liczbaPokoi = 6;
	rodzajPrzedmiotu = 0;
}

void CPoziom::wczytajPoziom() {
	srand(time(NULL));

	for (int a = 0; a < 15; ++a) {
		for (int b = 0; b < 15; ++b) {
			poziom[a][b].liczbaNiePrzeciwnikow = 0;
			for (auto a : poziom[a][b].przeciwnicy) {
				delete a;
			}
			poziom[a][b].przeciwnicy.clear();
			poziom[a][b].otoczenie.clear();
		}
	}

	std::ifstream plik("img\\Pokoje.txt");
	std::string linia;
	std::vector<std::string> liniaPokoje;
	while (std::getline(plik, linia)) {
		liniaPokoje.push_back(linia);
	}
	plik.close();
	std::ifstream plikBoss("img\\PokojeBoss.txt");
	std::vector<std::string> liniaPokojeBoss;
	while (std::getline(plikBoss, linia)) {
		liniaPokojeBoss.push_back(linia);
	}
	plikBoss.close();

	for (int a = 0; a < 15; ++a) {
		for (int b = 0; b < 15; ++b) {
			if (!(a == 7 && b == 7)) {
				if (poziom[a][b].obecnosc == true) {
					if (poziom[a][b].boss != true && poziom[a][b].treasure != true) {
						int Wylosowany = rand() % (liniaPokoje.size());
						for (int i = 0; i < 91; ++i) {
							if (liniaPokoje[Wylosowany][i] != '0') {
								if (liniaPokoje[Wylosowany][i] < 'l') {
									poziom[a][b].otoczenie.push_back(CelementOtoczenia(liniaPokoje[Wylosowany][i], ((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
								}
								else {
									if (liniaPokoje[Wylosowany][i] == 'z') {
										poziom[a][b].przeciwnicy.push_back(new CFly(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
									}
									else if (liniaPokoje[Wylosowany][i] == 'y') {
										poziom[a][b].przeciwnicy.push_back(new COgien(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
										++poziom[a][b].liczbaNiePrzeciwnikow;
									}
									else if (liniaPokoje[Wylosowany][i] == 'x') {
										poziom[a][b].przeciwnicy.push_back(new CHeadless(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
									}
									else if (liniaPokoje[Wylosowany][i] == 'w') {
										poziom[a][b].przeciwnicy.push_back(new CFlyShooting(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
									}
									else if (liniaPokoje[Wylosowany][i] == 'v') {
										poziom[a][b].przeciwnicy.push_back(new CTurret(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
									}
								}
							}
						}
					}
					else if (poziom[a][b].boss == true) {
						int Wylosowany = rand() % (liniaPokojeBoss.size());
						for (int i = 0; i < 91; ++i) {
							if (liniaPokojeBoss[Wylosowany][i] != '0') {
								if (liniaPokojeBoss[Wylosowany][i] < 'l') {
									poziom[a][b].otoczenie.push_back(CelementOtoczenia(liniaPokojeBoss[Wylosowany][i], ((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
								}
								else {
									if (liniaPokojeBoss[Wylosowany][i] == 'u') {
										poziom[a][b].przeciwnicy.push_back(new CBossTwins(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
									}
									else if (liniaPokojeBoss[Wylosowany][i] == 't') {
										poziom[a][b].przeciwnicy.push_back(new CBossFlyMaster(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
									}
									else if (liniaPokojeBoss[Wylosowany][i] == 'z') {
										poziom[a][b].przeciwnicy.push_back(new CFly(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
									}
									else if (liniaPokojeBoss[Wylosowany][i] == 'y') {
										poziom[a][b].przeciwnicy.push_back(new COgien(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
										++poziom[a][b].liczbaNiePrzeciwnikow;
									}
									else if (liniaPokojeBoss[Wylosowany][i] == 'x') {
										poziom[a][b].przeciwnicy.push_back(new CHeadless(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
									}
									else if (liniaPokojeBoss[Wylosowany][i] == 'w') {
										poziom[a][b].przeciwnicy.push_back(new CFlyShooting(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
									}
									else if (liniaPokojeBoss[Wylosowany][i] == 'v') {
										poziom[a][b].przeciwnicy.push_back(new CTurret(((i % 13) * 70 + wymiarXPlanszyMin), (floor(i / 13) * 70 + wymiarYPlanszyMin)));
									}
								}
							}
						}
					}
					else if (poziom[a][b].treasure == true) {
						rodzajPrzedmiotu = rand() % liczbaPrzedmiotow;
					}
				}
			}
		}
	}
}

void CPoziom::generujPoziom() {
	srand(time(NULL));
	std::vector <int> a, b;
	a.push_back(7);
	b.push_back(7);

	do {
		for (int i = 0; i < 15; ++i) {
			for (int j = 0; j < 15; ++j) {
				poziom[i][j].obecnosc = false;
				poziom[i][j].odkryty = false;
				poziom[i][j].boss = false;
				poziom[i][j].treasure = false;
			}
		}
		poziom[7][7].obecnosc = true;

		for (int i = 0; i < (liczbaPokoi - 1); ++i) {
			int tmpx = a[rand() % a.size()];
			int tmpy = b[rand() % b.size()];

			int tmpdzrwi = rand() % 4;
			switch (tmpdzrwi) {
			case 0:
				if (poziom[tmpx][tmpy].obecnosc == true && poziom[tmpx - 1][tmpy].obecnosc == false && (tmpx - 1) >= 0) {
					poziom[tmpx - 1][tmpy].obecnosc = true;
					a.push_back(tmpx - 1);
					b.push_back(tmpy);
				}
				else {
					--i;
				}
				break;
			case 1:
				if (poziom[tmpx][tmpy].obecnosc == true && poziom[tmpx][tmpy + 1].obecnosc == false && (tmpy + 1) <= 14) {
					poziom[tmpx][tmpy + 1].obecnosc = true;
					a.push_back(tmpx);
					b.push_back(tmpy + 1);
				}
				else {
					--i;
				}
				break;
			case 2:
				if (poziom[tmpx][tmpy].obecnosc == true && poziom[tmpx + 1][tmpy].obecnosc == false && (tmpx + 1) <= 14) {
					poziom[tmpx + 1][tmpy].obecnosc = true;
					a.push_back(tmpx + 1);
					b.push_back(tmpy);
				}
				else {
					--i;
				}
				break;
			case 3:
				if (poziom[tmpx][tmpy].obecnosc == true && poziom[tmpx][tmpy - 1].obecnosc == false && (tmpy - 1) >= 0) {
					poziom[tmpx][tmpy - 1].obecnosc = true;
					a.push_back(tmpx);
					b.push_back(tmpy - 1);
				}
				else {
					--i;
				}
				break;
			}
		}
	} while (sprawdzPoprawnoscGenerowania());

	poziom[7][7].odkryty = true;
}

bool CPoziom::sprawdzPoprawnoscGenerowania() {
	int liczba = 0;
	std::vector<int> pozx;
	std::vector<int> pozy;
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			int tmp = 0;
			if (poziom[j][i].obecnosc == true && poziom[j-1][i].obecnosc == true && (j > 0) && (i != 7 || j != 7)) {
				++tmp;
			}
			if (poziom[j][i].obecnosc == true && poziom[j+1][i].obecnosc == true && j < 15 && (i != 7 || j != 7)) {
				++tmp;
			}
			if (poziom[j][i].obecnosc == true && poziom[j][i-1].obecnosc == true && (i > 0) && (i != 7 || j != 7)) {
				++tmp;
			}
			if (poziom[j][i].obecnosc == true && poziom[j][i+1].obecnosc == true && i < 15 && (i != 7 || j != 7)) {
				++tmp;
			}
			if (tmp == 1) {
				pozx.push_back(j);
				pozy.push_back(i);
			}
		}
	}

	if (pozx.size() >= 2) {
		int tmp = rand() % pozx.size();
		poziom[pozx[tmp]][pozy[tmp]].boss = true;
		pozx.erase(pozx.begin() + tmp);
		pozy.erase(pozy.begin() + tmp);
		tmp = rand() % pozx.size();
		poziom[pozx[tmp]][pozy[tmp]].treasure = true;
		return false;
	}
	else {
		return true;
	}
}