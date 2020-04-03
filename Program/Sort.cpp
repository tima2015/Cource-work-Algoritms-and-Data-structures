#include "Sort.hpp"

void bubbleSort(int* array, int n){
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
}

void quicksort(int* array,int first, int last){
	if (first < last){
        int left = first, right = last, middle = array[(left + right) / 2];
        do{
            while (array[left] < middle) left++;
            while (array[right] > middle) right--;
            if (left <= right){
                int tmp = array[left];
                array[left] = array[right];
                array[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(array, first, right);
        qs(array, left, last);
    }
}