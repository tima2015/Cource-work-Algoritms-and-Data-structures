#include "Measurement.hpp"
#include "Sort.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#define MAX 1000000000 //Ограничение генерируемого числа
#define L 1000 //Количество тестов
#define N 10   //Размер массива

int main(){
	randomize();
	std::ofstream out;          // поток для записи
    out.open("D:\\hello.txt"); // окрываем файл для записи
    if (out.is_open()){
		cout << "Can't open file for writing!";
        return -1;//Если файл открыть не удалось, завершаем программу
    }
	out << "{\n\"L\": " << L << ",\n\"N\": " << N << ",\n\"Measurements\": [\n";
	for (int i = 0; i < L - 1; i++){
		Measurement ms = new Measurement(createRandomArray(N));
		
		out << ms.toJsonString() << ",\n";
		delete ms;
	}
	Measurement ms = new Measurement(createRandomArray(N));
	
	out << ms.toJsonString() << "\n]\n}";
	delete ms;
	out.close();
	return 0;
}

int* createRandomArray(int size){
	int* array = new int[size];
	for (int i = 0; i < size; i++){
		array[i] = random(MAX);
	}
}

string takeMeasurement(){
	Measurement *ms = new Measurement(createRandomArray(N));
		
	string jsonObject = ms->toJsonString();
	delete ms;
}