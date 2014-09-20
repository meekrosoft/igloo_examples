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

string convert_number_to_str(int n)
{
	// cout << "received: "  << n << endl;
	string conv = "";
	char c_digit = '\0';
	int digit;
	for (int i = 10; n > 0; i = i*10) {
		digit = n%i;
		// cout << "digit: " << digit << endl;
		c_digit = (char)(digit + '0');
		// cout << "c_digit: " << c_digit << endl;
		conv = c_digit + conv;
		n = n/10;
	}
	// cout << "*** Converted to: " << conv << endl;
	return conv;
}

string fizzBuzz (int i_array[], int size) {
	string out = "";
	int index = 0;

	while (size > 0) {
		if (size >= 1 && i_array[index] == 15)
			out = out + "FizzBuzz";
		else if (size >= 1 && i_array[index] == 3)
			out = out + "Fizz";
		else if (size >= 1 && i_array[index] == 5)
			out = out + "Buzz";
		else
			out = out + convert_number_to_str(i_array[index]);

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
	Spec(ShouldOutputSameAsNumber_WhenNot3or5or_NotAMultipleOfEither)
		{
			int array[10] = {1};
			Assert::That(fizzBuzz(array, 1), Equals("1"));
			int array2[10] = {1, 2};
			Assert::That(fizzBuzz(array2, 2), Equals("1, 2"));
			int array3[10] = {1, 2, 7, 13};
			Assert::That(fizzBuzz(array3, 4), Equals("1, 2, 7, 13"));
			int array4[10] = {1, 2, 7, 13, 222, 13340};
			Assert::That(fizzBuzz(array4, 6), Equals("1, 2, 7, 13, 222, 13340"));
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




