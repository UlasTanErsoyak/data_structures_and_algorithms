#include <stdio.h>
#include <string.h>

#define size  20
char stack[size];	
int top = -1;


void push(char letter);
char pop();

int main() {
	char word[20] = "hello world!";
	int len = strlen(word);
	for (int i = 0; i < len; i++) {
		char current_char = word[i];
		push(current_char);
	}
	while (top != -1)
	{
		printf("%c", pop());
	}
	return 0;
}

void push(char letter) {
	if (top + 1 == size) {
		printf("error: stack overflow!");
		return;
	}
	top++;
	stack[top] = letter;
}
char pop() {
	if (top == -1) {
		printf("stack is empty");
		return '\0';
	}
	char letter = stack[top];
	top--;
	return letter;
}