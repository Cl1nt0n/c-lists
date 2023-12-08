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
		//����� �������� �������� ����
		cout << '{' << current->numb << " \t-\t" << counter << '}' << endl;
		current = current->p_next;
		counter++;
	}

	//���� ������ ����
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

		//������� head
		delete head;
		size--;
	}
}

void List::erase(int index, int& error_code)
{
	int counter = 0;
	Node* current = head;//������� �������
	Node* previous = current;//���������� �������

	//���� ������� ������ ������� �������� �������� ��� ������� ������� �� nullptr
	while (counter < index && current != nullptr)
	{
		//����������� previous current
		previous = current;
		counter++;
		//current ����������� ��������� �������
		current = current->p_next;
	}

	//���� ������� �� ������
	if (current == nullptr)
	{
		error_code == 1;
		return;
	}
	//���� ������� �������� ���������� � head
	if (previous == current)
	{
		//����������� head ��������� �������
		head = head->p_next;
		//������� head
		delete current;
		size--;
		return;
	}
	//���� ��������� ������� ����� �������� �� null
	if (current->p_next != nullptr)
		previous->p_next = current->p_next;//������ ��������� p_next ����������� �� ��������� ����� ��������
	else
		previous->p_next = nullptr;//������ ��������� p_next ����������� �� nullptr

	//������� �������
	delete current;
	error_code = 0;
	size--;
}

void List::push_back(int numb)
{
	//���� ������ ����
	if (head == nullptr)
	{
		head = new Node(numb);
		return;
	}
	//��������� �� ������ �������
	Node* current = this->head;

	//�������� �� ������������ ��������
	if (current->numb == numb)
	{
		cout << "����� ������� ��� ����������. ����������, ����� ��� �������� ����� ���� ���������. " << endl;
		return;
	}

	//���� ������ ���������� ��������
	while (current->p_next != nullptr)
	{
		current = current->p_next;
		//�������� �� ������������
		if (current->numb == numb)
		{
			cout << "����� ������� ��� ����������. ����������, ����� ��� �������� ����� ���� ���������. " << endl;
			return;
		}
	}

	//�������� ������ ��������
	current->p_next = new Node(numb);
	//���������� �������
	size++;
	cout << "������� ������� ��������." << endl;
}

int List::get_size()
{
	//������� ������� ������
	return size;
}

int List::get_max_element()
{
	//���� ������ ����
	if (head == nullptr)
	{
		cout << "������ ����. ����� ������������� �������� ����������. " << endl;
		return -1;
	}

	//������� �������
	Node* current = head;
	//������������ �������
	int max = current->numb;
	//������ ������������� ��������
	int max_index = 0;
	int counter = 0;

	//���� ������� �� ���� ���������
	while (current->p_next != nullptr)
	{
		current = current->p_next;
		counter++;
		//�������� �� ��������
		if (current->numb > max)
		{
			max = current->numb;
			max_index = counter;
		}
	}
	//������� ������� ������������� ��������
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
