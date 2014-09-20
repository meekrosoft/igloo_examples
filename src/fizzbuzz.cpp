/*
 * fizzbuzz.cpp
 *
 *  Created on: Sep 20, 2014
 *      Author: lifebalance
 */

#include <igloo/igloo.h>
using namespace igloo;

#include <iostream>
using namespace std;

string fizzBuzz (string input) {
	return "";
}

Context(AFizzBuzzConverter)
{
	Spec(ShouldOutputFizzFor3)
	{
		Assert::That(fizzBuzz("3"), Equals("Fizz"));
	}

	/*Spec(ShouldInstructThatARegularLeapYearIsALeapYear)
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
	}  */
};




