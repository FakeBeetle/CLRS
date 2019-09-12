#include <iostream>
template <typename T>
void swap(T* p1, T* p2) {
	T intermedia = *p1;
	*p1 = *p2;
	*p2 = intermedia;
}


template <typename T>
int partition(T A[], int start, int end) {
	int standard = A[end];
	int current_small_index = 0;
	for (int i = 0; i != end; ++i) {
		if (A[i] < A[end]) {
			swap(&A[current_small_index], &A[i]);
			++current_small_index;
		}
	}
	swap(&A[current_small_index], &A[end]);
	return current_small_index;
}
template <typename T>
void quick_sort(T A[], int start, int end) {// n = end - start + 1
	if (start >= end)
		return;
	int partition_point = partition(A, start, end);//cn
	// £\ = (partition_point - start)/n
	quick_sort(A, start, partition_point - 1);//£\n
	quick_sort(A, partition_point + 1, end);//(1-£\)n
}
//test example
int main() {
	int A[7] = { 2, 5, 9, 3, 7, 0, -1 };
	quick_sort(A, 0, 6);
	for (int i = 0; i != 7; i++)
		std::cout << A[i];
	return 0;
}
