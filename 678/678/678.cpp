#include <iostream>
#include<string>
#include<Windows.h>
int k = 3;
int z = k + k;
using namespace std;
class mass3;
class mass1 {
public:
	string* m = new string[k];
	void m1(string s1, int i);
	virtual void print()
	{
		for (int i = 0; i < k; i++)
		{

			cout << m[i] << " ";
		}
		cout << "\n";
	}
};

void mass1::m1(string s1, int i)
{
	m[i] = s1;
}
class mass2 : public mass1 {

public:
	string* ma = new string[k];
	void m2(string s1, int i);
	void print() override
	{
		for (int i = 0; i < k; i++)
		{

			cout << ma[i] << " ";
		}
		cout << "\n";
	}
};
void mass2::m2(string s1, int i)
{
	ma[i] = s1;

	//cout << ma[2] << "1" << "\n";
}
class mass3 : public mass2 {

public:
	string* g = new string[z];
	string* v = new string[z];
	void m3(string* m1, string* m2);
	void zero();
	void print() override;
	void proverka(string* m1, string* m2);
	void print2();
	void zd();
	void index(int a);

};
void mass3::zd()
{
	for (int i = 0; i < z; i++)
	{
		int x = 0;
		if (m[x] == ma[x])
		{

			x++;

		}
		else
		{

			g[x] = m[x];
			g[x + 1] = ma[x];
		}
	}
}
void mass3::m3(string* m1, string* m2)
{
	int x = 0;
	for (int i = 0; i < k; i++)
	{
		g[x] = m1[x];
		x++;
	}
	for (int i = 0; i < k; i++)
	{

		g[x] = m2[i];
		x++;
	}
}
void mass3::zero()
{
	for (int i = 0; i < z; i++)
	{
		g[i] = " ";
	}

}
void mass3::index(int a)
{
	if ((a >= 0) && (a < z))
	{
		if (v[a] != "")
		{
			cout << v[a];
		}

	}
	else
	{
		cout << "Пусто";
	}// Если что то g это фулл связный массив

}
void mass3::print()
{
	for (int i = 0; i < z; i++)
	{

		cout << g[i] << " ";
	}
	cout << "\n";
}
void mass3::proverka(string* m1, string* m2)
{
	int x = 0;
	for (int i = 0; i < k; i++)
	{
		v[x] = m1[i];
		x++;

	}
	for (int i = 0; i < k; i++)
	{
		int p = 0;
		if (g[x] == m1[p] || g[x] == m1[p + 1] || g[x] == m1[p + 2])
		{
			x++;
			p++;
			//cout << "a" << endl;
		}
		else
		{
			v[x] = m2[i];
			x++;
			p++;
			//cout << "b" << endl;
		}
	}
}
void mass3::print2()
{
	for (int i = 0; i < z; i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
}
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int f;
	char p[8];
	mass1 m1;
	mass2 m2;
	mass3 m3;
	cout << "Введите первый массив \n";
	for (int i = 0; i < k; i++)
	{
		cin.get(p, 7);
		cin.ignore(INT_MAX, '\n');
		m1.m1(p, i);
	}
	cout << "Введите второй массив \n";
	for (int i = 0; i < k; i++)
	{
		cin.get(p, 7);
		cin.ignore(INT_MAX, '\n');
		m2.m2(p, i);
	}
	m3.m3(m1.m, m2.ma);
	mass1* masov = &m1;
	masov->print();
	masov = &m2;
	masov->print();
	masov = &m3;
	masov->print();
	m3.print();
	m3.proverka(m1.m, m2.ma);
	m3.print2();
	cout << "Введите номер индекса ";
	cin >> f;
	m3.index(f);
	cout << "\n";
}
