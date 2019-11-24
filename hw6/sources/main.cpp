#include <algorithm>
#include <random>
#include <iostream>
#include "customset.h"
#include "lotterystation.h"
#include "tickets.h"
#include <cmath>

int main() {
	int a[6] = { 1,2,3,4,5,6 };
	CustomSet<int> foo(a, 6);
	LotteryStation sample;
	sample.newRound();
	sample.setPrizeNumbers(foo, LOTTO6); // LOTTO6 is predefined
	LotteryTicket* jackpot = sample.buy(foo, LOTTO6);
	// prints "Bought a Lotto 6 ticket for 2 Yuan at round 1.\n"
	sample.claimPrize(jackpot);
}

