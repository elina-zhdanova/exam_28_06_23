#include "Header.h"

template <class T>
Stack<T>::Stack() {
	this->stack = nullptr;
	this->stackSize = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& stack) {
	this->stack = nullptr;
	this->stackSize = 0;
	int n = stack.stackSize;
	try {
		if (stack.empty()) this->stack = nullptr;
		else while (n > 0) this->push(stack.peek(n--));
	}
	catch (std::exception e) {
		std::cout << e.what();
	}
}

template <class T>
T Stack<T>::top() {
	if (this->empty()) throw std::exception("Стек пуст");
	return this->stack->value;
}

template <class T>
void Stack<T>::push(T& value) {
	Stack<T>::_stack* tmp = new Stack<T>::_stack;
	tmp->value = value;
	tmp->next = this->stack;
	this->stack = tmp;
	this->stackSize++;
}

template <class T>
T Stack<T>::pop() {
	T r_value;
	Stack<T>::_stack* out;
	if (this->empty()) throw std::exception("Стек пуст");
	this->stackSize--;
	out = this->stack;
	this->stack = this->stack->next;
	r_value = out->value;
	delete out;
	return r_value;
}

template <class T>
T& Stack<T>::getNElem(int num, Stack<T>::_stack* elem) const {
	if (num > this->stackSize) throw std::exception("В стеке элементов меньше");
	else if (num > 1) return this->getNElem(num - 1, elem->next);
	else if (num == 1) return elem->value;
	else throw std::exception("Индекс элемента не может быть равен или меньше нуля");
}

template <class T>
T& Stack<T>::peek(int num) const {
	return getNElem(num, this->stack);
}

template <class T>
bool Stack<T>::empty() const {
	if (this->stackSize == 0) return true;
	else return false;
}

template class Stack<char>;