#include <iostream>
#include <map>
using namespace std;

map<int, double> multi_single(map<int, double> poly, int n, double a)
{
    map<int, double> rs;
    for (auto it = poly.begin(); it != poly.end(); it++)
    {
        rs[it->first + n] = it->second * a;
    }
    return rs;
}

map<int, double> poly_puls(map<int, double> poly1, map<int, double> poly2)
{
    if (poly2.size() == 0)
    {
        return poly1;
    }

    for (auto it = poly2.begin(); it != poly2.end(); it++)
    {
        if (poly1.count(it->first))
        {
            // 相加后系数为0，则删除
            if (poly1[it->first] + it->second == 0.0)
            {
                poly1.erase(it->first);
            }
            else
            {
                poly1[it->first] += it->second;
            }
        }
        else
        {
            poly1[it->first] = it->second;
        }
    }
    return poly1;
}

int main()
{
    int k1, k2;
    map<int, double> poly1;
    map<int, double> poly2;
    map<int, double> rs;
    cin >> k1;
    int n;    // 指数
    double a; // 系数

    // 读取数据
    for (int i = 0; i < k1; i++)
    {
        cin >> n >> a;
        poly1[n] = a;
    }
    cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        cin >> n >> a;
        poly2[n] = a;
    }

    for (auto it = poly2.begin(); it != poly2.end(); it++)
    {
        rs = poly_puls(rs, multi_single(poly1, it->first, it->second));
    }

    cout << rs.size();
    for (auto it = rs.rbegin(); it != rs.rend(); it++)
    {
        printf(" %d %.1lf", it->first, it->second);
    }
}