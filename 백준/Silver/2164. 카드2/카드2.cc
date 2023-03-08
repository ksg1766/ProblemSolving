#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	queue<int> q;
	int iCount = 0;

	cin >> iCount;

	for (int i = 1; i <= iCount; i++)
		q.push(i);

	int iTemp;
	while (q.size() > 1)
	{
		q.pop();
		iTemp = q.front();
		q.pop();
		q.push(iTemp);
	}

	cout << q.front();

	return 0;
}