/*
 * make_amount2.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: lifebalance
 */

#include <igloo/igloo.h>
using namespace igloo;

#include <iostream>
using namespace std;

#include <sstream>


#include <vector>

ostream& operator << (ostream& os, vector<int>&  v)
{
	for (unsigned int i = 0; i < v.size() ; i++)
			os << v[i] << " ";
	return os;

}

int make_amount (int amount, vector<int>& denominations)
{
	// cout << "calling with amount = " << amount << " and  denom = " << make_str(denominations) << endl;
	int o_amount = amount;
	vector<int> od = denominations;

	if (amount == 0)
		return 1;
	if (amount < 0)
		return 0;
	if (denominations.size() == 0)
		return 0;

	// cout << "Checking ways to make " << amount << " with " << denominations << endl;
	// python code: current_coin, rest_of_coins = denominations[0], denominations[1:]
	int current_coin = denominations[0];
	vector<int> rest_of_coins (denominations.begin()+1, denominations.end());


	int count = 0;
	while (amount >= 0) {
		count += make_amount (amount, rest_of_coins);
		amount = amount - current_coin;
	}
	// cout << "***  Number of ways: " << count  << " for ";
	// cout << "returning with amount = " << o_amount << " and  denom = " << make_str(od) << endl;
	return count;
}

int make_amount (int amount, int denominations[], int dsize )
{
	vector<int> v_d(denominations, denominations + dsize);
	return make_amount (amount, v_d);
}


Context(AAmountConverter)
{
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



/*
 *

string make_str (vector<int>& v)
{
	ostringstream conv;
	conv.clear();

	for (unsigned int i = 0; i < v.size() ; i++)
		conv << v[i] << " ";

	return conv.str();

}

string make_str (int d[], int size)
{
	ostringstream conv;
	conv.clear();

	for (int i = 0; i < size; i++)
		conv << d[i] << " ";

	return conv.str();

}

int make_amount (int amount, int denominations[], int dsize )
{
	cout << "calling with amount = " << amount << " and  denom = " << make_str(denominations, dsize) << endl;
	int o_amount = amount;
	int o_dsize = dsize;

	vector<int> v_od (denominations, denominations + dsize);

	if (amount == 0)
		return 1;
	if (amount < 0)
		return 0;
	if (dsize == 0)
		return 0;

	cout << "Checking ways to make " << amount << " with " << make_str(denominations, dsize) << endl;
	int current_coin = denominations[0];

	int rest_of_coins[dsize-1];
	int rsize = dsize-1;
	for (int i = 1; i < dsize; i++)
		rest_of_coins[i-1] = denominations[i];
	vector<int> v_rest_of_coins (denominations+1, denominations+dsize);


	int count = 0;
	while (amount >= 0) {
		count += make_amount (amount, rest_of_coins, rsize);
		amount = amount - current_coin;
	}
	cout << "***  Number of ways: " << count  << " for ";
	cout << "returning with amount = " << o_amount << " and  denom = " << make_str(v_od) << endl;
	return count;
}
*/
