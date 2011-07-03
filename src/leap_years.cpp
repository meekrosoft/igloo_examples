/*
 * leap_years.cpp
 *
 *  Created on: Jul 2, 2011
 *      Author: mike
 */

#include <igloo/igloo.h>
using namespace igloo;


bool isLeapYear(int year)
{
	return  (year % 400 == 0) || ((year % 100) && !(year % 4));
}

Context(AStatelessLeapYearCalculator)
{
	Spec(ShouldInstructThatARegularYearIsNotALeapYear)
	{
		Assert::That(isLeapYear(2001), IsFalse());
		Assert::That(isLeapYear(2003), IsFalse());
	}

	Spec(ShouldInstructThatARegularLeapYearIsALeapYear)
	{
		Assert::That(isLeapYear(2004), IsTrue());
	}

	Spec(ShouldInstructThatYearDivisibleBy100andNot400IsNotALeapYear)
	{
		Assert::That(isLeapYear(1900), IsFalse());
	}

	Spec(ShouldInstructThatYearDivisibleBy400IsALeapYear)
	{
		Assert::That(isLeapYear(2000), IsTrue());
	}
};

