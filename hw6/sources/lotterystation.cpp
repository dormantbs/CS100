#include "lotterystation.h"
#include<random>
#include<ctime>

LotteryStation::LotteryStation() {
	m_round = 0;
	for (int i = 1; i < 44; ++i) {
		if (i < 31) ck_lt7 += i;
		ck_lt6 += i;
	}
}

LotteryTicket* LotteryStation::buy(CustomSet<int> numbers, int tickettype) {
	LotteryTicket* new_ticket;
	if (tickettype == LOTTO7) {

		if (numbers.size() < 7 ||
			ck_lt7.intersection(numbers).size() != numbers.size()) {
			puts("Failed");
			return nullptr;
		}
		new_ticket = new Lotto7Ticket(numbers, m_round);
	}
	else {
		if (numbers.size() < 6 ||
			ck_lt6.intersection(numbers).size() != numbers.size()) {
			puts("Failed");
			return nullptr;
		}
		new_ticket = new Lotto6Ticket(numbers, m_round);
	}
	printf("Bought a %d ticket for %d Yuan at round %d.\n", tickettype, new_ticket->getCost(), m_round);
	return new_ticket;
}

void LotteryStation::claimPrize(LotteryTicket* ticket) {
	int type = ticket->getTicketType(), res;
	if (type == LOTTO7) {
		res = ticket->claimPrize(m_number7, m_round);
		if (res != -1) {
			printf("This ticket wins %d Yuan.\n", res);
		}
	}
	else {
		res = ticket->claimPrize(m_number6, m_round);
		if (res != -1) {
			printf("This ticket wins %d Yuan.\n", res);
		}
	}
}

bool LotteryStation::setPrizeNumbers(CustomSet<int> numbers, int tickettype) {
	if (tickettype == LOTTO7) {
		if (numbers.size() != 7 ||
			ck_lt7.intersection(numbers).size() != numbers.size())
			return false;
		m_number7 = numbers;
	}
	else {
		if (numbers.size() != 6 ||
			ck_lt6.intersection(numbers).size() != numbers.size())
			return false;
		m_number6 = numbers;
	}

	return true;
}

void LotteryStation::newRound() {
	m_round++;
	while (m_number7.size() < LOTTO7) {
		m_number7 += randInt(1, 30);
	}
	while (m_number6.size() < LOTTO6) {
		m_number6 += randInt(1, 43);
	}
}