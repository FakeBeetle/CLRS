#include <iostream>
template <typename T>
void swap(T* p1, T* p2) {
	T intermedia = *p1;
	*p1 = *p2;
	*p2 = intermedia;
}
class Equal_group {
public:
	Equal_group();
	Equal_group(int start, int end) {
		this->start = start;
		this->end = end;
	}
	int start;
	int end;

};

template <typename T>
int partition(T A[], int start, int end) {
	int pivot = A[end];
	int count_equal_numbers = 0;
	int current_pivot_index = 0;
	for (int i = 0; i != end; ++i) {
		if (A[i] == A[end])
			++count_equal_numbers;
		if (A[i] <= A[end]) {
			swap(&A[current_pivot_index], &A[i]);
			++current_pivot_index;
		}
	}
	swap(&A[current_pivot_index], &A[end]);
	return current_pivot_index - count_equal_numbers / 2;
}

template <typename T>
Equal_group partition_new(T A[], int start, int end) {
	int pivot = A[end];
	int count_equal_numbers = 0;
	int current_pivot_index = 0;
	for (int i = 0; i != end; ++i) {
		if (A[i] == A[end])
			++count_equal_numbers;
		if (A[i] <= A[end]) {
			swap(&A[current_pivot_index], &A[i]);
			++current_pivot_index;
		}
	}
	swap(&A[current_pivot_index], &A[end]);
	return Equal_group(current_pivot_index-count_equal_numbers,current_pivot_index);
}

template <typename T>
int random_partition(T A[], int start, int end) {
	int random_index = rand() % (end - start + 1) + start;
	swap(&A[random_index], &A[end]);
	return partition(A, start, end);
}
template <typename T>
void quick_sort(T A[], int start, int end) {// n = end - start + 1
	if (start >= end)
		return;
	//int partition_point = random_partition(A, start, end);
	int partition_point = partition(A, start, end);//cn
	// £\ = (partition_point - start)/n
	quick_sort(A, start, partition_point - 1);//£\n
	quick_sort(A, partition_point + 1, end);//(1-£\)n
}

template <typename T>
void quick_sort_new(T A[], int start, int end) {// n = end - start + 1
	if (start >= end)
		return;
	Equal_group partition_group = partition_new(A, start, end);//cn
	// £\ = (partition_point - start)/n
	quick_sort(A, start, partition_group.start - 1);//£\n
	quick_sort(A, partition_group.end+ 1, end);//(1-£\)n
}

int main() {
	int A[7] = { 2, 5, 9, 3, 7, 0, -1 };
	quick_sort(A, 0, 6);
	for (int i = 0; i != 7; i++)
		std::cout << A[i];
	return 0;
}
/*快速排序的最好情况是
		T(n) = T(q)+T(n-1-q) + θ(n)
		快速排序的最坏情况是
			q = n-1 时
			T(n) = θ(n²)
		最好情况是
			q = floor(n-1/2)
			T(n) = θ(nlgn)
		书上只证明了在T(n)<=cn²时，T(n)的一个上界在q = n - 1时最大，q = floor(n-1/2)时最小，这不能证明q = n-1就是最坏情况,
		but as beginners, we could take it.
*/