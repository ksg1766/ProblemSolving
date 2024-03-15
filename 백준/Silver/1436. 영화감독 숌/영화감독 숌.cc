#include <iostream>

using namespace std;

void chactTerm(int iNum, bool& bResult);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input = 0;
    int result = 0;

    cin >> input;

    int iCount = 0;
    bool bResult = false;

    for (int i = 0; iCount < 10000; ++i)
    {
        chactTerm(i, bResult);
        if (bResult)
        {
            ++iCount;

            if (iCount == input)
            {
                result = i;
                break;
            }
        }
    }

    cout << result;

    return 0;
}

void chactTerm(int iNum, bool& bResult)
{
    while (iNum)
    {
        if (666 != iNum % 1000)
        {
            iNum /= 10;
        }
        else
        {
            bResult = true;
            return;
        }
    }

    bResult = false;
    return;
}