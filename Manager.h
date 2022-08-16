#pragma once
class Manager
{
private:
	int bank;
	int bet = 0 ;
	int refund;

public: 
	Manager();
	void start();

	int getBet() {
		return bet;
	}

	void setBank(int refund) {
		bank += refund;
	}

	void setBet(int aBet) {
		bet = aBet;
	}
};

