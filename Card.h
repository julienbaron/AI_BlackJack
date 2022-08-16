#pragma once
#include <string>
using namespace std;

enum PropertiesSize: int { SIZEWIDTH = 70, SIZEHEIGHT = 90 };


class Card
{

	private:
		PropertiesSize properties;
		string code;
		string sprite;
		int cardScore;
		int pX = 200;
		int pY = 200;
		int numberOfcard = 1;

	public:
		Card(string code);

		void Movecard();

		void EvaluteScoreCard(string codeCard);

		PropertiesSize  getProperties() {
			return properties;
		}

		string getCode() {
			return code;
		}

		int getPx() {
			return pX;
		}

		int getPy() {
			return pY;
		}

		int getNumberOfCard() {
			return numberOfcard;
		}

		string getsprite() {
			return sprite;
		}

		int getScoreCard() {
			return cardScore;
		}

		int setNumberOfCard(int aNumberOfCard) {
			numberOfcard = aNumberOfCard;
		}

		void setCode(string acode) {
			code = acode;
		}

		void setPx(int apX) {
			pX = apX;
		}

		void setSprite(string aSprite) {
			sprite = aSprite;
		}

		void setCardScore(int aCardScore) {
			cardScore = aCardScore;
		}

};

