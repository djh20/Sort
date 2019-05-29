#pragma once
#include <iostream>
using namespace std;
class Stack
{
	int* stack;
	int top;
	int capacity;
public:
	void init_stack();
	void push(int i);
	int pop();
	int is_stack_empty();
	Stack(int capacity);
	~Stack();
};

