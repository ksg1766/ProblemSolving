#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    int Sum = 0;
    int Min = 4001;
    int Max = -4000;
    pair<int, int> Most = { 4001, -1 };
    pair<int, int> Second = { 4001, -1 };

    vector<int> v(8001, 0);

    cin >> N;

    int MidPos = N;
    int Mid = 4001;

    //v.reserve(8001);

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        ++v[input + 4000];
        
        Sum += input;
    }

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i])
        {
            if (Min == 4001 && Min > i - 4000)
            {
                Min = i - 4000;
            } // Min

            if (Max < i - 4000)
            {
                Max = i - 4000;
            } // Max

            if (Most.second < v[i])
            {
                Most.first = i - 4000;
                Most.second = v[i];

                Second = Most;
            } // Most
            else if (Most.second == v[i])
            {
                if (Second.first == Most.first)
                {
                    Second.first = i - 4000;
                    Second.second = v[i];
                }
            }

            if (4001 == Mid && N / 2 < MidPos && N / 2 >= MidPos - v[i])
            {
                Mid = i - 4000;
            } // Mid
            else
            {
                MidPos -= v[i];
            }
        }
    }

    float avg = Sum / (float)N; // Average

    Sum = round(avg);

    cout << Sum << '\n';
    cout << Mid << '\n';
    cout << Second.first << '\n';
    cout << Max - Min << '\n';

    return 0;
}