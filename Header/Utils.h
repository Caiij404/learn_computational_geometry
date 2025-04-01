#pragma once

// 最后不需要分号！！！ 我说下面小于号的重载函数咋报错
//#define ZERO_ERROR 10e-7;

#define ZERO_ERROR 10e-7

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


	bool operator < (const point& p) const {
		return (x < p.x) || (abs(x - p.x) < ZERO_ERROR && y < p.y);
	}
};

// p1 - p2
point sub(point p1, point p2)
{
	return point(p1.x - p2.x, p1.y - p2.y);
}

// p1 x p2
double cross(point& p1, point& p2)
{
	return p1.x * p2.y - p1.y * p2.x;
}

// (p2 - p1) x (p3 - p2)
double cross(point& p1, point& p2, point& p3)
{
	return (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
}