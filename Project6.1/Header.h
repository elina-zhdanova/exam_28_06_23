#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T>
class Stack {
private:
	struct _stack {
		T value;
		struct Stack<T>::_stack* next;
	};
	Stack<T>::_stack* stack;
	T& getNElem(int num, Stack<T>::_stack* elem) const;
	int stackSize;
public:
	Stack();
	Stack(const Stack<T>& stack);
	T top();
	void push(T& value);
	T pop();
	T& peek(int num) const;
	bool empty() const;
};

#endif