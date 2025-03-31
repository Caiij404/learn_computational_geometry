
#include <iostream>
#include <ConvexHull.h>
#include <Utils.h>
int main()
{
    std::cout << "Hello World!\n";

    std::vector<point> points;
    auto ret = ConvexHull::Get()->GetConvexHull(points);

    return 0;
}
