#include "tickets.h"

LotteryTicket::LotteryTicket(const CustomSet<int>& numbers, int round) {
	m_numbers += numbers;
	m_numbers.printSet();
	m_round = round;
	claimed = false;
}

int LotteryTicket::getRound() const{
	return m_round;
}

int LotteryTicket::getCost() const{
	return m_cost;
}

void LotteryTicket::setCost(const int& cost) {
	m_cost = cost;
}

void LotteryTicket::setClaimed() {
	claimed = true;
}

bool LotteryTicket::isClaimed() const{
	return claimed;
}


Lotto7Ticket::
Lotto7Ticket(const CustomSet<int>& numbers, int round) :
	LotteryTicket(numbers, round) {
	int down = 1, up = 1, siz = numbers.size();
	for (int i = 1; i <= LOTTO7; ++i) {
		up = up * (siz - i + 1);
		down = down * i;
	}

	this->setCost((up << 1) / down);
}

int Lotto7Ticket::getTicketType() {
	return LOTTO7;
}

int Lotto7Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round) {
	CustomSet<int> res = m_numbers.intersection(prizeNumbers);
	int num = res.size();
	if (round != this->getRound() || this->isClaimed()) return -1;

	this->setClaimed();
	switch (num) {
	case 7:
		return 2000000;
		break;
	case 6:
		return 4500;
		break;
	case 5:
		return  75;
		break;
	case 4:
		return 5;
		break;
	default:
		return 0;
		break;
	}
}

Lotto6Ticket::
Lotto6Ticket(const CustomSet<int>& numbers, int round) :
	LotteryTicket(numbers, round) {
	int down = 1, up = 1, siz = numbers.size();
	for (int i = 1; i <= LOTTO6; ++i) {
		up = up * (siz - i + 1);
		down = down * i;
	}

	this->setCost((up << 1) / down);
}

int Lotto6Ticket::getTicketType() {
	return LOTTO6;
}

int Lotto6Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round) {
	CustomSet<int> res = m_numbers.intersection(prizeNumbers);
	int num = res.size();
	if (round != this->getRound() || this->isClaimed()) return -1;

	this->setClaimed();
	switch (num) {
	case 6:
		return 2000000;
		break;
	case 5:
		return 4500;
		break;
	case 4:
		return  75;
		break;
	case 3:
		return 5;
		break;
	default:
		return 0;
		break;
	}
}