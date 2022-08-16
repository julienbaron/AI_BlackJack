#include <string>
#include "Card.h"

using namespace std; 

Card::Card(std::string acode) {
	Card::setCode(acode);
	Card::setSprite(acode + ".bmp");
	Card::EvaluteScoreCard(acode);
}

void Card::Movecard()
{
	int bufferPx = Card::getPx() + 30 * Card::getNumberOfCard();
	Card::setPx(bufferPx);
}

void Card::EvaluteScoreCard(string codeCard) {
	codeCard = Card::getCode().substr(1);
	//TODO: create switch condition with enum and add as 
	if (codeCard == "2") { Card::setCardScore(2);}
	else if (codeCard == "3") { Card::setCardScore(3);}
	else if (codeCard == "4") { Card::setCardScore(4); }
	else if (codeCard == "5") { Card::setCardScore(5); }
	else if (codeCard == "6") { Card::setCardScore(6); }
	else if (codeCard == "7") { Card::setCardScore(7); }
	else if (codeCard == "8") { Card::setCardScore(8); }
	else if (codeCard == "9") { Card::setCardScore(9); }
	else if (codeCard == "10" || codeCard =="V" || codeCard == "Q" || codeCard == "K") { Card::setCardScore(10); }
}