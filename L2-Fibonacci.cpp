#include <iostream>
#include <chrono>
#include <iomanip>
#include <functional>
using namespace std; 

int recursive(int n) {
	if (n == 0 || n==1) {
		return n;
	}
	return recursive(n - 1)+recursive(n - 2);
}

int variable(int n) {
	int prev = 0; 
	int curr = 1;
	int next;

	for (int i = 2; i <= n; i++) {
		next = prev + curr;
		prev = curr; 
		curr = next;

	}
	return curr; 
}

int main() {
	int a = 10, b = 40, c = 120, d=1;

	cout << "N = 10" << endl;
	//Recurison for N=10
	auto start1 = chrono::high_resolution_clock::now();
	cout <<"Recursive method (Inefficient): "<< recursive(a) << endl;
	auto end1 = chrono::high_resolution_clock::now();
	cout << "Time taken for Recursion: ";
	double time_taken1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
	time_taken1 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken1 << endl;
	cout << endl;

	//Variables method for N=10
	auto start2 = chrono::high_resolution_clock::now();
	cout <<"Variables method (Efficient): "<< variable(a) << endl;
	auto end2 = chrono::high_resolution_clock::now();
	cout << "Time taken for Variables method: ";
	double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
	time_taken2 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken2 << endl;
	cout << endl; 

	cout << "N = 40" << endl;
	//Recursion method for N=40
	auto start3 = chrono::high_resolution_clock::now();
	cout << "Recursive method (Inefficient): " << recursive(b) << endl;
	auto end3 = chrono::high_resolution_clock::now();
	cout << "Time taken for Recursion: ";
	double time_taken3 = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();
	time_taken3 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken3 << endl;
	cout << endl;

	//Variable method for N= 40
	auto start4 = chrono::high_resolution_clock::now();
	cout << "Variables method (Efficient): " << variable(b) << endl;
	auto end4 = chrono::high_resolution_clock::now();
	cout << "Time taken for Variable method: ";
	double time_taken4 = chrono::duration_cast<chrono::nanoseconds>(end4 - start4).count();
	time_taken4 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken4 << endl;
	cout << endl;

	cout << "N = 120" << endl;
	//Variable method for N=120
	auto start6 = chrono::high_resolution_clock::now();
	cout << "Variables method (Efficient): " << variable(c) << endl;
	auto end6 = chrono::high_resolution_clock::now();
	cout << "Time taken for Variable method: ";
	double time_taken6 = chrono::duration_cast<chrono::nanoseconds>(end6 - start6).count();
	time_taken6 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken6 << endl;
	cout << endl;

	//Recursion method for N=120
	auto start5 = chrono::high_resolution_clock::now();
	cout << "Recursive method (Inefficient): " << recursive(c) << endl;
	auto end5 = chrono::high_resolution_clock::now();
	cout << "Time taken for Recursion method: ";
	double time_taken5 = chrono::duration_cast<chrono::nanoseconds>(end5 - start5).count();
	time_taken5 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken5 << endl;
	cout << endl;
}
