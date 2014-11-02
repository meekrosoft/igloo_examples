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

int make_amount(int amount, vector<int>& denominations)
{
	if (amount == 0)
  	  return 1;
    if (amount < 0)
	  return 0;
	if (denominations.size() == 0)
		return 0;

	int current_coin = denominations[0];
	vector<int> rest_of_coins (denominations.begin()+1, denominations.end());

	int count = 0;
	while (amount >= 0)
	{
		count += make_amount(amount, rest_of_coins);
		amount = amount - current_coin;
	}

	return count;
}

int make_amount(int amount, int denominations[], int size)
{
	vector<int> v_d(denominations, denominations+size);
	return make_amount(amount, v_d);

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
	Spec(ShouldOutput1For2And1)
		{
			int d[2] = {1};
			Assert::That(make_amount(2, d, 1), Equals(1));
		}

		Spec(ShouldOutput2For2And2)
		{
			int d[2] = {1,2};
			Assert::That(make_amount(2, d, 2), Equals(2));
			// {1,1} and {2}
		}

		Spec(ShouldOutput2For3And12)
		{
				int d[2] = {1,2};
				Assert::That(make_amount(3, d, 2), Equals(2));
				// {1,1,1} and {1,2}
		}
		Spec(ShouldOutput3For4And12)
		{
			int d[2] = {1,2};
			Assert::That(make_amount(4, d, 2), Equals(3));
			// {1,1,1,1} and {1, 1, 2} and {2, 2}
		}
		Spec(ShouldOutput4For4And123)
		{
			int d[3] = {1, 2, 3};
			Assert::That(make_amount(4, d, 3), Equals(4));
			// {1,1,1,1} and {1, 1, 2} and {2, 2} and {1, 3}
		}
		Spec(ShouldOutput8For7And123)
		{
			int d[3] = {1, 2, 3};
			Assert::That(make_amount(7, d, 3), Equals(8));
			// {1,1,1,1} and {1, 1, 2} and {2, 2} and {1, 3}
		}

};


