#include <iostream>
int second_minimum(int* A,int n) {


}



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
	int count_equal_numbers = 0;
	int current_small_index = 0;
	for (int i = 0; i != end; ++i) {
		if (A[i] == A[end])
			++count_equal_numbers;
		if (A[i] <= A[end]) {
			swap(&A[current_small_index], &A[i]);
			++current_small_index;
		}
	}
	swap(&A[current_small_index], &A[end]);
	return current_small_index - count_equal_numbers / 2;
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
	int partition_point = random_partition(A, start, end);//cn
	// £\ = (partition_point - start)/n
	quick_sort(A, start, partition_point - 1);//£\n
	quick_sort(A, partition_point + 1, end);//(1-£\)n
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

int minimum(int* A,int n) {
	int res = A[0];
	for (int i = 0; i != n; ++i)
			if (A[i] < res)
				res = A[i];
	return res;
}

int maximum(int* A, int n) {
	int res = A[0];
	for (int i = 0; i != n; ++i)
		if (A[i] > res)
			res = A[i];
	return res;
}

int random_select(int A[], int start, int end, int order) {
	/*
		This algorithm partition the given set to three subsets, one of which is the pivot,
		another one in which the elements are smaller than the pivot, and the other one in which 
		all elements are larger than the pivot. If the random partition generates a lucky number that 
		is just the order we want to find, the function returns the corresponding elem
	*/
	if (start == end) {
		return A[start];
	}
	int mid = random_partition(A, start, end);
	int size = mid - start + 1;
	if (order == size)
		return A[mid];
	else if (order < size)
		return random_select(A, start, mid - 1, order);//low district
	else
		return random_select(A, mid + 1, end, order-size);//high district  

}

template<typename T>
int partition_for_groups(T A[], int start, int end) {
	int standard = A[end];
	int count_equal_numbers = 0;
	int current_small_index = 0;
	for (int i = 0; i != end; ++i) {
		if (A[i] == A[end])
			++count_equal_numbers;
		if (A[i] <= A[end]) {
			swap(&A[current_small_index], &A[i]);
			++current_small_index;
		}
	}
	swap(&A[current_small_index], &A[end]);
	return current_small_index - count_equal_numbers / 2;
}
int select(int A[], int start, int end, int order) {
	int* pmedian = new int[];
	int num_of_groups = (end - start + 1) / 5 + (int)(bool)((end - start + 1) % 5);
	for (int i = 0; i != num_of_groups; ++i) {
		insertion_sort(A, start + 5 * i, start5*i + 4);
	}
	for (int i = 0; i != num_of_groups; ++i) {
		pmedian[i] = A[start + 5 * i + 2];
	}
	select(pmedian, 0, num_of_groups - 1, order);


}

int main() {
	return 0; 
}
