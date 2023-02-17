#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	//정적 = 컴파일 타임 / 프로그램 실행 전
	//동적 = 런 타임 / 프로그램 실행 중

	int N;
	vector<int> v;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		cout << v[i] << '\n';

	return 0;
}