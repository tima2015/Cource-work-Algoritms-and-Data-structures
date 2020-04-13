#include <iostream>
#include <conio.h>
#include "Writer.hpp"

//������ ��������� � �������������� ����������������� ���������� � �������
void uiMod();
//
void takeAnalysis(unsigned int N,unsigned int L, unsigned int outformat);

/**
 * ����� ��������� ����������� ������ ���������� ����������
 * ���� ��������� ��������� � �������� ���������� 
 * ������ ������� (argv[1]), ���������� ������ (argv[2]) � ������ ������ (argv[3]),
 * �� ��������� ����������� ��� ������/����� �������.
 * �� ���� ��������� ������� ��������� ��������� ������ ������� �
 * ���-�� ������ � ������� ����������� ����������������� ����������.
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
	std::cout << "������� ������ ������� ��� �������: ";
	std::cin >> N;
	system("cls");
	std::cout << "������� ���������� ������: ";
	std::cin >> L;
	system("cls");
	std::cout << "������� ������:\n1)JSON\n2)TXT\n3)TXT-���������. �� �������������, ��� �������� ���-�� ������";
	std::cout << "\n������� ����� ����������������� ��������: ";
	std::cin >> out_mode;
	system("cls");
	std::cout << "����� ������� ��������� ������������ ���� ���������� ����������.\n"
			  << "��������� ���������:\n������ ������� ��� ���������� " << N
			  << ";\n���������� ������ " << L << ".\n��������� ��������� ������ ���������. "
			  << "���� �� ����� ������� �������� ��� ����� ������ ����� ���������� �����!";
	takeAnalysis(N,L, out_mode);
	system("cls");
	std::cout << "������ ��������� ������� ���������!\n������� ����� ������� ��� ������";
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