#include <iostream>
template<typename T>
void swap(T* p1, T* p2) {
	T intermedia = *p1;
	*p1 = *p2;
	*p2 = intermedia;
}
class Interval {
public:
	Interval(int left, int right) {
		this->left = left;
		this->right = right;
	}
	int left;
	int right;
	friend bool operator>(Interval interval1, Interval interval2) {
		return interval1.left > interval2.right;
	}
	friend bool operator<(Interval interval1, Interval interval2) {
		return interval1.right < interval2.left;
	}
	friend bool operator==(Interval interval1, Interval interval2) {
		return (interval1.right-interval2.left)*(interval1.left-interval2.right)<=0;
	}
	friend bool operator>=(Interval interval1, Interval interval2) {
		return interval1 > interval2||interval1==interval2;
	}
	friend bool operator<=(Interval interval1, Interval interval2) {
		return interval1 < interval2 || interval1 == interval2;
	}
};

class Overlapped_Intervals {
public:
	Overlapped_Intervals();
	Overlapped_Intervals(int start, int end) {
		this->start = start;
		this->end = end;
	}
	int start;
	int end;

};
template<typename T>
Overlapped_Intervals partition_intervals(T A[], int start, int end) {
	T pivot = A[end];
	int count_overlapped_intervals = 0;
	int current_pivot_index = 0;
	for (int i = 0; i != end; ++i) {
		if (A[i] == A[end])
			++count_overlapped_intervals;
		if (A[i] <= A[end]) {
			swap(&A[current_pivot_index], &A[i]);
			++current_pivot_index;
		}
	}
	swap(&A[current_pivot_index], &A[end]);
	return Overlapped_Intervals(count_overlapped_intervals, current_pivot_index);
}
void fuzzy_sort(Interval A[],int start,int end) {
	if (start >= end)
		return;
	Overlapped_Intervals partition_interval_group = partition_intervals(A, start, end);
	fuzzy_sort(A, start, partition_interval_group.start-1);
	fuzzy_sort(A, partition_interval_group.start + 1,end);
}
int main() {
	return 0;
}