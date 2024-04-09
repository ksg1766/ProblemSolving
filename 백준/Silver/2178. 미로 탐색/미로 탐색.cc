#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int Count = 1;

struct Pos
{
    Pos() {}
    Pos(int InY, int InX) : y(InY), x(InX) {}

    Pos operator+(const Pos& rhs)
    {
        return Pos(y + rhs.y, x + rhs.x);
    }

    bool operator==(Pos& rhs)
    {
        if (y == rhs.y && x == rhs.x)
        {
            return true;
        }
        return false;
    }
    
    bool operator!=(Pos& rhs)
    {
        if (*this == rhs)
        {
            return false;
        }
        return true;
    }

    int y = 0;
    int x = 0;
};

bool operator<(const Pos& lhs, const Pos& rhs)
{
    if (lhs.y < rhs.y)
    {
        return true;
    }
    else if (lhs.y == rhs.y)
    {
        if (lhs.x < rhs.x)
        {
            return true;
        }
    }

    return false;
}

Pos Dir[4] =
{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

void BFS(vector<vector<char>>& InMaze, vector<vector<bool>>& InCache, map<Pos, Pos>& InParent, Pos InDest)
{
    queue<Pos> q;

    Pos Start = Pos(0, 0);

    InCache[0][0] = true;
    InParent[Start] = Start;

    q.push(Start);

    while (false == q.empty())
    {
        Pos Next = q.front();

        if (InDest == Next)
            break;

        q.pop();

        for (size_t i = 0; i < 4; ++i)
        {
            Pos Discovered = Next + Dir[i];
            if (Discovered.y <= InDest.y && Discovered.y >= 0 &&
                Discovered.x <= InDest.x && Discovered.x >= 0 &&
                false == InCache[Discovered.y][Discovered.x] &&
                1 == InMaze[Discovered.y][Discovered.x])
            {
                q.push(Discovered);
                InCache[Discovered.y][Discovered.x] = true;

                InParent[Discovered] = Next;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<char>> Maze(N, vector<char>(M, 0));
    vector<vector<bool>> Cache(N, vector<bool>(M, false));
    map<Pos, Pos> Parent;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            char input;
            cin >> input;
            if (input == '1')
            {
                Maze[i][j] = 1;
            }
            else
            {
                Maze[i][j] = 0;
            }
        }
    }


    BFS(Maze, Cache, Parent, Pos(N - 1, M - 1));

    for (Pos pair = Pos(N - 1, M - 1); pair != Parent[pair]; pair = Parent[pair])
    {
        ++Count;
    }

    cout << Count;

    return 0;
}