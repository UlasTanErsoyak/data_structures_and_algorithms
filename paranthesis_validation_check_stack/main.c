#include <stdio.h>
#include <string.h>

#define size 50
char stack[size];
int top = -1;

void push(char x);
char pop();

int main(void) {
	char a[50] = "{[(3+2)*2(60-30)]+ [(20-30)]}";
	for (int i = 0; i < strlen(a); i++) {
		char idx = a[i];
		if (idx == '[' || idx == '(' || idx == '{') {
			push(idx);
		}
		else if (idx == ']' || idx == ')' || idx == '}') {
			char rs = pop();
			if (idx == '{' && rs != '}') {
				printf("invalid!");
				break;
			}
			if (idx == '[' && rs != ']') {
				printf("invalid!");
				break;
			}
			if (idx == '(' && rs != ')') {
				printf("invalid!");
				break;
			}
		}
	}
	if (top != -1) {
		printf("invalid!");
	}
	else {
		printf("valid!");
	}
	return 0;
}
void push(char x) {
	if (top + 1 == size) {
		printf("stack overflow\n");
		return;
	}
	top++;
	stack[top] = x;
}
char pop() {
	if (top == -1) {
		printf("stack is empty\n");
		return '\0';
	}
	char rs = stack[top];
	top--;
	return rs;
}