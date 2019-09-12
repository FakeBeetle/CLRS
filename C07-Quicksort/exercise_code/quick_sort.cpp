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
	int count_of_equal_numbers = 0;
	int current_small_index = 0;
	for (int i = start; i != end; ++i) {
		if (A[i] == A[end])
			++count;//这个计数保证了在等于standard的元素较多时，能返回这些相同元素的中间位置下标
		if (A[i] <= A[end]) {
			swap(&A[current_small_index], &A[i]);
			++current_small_index;
		}
	}
	swap(&A[current_small_index], &A[end]);
	return current_small_index-count_of_equal_numbers/2;//
}

template <typename T>
void quick_sort(T A[], int start, int end) {// n = end - start + 1
	if (start >= end)
		return;
	int partition_point = partition(A, start, end);//cn
	// α = (partition_point - start)/n
	quick_sort(A, start, partition_point - 1);//αn
	quick_sort(A, partition_point + 1, end);//(1-α)n

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
