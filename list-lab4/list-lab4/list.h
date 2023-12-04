#include "iostream"

using namespace std;
//список
class List
{
public:
	List();
	~List();

	int get_size();//Функция получения размера списка
	int get_max_element();//функция получения максимального элемента
	void push_back(int numb);//функция добавления элемента в конец списка
	void print();//функция печати списка
	void clear();//функция удаления списка
	void erase(int index);//функция удаления выбранного элемента списка

	int& operator[](const int index);//перегрузка оператора []

private:
	//узел
	class Node
	{
	public:
		//указатель на следующий узел
		Node* p_next;
		//значение в узле
		int numb;

		Node(int numb, Node* p_next = nullptr)
		{
			this->numb = numb;
			this->p_next = p_next;
		}
	};

	//размер списка
	int size;
	//указатель на начальный элемент
	Node* head;
};



