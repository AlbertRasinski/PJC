#include "CRysowanieOkienka.h"

CRysowanieOkienka::CRysowanieOkienka() {
	tsmenu0.texture_.loadFromFile("img/menu0.png");
	tsmenu0.sprite_ = sf::Sprite(tsmenu0.texture_);
	tsmenu1.texture_.loadFromFile("img/menu1.png");
	tsmenu1.sprite_ = sf::Sprite(tsmenu1.texture_);
	tsmenu4.texture_.loadFromFile("img/menu4.png");
	tsmenu4.sprite_ = sf::Sprite(tsmenu4.texture_);
	tswybor.texture_.loadFromFile("img/wybor.png");
	tswybor.sprite_ = sf::Sprite(tswybor.texture_);
	tswybor.sprite_.setOrigin(sf::Vector2f(tswybor.sprite_.getTexture()->getSize().x * 0.5, tswybor.sprite_.getTexture()->getSize().y * 0.5));

	tsPostac[0].texture_.loadFromFile("img/front.png");
	tsPostac[0].sprite_ = sf::Sprite(tsPostac[0].texture_);
	tsPostac[0].sprite_.setOrigin(sf::Vector2f(tsPostac[0].sprite_.getTexture()->getSize().x * 0.5, tsPostac[0].sprite_.getTexture()->getSize().y * 0.5));
	tsPostac[1].texture_.loadFromFile("img/back.png");
	tsPostac[1].sprite_ = sf::Sprite(tsPostac[1].texture_);
	tsPostac[1].sprite_.setOrigin(sf::Vector2f(tsPostac[1].sprite_.getTexture()->getSize().x * 0.5, tsPostac[1].sprite_.getTexture()->getSize().y * 0.5));
	tsPostac[2].texture_.loadFromFile("img/right.png");
	tsPostac[2].sprite_ = sf::Sprite(tsPostac[2].texture_);
	tsPostac[2].sprite_.setOrigin(sf::Vector2f(tsPostac[2].sprite_.getTexture()->getSize().x * 0.5, tsPostac[2].sprite_.getTexture()->getSize().y * 0.5));
	tsPostac[3].texture_.loadFromFile("img/left.png");
	tsPostac[3].sprite_ = sf::Sprite(tsPostac[3].texture_);
	tsPostac[3].sprite_.setOrigin(sf::Vector2f(tsPostac[3].sprite_.getTexture()->getSize().x * 0.5, tsPostac[3].sprite_.getTexture()->getSize().y * 0.5));

	tsSerceCale.texture_.loadFromFile("img/zycie_cale.png");
	tsSerceCale.sprite_ = sf::Sprite(tsSerceCale.texture_);
	tsSerceCale.sprite_.setOrigin(sf::Vector2f(tsSerceCale.sprite_.getTexture()->getSize().x * 0.5, tsSerceCale.sprite_.getTexture()->getSize().y * 0.5));

	tsSercePol.texture_.loadFromFile("img/zycie_pol.png");
	tsSercePol.sprite_ = sf::Sprite(tsSercePol.texture_);
	tsSercePol.sprite_.setOrigin(sf::Vector2f(tsSercePol.sprite_.getTexture()->getSize().x * 0.5, tsSercePol.sprite_.getTexture()->getSize().y * 0.5));

	tsSercePuste.texture_.loadFromFile("img/zycie_puste.png");
	tsSercePuste.sprite_ = sf::Sprite(tsSercePuste.texture_);
	tsSercePuste.sprite_.setOrigin(sf::Vector2f(tsSercePuste.sprite_.getTexture()->getSize().x * 0.5, tsSercePuste.sprite_.getTexture()->getSize().y * 0.5));

	tsBasement.texture_.loadFromFile("img/basement.png");
	tsBasement.sprite_ = sf::Sprite(tsBasement.texture_);

	tsLezka.texture_.loadFromFile("img/lezka.png");
	tsLezka.sprite_ = sf::Sprite(tsLezka.texture_);
	tsLezka.sprite_.setOrigin(sf::Vector2f(tsLezka.sprite_.getTexture()->getSize().x * 0.5, tsLezka.sprite_.getTexture()->getSize().y * 0.5));

	tsTrapdoor.texture_.loadFromFile("img/trapdoor.png");
	tsTrapdoor.sprite_ = sf::Sprite(tsTrapdoor.texture_);
	tsTrapdoor.sprite_.setPosition(597, 178);

	tsKamien1.texture_.loadFromFile("img/kamien1.png");
	tsKamien1.sprite_ = sf::Sprite(tsKamien1.texture_);
	tsKamien1.sprite_.setOrigin(sf::Vector2f(tsKamien1.sprite_.getTexture()->getSize().x * 0.5, tsKamien1.sprite_.getTexture()->getSize().y * 0.5));

	tsKamien2.texture_.loadFromFile("img/kamien2.png");
	tsKamien2.sprite_ = sf::Sprite(tsKamien2.texture_);
	tsKamien2.sprite_.setOrigin(sf::Vector2f(tsKamien2.sprite_.getTexture()->getSize().x * 0.5, tsKamien2.sprite_.getTexture()->getSize().y * 0.5));

	tsCzaszka.texture_.loadFromFile("img/czaszka.png");
	tsCzaszka.sprite_ = sf::Sprite(tsCzaszka.texture_);
	tsCzaszka.sprite_.setOrigin(sf::Vector2f(tsCzaszka.sprite_.getTexture()->getSize().x * 0.5, tsCzaszka.sprite_.getTexture()->getSize().y * 0.5));

	tsStal.texture_.loadFromFile("img/stal.png");
	tsStal.sprite_ = sf::Sprite(tsStal.texture_);
	tsStal.sprite_.setOrigin(sf::Vector2f(tsStal.sprite_.getTexture()->getSize().x * 0.5, tsStal.sprite_.getTexture()->getSize().y * 0.5));

	tsFly.texture_.loadFromFile("img/fly.png");
	tsFly.sprite_ = sf::Sprite(tsFly.texture_);
	tsFly.sprite_.setOrigin(sf::Vector2f(tsFly.sprite_.getTexture()->getSize().x * 0.5, tsFly.sprite_.getTexture()->getSize().y * 0.5));

	tsFlyShooting.texture_.loadFromFile("img/flyshooting.png");
	tsFlyShooting.sprite_ = sf::Sprite(tsFlyShooting.texture_);
	tsFlyShooting.sprite_.setOrigin(sf::Vector2f(tsFlyShooting.sprite_.getTexture()->getSize().x * 0.5, tsFlyShooting.sprite_.getTexture()->getSize().y * 0.5));

	tsHeadless.texture_.loadFromFile("img/headless.png");
	tsHeadless.sprite_ = sf::Sprite(tsHeadless.texture_);
	tsHeadless.sprite_.setOrigin(sf::Vector2f(tsHeadless.sprite_.getTexture()->getSize().x * 0.5, tsHeadless.sprite_.getTexture()->getSize().y * 0.5));

	tsOgien.texture_.loadFromFile("img/Fire.png");
	tsOgien.sprite_ = sf::Sprite(tsOgien.texture_);
	tsOgien.sprite_.setOrigin(sf::Vector2f(tsFly.sprite_.getTexture()->getSize().x * 0.65, 70));

	tsTurret.texture_.loadFromFile("img/turret.png");
	tsTurret.sprite_ = sf::Sprite(tsTurret.texture_);
	tsTurret.sprite_.setOrigin(sf::Vector2f(tsTurret.sprite_.getTexture()->getSize().x * 0.5, tsTurret.sprite_.getTexture()->getSize().y * 0.5));

	tsBossTwins.texture_.loadFromFile("img/BossTwins.png");
	tsBossTwins.sprite_ = sf::Sprite(tsBossTwins.texture_);
	tsBossTwins.sprite_.setOrigin(sf::Vector2f(tsBossTwins.sprite_.getTexture()->getSize().x * 0.5, tsBossTwins.sprite_.getTexture()->getSize().y * 0.5));

	tsBossFlyMaster.texture_.loadFromFile("img/BossFlyMaster.png");
	tsBossFlyMaster.sprite_ = sf::Sprite(tsBossFlyMaster.texture_);
	tsBossFlyMaster.sprite_.setOrigin(sf::Vector2f(tsBossFlyMaster.sprite_.getTexture()->getSize().x * 0.5, tsBossFlyMaster.sprite_.getTexture()->getSize().y * 0.5));

	tsPociskiPrzecwnik.texture_.loadFromFile("img/pociskiprzeciwnik.png");
	tsPociskiPrzecwnik.sprite_ = sf::Sprite(tsPociskiPrzecwnik.texture_);
	tsPociskiPrzecwnik.sprite_.setOrigin(sf::Vector2f(tsPociskiPrzecwnik.sprite_.getTexture()->getSize().x * 0.5, tsPociskiPrzecwnik.sprite_.getTexture()->getSize().y * 0.5));

	tsDrzwi[0].texture_.loadFromFile("img/doorLeFT.png");
	tsDrzwi[0].sprite_ = sf::Sprite(tsDrzwi[0].texture_);
	tsDrzwi[1].texture_.loadFromFile("img/doorUP.png");
	tsDrzwi[1].sprite_ = sf::Sprite(tsDrzwi[1].texture_);
	tsDrzwi[2].texture_.loadFromFile("img/doorRIGHT.png");
	tsDrzwi[2].sprite_ = sf::Sprite(tsDrzwi[2].texture_);
	tsDrzwi[3].texture_.loadFromFile("img/doorDOWN.png");
	tsDrzwi[3].sprite_ = sf::Sprite(tsDrzwi[3].texture_);

	tsDrzwizamkniete[0].texture_.loadFromFile("img/doorLeFTclosed.png");
	tsDrzwizamkniete[0].sprite_ = sf::Sprite(tsDrzwizamkniete[0].texture_);
	tsDrzwizamkniete[1].texture_.loadFromFile("img/doorUPclosed.png");
	tsDrzwizamkniete[1].sprite_ = sf::Sprite(tsDrzwizamkniete[1].texture_);
	tsDrzwizamkniete[2].texture_.loadFromFile("img/doorRIGHTclosed.png");
	tsDrzwizamkniete[2].sprite_ = sf::Sprite(tsDrzwizamkniete[2].texture_);
	tsDrzwizamkniete[3].texture_.loadFromFile("img/doorDOWNclosed.png");
	tsDrzwizamkniete[3].sprite_ = sf::Sprite(tsDrzwizamkniete[3].texture_);

	tsOdkryty.texture_.loadFromFile("img/odkryty.png");
	tsOdkryty.sprite_ = sf::Sprite(tsOdkryty.texture_);

	tsNieodkryty.texture_.loadFromFile("img/nieodkryty.png");
	tsNieodkryty.sprite_ = sf::Sprite(tsNieodkryty.texture_);

	tsBoss.texture_.loadFromFile("img/boss.png");
	tsBoss.sprite_ = sf::Sprite(tsBoss.texture_);

	tsTreasure.texture_.loadFromFile("img/treasure.png");
	tsTreasure.sprite_ = sf::Sprite(tsTreasure.texture_);

	tsPodest.texture_.loadFromFile("img/podest.png");
	tsPodest.sprite_ = sf::Sprite(tsPodest.texture_);
	tsPodest.sprite_.setPosition(602, 328);

	tsPrzedmiot1.texture_.loadFromFile("img/przedmiot1.png");
	tsPrzedmiot1.sprite_ = sf::Sprite(tsPrzedmiot1.texture_);
	tsPrzedmiot1.sprite_.setPosition(605, 280);

	tsPrzedmiot2.texture_.loadFromFile("img/przedmiot2.png");
	tsPrzedmiot2.sprite_ = sf::Sprite(tsPrzedmiot2.texture_);
	tsPrzedmiot2.sprite_.setPosition(605, 280);

	tsPrzedmiot3.texture_.loadFromFile("img/przedmiot3.png");
	tsPrzedmiot3.sprite_ = sf::Sprite(tsPrzedmiot3.texture_);
	tsPrzedmiot3.sprite_.setPosition(605, 280);

	tsPrzedmiot4.texture_.loadFromFile("img/przedmiot4.png");
	tsPrzedmiot4.sprite_ = sf::Sprite(tsPrzedmiot4.texture_);
	tsPrzedmiot4.sprite_.setPosition(605, 280);

	tsPrzedmiot5.texture_.loadFromFile("img/przedmiot5.png");
	tsPrzedmiot5.sprite_ = sf::Sprite(tsPrzedmiot5.texture_);
	tsPrzedmiot5.sprite_.setPosition(605, 280);

	tsPrzedmiot6.texture_.loadFromFile("img/przedmiot6.png");
	tsPrzedmiot6.sprite_ = sf::Sprite(tsPrzedmiot6.texture_);
	tsPrzedmiot6.sprite_.setPosition(605, 280);

	tsPrzedmiot7.texture_.loadFromFile("img/przedmiot7.png");
	tsPrzedmiot7.sprite_ = sf::Sprite(tsPrzedmiot7.texture_);
	tsPrzedmiot7.sprite_.setPosition(605, 280);

	tsPrzedmiot8.texture_.loadFromFile("img/przedmiot8.png");
	tsPrzedmiot8.sprite_ = sf::Sprite(tsPrzedmiot8.texture_);
	tsPrzedmiot8.sprite_.setPosition(605, 280);

	tsPrzedmiot9.texture_.loadFromFile("img/przedmiot9.png");
	tsPrzedmiot9.sprite_ = sf::Sprite(tsPrzedmiot9.texture_);
	tsPrzedmiot9.sprite_.setPosition(605, 280);

	tsPrzedmiot10.texture_.loadFromFile("img/przedmiot10.png");
	tsPrzedmiot10.sprite_ = sf::Sprite(tsPrzedmiot10.texture_);
	tsPrzedmiot10.sprite_.setPosition(605, 280);

	tsPrzedmiot11.texture_.loadFromFile("img/przedmiot11.png");
	tsPrzedmiot11.sprite_ = sf::Sprite(tsPrzedmiot11.texture_);
	tsPrzedmiot11.sprite_.setPosition(605, 280);

	tsPokojeTlo.texture_.loadFromFile("img/pokojeTlo.png");
	tsPokojeTlo.sprite_ = sf::Sprite(tsPokojeTlo.texture_);
	tsPokojeTlo.sprite_.setPosition(1145, 15);

	tsObecny.texture_.loadFromFile("img/obecny.png");
	tsObecny.sprite_ = sf::Sprite(tsObecny.texture_);
	tsObecny.sprite_.setPosition(1191, 57);
}


void CRysowanieOkienka::rysuj() {

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Rasinski Albert PJC", sf::Style::Titlebar | sf::Style::Close);

	sf::Event event;
	window.setFramerateLimit(100);
	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		menu.poruszaniePoMenu();

		if (menu.tryb == 0) {
			window.draw(tsmenu0.sprite_);
		}
		else if (menu.tryb == 1) {
			window.draw(tsmenu1.sprite_);

			if (menu.wybor == 0) {
				tswybor.sprite_.setPosition(453, 182);
				window.draw(tswybor.sprite_);
			}
			else if (menu.wybor == 1) {
				tswybor.sprite_.setPosition(477, 350);
				window.draw(tswybor.sprite_);
			}
			else if (menu.wybor == 2) {
				tswybor.sprite_.setPosition(571, 504);
				window.draw(tswybor.sprite_);
			}
		}
		else if (menu.tryb == 2) {
			window.close();
		}
		else if (menu.tryb == 3) {
			window.draw(tsBasement.sprite_);

			int tmpSerce = 0;
			for (tmpSerce; tmpSerce < floor(menu.gra->postac.zyciePostaci.obecneZycie / 2); ++tmpSerce) {
				tsSerceCale.sprite_.setPosition(130 + tmpSerce * tsSerceCale.sprite_.getTexture()->getSize().x, 30);
				window.draw(tsSerceCale.sprite_);
			}
			if ((menu.gra->postac.zyciePostaci.obecneZycie - tmpSerce * 2) == 1) {
				tsSercePol.sprite_.setPosition(130 + tmpSerce * tsSercePol.sprite_.getTexture()->getSize().x, 30);
				window.draw(tsSercePol.sprite_);
				++tmpSerce;
			}
			for (tmpSerce; tmpSerce < (menu.gra->postac.zyciePostaci.maksymalneZycie / 2); ++tmpSerce) {
				tsSercePuste.sprite_.setPosition(130 + tmpSerce * tsSercePuste.sprite_.getTexture()->getSize().x, 30);
				window.draw(tsSercePuste.sprite_);
			}

			window.draw(tsPokojeTlo.sprite_);

			for (int i = -2; i < 3; ++i) {
				for (int j = 2; j > -3; --j) {
					if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX - j][menu.gra->postac.obecnePomieszczenieY - i].obecnosc) {
						if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX - j][menu.gra->postac.obecnePomieszczenieY - i].odkryty) {
							tsOdkryty.sprite_.setPosition(1191 - (j * 21), 57 - (i * 19));
							window.draw(tsOdkryty.sprite_);
						}
						else {
							tsNieodkryty.sprite_.setPosition(1191 - (j * 21), 57 - (i * 19));
							window.draw(tsNieodkryty.sprite_);
						}
						if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX - j][menu.gra->postac.obecnePomieszczenieY - i].boss) {
							tsBoss.sprite_.setPosition(1191 - (j * 21), 57 - (i * 19));
							window.draw(tsBoss.sprite_);
						}
						if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX - j][menu.gra->postac.obecnePomieszczenieY - i].treasure) {
							tsTreasure.sprite_.setPosition(1191 - (j * 21), 57 - (i * 19));
							window.draw(tsTreasure.sprite_);
						}
					}
				} 
			}
			window.draw(tsObecny.sprite_);
			

			if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX - 1][menu.gra->postac.obecnePomieszczenieY].obecnosc) {
				if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy.size() == menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow) {
					tsDrzwi[0].sprite_.setPosition(110, 300);
					window.draw(tsDrzwi[0].sprite_);
				}
				else {
					tsDrzwizamkniete[0].sprite_.setPosition(110, 300);
					window.draw(tsDrzwizamkniete[0].sprite_);
				}
			}
			if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX + 1][menu.gra->postac.obecnePomieszczenieY].obecnosc) {
				if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy.size() == menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow) {
					tsDrzwi[2].sprite_.setPosition(1085, 300);
					window.draw(tsDrzwi[2].sprite_);
				}
				else {
					tsDrzwizamkniete[2].sprite_.setPosition(1085, 300);
					window.draw(tsDrzwizamkniete[2].sprite_);
				}
			}
			if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY - 1].obecnosc) {
				if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy.size() == menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow) {
					tsDrzwi[1].sprite_.setPosition(575, 36);
					window.draw(tsDrzwi[1].sprite_);
				}
				else {
					tsDrzwizamkniete[1].sprite_.setPosition(575, 36);
					window.draw(tsDrzwizamkniete[1].sprite_);
				}
			}
			if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY + 1].obecnosc) {
				if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy.size() == menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow) {
					tsDrzwi[3].sprite_.setPosition(575, 600);
					window.draw(tsDrzwi[3].sprite_);
				}
				else {
					tsDrzwizamkniete[3].sprite_.setPosition(575, 600);
					window.draw(tsDrzwizamkniete[3].sprite_);
				}
			}


			for (int i = 0; i < menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie.size(); ++i) {
				if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].typOtoczenia == 'a') {
					tsKamien1.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaX, menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaY);
					window.draw(tsKamien1.sprite_);
				}
				else if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].typOtoczenia == 'b') {
					tsKamien2.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaX, menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaY);
					window.draw(tsKamien2.sprite_);
				}
				else if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].typOtoczenia == 'c') {
					tsCzaszka.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaX, menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaY);
					window.draw(tsCzaszka.sprite_);
				}
				else if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].typOtoczenia == 'd') {
					tsStal.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaX, menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].otoczenie[i].polozenieOtoczenia.pozycjaY);
					window.draw(tsStal.sprite_);
				}
			}

			if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].boss == true && menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy.size() == menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].liczbaNiePrzeciwnikow) {
				window.draw(tsTrapdoor.sprite_);
			}
			else if (menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].treasure == true) {
				window.draw(tsPodest.sprite_);
				switch (menu.gra->poziom.rodzajPrzedmiotu) {
				case 0:
				case 11:
					window.draw(tsPrzedmiot1.sprite_);
					break;
				case 1:
					window.draw(tsPrzedmiot2.sprite_);
					break;
				case 2:
				case 12:
					window.draw(tsPrzedmiot3.sprite_);
					break;
				case 3:
					window.draw(tsPrzedmiot4.sprite_);
					break;
				case 4:
					window.draw(tsPrzedmiot5.sprite_);
					break;
				case 5:
				case 13:
					window.draw(tsPrzedmiot6.sprite_);
					break;
				case 6:
					window.draw(tsPrzedmiot7.sprite_);
					break;
				case 7:
					window.draw(tsPrzedmiot8.sprite_);
					break;
				case 8:
					window.draw(tsPrzedmiot9.sprite_);
					break;
				case 9:
					window.draw(tsPrzedmiot10.sprite_);
					break;
				case 10:
					window.draw(tsPrzedmiot11.sprite_);
				}
			}

			for (int i = 0; i < menu.gra->lezki.size(); ++i) {
				tsLezka.sprite_.setPosition(menu.gra->lezki[i].obecnePolozeniePociskow.pozycjaX, menu.gra->lezki[i].obecnePolozeniePociskow.pozycjaY);
				window.draw(tsLezka.sprite_);
			}



			for (int i = 0; i < menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy.size(); ++i) {
				for (int j = 0; j < menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPociskiSize(); ++j) {
					tsPociskiPrzecwnik.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPociskPozycjaX(j), menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPociskPozycjaY(j));
					window.draw(tsPociskiPrzecwnik.sprite_);
				}

				if (dynamic_cast<CFly*>(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i])) {
					tsFly.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaX(), menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaY());
					window.draw(tsFly.sprite_);
				}
				else if (dynamic_cast<COgien*>(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i])) {
					tsOgien.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaX(), menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaY());
					window.draw(tsOgien.sprite_);
				}
				else if (dynamic_cast<CHeadless*>(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i])) {
					tsHeadless.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaX(), menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaY());
					window.draw(tsHeadless.sprite_);
				}
				else if (dynamic_cast<CFlyShooting*>(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i])) {
					tsFlyShooting.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaX(), menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaY());
					window.draw(tsFlyShooting.sprite_);
				}
				else if (dynamic_cast<CTurret*>(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i])) {
					tsTurret.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaX(), menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaY());
					window.draw(tsTurret.sprite_);
				}
				else if (dynamic_cast<CBossTwins*>(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i])) {
					tsBossTwins.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaX(), menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaY());
					window.draw(tsBossTwins.sprite_);
				}
				else if (dynamic_cast<CBossFlyMaster*>(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i])) {
					tsBossFlyMaster.sprite_.setPosition(menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaX(), menu.gra->poziom.poziom[menu.gra->postac.obecnePomieszczenieX][menu.gra->postac.obecnePomieszczenieY].przeciwnicy[i]->getPolozeniePrzeciwnikaY());
					window.draw(tsBossFlyMaster.sprite_);
				}
			}

			tsPostac[menu.gra->postac.wygladPostaci].sprite_.setPosition(menu.gra->postac.polozeniePostaci.pozycjaX, menu.gra->postac.polozeniePostaci.pozycjaY);
			window.draw(tsPostac[menu.gra->postac.wygladPostaci].sprite_);
		}
		else if (menu.tryb == 4) {
			window.draw(tsmenu4.sprite_);
		}
		window.display();
	}
}