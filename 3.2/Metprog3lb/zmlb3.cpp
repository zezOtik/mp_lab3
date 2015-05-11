/** \zmlb3.cpp*/

#include <iostream>
#include <stack>
/**
namespace std
@brief ������������ ���� std
*/
using namespace std;

///������� �������
/** void main stack*/
void main()
{
	/**
	@brief ������ �� �������
	@param S - ����
	@param number - ������ ��� ������
	@param number 2 - ������ ��� ������
	@param i - �������
	@param value - ������
	*/
	setlocale(LC_ALL, "Russian");
	stack <int> S; //�������� ����� S ���� int
	char number; int value;
	char number2;
	int N,i;
	cout << "������� ���-�� ��������" << endl;
	cin >> N;
	for (i = 0; i < N; i++)
	{
			cout << "1. �������� �������" << endl;
			cout << "2. ������� �������" << endl;
			cout << "3. �������� ������� �������" << endl;
			cout << "4. ������ ������ �����" << endl;
			cout << "0. �����" << endl;
			cout << "����� ������� > "; cin >> number;
			switch (number)
			{
			case '1': //���������� ��������
				cout << "�������� > "; cin >> value;
				S.push(value); cout << endl << "������� �������� � ����\n\n";
				break;
				//-----------------------------------------------
			case '2': //�������� ��������
				if (S.empty() == true) cout << "\n���� ����\n\n";
				else
				{
					S.pop(); cout << endl << "������� ������ �� �����\n\n";
				} break;
				//-----------------------------------------------
			case '3': //����� �������� ��������
				if (S.empty() == true) cout << "\n���� ����\n\n";
				else cout << "\n������� ������� �����: " << S.top() << "\n\n";
				break;
				//-----------------------------------------------
			case '4': //����� ������� �����
				if (S.empty() == true) cout << "\n���� ����\n\n";
				else cout << "\n������ �����: " << S.size() << "\n\n";
				break;
				//-----------------------------------------------
			case '0':
				exit(0);
				break; //�����
			default: cout << endl << "������� �� ������������\n\n";
				break;
			}
			cout << endl;
			cout << "� ��� �������� " << N - i - 1 << " ��������" << endl;
			cout << endl;		
	}
	cout << " ���� �� � ��� ������� ������� ����?" << endl;
	cout << "Y or y ��� ������ N or n ��� ���������" << endl;
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