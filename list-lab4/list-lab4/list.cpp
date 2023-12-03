#include "list.h";

List::List()
{
	size = 0;
	head = nullptr;
}

List::~List()
{
	cout << "Список удален." << endl;
}

void List::print()
{
	Node* current = this->head;
	int counter = 0;
	while (current != nullptr)
	{
		cout << '{' << current->numb << " \t-\t" << counter << '}' << endl;
		current = current->p_next;
		counter++;
	}

	if (counter == 0)
		cout << "{ }" << endl;
}

void List::clear()
{
	while (size)
	{
		Node* head = this->head;
		this->head = head->p_next;

		delete[] head;
		size--;
	}
}

void List::erase(int index)
{
	int counter = 0;
	Node* current = head;

	while (counter < index - 1)
	{
		current = current->p_next;
		counter++;
	} 

	if (current->p_next == nullptr)
	{
		delete[] current;
		return;
	}

	Node* erasing = current->p_next;
	if (erasing->p_next != nullptr)
		current->p_next = erasing->p_next;
	else
		current->p_next = nullptr;

	delete[] erasing;
	size--;
}

void List::push_back(int numb)
{
	if (head == nullptr)
	{
		head = new Node(numb);
	}
	else
	{
		Node* current = this->head;
		while (current->p_next != nullptr)
		{
			current = current->p_next;
		}
		current->p_next = new Node(numb);
	}
	size++;
}

int List::get_size()
{
	return size;
}

int& List::operator[](const int index)
{
	int counter = 0;
	Node* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->numb;
		}
		current = current->p_next;
		counter++;
	}
}
