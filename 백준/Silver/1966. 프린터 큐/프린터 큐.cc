#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 0;
    int N = 0, M = 0;

    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        int count = 0;

        for (int i = 0; i < N; ++i)
        {
            int input = 0;
            cin >> input;
            q.push({ i, input });
            pq.push(input);
        }
        
        while (true)
        {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();

            if (value == pq.top())
            {
                pq.pop();

                ++count;

                if (index == M)
                {
                    cout << count << '\n';
                    break;
                }
            }
            else
            {
                q.push({ index, value });
            }
        }
    }

    return 0;
}