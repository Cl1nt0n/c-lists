#include "list.h";

//конструктор
List::List()
{
	size = 0;
	head = nullptr;
}
//деструктор
List::~List()
{
	cout << "Список удален." << endl;
}

void List::print()
{
	//указатель на головной элемент
	Node* current = this->head;
	int counter = 0;
	//пока указатель на текущий узел не равен null
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
	//пока размер больше нуля идем от начла списка к концу, удаляя головные элементы
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

	//пока счетчик на 1 меньше индекса искомого элемента
	while (counter < index - 1)
	{
		current = current->p_next;
		counter++;
	}

	if (current->p_next == nullptr)
	{
		delete[] current;
		cout << "Элемент успешно удален." << endl;
		return;
	}

	Node* erasing = current->p_next;
	if (erasing->p_next != nullptr)
		current->p_next = erasing->p_next;
	else
		current->p_next = nullptr;

	delete[] erasing;
	cout << "Элемент успешно удален." << endl;
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

		if (current->numb == numb)
		{
			cout << "Такой элемент уже существует. Необходимо, чтобы все элементы листа были уникальны. " << endl;
			return;
		}

		while (current->p_next != nullptr)
		{
			current = current->p_next;
			if (current->numb == numb)
			{
				cout << "Такой элемент уже существует. Необходимо, чтобы все элементы листа были уникальны. " << endl;
				return;
			}
		} 
		
		current->p_next = new Node(numb);
	}
	size++;
	cout << "Элемент успешно добавлен." << endl;
}

int List::get_size()
{
	return size;
}

int List::get_max_element()
{
	if (head == nullptr)
	{
		cout << "Список пуст. Поиск максимального элемента невозможен. " << endl;
		return -1;
	}

	Node* current = head;
	int max = current->numb;
	int max_index = 0;
	int counter = 0;

	if (current->numb > max)
	{
		max = current->numb;
		max_index = counter;
	}

	while (current->p_next != nullptr)
	{
		current = current->p_next;
		counter++;
		if (current->numb > max)
		{
			max = current->numb;
			max_index = counter;
		}
	}

	return max_index;
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
