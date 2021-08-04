#pragma once
#include "asdfax.h"
#include "Fraction main.h"

fraction operator+(fraction left, fraction right)
{
	left.to_proper();
	right.to_proper();
	fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator
	(
		left.get_numerator() * right.get_denominator() +
		right.get_numerator() * left.get_denominator()
	);
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	return result;
}