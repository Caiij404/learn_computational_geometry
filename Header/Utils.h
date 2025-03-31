#pragma once

#define ZERO_ERROR 10e-7;

bool Equal(double a, double b)
{
	return abs(a - b) < ZERO_ERROR;
}

struct point
{
	point(double a, double b) :x(a), y(b) {};
	point() :x(0), y(0) {};
	double x;
	double y;
};