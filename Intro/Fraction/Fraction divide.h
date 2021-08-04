#pragma once
#include "asdfax.h"
#include "Fraction main.h"

fraction operator/(fraction left, fraction right)
{
	return left * right.inverted();
}