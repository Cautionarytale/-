#include<iostream>
using namespace std;
#include<stack>
#include<queue>
int main()
{
	int n;
	while (cin >> n, n != 0)
	{
		int val_0;
		while (cin >> val_0, val_0 != 0)
		{
			deque<int>d; d.push_back(val_0);
			for (int i = 1; i < n; i++)
			{
				int val; cin >> val;
				d.push_back(val);
			}
			stack<int>s; int j = 1;
			while (1)
			{
				s.push(j++);
				while (!s.empty() && s.top() == d.front())
				{
					s.pop(); d.pop_front();
				}
				
				if (d.empty())
				{
					cout << "YES" << endl;
					break;
				}
				if (j > n)
				{
					cout << "NO" << endl;
					break;
				}
			}
			
		}
		cout <<""<< endl;
	}
	return 0;
}
