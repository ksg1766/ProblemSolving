#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(const vector<vector<bool>>& v, vector<bool>& cache, int InStart)
{
    cache[InStart] = true;
    cout << InStart + 1 << ' ';

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[InStart][i])
        {
            if (!cache[i])            
            {
                DFS(v, cache, i);
            }
        }
    }
}

void BFS(const vector<vector<bool>>& v, vector<bool>& cache, int InStart)
{
    queue<int> q;
    cache[InStart] = true;
    q.push(InStart);

    while (!q.empty())
    {
        int Next = q.front();
        q.pop();

        cout << Next + 1 << ' ';

        for (int i = 0; i < v.size(); ++i)
        {
            if (v[Next][i])
            {
                if(!cache[i])
                {
                    cache[i] = true;
                    q.push(i);
                }
            }         
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<bool>> v(N, vector<bool>(N, false));
    vector<bool> cache1(N, false);
    vector<bool> cache2(N, false);

    for (int i = 0; i < M; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;

        v[n1 - 1][n2 - 1] = true;
        v[n2 - 1][n1 - 1] = true;
    }

    DFS(v, cache1, V - 1);

    cout << '\n';

    BFS(v, cache2, V - 1);

    return 0;
}