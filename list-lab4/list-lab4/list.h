#include "iostream"

using namespace std;
class List
{
public:
	List();
	~List();

	int get_size();
	int get_max_element();
	void push_back(int numb);
	void print();
	void clear();
	void erase(int index);

	int& operator[](const int index);

private:
	class Node
	{
	public:
		Node* p_next;
		int numb;

		Node(int numb, Node* p_next = nullptr)
		{
			this->numb = numb;
			this->p_next = p_next;
		}
	};

	int size;
	Node* head;
};



