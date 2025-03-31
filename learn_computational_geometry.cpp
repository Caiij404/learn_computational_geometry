
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
    auto ret = ins->GetConvexHull(points);

    return 0;
}
