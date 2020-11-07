//Yet Chun Fong 300376480 
//CSCi 115 Lab 9 

#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std; 

void LCS(string x, string y, int m, int n) {

	//Create a 2 dimensional array 
	int** matrix = new int* [m + 1];
	for (int i = 0; i < m + 1; i++) {
		matrix[i] = new int[n + 1];
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			//Case 1 
			if (i == 0 || j == 0) {
				matrix[i][j] = 0;
			}

			//Case 2 
			else if (x[i - 1] == y[j - 1]) {
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			}

			//Case 3
			else {
				matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
			}
		}
	}
	
	int index = matrix[m][n];
	char* longest = new char[index + 1];
	longest[index] = '\0';

	int i = m; 
	int j = n;

	while (index > 0) {
		if (matrix[i - 1][j] == matrix[i][j]) {
			i--; 
		}
		else if(matrix[i][j-1] == matrix[i][j]) {
			j--;
		}
		else {
			longest[index - 1] = x[i - 1];
			i--;
			j--;
			index--;
		}
	}
	cout << "LCS of " << x << " and " << y << " :" << matrix[m][n] << " " << longest << endl;

}

int main() {
	string X1 = "ACADB";
	string Y1 = "CBDA" ;
	int m1 = X1.length();
	int n1 = Y1.length();
	srand(time(NULL));
	auto start1 = chrono::high_resolution_clock::now();
	LCS(X1, Y1, m1, n1);
	auto end1 = chrono::high_resolution_clock::now();
	cout << "Running time: ";
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
	time_taken *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken << endl;
	cout << endl;

	string X2 = "BACDB";
	string Y2 = "BDCB";
	int m2 = X2.length();
	int n2 = Y2.length();
	srand(time(NULL));
	auto start2 = chrono::high_resolution_clock::now();
	LCS(X2, Y2, m2, n2);
	auto end2 = chrono::high_resolution_clock::now();
	cout << "Running time: ";
	double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
	time_taken2 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken2 << endl;
	cout << endl;

	string X3 = "XMJYAUZ";
	string Y3 = "MZJAWXU";
	int m3 = X3.length();
	int n3 = Y3.length();
	srand(time(NULL));
	auto start3 = chrono::high_resolution_clock::now();
	LCS(X3, Y3, m3, n3);
	auto end3 = chrono::high_resolution_clock::now();
	cout << "Running time: ";
	double time_taken3 = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();
	time_taken3 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken3 << endl;
	cout << endl;

	string X4 = "ABCBDAB";
	string Y4 = "BDCABA";
	int m4 = X4.length();
	int n4 = Y4.length();
	srand(time(NULL));
	auto start4 = chrono::high_resolution_clock::now();
	LCS(X4, Y4, m4, n4);
	auto end4 = chrono::high_resolution_clock::now();
	cout << "Running time: ";
	double time_taken4 = chrono::duration_cast<chrono::nanoseconds>(end4 - start4).count();
	time_taken4 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken4 << endl;
	cout << endl;
	
	return 0;
}
