/** \lb_3.cpp*/
#include <iostream>
/**
namespace std
@brief Пространство имен std
*/
using namespace std;

struct DoubleList //описание узла списка
{
	int data; //информационное поле
	DoubleList *next; //указатель на следующий элемент
	DoubleList *prev; //указатель на предыдущий элемент
};
DoubleList *head; //указатель на первый элемент списка
//**ДОБАВЛЕНИЕ ЭЛЕМЕНТА**
void AddList(int value, int position)
{
	DoubleList *node = new DoubleList; //создание нового элемента
	node->data = value; //присвоение элементу значения
	if (head == NULL) //если список пуст
	{
		node->next = node; //установка указателя next
		node->prev = node; //установка указателя prev
		head = node; //определяется голова списка
	}
	else
	{
		DoubleList *p = head;
		for (int i = position; i>1; i--) p = p->next;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
	cout << "\nЭлемент добавлен...\n\n";
}
//**УДАЛЕНИЕ ЭЛЕМЕНТА**
int DeleteList(int position)
{
	if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
	if (head == head->next)
	{
		delete head;
		head = NULL;
	}
	else
	{
		DoubleList *a = head;
		for (int i = position; i>1; i--) a = a->next;
		if (a == head) head = a->next;
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
	cout << "\nЭлемент удален...\n\n";
}
//**ВЫВОД СПИСКА**
void PrintList()
{
	if (head == NULL) cout << "\nСписок пуст\n\n";
	else
	{
		DoubleList *a = head;
		cout << "\nЭлементы списка: ";
		do
		{
			cout << a->data << " ";
			a = a->next;
		} while (a != head); cout << "\n\n";
	}
}
//**ГЛАВНАЯ ФУНКЦИЯ**
void main()
{
	setlocale(LC_ALL, "Rus");
	int value, position, x;
	int i, N;
	cout << "Введите кол-во действий" << endl;
	cin >> N;
	for (i = 0; i < N; i ++)
	{
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Вывести список" << endl;
		cout << "0. Выйти" << endl;
		cout << "\nНомер операции > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Значение > "; cin >> value;
			cout << "Позиция > "; cin >> position;
			AddList(value, position); break;
		case 2:
			cout << "Позиция > "; cin >> position;
			DeleteList(position); break;
		case 3: PrintList(); break;
		case 0: exit(0); break;
		} 
		cout << "Осталось "<< N - i - 1 << "действий" << endl;
		printf("\n");
	} while (x != 0);
}