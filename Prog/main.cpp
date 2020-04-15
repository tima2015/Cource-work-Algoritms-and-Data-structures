#include <iostream>
#include <conio.h>
#include "Writer.hpp"

//Работа программы с использованием пользовательского интерфейса в консоли
void uiMod();
//
void takeAnalysis(unsigned int N,unsigned int L, unsigned int outformat);

/**
 * Старт программы выполняющей анализ алгоритмов сортировки
 * Если программе передаётся в качестве аргументов 
 * размер массива (argv[1]), количество тестов (argv[2]) и формат вывода (argv[3]),
 * то программа выполняется без вывода/ввода консоли.
 * Во всех остальных случаях программа считывает размер массива и
 * кол-во тестов с помошью консольного пользовательского интерфейса.
 */
int main(int argc, char** argv){
	if(argc != 4)
		uiMod();
	else
		takeAnalysis(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	return 0;
}

void uiMod(){
	unsigned int N,L,out_mode;
	std::cout << "Введите размер массива для анализа: ";
	std::cin >> N;
	system("cls");
	std::cout << "Введите количество тестов: ";
	std::cin >> L;
	system("cls");
	std::cout << "Форматы вывода:\n1)JSON\n2)TXT\n3)TXT-Подробный. Не рекомендуется, для большого кол-ва тестов";
	std::cout << "\nВведите номер предпочтительного варианта: ";
	std::cin >> out_mode;
	system("cls");
	std::cout << "Начат процесс сравнения эффекивности двух алгоритмов сортировки.\n"
			  << "Выбранные параметры:\nРазмер массива для сортировки " << N
			  << ";\nКоличество тестов " << L << ".\nПодождите окончания работы программы. "
			  << "Если вы ввели большие значения это может занять более нескольких часов!";
	takeAnalysis(N,L, out_mode);
	system("cls");
	std::cout << "Работа программы успешно завершена!\nНажмите любую клавишу для выхода";
	getch();
}

#define JSON_WRITER       1
#define TXT_WRITER        2
#define DETAIL_TXT_WRITER 3
void takeAnalysis(unsigned int N,unsigned int L, unsigned int outformat){
	Writer *w;
	switch(outformat){
		case JSON_WRITER:
			w = new JsonWriter(N,L);
			break;
		case TXT_WRITER:
			w = new TxtWriter(N,L);
			break;
		case DETAIL_TXT_WRITER:
			w = new DetailTxtWriter(N,L);
			break;
		default:
			exit(EXIT_FAILURE);
	}
	for(unsigned int i = 0; i < L; i++){
		Analysis *a = new Analysis(N);
		w->write(a);
		delete a;
	}
	delete w;
}