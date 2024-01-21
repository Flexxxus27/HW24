#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void print_arr(T arr[], int size1);

void fill_arr(int arr[], int length, int left, int rigth);

template <typename T>
void resize_arr(T*& arr, int length, int num1) {
	if (num1 <= 0)
		return;
	int* tmp = new int[length + num1] {};

	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;

}



int main() {
	setlocale(0, "");
	int n, m;

	//Задание 1.
	std::cout << "Задание 1.\n\n";
	std::cout << "Введите длины массивов: ";
	std::cin >> n >> m;

	int* arr1 = new int[n];
	int* arr2 = new int[m];
	fill_arr(arr1, n, 10, 30);
	fill_arr(arr2, m, 30, 60);
	std::cout << "Изначальные массивы:\n";
	print_arr(arr1, n);
	print_arr(arr2, m);

	int* arr3 = new int[n + m];
	for (int i = 0; i < n; i++) 
		arr3[i] = arr1[i];
	for (int i = n; i < n + m; i++)
		arr3[i] = arr2[i - n];
	std::cout << "Новый массив:\n";
	print_arr(arr3, n + m);
	delete[] arr1;
	delete[] arr2;

	//Задание 2.

	std::cout << "Задание 2.\n";
	std::cout << "Изначальный массив:\n";
	int* arrRise = new int[5];
	fill_arr(arrRise, 5, 0, 10);
	print_arr(arrRise, 5);
	std::cout << "Увеличенный массив:\n";
	resize_arr(arrRise, 5, 5);
	print_arr(arrRise, 10);






	return 0;
}

template <typename T>
void print_arr(T arr[], int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

void fill_arr(int arr[], int length, int left, int rigth) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (rigth + 1 - left) + left;
};

