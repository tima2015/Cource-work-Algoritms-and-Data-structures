#include "Measurement.hpp"
#include <random>

#define MAX 999999999 //Максимально возможное сгенерированное число

Measurement::Measurement(unsigned int size) : size(size) {
	static std::default_random_engine dre(time(0));
	array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = dre() % MAX;
	}
}

Measurement::Measurement(const Measurement &orig){
	size = orig.size;
	array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = orig.array[i];
	}
}

Measurement::~Measurement() {
	delete[] array;
}

void Measurement::begin() {
	beginTime = clock();
}

void Measurement::end() {
	endTime = clock();
}

int* Measurement::getArray() const{
	return array;
}

clock_t Measurement::getDeltaTime() const {
	return endTime - beginTime;
}
