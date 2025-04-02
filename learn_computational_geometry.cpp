
#include <iostream>
#include <ConvexHull.h>
#include <Utils.h>
int main()
{
    std::cout << "Hello World!\n";

    std::vector<point> points;
    auto ins = ConvexHull::Get();
    if (!ins)
        return -1;
    auto ret1 = ins->GetConvexHull_Andrew(points);

    auto ret2 = ins->GetConvexHull_Graham(points);

    return 0;
}
