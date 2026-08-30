// @DROP
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue <char> time;
	int time1, time2;

	for(char i = 'A'; i < 'Q' ;i++) time.push(i);

	for (int i = 0; i < 15;i++)
	{
		cin >> time1 >> time2;
		auto a = time.front();
		time.pop();
		auto b = time.front();
		time.pop();

		std::cout << a << " " << b;
		if(time1 > time2) {
			time.push(a);
			std::cout << " " << a << '\n';
		} else {
			time.push(b);
			std::cout << " " << b << '\n';
		}
	}

	cout << time.front() << endl;

	return 0;
}