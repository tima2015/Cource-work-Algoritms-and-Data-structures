#include <iostream>
#include <fstream>
#include "Analysis.hpp"

using namespace std;

/**
 * Старт программы выполняющей анализ алгоритмов сортировки
 */
int main(int argc, char **argv) {
   unsigned int N0,N1,L,step;
   //Чтение данных из input.txt
   ifstream in("input.txt");
   if (!in.is_open())
      return EXIT_FAILURE;
   in >> N0 >> N1 >> step >> L;
   in.close();
   
   //Создание файла для записи результатов
   ofstream out(to_string(N0) + "_" +
                to_string(N1) + "_" + to_string(L) + ".txt");
   if (!out.is_open())
      return EXIT_FAILURE;

   //Выполнение тестов
   for (unsigned int N = N0; N <= N1; N += step) {
      cout << N;
      clock_t aBubble = 0;
      clock_t aQuick = 0;
      for (unsigned int i = 0; i < L; i++) {
         Analysis *a = new Analysis(N);
         aBubble += a->getBubbleMeasurement()->getDeltaTime()/L;
         aQuick += a->getQuickMeasurement()->getDeltaTime()/L;
         delete a;
      }
      out << N << " " << aBubble << " " << aQuick << endl;
      cout << " ok\n";
   }
   out.close();
   return 0;
}