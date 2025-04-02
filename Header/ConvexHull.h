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

		// nlogn
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

	std::vector<point> GetConvexHull_Andrew(std::vector<point>& input) {
		int n = _points.size();
		if (n <= 1) return _points;

		std::vector<point> vec(_points.begin(), _points.end());
		point_sort(vec);

		//��͹��
		std::vector<point> hull;
		for (int i = 0; i < n; ++i)
		{
			// ������������µ��γɷ���תʱ��ɾ�����һ����
			// ����size���жϲ�Ҫ©�ˣ�
			while (hull.size() >= 2 && cross1(hull[hull.size() - 2], hull.back(), vec[i]) <= 0.0)
			{
				hull.pop_back();
			}

			hull.push_back(vec[i]);
		}

		//��͹��
		int lower_size = hull.size();
		for (int i = n - 2; i >= 0; --i)
		{
			// �������ת
			while (hull.size() > lower_size && cross1(hull[hull.size() - 2], hull.back(), vec[i]) <= 0)
			{
				hull.pop_back();
			}
			hull.push_back(vec[i]);
		}
		
		//ɾ����β�ظ������
		if (hull.size() > 1) hull.pop_back();

		return hull;
	}


	std::vector<point> GetConvexHull_Graham(std::vector<point>& input)
	{
		int n = _points.size();
		if (n <= 1) return _points;

		std::vector<point> vec(_points.begin(), _points.end());

		/*point pivot = vec[0];
		for (size_t i = 1; i < vec.size(); ++i)
		{
			pivot = (vec[i].y < pivot.y || vec[i].y == pivot.y && vec[i].x < pivot.x) ? vec[i] : pivot;
		}*/

		//�ҵ�y��С�ĵ㣻����м�����Сy�ĵ㣬��ѡx��С��
		auto size = vec.size();
		for (size_t i = 1; i < size; ++i)
		{
			if (vec[i].y < vec[0].y || vec[i].y == vec[0].y && vec[i].x < vec[0].x)
				std::swap(vec[i], vec[0]);
		}

		sort(vec.begin() + 1, vec.end(), [&](point& p1, point& p2) {
			
			auto ret = cross2(vec[0], p1, p2);
			if (abs(ret) < ZERO_ERROR) // ������ȡ����С��
			{
				return p1.x - vec[0].x < p2.x - vec[0].x;
			}
			else {
				return ret > 0.0;
			}

			});

		std::vector<point> result;
		for (size_t i = 0; i < vec.size(); ++i)
		{
			while (result.size() >= 2 && cross2(result[result.size() - 2], result.back(), vec[i]) <= 0)
			{
				result.pop_back();
			}
			result.push_back(vec[i]);
		}

		return result;
	}

};

// ��̬��Ա��ʼ��
ConvexHull* ConvexHull::ins = nullptr;