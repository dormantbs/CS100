#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <memory>
#include <algorithm>
#include "customset.h"

#ifndef H_tickets
#define H_tickets
#define LOTTO6 6
#define LOTTO7 7

using namespace std;

class LotteryTicket
{
public:
	LotteryTicket(const CustomSet<int>& numbers, int round);

	int getRound() const;
	int getCost() const;
	virtual int getTicketType() = 0;
	void setCost(const int& cost);
	virtual int claimPrize(const CustomSet<int>& prizeNumbers, int round) = 0;
	void setClaimed();
	bool isClaimed() const;

private:
	int m_round; // The valid round of a ticket. An outdated ticket is invalid.
	int m_cost; // The amount of money spent on this ticket.
	bool claimed;

protected:
	CustomSet<int> m_numbers;
};


class Lotto7Ticket :
	public LotteryTicket {
public:
	Lotto7Ticket(const CustomSet<int>& numbers, int round);
	int getTicketType();
	int claimPrize(const CustomSet<int>& prizeNumbers, int round);
};


class Lotto6Ticket :
	public LotteryTicket {
public:
	Lotto6Ticket(const CustomSet<int>& numbers, int round);
	int getTicketType();
	int claimPrize(const CustomSet<int>& prizeNumbers, int round);
};

#endif // !H_tickets


