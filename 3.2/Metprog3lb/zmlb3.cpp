/** \zmlb3.cpp*/

#include <iostream>
#include <stack>
/**
namespace std
@brief Пространство имен std
*/
using namespace std;

///главная функция
/** void main stack*/
void main()
{
	/**
	@brief Работа со стекком
	@param S - Стек
	@param number - индекс для выбора
	@param number 2 - Индекс для выбора
	@param i - счетчик
	@param value - данные
	*/
	setlocale(LC_ALL, "Russian");
	stack <int> S; //создание стека S типа int
	char number; int value;
	char number2;
	int N,i;
	cout << "Введите кол-во действий" << endl;
	cin >> N;
	for (i = 0; i < N; i++)
	{
			cout << "1. Добавить элемент" << endl;
			cout << "2. Удалить элемент" << endl;
			cout << "3. Получить верхний элемент" << endl;
			cout << "4. Узнать размер стека" << endl;
			cout << "0. Выйти" << endl;
			cout << "Номер команды > "; cin >> number;
			switch (number)
			{
			case '1': //добавление элемента
				cout << "Значение > "; cin >> value;
				S.push(value); cout << endl << "Элемент добавлен в стек\n\n";
				break;
				//-----------------------------------------------
			case '2': //удаление элемента
				if (S.empty() == true) cout << "\nСтек пуст\n\n";
				else
				{
					S.pop(); cout << endl << "Элемент удален из стека\n\n";
				} break;
				//-----------------------------------------------
			case '3': //вывод верхнего элемента
				if (S.empty() == true) cout << "\nСтек пуст\n\n";
				else cout << "\nВерхний элемент стека: " << S.top() << "\n\n";
				break;
				//-----------------------------------------------
			case '4': //вывод размера стека
				if (S.empty() == true) cout << "\nСтек пуст\n\n";
				else cout << "\nРазмер стека: " << S.size() << "\n\n";
				break;
				//-----------------------------------------------
			case '0':
				exit(0);
				break; //выход
			default: cout << endl << "Команда не определенная\n\n";
				break;
			}
			cout << endl;
			cout << "У вас осталось " << N - i - 1 << " действия" << endl;
			cout << endl;		
	}
	cout << " Есть ли у вас желание вывести стек?" << endl;
	cout << "Y or y для вывода N or n для отрицания" << endl;
	cin >> number2;
	switch (number2)
	{
	case ('Y'|'y') :
		i = S.size();
		while(i > 0)
			{
			cout << S.top();
			S.pop();
			printf(" ");
			i--;
			}break;
		case ('N'|'n'):
			cout << "Ok" << endl;
			break;
	}
	system("pause");
}