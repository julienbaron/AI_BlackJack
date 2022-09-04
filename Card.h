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
		bool isPlayer;

	public:
		Card(string code);

		~Card() {};

		void Movecard(int numberOfCard);

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

		void setNumberOfCard(int aNumberOfCard) {
			numberOfcard += aNumberOfCard;
			Movecard(numberOfcard);
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

		void setIsPlayer(bool aIsPlayer) {
			if (aIsPlayer) {pY = 300;}
			else { pY = 100; }
			isPlayer = true; 
		}
};

