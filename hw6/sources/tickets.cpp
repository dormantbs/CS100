#include "tickets.h"

inline int get_money(int num, int tickettype) {
	if (tickettype == LOTTO6) ++num;

	switch (num) {
		case 7: return 2000000; break;
		case 6: return 4500; break;
		case 5: return  75; break;
		case 4: return 5; break;
		default: return 0; break;
	}
}

inline int C(int n, int m) {
	int up = 1, down = 1;
	for (int i = 1; i <= m; ++i) {
		up = up * (n - i + 1);
		down = down * i;
	}
	return up / down;
}

LotteryTicket::LotteryTicket(const CustomSet<int>& numbers, int round) {
	m_numbers += numbers;
	m_round = round;
	m_cost = -1;
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
	int siz = numbers.size();
	this->setCost(C(siz, LOTTO7) << 1);
}

int Lotto7Ticket::getTicketType() {
	return LOTTO7;
}

int Lotto7Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round) {
	CustomSet<int> res = m_numbers.intersection(prizeNumbers);
	int num = res.size(), ret = m_numbers.size() - num;
	if (round != this->getRound() || this->isClaimed()) return -1;

	this->setClaimed();
	int ans = 0;
	for (int i = num, j = LOTTO7 - num; i >= 4 && j <= ret; --i, ++j) {
		ans = ans + C(num, i) * C(ret, j) * get_money(i, LOTTO7);
	}

	return ans;
}

Lotto6Ticket::
Lotto6Ticket(const CustomSet<int>& numbers, int round) :
	LotteryTicket(numbers, round) {
	int siz = numbers.size();
	this->setCost(C(siz, LOTTO6) << 1);
}

int Lotto6Ticket::getTicketType() {
	return LOTTO6;
}

int Lotto6Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round) {
	CustomSet<int> res = m_numbers.intersection(prizeNumbers);
	int num = res.size(), ret = m_numbers.size() - num;
	if (round != this->getRound() || this->isClaimed()) return -1;

	this->setClaimed();
	int ans = 0;
	for (int i = num, j = LOTTO6 - num; i >= 3 && j <= ret; --i, ++j) {
		ans = ans + C(num, i) * C(ret, j) * get_money(i, LOTTO6);
	}

	return ans;
}