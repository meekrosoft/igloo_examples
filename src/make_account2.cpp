/*
 * make_account2.cpp
 *
 *  Created on: Nov 2, 2014
 *      Author: lifebalance
 */

#include <igloo/igloo.h>
using namespace igloo;

Context(AAmountConverter)
{
	Spec(ShouldOutput0ForNegative1)
	{
		int d[1] = {1};
		Assert::That(make_amount(-1, d, 1), Equals(0));
	}
};


