#include <iostream>
#include <queue>
int main() {

	std::queue<int> q;
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	q.push(10);
	std::cout << q.size() << '\n';
	std::cout << q.front() << '\n';
	std::cout << q.back() << '\n';

	while (!q.empty()) {
		std::cout << q.front() <<' ';
		q.pop();
	}

	return 0;
}