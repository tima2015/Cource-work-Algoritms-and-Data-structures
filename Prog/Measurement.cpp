#include "Measurement.hpp"
#include <random>

#define MAX 999999999 //Максимально возможное сгенерированное число

Measurement::Measurement(unsigned int size) : size(size) {
	static std::default_random_engine dre(time(0));
	array = new int[size];
	rowArray = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = rowArray[i] = dre() % MAX;
	}
}

Measurement::Measurement(const Measurement &orig){
	size = orig.size;
	array = new int[size];
	rowArray = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = orig.array[i];
		rowArray[i] = orig.array[i];
	}
}

Measurement::~Measurement() {
	delete[] array;
	delete[] rowArray;
}

void Measurement::begin() {
	beginTime = clock();
}

void Measurement::end() {
	endTime = clock();
}

int *Measurement::getRowArray() const {
	return rowArray;
}

int* Measurement::getArray() const{
	return array;
}

unsigned int Measurement::getArraySize() const {
	return size;
}

clock_t Measurement::getBeginTime() const {
	return beginTime;
}

clock_t Measurement::getEndTime() const {
	return endTime;
}

clock_t Measurement::getDeltaTime() const {
	return endTime - beginTime;
}
