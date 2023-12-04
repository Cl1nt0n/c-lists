#include "list.h";

//�����������
List::List()
{
	size = 0;
	head = nullptr;
}
//����������
List::~List()
{
	cout << "������ ������." << endl;
}

void List::print()
{
	//��������� �� �������� �������
	Node* current = this->head;
	int counter = 0;
	//���� ��������� �� ������� ���� �� ����� null
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
	//���� ������ ������ ���� ���� �� ����� ������ � �����, ������ �������� ��������
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

	//���� ������� �� 1 ������ ������� �������� ��������
	while (counter < index - 1)
	{
		current = current->p_next;
		counter++;
	}

	if (current->p_next == nullptr)
	{
		delete[] current;
		cout << "������� ������� ������." << endl;
		return;
	}

	Node* erasing = current->p_next;
	if (erasing->p_next != nullptr)
		current->p_next = erasing->p_next;
	else
		current->p_next = nullptr;

	delete[] erasing;
	cout << "������� ������� ������." << endl;
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
			cout << "����� ������� ��� ����������. ����������, ����� ��� �������� ����� ���� ���������. " << endl;
			return;
		}

		while (current->p_next != nullptr)
		{
			current = current->p_next;
			if (current->numb == numb)
			{
				cout << "����� ������� ��� ����������. ����������, ����� ��� �������� ����� ���� ���������. " << endl;
				return;
			}
		} 
		
		current->p_next = new Node(numb);
	}
	size++;
	cout << "������� ������� ��������." << endl;
}

int List::get_size()
{
	return size;
}

int List::get_max_element()
{
	if (head == nullptr)
	{
		cout << "������ ����. ����� ������������� �������� ����������. " << endl;
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
