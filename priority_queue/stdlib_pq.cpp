#include <iostream>
#include <queue>
int main() {

	std::priority_queue<int> q;
	q.push(5);
	q.push(21);
	q.push(-3);
	q.push(7);
	q.push(8);
	q.push(12);
	q.push(10);
	std::cout << q.size() << '\n';
	std::cout << q.top() << '\n';

	while (!q.empty()) {
		std::cout << q.top() <<' ';
		q.pop();
	}

	return 0;
}