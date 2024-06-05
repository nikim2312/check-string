#include "Checker.h"
void Checker::Add(char first, char sec)
{
	if (qol == 0)
	{
		pairs = new char[2];
		pairs[0] = first;
		pairs[1] = sec;
	}
	else
	{
		char* tmp;
		tmp = new char[qol + 2];
		for (int i = 0; i < qol; i++)
		{
			tmp[i] = pairs[i];
		}
		tmp[qol] = first;
		tmp[qol + 1] = sec;
		delete[] pairs;
		pairs = tmp;
	}
	qol+= 2;
}
bool Checker::Check()
{
	Stack stack;
	ifstream is(name);
	if (!is.is_open())
	{
		cout << "Error of opening file for reading!";
		return -1;
	}
	string b;
	int count = 0;
	while (!is.eof())
	{
		getline(is, b); 
		count++;
	}
	is.close();
	is.open(name);
	if (!is.is_open())
	{
		cout << "Error of opening file for reading!";
		return -1;
	}
	bool stop = true;
	string* mas;
	mas = new string[count];
	int a = 1;
	for (int i = 0; i < count; i++) //Если в стеке сверху лежит например { а нужно удалить ],то тоже false
	{ 
		if (stop == false)
			break;
		getline(is, mas[i]);
		for (int j = 0; j < mas[i].length(); j++)  // { [ (
		{
			for (int y = 0; y < qol; y+=2)
			{
				
				if (mas[i][j] == pairs[y])
				{
					stack.Push(y);
				}
			}
			
				for(int t = 1; t < qol; t+=2)
				{
					if (mas[i][j] == pairs[t] && !stack.IsEmpty() && pairs[stack.Back_el()] != pairs[t - 1]) 
					{
						stop = false;
						break;
					}
				}
				for (int w = 1; w < qol; w+=2)
				{
					if (mas[i][j] == pairs[w] && stack.IsEmpty())
					{
						stop = false;
						break;
					}
				}
				for (int r = 1; r < qol; r+=2)
				{
					if (stop = true && mas[i][j] == pairs[r])
						stack.Pop();
				}
		}

	}
	is.close();
	if (stack.IsEmpty() && stop == true)
		return true;
	else 
		return false;
};
