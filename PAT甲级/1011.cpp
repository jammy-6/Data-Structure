#include <iostream>
#include <vector>

using namespace std;

double max_odds[3];
int max_odds_idx[3];
double max_odd, temp;
int max_odd_idx;
int main()
{

    for (int i = 0; i < 3; i++)
    {
        max_odd = -1;
        for (int j = 0; j < 3; j++)
        {
            cin >> temp;
            if (temp > max_odd)
            {
                max_odd = temp;
                max_odd_idx = j;
            }
        }
        max_odds[i] = max_odd;
        max_odds_idx[i] = max_odd_idx;
    }

    char output[3] = {'W', 'T', 'L'};
    for (int i = 0; i < 3; i++)
    {
        printf("%c ", output[max_odds_idx[i]]);
    }
    double profit = (max_odds[0] * max_odds[1] * max_odds[2] * 0.65 - 1) * 2;
    printf("%.2f", profit);
}
