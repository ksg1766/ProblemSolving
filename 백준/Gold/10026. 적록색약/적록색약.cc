#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int gCount = 0;
char DirY[4] = { 1, 0, -1, 0 };
char DirX[4] = { 0, 1, 0, -1 };

void BFS(const vector<vector<char>>& area, vector<vector<bool>>& cache, char& startY, char& startX)
{
    queue<pair<char, char>> q;
    q.emplace(startY, startX);
    const char& startColor = area[startY][startX];

    while(!q.empty())
    {
        pair<char, char>& cell = q.front();

        for(int i = 0; i < 4; ++i)
        {
            char nextY = cell.first + DirY[i];
            char nextX = cell.second + DirX[i];
            if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N)
            {
                if (startColor == area[nextY][nextX] && false == cache[nextY][nextX])
                {
                    cache[nextY][nextX] = true;
                    q.emplace( nextY, nextX );
                }
            }
        }
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<vector<char>> area(N, vector<char>(N, 0));
    vector<vector<bool>> cache(N, vector<bool>(N, false));

    for(int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> area[i][j];
        }
    }
    
    for (char i = 0; i < N; ++i)
    {
        for (char j = 0; j < N; ++j)
        {
            if (false == cache[i][j])
            {
                BFS(area, cache, i, j);
                ++gCount;
            }
        }
    }

    cout << gCount << ' ';

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cache[i][j] = false;
            if ('G' == area[i][j])
                area[i][j] = 'R';
        }
    }

    gCount = 0;

    for (char i = 0; i < N; ++i)
    {
        for (char j = 0; j < N; ++j)
        {
            if (false == cache[i][j])
            {
                BFS(area, cache, i, j);
                ++gCount;
            }
        }
    }

    cout << gCount;

    return 0;
}