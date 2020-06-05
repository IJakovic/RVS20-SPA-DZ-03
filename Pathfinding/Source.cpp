#include <iostream>

using namespace std;

const int x = 21;
const int y = 41;


void indeksi(int polje[x][y]) {
	int n = 0;
	for (int i = 1; i < x; i++)
	{
		for (int j = 1; j < y; j++)
		{
			polje[i][j] = n;
			n++;
		}
	}
}


void draw(int polje[x][y], int visinaA, int sirinaA, int visinaB, int sirinaB, int visinaA1, int sirinaA1) {
	system("cls");
	for (int i = 1; i < x; i++)
	{
		for (int j = 1; j < y; j++)
		{
			if (polje[i][j] == polje[visinaA][sirinaA]) cout << 'A';
			else if (polje[i][j] == polje[visinaA1][sirinaA1]) cout << 'x';
			else if (polje[i][j] == polje[visinaB][sirinaB]) cout << 'B';
			else cout << '-';
		}
		cout << endl;
	}
}


void pathfinding(int polje[x][y], int visinaA, int sirinaA, int visinaB, int sirinaB) {

	int visinaX = visinaA;
	int sirinaX = sirinaA;

	while (polje[visinaX][sirinaX] != polje[visinaB][sirinaB])
	{
		if (visinaX < visinaB)
		{
			draw(polje, visinaA, sirinaA, visinaB, sirinaB, ++visinaX, sirinaX);
		}
		else if (visinaX > visinaB)
		{
			draw(polje, visinaA, sirinaA, visinaB, sirinaB, --visinaX, sirinaX);
		}
		if (sirinaX < sirinaB)
		{
			draw(polje, visinaA, sirinaA, visinaB, sirinaB, visinaX, ++sirinaX);
		}
		else if (sirinaX > sirinaB)
		{
			draw(polje, visinaA, sirinaA, visinaB, sirinaB, visinaX, --sirinaX);
		}
	}
}


int main() {

	int polje[x][y];
	indeksi(polje);

	int visinaA;
	int sirinaA;
	int visinaB;
	int sirinaB;
	cout << "Unesite visinu A: ";
	cin >> visinaA;
	cout << "Unesite sirinu A: ";
	cin >> sirinaA;
	cout << "Unesite visinu B: ";
	cin >> visinaB;
	cout << "Unesite sirinu B: ";
	cin >> sirinaB;

	pathfinding(polje, visinaA, sirinaA, visinaB, sirinaB);

	return 0;
}