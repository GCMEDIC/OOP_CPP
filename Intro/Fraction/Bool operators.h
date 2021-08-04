#pragma once
#include "asdfax.h"
#include "Fraction main.h"

bool operator==(fraction left, fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator !=(const fraction& left, const fraction& right)
{
	return !(left == right);
}