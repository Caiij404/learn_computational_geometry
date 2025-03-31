#pragma once
#include <vector>
#include "Utils.h"
#include <algorithm>

class ConvexHull
{
private:
	ConvexHull() {
		_points = { point(2.0, 5.0),point(0.0, 4.0),point(5.0, 4.0),point(3.0, 4.0),point(2.0, 3.0),point(0.0, 3.0),point(1.0,2.0),point(3.0,0.0),point(5.0,1.0) };
	}

	static ConvexHull* ins;

	std::vector<point> _points;

	void point_sort(std::vector<point>& points)
	{
		if (points.size() <= 1)
			return;

		std::sort(points.begin(), points.end(), [](point p1, point p2) {
			return (!Equal(p1.x, p2.x)) ? p1.x < p2.x : p1.y < p2.y;
			});
	}

public:
	static ConvexHull* Get() {
		if (ins == nullptr)
		{
			ins = new ConvexHull();
		}
		return ins;
	}

	std::vector<point> GetConvexHull(std::vector<point>& input) {
		std::vector<point> ret(_points.begin(), _points.end());
		point_sort(ret);
		return ret;
	}
};

// 静态成员初始化
ConvexHull* ConvexHull::ins = nullptr;