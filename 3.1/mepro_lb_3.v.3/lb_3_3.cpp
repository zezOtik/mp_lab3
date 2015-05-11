/**
\file: main.cpp
*/
#include <iostream>

/*! \brief void main() - tochka vhoda v programmu
*
*	sozdaet ochered v kolcevom bufer
*
*	razmer bufera zadaetsya polzovatelem
*
*	obespechivaet rabotu s ney
*
*	vyvodit ochered
*
*	ochischaet pamyat	*/

void main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	int Size;

	int numHead = -1;
	int numTail = -1;
	std::cout << "¬ведите размер буфера \n";
	std::cin >> Size;
	std::cout << "¬ведите колличество операций\n";
	std::cin >> N;

	int* Buf = new int[Size];

	int x;
	char c;
	for (int i = 0; i<N; i++)
	{
		std::cin >> c;
		if (c == 'a')
		{	// c == 'a'
			std::cin >> x;
			if (numTail == -1)
			{
				numHead = 0;
				numTail = 0;
				Buf[0] = x;
			}
			else
			{
				numTail += 1;
				if (numTail == Size) numTail = 0;
				Buf[numTail] = x;
			}
		}
		else
		{	// c == 'd'
			if (numHead == numTail)
			{
				numHead = -1;
				numTail = -1;
			}
			else
			{
				numHead += 1;
				if (numHead == Size) numHead = 0;
			}
		}
	}

	if (numHead != -1)
	{
		while (numHead != numTail)
		{
			std::cout << Buf[numHead] << " ";
			numHead++;
			if (numHead == Size)numHead = 0;
		}
		std::cout << Buf[numHead];
	}

	std::cout << '\n';

	delete Buf;
	system("pause");
}