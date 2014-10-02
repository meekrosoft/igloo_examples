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
	string add_s = ""; // what to add?

	for (int index = 0; // start from the front
		 size > 0;
		 add_s.clear(), size--, index++)
	{
		if (i_array[index] %3 == 0)
			add_s =  "Fizz";
		if (i_array[index] %5 == 0)
			add_s = add_s + "Buzz";
		if (i_array[index] %7 == 0)
			add_s = add_s + "Mix";

		if (add_s.empty())
			out = out + i_array[index];
		else
			out = out + add_s;
		out = out + ", "; // delimiter required
	}
	// return without the last redundant delimiter
	out = out.substr(0, out.length()-2);
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
			int array3[10] = {1, 2, 8, 13};
			Assert::That(fizzBuzz(array3, 4), Equals("1, 2, 8, 13"));
			int array4[10] = {1, 2, 8, 13, 223, 13343};
			Assert::That(fizzBuzz(array4, 6), Equals("1, 2, 8, 13, 223, 13343"));
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
		int array3[10] = {1, 2, 8, 37};
		Assert::That(fizzBuzz(array3, 4), Equals("1, 2, 8, 37"));
		int array4[10] = {1, 2, 8, 13, 30, 222, 223, 13340, 13343};
		Assert::That(fizzBuzz(array4, 9), Equals("1, 2, 8, 13, FizzBuzz, Fizz, 223, Buzz, 13343"));
	}

	Spec(ShouldOutputMixForMultipleOf7)
	{
		int array[4] = {3, 5, 7, 2};
		Assert::That(fizzBuzz(array, 4), Equals("Fizz, Buzz, Mix, 2"));
		int array1[4] = {105};
				Assert::That(fizzBuzz(array1, 1), Equals("FizzBuzzMix"));
	}
};

string operator + (string& in, int number) {
	//string num_str = convert_number_to_str(number);
	char buf[5];
	string num_str(itoa(number, buf, 10));
	in = in + num_str;
	return in;
}

string convert_number_to_str(int n)
{
	ostringstream conv;
	conv.clear();
	conv << n;
	cout << "out string: " << conv.str() << endl;
	return conv.str();
}

/* deprecated version which is horrible, but
 * here FWIW
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
