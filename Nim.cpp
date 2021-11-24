#include "Nim.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <vector>
using namespace std;

Nim::Nim() {}

Nim::~Nim() {}

void Nim::printmenu()
{
	cout << "�������� ����� ����(����� - 666):" << endl;
	cout << "1.���� �� 2 ������" << endl;
	cout << "2.���� � �����������" << endl;
	cout << "3.���������� ���" << endl;
}

void Nim::showmas(char* mas1, int x, char* mas2, int y, char* mas3, int z)
{
	cout << "������� ����:" << endl;
	for (int i = 0; i < x; i++)
	{
		mas1[i] = '*';
		cout << mas1[i];
	}
	cout << endl;
	for (int i = 0; i < y; i++)
	{
		mas2[i] = '*';
		cout << mas2[i];
	}
	cout << endl;
	for (int i = 0; i < z; i++)
	{
		mas3[i] = '*';
		cout << mas3[i];
	}
	cout << endl;
}

void Nim::twoplayers()
{
	int x, y, z;
	int i = 0;
	bool win = false;
	string winner, player, player1, player2;
	SetConsoleCP(1251);
	cout << "������� ��� ������� ������:" << endl;
	cin >> player1;
Point2:cout << "������� ��� ������� ������:" << endl;
	cin >> player2;
	if (player2 == player1)
	{
		cout << "����� ��� ��� ������ ������ �������, ���������� ��� ���!" << endl;
		goto Point2;
	}
	SetConsoleCP(866);
	player = player1;
	x = rand() % 8 + 3;
	y = rand() % 8 + 3;
	z = rand() % 8 + 3;
	char* mas1 = new char[x];
	char* mas2 = new char[y];
	char* mas3 = new char[z];
	system("cls");
	showmas(mas1, x, mas2, y, mas3, z);
	do
	{
		int pile, value;
		cout << "����� " << player << "!" << endl;
		cout << "�������� �����, � ������� ������ ������� ���������: ";
	Loop:cin >> pile;
		if (pile == 1 or pile == 2 or pile == 3);
		else
		{
			cout << "�������� ����� �����, ���������� ��� ���!" << endl;
			goto Loop;
		}
	Point:cout << "������� ���-�� ��������, ������� ������ �������: ";
		cin >> value;
		switch (pile)
		{
		case 1:
			if (x == 0)
			{
				cout << "��� ����� �����! �������� ������!" << endl;
				goto Loop;
			}
			if (value < 1 || value > x)
			{
				cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
				goto Point;
			}
			x -= value;
			system("pause");
			system("cls");
			showmas(mas1, x, mas2, y, mas3, z);
			break;
		case 2:
			if (y == 0)
			{
				cout << "��� ����� �����! �������� ������!" << endl;
				goto Loop;
			}
			if (value < 1 || value > y)
			{
				cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
				goto Point;
			}
			y -= value;
			system("pause");
			system("cls");
			showmas(mas1, x, mas2, y, mas3, z);
			break;
		case 3:
			if (z == 0)
			{
				cout << "��� ����� �����! �������� ������!" << endl;
				goto Loop;
			}
			if (value < 1 || value > z)
			{
				cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
				goto Point;
			}
			z -= value;
			system("pause");
			system("cls");
			showmas(mas1, x, mas2, y, mas3, z);
			break;
		}
		if (x == 0 && y == 0 && z == 0)
		{
			win = true;
			cout << player << " ���������!" << endl;
			winner = player;
			system("pause");
			system("cls");
		}
		i++;
		if (i % 2 == 0) player = player1;
		else player = player2;
	} while (!win);
	delete[] mas1;
	delete[] mas2;
	delete[] mas3;
	ofstream fout;
	fout.open("records.txt", ofstream::app);
	fout << "���� �� 3 �����\n";
	fout << player1 << " vs " << player2 << "\n" << "���������: " << winner << "\n\n";
}

void Nim::showai(vector<char> pile1, vector<char> pile2, int size1, int size2)
{
	cout << "������� ����:" << endl;
	for (int i = 0; i < size1; i++)
	{
		pile1.push_back('*');
		cout << pile1[i];
	}
	cout << endl;
	for (int i = 0; i < size2; i++)
	{
		pile2.push_back('*');
		cout << pile2[i];
	}
	cout << endl;
}

void Nim::showai(vector<char> pile1, vector<char> pile2, vector<char> pile3, int size1, int size2, int size3)
{
	cout << "������� ����:" << endl;
	for (int i = 0; i < size1; i++)
	{
		pile1.push_back('*');
		cout << pile1[i];
	}
	cout << endl;
	for (int i = 0; i < size2; i++)
	{
		pile2.push_back('*');
		cout << pile2[i];
	}
	cout << endl;
	for (int i = 0; i < size3; i++)
	{
		pile3.push_back('*');
		cout << pile3[i];
	}
	cout << endl;
}

void Nim::showai(vector<char> pile1, vector<char> pile2, vector<char> pile3, vector<char> pile4, int size1, int size2, int size3, int size4)
{
	cout << "������� ����:" << endl;
	for (int i = 0; i < size1; i++)
	{
		pile1.push_back('*');
		cout << pile1[i];
	}
	cout << endl;
	for (int i = 0; i < size2; i++)
	{
		pile2.push_back('*');
		cout << pile2[i];
	}
	cout << endl;
	for (int i = 0; i < size3; i++)
	{
		pile3.push_back('*');
		cout << pile3[i];
	}
	cout << endl;
	for (int i = 0; i < size4; i++)
	{
		pile4.push_back('*');
		cout << pile4[i];
	}
	cout << endl;
}

void Nim::ai()
{
	vector<char> pile1, pile2, pile3, pile4;
	int i = 0, game;
	bool win = false;
	string winner, player, player1, player2 = "���������";
	SetConsoleCP(1251);
	cout << "������� ���� ���: ";
	cin >> player1;
	SetConsoleCP(866);
	system("cls");
	cout << "����� ������ ������?" << endl << "1.������" << endl << "2.������" << endl;
ex:cin >> game;
	switch (game)
	{
	case 1: player = player1;
		break;
	case 2: player = player2;
		break;
	default:
		cout << "�� ����� �������� ����, ���������� ��� ���!" << endl;
		goto ex;
		break;
	}
	system("pause");
	system("cls");
	int size1 = rand() % 8 + 3;
	int size2 = rand() % 8 + 3;
	int size3 = rand() % 8 + 3;
	int size4 = rand() % 8 + 3;
	int choose;
	cout << "������� ���-�� �����, ������� ����� �� ������� ����(�� 2 �� 4): ";
Loop:cin >> choose;
	if (choose == 2)
	{
		size3 = 0;
		size4 = 0;
		pile3.clear();
		pile4.clear();
		system("cls");
		showai(pile1, pile2, size1, size2);
	}
	else if (choose == 3)
	{
		size4 = 0;
		pile4.clear();
		system("cls");
		showai(pile1, pile2, pile3, size1, size2, size3);
	}
	else if (choose == 4)
	{

		system("cls");
		showai(pile1, pile2, pile3, pile4, size1, size2, size3, size4);
	}
	else
	{
		cout << "�� ����� �������� ��������, ���������� ��� ���!" << endl;
		goto Loop;
	}
	do
	{
		cout << "����� " << player << "!" << endl;
		if (player == player1)
		{
			int pile, value;
			cout << "�������� �����, � ������� ������ ������� ���������: ";
			if (choose == 2)
			{
			Loopch2:cin >> pile;
				if (pile == 1 or pile == 2)
				{
				Pointch2:cout << "������� ���-�� ��������, ������� ������ �������: ";
					cin >> value;
					switch (pile)
					{
					case 1:
						if (size1 == 0)
						{
							cout << "��� ����� �����! �������� ������!" << endl;
							goto Loopch2;
						}
						if (value < 1 || value > size1)
						{
							cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
							goto Pointch2;
						}
						size1 -= value;
						system("pause");
						system("cls");
						showai(pile1, pile2, size1, size2);
						break;
					case 2:
						if (size2 == 0)
						{
							cout << "��� ����� �����! �������� ������!" << endl;
							goto Loopch2;
						}
						if (value < 1 || value > size2)
						{
							cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
							goto Pointch2;
						}
						size2 -= value;
						system("pause");
						system("cls");
						showai(pile1, pile2, size1, size2);
						break;
					}
					if (size1 == 0 && size2 == 0)
					{
						win = true;
						cout << player << " ���������!" << endl;
						winner = player;
						system("pause");
						system("cls");
					}
					player = player2;
				}
				else
				{
					cout << "�������� ����� �����, ���������� ��� ���!" << endl;
					goto Loopch2;
				}
			}
			else if (choose == 3)
			{
			Loopch3:cin >> pile;
				if (pile == 1 or pile == 2 or pile == 3)
				{
				Pointch3:cout << "������� ���-�� ��������, ������� ������ �������: ";
					cin >> value;
					switch (pile)
					{
					case 1:
						if (size1 == 0)
						{
							cout << "��� ����� �����! �������� ������!" << endl;
							goto Loopch3;
						}
						if (value < 1 || value > size1)
						{
							cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
							goto Pointch3;
						}
						size1 -= value;
						system("pause");
						system("cls");
						showai(pile1, pile2, pile3, size1, size2, size3);
						break;
					case 2:
						if (size2 == 0)
						{
							cout << "��� ����� �����! �������� ������!" << endl;
							goto Loopch3;
						}
						if (value < 1 || value > size2)
						{
							cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
							goto Pointch3;
						}
						size2 -= value;
						system("pause");
						system("cls");
						showai(pile1, pile2, pile3, size1, size2, size3);
						break;
					case 3:
						if (size3 == 0)
						{
							cout << "��� ����� �����! �������� ������!" << endl;
							goto Loopch3;
						}
						if (value < 1 || value > size3)
						{
							cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
							goto Pointch3;
						}
						size3 -= value;
						system("pause");
						system("cls");
						showai(pile1, pile2, pile3, size1, size2, size3);
						break;
					}
					if (size1 == 0 && size2 == 0 && size3 == 0)
					{
						win = true;
						cout << player1 << " ���������!" << endl;
						winner = player1;
						system("pause");
						system("cls");
					}
					player = player2;
				}
				else
				{
					cout << "�������� ����� �����, ���������� ��� ���!" << endl;
					goto Loopch3;
				}
			}
			else if (choose == 4)
			{
			Loopch4:cin >> pile;
				if (pile == 1 or pile == 2 or pile == 3 or pile == 4)
				{
				Pointch4:cout << "������� ���-�� ��������, ������� ������ �������: ";
					cin >> value;
					switch (pile)
					{
					case 1:
						if (size1 == 0)
						{
							cout << "��� ����� �����! �������� ������!" << endl;
							goto Loopch4;
						}
						if (value < 1 || value > size1)
						{
							cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
							goto Pointch4;
						}
						size1 -= value;
						system("pause");
						system("cls");
						showai(pile1, pile2, pile3, pile4, size1, size2, size3, size4);
						break;
					case 2:
						if (size2 == 0)
						{
							cout << "��� ����� �����! �������� ������!" << endl;
							goto Loopch4;
						}
						if (value < 1 || value > size2)
						{
							cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
							goto Pointch4;
						}
						size2 -= value;
						system("pause");
						system("cls");
						showai(pile1, pile2, pile3, pile4, size1, size2, size3, size4);
						break;
					case 3:
						if (size3 == 0)
						{
							cout << "��� ����� �����! �������� ������!" << endl;
							goto Loopch4;
						}
						if (value < 1 || value > size3)
						{
							cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
							goto Pointch4;
						}
						size3 -= value;
						system("pause");
						system("cls");
						showai(pile1, pile2, pile3, pile4, size1, size2, size3, size4);
						break;
					case 4:
						if (size4 == 0)
						{
							cout << "��� ����� �����! �������� ������!" << endl;
							goto Loopch4;
						}
						if (value < 1 || value > size4)
						{
							cout << "������ ����� ������� ��������, ���������� ��� ���!" << endl;
							goto Pointch4;
						}
						size4 -= value;
						system("pause");
						system("cls");
						showai(pile1, pile2, pile3, pile4, size1, size2, size3, size4);
						break;
					}
					if (size1 == 0 && size2 == 0 && size3 == 0 && size4 == 0)
					{
						win = true;
						cout << player1 << " ���������!" << endl;
						winner = player1;
						system("pause");
						system("cls");
					}
					player = player2;
				}
				else
				{
					cout << "�������� ����� �����, ���������� ��� ���!" << endl;
					goto Loopch4;
				}
			}
		}
		else if (player == player2)
		{
			int tmp1 = size1, tmp2 = size2, tmp3 = size3, tmp4 = size4;
			if (choose == 2)
			{
				int nim = size1 ^ size2;
				if (nim == 0)
				{
					if (size2 != 0)
					{
						cout << player2 << " ����� 1 ������ �� 2 ����." << endl;
						size2--;
					}
					else if (size1 != 0)
					{
						cout << player2 << " ����� 1 ������ �� 1 ����." << endl;
						size1--;
					}
				}
				else
				{
					int pileNumber = 0, takestars = 0;
					if ((size1 ^ nim) >= size1)
					{
						pileNumber = size2;
						size2 = (size2 ^ nim);
					}
					else
					{
						pileNumber = size1;
						size1 = (size1 ^ nim);
					}
					takestars = pileNumber - (pileNumber ^ nim);
					if (pileNumber == tmp1)
						pileNumber = 1;
					else
						pileNumber = 2;
					cout << player2 << " ����� " << takestars << " �����(�,�) �� " << pileNumber << " ����." << endl;
				}
				system("pause");
				system("cls");
				showai(pile1, pile2, size1, size2);
			}

			if (choose == 3)
			{
				int nim = size1 ^ size2 ^ size3;
				if (nim == 0)
				{
					if (size3 != 0)
					{
						cout << player2 << " ����� 1 ������ �� 3 ����." << endl;
						size3--;
					}
					else if (size2 != 0)
					{
						cout << player2 << " ����� 1 ������ �� 2 ����." << endl;
						size2--;
					}
					else if (size1 != 0)
					{
						cout << player2 << " ����� 1 ������ �� 1 ����." << endl;
						size1--;
					}
				}
				else
				{
					int pileNumber = 0, takestars = 0;
					if ((size1 ^ nim) >= size1)
					{
						if ((size2 ^ nim) >= size2)
						{
							pileNumber = size3;
							size3 = (size3 ^ nim);
						}
						else
						{
							pileNumber = size2;
							size2 = (size2 ^ nim);
						}
					}
					else
					{
						pileNumber = size1;
						size1 = (size1 ^ nim);
					}
					takestars = pileNumber - (pileNumber ^ nim);
					if (pileNumber == tmp1)
						pileNumber = 1;
					else if (pileNumber == tmp2)
						pileNumber = 2;
					else
						pileNumber = 3;
					cout << player2 << " ����� " << takestars << " �����(�,�) �� " << pileNumber << " ����." << endl;
				}
				system("pause");
				system("cls");
				showai(pile1, pile2, pile3, size1, size2, size3);
			}

			if (choose == 4)
			{
				int nim = size1 ^ size2 ^ size3 ^ size4;
				if (nim == 0)
				{
					if (size4 != 0)
					{
						cout << player2 << " ����� 1 ������ �� 4 ����." << endl;
						size4--;
					}
					if (size3 != 0)
					{
						cout << player2 << " ����� 1 ������ �� 3 ����." << endl;
						size3--;
					}
					else if (size2 != 0)
					{
						cout << player2 << " ����� 1 ������ �� 2 ����." << endl;
						size2--;
					}
					else if (size1 != 0)
					{
						cout << player2 << " ����� 1 ������ �� 1 ����." << endl;
						size1--;
					}
				}
				else
				{
					int pileNumber = 0, takestars = 0;
					if ((size1 ^ nim) >= size1)
					{
						if ((size2 ^ nim) >= size2)
						{
							if ((size3 ^ nim) >= size3)
							{
								pileNumber = size4;
								size4 = (size4 ^ nim);
							}
							else
							{
								pileNumber = size3;
								size3 = (size3 ^ nim);
							}
						}
						else
						{
							pileNumber = size2;
							size2 = (size2 ^ nim);
						}
					}
					else
					{
						pileNumber = size1;
						size1 = (size1 ^ nim);
					}
					takestars = pileNumber - (pileNumber ^ nim);
					if (pileNumber == tmp1)
						pileNumber = 1;
					else if (pileNumber == tmp2)
						pileNumber = 2;
					else if (pileNumber == tmp3)
						pileNumber = 3;
					else
						pileNumber = 4;
					cout << player2 << " ����� " << takestars << " �����(�,�) �� " << pileNumber << " ����." << endl;
				}
				system("pause");
				system("cls");
				showai(pile1, pile2, pile3, pile4, size1, size2, size3, size4);
			}

			if (size1 == 0 && size2 == 0 && size3 == 0 && size4 == 0)
			{
				win = true;
				cout << player2 << " ���������!" << endl;
				winner = player2;
				system("pause");
				system("cls");
			}
			player = player1;
		}
	} while (!win);
	pile1.clear();
	pile2.clear();
	pile3.clear();
	pile4.clear();
	ofstream fout;
	fout.open("records.txt", ofstream::app);
	fout << "���� �� " << choose << " �����\n" << player1 << " vs " << player2 << "\n" << "���������: " << winner << "\n\n";
}

void Nim::fromfile()
{
	system("pause");
	system("cls");
	ifstream fin;
	fin.open("records.txt");
	if (!fin.is_open())
	{
		cout << "���� ���������� ����!" << endl;
	}
	else
	{
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
	}
	fin.close();
}

void Nim::removefile()
{
	system("cls");
	remove("records.txt");
	cout << "���������� ������� �������!" << endl;
}

void Nim::files()
{
	int choose;
	cout << "1.���������� ���������� ���\n2.������� ���������� ���" << endl;
Loop:cin >> choose;
	switch (choose)
	{
	case 1: fromfile();
		system("pause");
		system("cls");
		break;
	case 2: removefile();
		system("pause");
		system("cls");
		break;
	default:
		cout << "�� ����� �������� ��������, ���������� �����!" << endl;
		goto Loop;
		break;
	}
}