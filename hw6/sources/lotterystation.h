#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <memory>
#include <algorithm>

#include "customset.h"
#include "tickets.h"

#include<random>
#include<ctime>

#ifndef H_lotterystation
#define H_lotterystation

class LotteryStation
{
public:
	LotteryStation();

	LotteryTicket* buy(CustomSet<int> numbers, int tickettype);
	void claimPrize(LotteryTicket* ticket);
	void newRound();
	bool setPrizeNumbers(CustomSet<int> numbers, int tickettype);

private:
	int m_round; // Should be initialized to 0. 
	CustomSet<int> ck_lt7, ck_lt6, m_number7, m_number6;

	int randInt(int lower_bound, int upper_bound) {
		int res = rand() % (upper_bound - lower_bound + 1) + lower_bound;
		return res;
	}
};
#endif // !H_lotterystation

