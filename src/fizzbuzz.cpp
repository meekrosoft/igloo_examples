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

string fizzBuzz (int i_array[], int size) {
	string out = "";

	if (size >= 1 && i_array[0] == 3)
		out = out + "Fizz";
	if (size >= 1 && i_array[0] == 5)
			out = out + "Buzz";


	return out;
}

Context(AFizzBuzzConverter)
{
	Spec(ShouldOutputFizzFor3)
	{
		int array[10] = {3};
		Assert::That(fizzBuzz(array, 10), Equals("Fizz"));
	}

	Spec(ShouldOutputBuzzFor5)
	{
		int array[10] = {5};
		Assert::That(fizzBuzz(array, 10), Equals("Buzz"));
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




