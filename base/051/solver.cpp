#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	queue <char> time;
	int time1, time2;

	for(char i = 'A'; i < 'Q' ;i++) time.push(i);

	for (int i = 0; i < 15;i++)
	{
		cin >> time1 >> time2;

		if(time1 > time2)
		{
			time.push(time.front());
			time.pop();
			time.pop();
		}
		else
		{
			time.pop();
			time.push(time.front());
			time.pop();
		}
	}

	cout << time.front() << endl;

	return 0;
}