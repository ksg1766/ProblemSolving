#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iNumSrc = 0;
    vector<int> vecSrcs;

    cin >> iNumSrc;

    for (int i = 0; i < iNumSrc; ++i)
    {
        int input;
        cin >> input;
        vecSrcs.push_back(input);
    }
    
    int iNumDst = 0;
    vector<int> vecDsts;

    cin >> iNumDst;

    for (int i = 0; i < iNumDst; ++i)
    {
        int input;
        cin >> input;
        vecDsts.push_back(input);
    }

    sort(vecSrcs.begin(), vecSrcs.end());

    vector<int> vecCache(*(vecSrcs.end() - 1) - vecSrcs[0] + 1);

    for (int i = 0; i < vecSrcs.size(); ++i)
    {
        ++vecCache[vecSrcs[i] - vecSrcs[0]];
    }

    for (int i = 0; i < vecDsts.size(); ++i)
    {
        if (vecDsts[i] < vecSrcs[0] || vecDsts[i] > *(vecSrcs.end() - 1))
            cout << "0 ";
        else
            cout << vecCache[vecDsts[i] - vecSrcs[0]] << ' ';
    }

    return 0;
}