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
	int index = 0;

	while (size > 0) {
		if (size >= 1 && i_array[index] == 15)
			out = out + "FizzBuzz";
		if (size >= 1 && i_array[index] == 3)
			out = out + "Fizz";
		if (size >= 1 && i_array[index] == 5)
			out = out + "Buzz";
		size--; index++;
		if (size != 0)
			out = out + ", ";
	}
	return out;
}

Context(AFizzBuzzConverter)
{
	Spec(ShouldOutputFizzFor3)
	{
		int array[10] = {3};
		Assert::That(fizzBuzz(array, 1), Equals("Fizz"));
	}

	Spec(ShouldOutputBuzzFor5)
	{
		int array[10] = {5};
		Assert::That(fizzBuzz(array, 1), Equals("Buzz"));
	}

	Spec(ShouldOutputFizzBuzzFor15)
		{
			int array[10] = {15};
			Assert::That(fizzBuzz(array, 1), Equals("FizzBuzz"));
		}

	Spec(ShouldOutputFizz_BuzzFor3And5)
	{
		int array[10] = {3, 5};
		Assert::That(fizzBuzz(array, 2), Equals("Fizz, Buzz"));
		int array2[10] = {5, 3};
		Assert::That(fizzBuzz(array2, 2), Equals("Buzz, Fizz"));
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




