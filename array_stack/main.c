#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int data);
void pop();
int peek();
bool is_empty();

int main(void){
	push(10);
	printf("%d ",peek());
	push(25);
	push(26);
	push(27);
	printf("%d ",peek());
	pop();
	printf("%d ",peek());
	return 0;
}

void push(int data){
	if(top+1==SIZE){
		printf("stack overflow");
		return;
	}
	top+=1;
	stack[top] = data;
}
void pop(){
	if(top==-1){
		printf("stack is empty");
		return;
	}
	top-=1;
}
int peek(){
	if(top!=-1)	return stack[top];
	printf("stack is empty");
}

bool is_empty(){
	if(top==-1) return true;
	else return false;
}






#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int data);
void pop();
int peek();
bool is_empty();

int main(void){
	push(10);
	printf("%d ",peek());
	push(25);
	push(26);
	push(27);
	printf("%d ",peek());
	pop();
	printf("%d ",peek());
	return 0;
}

void push(int data){
	if(top+1==SIZE){
		printf("stack overflow");
		return;
	}
	top+=1;
	stack[top] = data;
}
void pop(){
	if(top==-1){
		printf("stack is empty");
		return;
	}
	top-=1;
}
int peek(){
	if(top!=-1)	return stack[top];
	printf("stack is empty");
}

bool is_empty(){
	if(top==-1) return true;
	else return false;
}






