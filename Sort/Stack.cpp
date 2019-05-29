#include "Stack.h"

void Stack::init_stack()
{
	top = 0;
}

void Stack::push(int i)
{
	if (top >= capacity) {
		printf("stack full\n");
		return;
	}
	else
		stack[top++] = i;
}

int Stack::pop()
{
	if (top == 0)
		return 0;
	else
		return stack[--top];
}

int Stack::is_stack_empty()
{
	if (top == 0)
		return 1;
	else
		return 0;
}

Stack::Stack(int capacity)
{
	this->capacity = capacity;
	top = 0;
	stack = new int[capacity];
}

Stack::~Stack()
{
	delete[] stack;
}
