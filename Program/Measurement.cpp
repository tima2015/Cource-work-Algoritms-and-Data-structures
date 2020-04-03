#include "Measurement.hpp"
#include <timeapi.h>

Measurement::Measurement(int* rowArray, int size) : size(size){
	this->rowArray = new int[size];
	for(int i = 0; i < size; i++)
		this->rowArray[i] = rowArray[i];
}

Measurement::~Measurement(){
	delete[] rowArray;
	delete[] resultArray;
}

void Measurement::begin(){
	beginTime = timeGetTime();
}

void Measurement::end(int* resultArray){
	endTime = timeGetTime();
	this->resultArray = new int[size];
	for(int i = 0; i < size; i++)
		this->resultArray[i] = resultArray[i];
}

int* Measurement::getRowArray() const{
	return rowArray;
}

int* Measurement::getResultArray() const{
	return resultArray;
}

int Measurement::getArraySize() const{
	return size;
}

int Measurement::getBeginTime() const{
	return beginTime;
}

int Measurement::getEndTime() const{
	return endTime;
}

int Measurement::getDeltaTime() const{
	return endTime - beginTime;
}

string Measurement::toJsonString() const{
	string out;
	out += "{\n\"rowArray\": [\n";
	for (int i = 0; i < size - 1; i++){
		out += rowArray[i];
		out += ",\n"
	}
	out += rowArray[size - 1];
	out += "\n],\n\"resultArray\": [\n";
	for (int i = 0; i < size - 1; i++){
		out += resultArray[i];
		out += ",\n"
	}
	out += resultArray[size - 1];
	out += "\n],\n\"size\": ";
	out += size;
	out += ",\n\"beginTime\": ";
	out += beginTime;
	out += ",\n\"endTime\": ";
	out += endTime;
	out += ",\n\"deltaTime\": ";
	out += getDeltaTime();
	out += "\n}";
	return out;
}