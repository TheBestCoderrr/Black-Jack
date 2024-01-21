#pragma once

template<class T>
class Node {
public:
	explicit Node(T value, Node* next = nullptr, Node* prev = nullptr);
	void setValue(T v);
	T getValue() const;
	void setNext(Node* n);
	Node* getNext() const;
	void setPrev(Node* p);
	Node* getPrev() const;
	void print() const;
private:
	T value;
	Node* next;
	Node* prev;
};

template<class T>
Node<T>::Node(T value, Node* next, Node* prev) : value(value), next(next), prev(prev) {}

template<class T>
void Node<T>::setValue(T v)
{
	value = v;
}

template<class T>
T Node<T>::getValue() const
{
	return value;
}

template<class T>
void Node<T>::setNext(Node* n)
{
	next = n;
}

template<class T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

template<class T>
void Node<T>::setPrev(Node* p)
{
	prev = p;
}

template<class T>
Node<T>* Node<T>::getPrev() const
{
	return prev;
}

template<class T>
void Node<T>::print() const
{
	cout << value;
}




