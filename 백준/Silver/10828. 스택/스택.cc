#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
public:
	Stack();
	void push(T _input);
	void pop();
	void empty();
	bool top();
	size_t size();

private:
	size_t iSize;
	vector<T> vData;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	int N;
	string szCommand;
	int iInput;
	cin >> N;
	
	Stack<int> st;

	for (int i = 0; i < N; ++i)
	{
		cin >> szCommand;
		if (szCommand == "push")
		{
			cin >> iInput;
			st.push(iInput);
		}
		else if (szCommand == "pop")
		{
			st.pop();
			cout << '\n';
		}
		else if (szCommand == "empty")
		{
			st.empty();
			cout << '\n';
		}
		else if (szCommand == "top")
		{
			st.top();
			cout << '\n';
		}
		else
		{
			cout << st.size();
			cout << '\n';
		}
	}
	
	return 0;
}

template <typename T>
Stack<T>::Stack():iSize(0) {}

template <typename T>
void Stack<T>::push(T _input)
{
	vData.push_back(_input);

	++iSize;
}

template <typename T>
void Stack<T>::pop()
{
	if (top())
	{
		vData.pop_back();
		--iSize;
	}
}

template <typename T>
size_t Stack<T>::size()
{
	return iSize;
}

template <typename T>
void Stack<T>::empty()
{
	if (!iSize)
		cout << 1;
	else
		cout << 0;
	
}

template <typename T>
bool Stack<T>::top()
{
	if (iSize)
	{
		cout << vData[iSize - 1];
		return 1;
	}
	else
	{
		cout << -1;
		return 0;
	}
}