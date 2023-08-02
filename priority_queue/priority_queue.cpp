#include <iostream>

#define max_size 10

struct priority_queue {
	int queue[max_size];
	int item_count = 0;

	bool isFull = (item_count >= max_size) ? true : false;

	void insert(int data) {
		if (isFull) {
			std::cout << "queue is full";
			return;
		}
		if (item_count == 0) {
			queue[0] = data;
			item_count++;
			return;
		}
		shift(data, 0);
		item_count++;
	}
	void print() {
		for (int i = 0; i < item_count; i++) std::cout << queue[i] << ' ';
	}

private:
	void shift(int data, int index) {
		if (index >= item_count) {
			queue[index] = data;
			return;
		}
		if (data > queue[index]) {
			int temp = queue[index];
			queue[index] = data;
			shift(temp, index + 1);
		}
		else {
			shift(data, index + 1);
		}
	}
};

int main() {
	priority_queue q;
	q.insert(5);
	q.insert(3);
	q.insert(7);
	q.insert(9);
	q.insert(10);
	q.insert(1);
	q.print();
	return 0;
}