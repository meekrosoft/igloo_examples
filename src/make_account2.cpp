/*
 * make_account2.cpp
 *
 *  Created on: Nov 2, 2014
 *      Author: lifebalance
 */

#include <igloo/igloo.h>
using namespace igloo;

#include <iostream>
using namespace std;

#include <vector>

int make_amount(int amount, int denominations[], int dsize)
{
	if (amount == 0)
  	  return 1;
    if (amount < 0)
	  return 0;
	if (dsize == 0)
		return 0;

	int current_coin = denominations[0];
	int rest_of_coins[dsize-1];
	int rsize = dsize-1;
	for (int i = 1; i < dsize; i++)
		rest_of_coins[i-1] = denominations[i];

	int count = 0;
	while (amount >= 0)
	{
		count = make_amount(amount, rest_of_coins, rsize);
		amount = amount - current_coin;
	}

	return count;
}


Context(AAmountConverter)
{
	Spec(ShouldOutput1For0)
	{
	  int d[1] = {1};
	  Assert::That(make_amount(0, d, 1), Equals(1));
	}
	Spec(ShouldOutput0ForNegative1)
	{
	  int d[1] = {1};
	  Assert::That(make_amount(-1, d, 1), Equals(0));
	}

	Spec(ShouldOutput0For1AndNull)
	{
	  Assert::That(make_amount(1, {}, 0), Equals(0));
	}
	Spec(ShouldOutput1For1And1)
	{
	  int d[1] = {1};
	  Assert::That(make_amount(1, d, 1), Equals(1));
	}

};


