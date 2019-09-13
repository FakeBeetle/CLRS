#include <iostream>
template<typename T>
void swap(T* p1, T* p2) {
	T inter = *p1;
	*p1 = *p2;
	*p2 = inter;
}
template<typename T>
int Hoare_partition(T A[], int start, int end) {
	T pivot = A[start];
	int i = start;
	int j = end;
	while (1) {
		while (A[j] > pivot)
			--j;
		while (A[i] < pivot)
			++i;
		//循环不变式A[start..i-1]<pivot A[j+1..end]>pivot
		//此时A[i]>=pivot,A[j]<=pivot,i不可能大于j,否则pivot既不存在于A[start..i-1]，又不存在于A[j+1..end]
		if (i < j)
			swap(&A[i], &A[j]);//交换，那么A[start..i]<=pivot<=A[j..end]
		else
			return j;
	}
	
}

template<typename T>
void Hoare_quick_sort(T A[], int start, int end) {
	if (start >= end)
		return;
	int partition_point = Hoare_partition(A, start, end);
	Hoare_quick_sort(A, start, partition_point - 1);
	Hoare_quick_sort(A, partition_point + 1, end);
}
int main() {
	int A[10] = { 4,2,3,4,5,6,4,7,9,10};//在含有相同元素时，Hoare算法可能陷入死循环
	Hoare_quick_sort(A, 0, 9);
	for (int i = 0; i != 10; ++i)
		std::cout << A[i];
	return 0;
}