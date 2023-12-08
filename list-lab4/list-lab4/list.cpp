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
		//вывод значения текущего узла
		cout << '{' << current->numb << " \t-\t" << counter << '}' << endl;
		current = current->p_next;
		counter++;
	}

	//если список пуст
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

		//удаляем head
		delete head;
		size--;
	}
}

void List::erase(int index, int& error_code)
{
	int counter = 0;
	Node* current = head;//текущий элемент
	Node* previous = current;//предыдущий элемент

	//пока счетчик меньше индекса искомого элемента или текущий элемент не nullptr
	while (counter < index && current != nullptr)
	{
		//присваиваем previous current
		previous = current;
		counter++;
		//current присваиваем следующий элемент
		current = current->p_next;
	}

	//если элемент не найден
	if (current == nullptr)
	{
		error_code == 1;
		return;
	}
	//если искомое значение содержится в head
	if (previous == current)
	{
		//присваиваем head следующий элемент
		head = head->p_next;
		//удаляем head
		delete current;
		size--;
		return;
	}
	//если следующий элемент после искомого не null
	if (current->p_next != nullptr)
		previous->p_next = current->p_next;//меняем указатель p_next предыдущего на следующий после искомого
	else
		previous->p_next = nullptr;//меняем указатель p_next предыдущего на nullptr

	//удаляем элемент
	delete current;
	error_code = 0;
	size--;
}

void List::push_back(int numb)
{
	//если список пуст
	if (head == nullptr)
	{
		head = new Node(numb);
		return;
	}
	//указатель на первый элемент
	Node* current = this->head;

	//проверка на уникальность элемента
	if (current->numb == numb)
	{
		cout << "Такой элемент уже существует. Необходимо, чтобы все элементы листа были уникальны. " << endl;
		return;
	}

	//цикл поиска последнего элемента
	while (current->p_next != nullptr)
	{
		current = current->p_next;
		//проверка на уникальность
		if (current->numb == numb)
		{
			cout << "Такой элемент уже существует. Необходимо, чтобы все элементы листа были уникальны. " << endl;
			return;
		}
	}

	//создание нового элемента
	current->p_next = new Node(numb);
	//увеличение размера
	size++;
	cout << "Элемент успешно добавлен." << endl;
}

int List::get_size()
{
	//возврат размера списка
	return size;
}

int List::get_max_element()
{
	//если список пуст
	if (head == nullptr)
	{
		cout << "Список пуст. Поиск максимального элемента невозможен. " << endl;
		return -1;
	}

	//текущий элемент
	Node* current = head;
	//максимальный элемент
	int max = current->numb;
	//индекс максимального элемента
	int max_index = 0;
	int counter = 0;

	//цикл прохода по всем элементам
	while (current->p_next != nullptr)
	{
		current = current->p_next;
		counter++;
		//проверка на максимум
		if (current->numb > max)
		{
			max = current->numb;
			max_index = counter;
		}
	}
	//возврат индекса максимального элемента
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
