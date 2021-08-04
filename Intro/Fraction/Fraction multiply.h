#pragma once
#include "asdfax.h"
#include "Fraction main.h"

fraction operator*(fraction left, fraction right)
{
	left.to_improper();
	right.to_improper();
	return fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}