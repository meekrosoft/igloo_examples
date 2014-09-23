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

#include <sstream>

// two helper functions
string convert_number_to_str (int);
string operator + (string& in, int number);

string fizzBuzz (int i_array[], int size) {
	string out = "";
	int index = 0;

	while (size > 0) {
		if (i_array[index]%15 == 0)
			out = out + "FizzBuzz";
		else if (i_array[index]%3 == 0)
			out = out + "Fizz";
		else if (i_array[index]%5 == 0)
			out = out + "Buzz";
		else
			// out = out + convert_number_to_str(i_array[index]);
			// out = out + (char)(i_array[index]);
			out = out + i_array[index];

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
		// int array[10] = {3};
		// maybe, this whole set of tests will look more elegant if
		// vectors are used?
		Assert::That(fizzBuzz((int[]){3}, 1), Equals("Fizz"));
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
			int array4[10] = {1, 2, 7, 13, 223, 13342};
			Assert::That(fizzBuzz(array4, 6), Equals("1, 2, 7, 13, 223, 13342"));
		}

	Spec(ShouldOutputFizzAndBuzzWhenMultipesOf_3or5or_Both)
	{
		int array[10] = {9};
		Assert::That(fizzBuzz(array, 1), Equals("Fizz"));
		int array2[10] = {9, 10};
		Assert::That(fizzBuzz(array2, 2), Equals("Fizz, Buzz"));
		int array3[10] = {3, 5, 15};
		Assert::That(fizzBuzz(array3, 3), Equals("Fizz, Buzz, FizzBuzz"));
		int array4[10] = {15, 30, 9};
		Assert::That(fizzBuzz(array4, 3), Equals("FizzBuzz, FizzBuzz, Fizz"));
	}

	Spec(ShouldOutputForAll_MixedNumbers)
	{
		int array[10] = {9};
		Assert::That(fizzBuzz(array, 1), Equals("Fizz"));
		int array2[10] = {9, 11};
		Assert::That(fizzBuzz(array2, 2), Equals("Fizz, 11"));
		int array3[10] = {1, 2, 7, 35};
		Assert::That(fizzBuzz(array3, 4), Equals("1, 2, 7, Buzz"));
		int array4[10] = {1, 2, 7, 13, 30, 222, 223, 13340, 13342};
		Assert::That(fizzBuzz(array4, 9), Equals("1, 2, 7, 13, FizzBuzz, Fizz, 223, Buzz, 13342"));
	}
};

string operator + (string& in, int number) {
		string num_str = convert_number_to_str(number);
		in = in + num_str;
		return in;
}

string convert_number_to_str(int n)
{
	ostringstream conv;
	conv.clear();
	conv << n;
	// cout << "out string: " << conv.str() << endl;
	return conv.str();

}

/* deprecated version which is horrible, but here FWIW
 *
 */
string convert_number_to_str2(int n)
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
