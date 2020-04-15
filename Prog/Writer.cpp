#include "Writer.hpp"
#include <ctime> //void DetailTxtWriter::write(Analysis *a) -- CLOCKS_PER_SEC

JsonWriter::JsonWriter(unsigned int N, unsigned int L) : L(L){
	outfile.open(std::to_string(N) + "_" + std::to_string(L) + ".json");
	if(!outfile.is_open())
		exit(EXIT_FAILURE);
	outfile << "{\n\t\"N\" : " << N << ",\n\t\"L\" : " << L << ",\n\t\"Measurements\": [\n";
}

JsonWriter::~JsonWriter(){
	outfile << "\t]\n}";
	outfile.close();
}

void JsonWriter::write(Analysis *a){
	outfile << "\t\t{ \"bubble\" : " << a->getBubbleMeasurement()->getDeltaTime()
			<< ", \"quick\" : " << a->getQuickMeasurement()->getDeltaTime() << "}";
	if (i++ < L)
		outfile << ',';
	outfile << '\n';
}

TxtWriter::TxtWriter(unsigned int N, unsigned int L){
	outfile.open(std::to_string(N) + "_" + std::to_string(L) + ".txt");
	if(!outfile.is_open())
		exit(EXIT_FAILURE);
	outfile << N << " " << L << "\n";
}

TxtWriter::~TxtWriter(){
	outfile.close();
}

void TxtWriter::write(Analysis *a){
	outfile << a->getBubbleMeasurement()->getDeltaTime() << " "
			<< a->getQuickMeasurement()->getDeltaTime() << "\n";
}

DetailTxtWriter::DetailTxtWriter(unsigned int N, unsigned int L) : N(N), L(L){
	outfile.open(std::to_string(N) + "_" + std::to_string(L) + ".txt");
	if(!outfile.is_open())
		exit(EXIT_FAILURE);
	outfile << "Размер массива " << N << ".\tКоличество тестов " << L << ".\n\n";
}

DetailTxtWriter::~DetailTxtWriter(){
	outfile.close();
}

void DetailTxtWriter::write(Analysis *a){
	outfile << "--------------------[" << i++ << '/' << L << "]--------------------\n"
			<< "Сортировка пузырьком.\nВремя(такты): " << a->getBubbleMeasurement()->getDeltaTime()
			<< "\nВремя(секунды): " << a->getBubbleMeasurement()->getDeltaTime()/CLOCKS_PER_SEC
			<< "\n----------Массив до сортировки----------\n";
	printArray(a->getBubbleMeasurement()->getRowArray());
	outfile << "\n----------Отсортированый массив----------\n";
	printArray(a->getBubbleMeasurement()->getArray());
	outfile << "\n--------------------------------------------------"
			<< "\nБыстрая сортировка Хоара.\nВремя(такты): " 
			<< a->getQuickMeasurement()->getDeltaTime() << "\nВремя(секунды): "
			<< a->getQuickMeasurement()->getDeltaTime()/CLOCKS_PER_SEC 
			<< "\n----------Массив до сортировки----------\n";
	printArray(a->getQuickMeasurement()->getRowArray());
	outfile << "\n----------Отсортированый массив----------\n";
	printArray(a->getQuickMeasurement()->getArray());
	outfile << "\n\n\n\n";
}

void DetailTxtWriter::printArray(int* array){
	int temp = N-1;
	for(int i = 0; i < temp; i++){
		outfile << array[i] << ',';
	}
	outfile << array[temp];
}
