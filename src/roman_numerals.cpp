/*
 * roman_numerals.cpp
 *
 *  Created on: Jul 3, 2011
 *      Author: mike
 */
#include <igloo/igloo.h>
#include <map>
#include <iostream>

using namespace igloo;

std::string to_roman(int i)
{
	std::string s;

	std::map<int, std::string> conversion;
	conversion.insert(std::make_pair(1,"I"));
	conversion.insert(std::make_pair(4,"IV"));
	conversion.insert(std::make_pair(5,"V"));
	conversion.insert(std::make_pair(9,"IX"));
	conversion.insert(std::make_pair(10,"X"));
	conversion.insert(std::make_pair(40,"XL"));
	conversion.insert(std::make_pair(50,"L"));
	conversion.insert(std::make_pair(90,"XC"));
	conversion.insert(std::make_pair(100,"C"));
	conversion.insert(std::make_pair(400,"CD"));
	conversion.insert(std::make_pair(500,"D"));
	conversion.insert(std::make_pair(900,"CM"));
	conversion.insert(std::make_pair(1000,"M"));

	std::map<int,std::string>::reverse_iterator rit;
	for (rit=conversion.rbegin(); rit != conversion.rend(); rit++)
	{
		int digit = rit->first;
		std::string roman = rit->second;
		while (i >= digit)
		{
			s+=roman;
			i-=digit;
		}
	}
	return s;
}

Context(ARomanNumeralsConverter)
{
	Spec(UnitsAreConvertedCorrectly)
	{
		Assert::That(to_roman(1), Equals("I"));
		Assert::That(to_roman(2), Equals("II"));
		Assert::That(to_roman(3), Equals("III"));
		Assert::That(to_roman(4), Equals("IV"));
		Assert::That(to_roman(5), Equals("V"));
		Assert::That(to_roman(6), Equals("VI"));
		Assert::That(to_roman(7), Equals("VII"));
		Assert::That(to_roman(8), Equals("VIII"));
		Assert::That(to_roman(9), Equals("IX"));
		Assert::That(to_roman(10), Equals("X"));
	}

	Spec(TensAreConvertedCorrectly)
	{
		Assert::That(to_roman(40), Equals("XL"));
		Assert::That(to_roman(50), Equals("L"));
		Assert::That(to_roman(99), Equals("XCIX"));
	}

	Spec(YearsAreConvertedCorrectly)
	{
		Assert::That(to_roman(99), Equals("XCIX"));
		Assert::That(to_roman(1990), Equals("MCMXC"));
		Assert::That(to_roman(2008), Equals("MMVIII"));
	}
};
