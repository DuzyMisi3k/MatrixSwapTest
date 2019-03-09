// EliminacjaGaussaDowolnaMacierz.

#include "pch.h"
#include <iostream>
using namespace std;

void wyswTablice(double ** Tablica, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << Tablica[i][j] << " | ";
		}cout << "\n";
	}
	cout << "\n";

}

void wyswMacierzA(double ** Tablica, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << Tablica[i][j] << " | ";
		}cout << "\n";
	}
	cout << "\n";

}


void wyswMacierzB(double ** Tablica, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = m; j < n; j++) {
			cout << Tablica[i][j] << " | ";
		}cout << "\n";
	}
	cout << "\n";
}



void Odwracanie(double ** T, int n, int m) {

	for (int i = 0; i < n; i++) {
		double liczba = T[i][i];


		for (int j = 0 ; j < m; j++)
		{
			T[i][j] = T[i][j] / liczba;
		}

		for (int k = i ; k < n -1; k++) {
			liczba = T[k+1][i];

			for (int j = 0; j < m; j++) {
				T[k+1][j] = T[k+1][j] - T[i][j] * liczba;
				//cout << T[k + 1][j] << " ";
			}
			//cout << "\n";
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = n - k; i > 0; i--) {
					double liczba = T[i-1][n-k];
					for (int j = 0; j < m; j++) {
						T[i - 1][j] = T[i - 1][j] - (T[n-k][j] * liczba);
					//	cout << T[i-1][j] << " ";
					}
				//	cout << "\n";
				}
	}
		
}

	




int wielkoscMacierzy() {
	cout << "Wprowadz wielkosc macierzy (możesz wpisać tylko "3"): ";
	int n;
	cin >> n;
	return n;
}

int main()
{
	int n = wielkoscMacierzy();
	int m = 2 * n;
	double **T = new double *[n];
	for (int i = 0; i < n; i++) {
		T[i] = new double[2*n];
	}int u = 0;
	for (int i = 0; i < n; i++)
		
		for (int j = 0; j < n; j++) {
			double a[9] = { 3,3,-4,-3,0,6,1,1,5 };
			T[i][j] = a[u];
			u++;
		}
		for (int i = 0; i < n; i++)
			for (int j = n; j < 2*n; j++) {
				if (n+i == j) {
					T[i][j] = 1;
				}
				else {
					T[i][j] = 0;
				}
			}

		wyswMacierzA(T, n, m);
		wyswMacierzB(T, n, m);
		wyswTablice(T, n, m);
		Odwracanie(T, n, m);
		wyswTablice(T, n, m);
		wyswMacierzA(T, n, m);
		wyswMacierzB(T, n, m);



	std::cout << "Hello World!\n";
}

//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
