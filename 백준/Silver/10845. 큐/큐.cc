#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iCounter = 0;

    int iHead = 0;
    int iTail = 0;
    int myQueue[10000];

    cin >> iCounter;

    for (int i = 0; i < iCounter; ++i)
    {
        char szOrder[6];
        cin >> szOrder;

        if (!strcmp(szOrder, "push"))
        {
            int input;
            cin >> input;
            myQueue[iTail] = input;
            ++iTail;
            continue;
        }
        else if(!strcmp(szOrder, "pop"))
        {
            if (iTail == iHead)
                cout << -1;
            else
            {
                cout << myQueue[iHead];
                ++iHead;
            }
        }
        else if(!strcmp(szOrder, "size"))
        {
            cout << iTail - iHead;
        }
        else if(!strcmp(szOrder, "empty"))
        {
            if (iTail == iHead)
                cout << 1;
            else
                cout << 0;
        }
        else if(!strcmp(szOrder, "front"))
        {
            if (iTail == iHead)
                cout << -1;
            else
                cout << myQueue[iHead];
        }
        else if(!strcmp(szOrder, "back"))
        {
            if (iTail == iHead)
                cout << -1;
            else
                cout << myQueue[iTail - 1];
        }

        cout << '\n';
    }

    return 0;
}