#include <iostream>
#include <stack>
using namespace std;
int main() {
	stack<int> s;
	std::cout << s.empty()<<' ';
	s.push(30);
	s.push(25);
	s.push(1);
	s.push(2);
	std::cout<<s.size()<< ' ';
	std::cout<< s.top()<< ' ';
	std::cout<< s.empty()<< ' ';
	while(!s.empty()){
		std::cout<<s.top()<<'\n';
		s.pop();
	}
}