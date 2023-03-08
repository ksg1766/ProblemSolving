#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	Node():iData(0)
	{
		next = nullptr;
		prev = nullptr;
	}
	Node(T _data) :iData(_data)
	{
		next = nullptr;
		prev = nullptr;
	}

	T iData;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
class Deque
{
public:
	Deque();
	void push_front(T _input);
	void push_back(T _input);
	void pop_front();
	void pop_back();
	void empty();
	void front();
	void back();
	size_t size();

private:
	size_t iSize;
	Node<T>* head;
	Node<T>* tail;
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
	
	Deque<int> dq;

	for (int i = 0; i < N; ++i)
	{
		cin >> szCommand;
		if (szCommand == "push_back")
		{
			cin >> iInput;
			dq.push_back(iInput);
		}
		else if (szCommand == "push_front")
		{
			cin >> iInput;
			dq.push_front(iInput);
		}
		else if (szCommand == "pop_back")
        {
            dq.pop_back();
            cout << '\n';
        }
		else if (szCommand == "pop_front")
        {
            dq.pop_front();
            cout << '\n';
        }
		else if (szCommand == "empty")
        {
            dq.empty();
            cout << '\n';
        }
		else if (szCommand == "back")
        {
            dq.back();
            cout << '\n';
        }
		else if (szCommand == "front")
        {
            dq.front();
            cout << '\n';
        }
		else
        {
            cout << dq.size();
            cout << '\n';
        }
	}
	
	return 0;
}

template <typename T>
Deque<T>::Deque():iSize(0)
{
	head = nullptr;
	tail = nullptr;
}

template <typename T>
void Deque<T>::push_front(T _input)
{
	Node<T>* tempNode = new Node<T>(_input);
	if (iSize == 0)
	{
		head = tempNode;
		tail = tempNode;
	}

	else
	{
		head->prev = tempNode;
		tempNode->next = head;
		head = tempNode;
	}

	++iSize;
}

template <typename T>
void Deque<T>::push_back(T _input)
{
	Node<T>* tempNode = new Node<T>(_input);
	if (iSize == 0)
	{
		head = tempNode;
		tail = tempNode;
	}

	else
	{
		tempNode->prev = tail;
		tail->next = tempNode;
		tail = tempNode;
	}

	++iSize;
}

template <typename T>
void Deque<T>::pop_front()
{
	front();
	if (iSize)
	{
		Node<T>* temp;
		temp = head;
		head = head->next;

		delete temp;
		--iSize;
	}
}

template <typename T>
void Deque<T>::pop_back()
{
	back();
	if (iSize)
	{
		Node<T>* temp;
		temp = tail;
		tail = tail->prev;

		delete temp;
		--iSize;
	}
}

template <typename T>
size_t Deque<T>::size()
{
	return iSize;
}

template <typename T>
void Deque<T>::empty()
{
	if (!iSize)
		cout << 1;
    else
    	cout << 0;
	
}

template <typename T>
void Deque<T>::front()
{
	if (!iSize)
		cout << -1;
	else
		cout << head->iData;
}

template <typename T>
void Deque<T>::back()
{
	if (!iSize)
		cout << -1;
	else
		cout << tail->iData;
}