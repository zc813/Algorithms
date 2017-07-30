// Two implementations of Quicksort
// One implementation of Heapsort
//
// Zhenbang Chen
// Sat, Jul 29

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;

template<typename T>
void quicksort(vector<T>& nums, size_t lo, size_t hi){
	auto partition = [](vector<T>& v, size_t lo, size_t hi){
		size_t i = lo, j = hi+1;
		T pivot = v[lo];
		while(1){
			do{
				++i;
			} while(i <= hi && v[i] < pivot);

			do{
				--j;
			} while(j > lo && v[j] >= pivot);

			if (i>j) break;

			T temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
		T temp = v[j];
		v[j] = v[lo];
		v[lo] = temp;
		return j;
	};

	if (lo < hi){
		size_t p = partition(nums, lo, hi);
		quicksort(nums, lo, p);
		quicksort(nums, p + 1, hi);
	}
}

template<class It>
void quicksort2(It begin, It end){
	auto partition = [](It b, It e){
		auto pivot = *b;
		It j = b;
		for (It i = b+1; i != e; ++i){
			if (*i < pivot){
				++j;
				auto temp = *i;
				*i = *j;
				*j = temp;
			}
		}
		*b = *j;
		*j = pivot;
		return j;
	};

	if (begin != end){
		It p = partition(begin, end);
		quicksort2(begin, p);
		if(p!=end) quicksort2(p+1, end);
	}
}

template<typename T>
void heapsort(vector<T>& nums){
	auto swap = [&nums](size_t a, size_t b){
		T tmp (nums[a]);
		nums[a] = nums[b];
		nums[b] = tmp;
	};

	std::function<void(size_t,size_t)> SiftDown;
	SiftDown = [&nums, &swap, &SiftDown](size_t index, size_t size){
		size_t child, larger;
		while ((child = index*2+1) < size){
			larger = index;

			if ( nums[index] < nums[child] )
				larger = child;
			if ( child + 1 < size && nums[larger] < nums[child+1] )
				larger = child + 1;
			if ( larger == index )
				break;
			swap(index, larger);
			index = larger;
		}
	};

	for (size_t i = nums.size()/2; i>0; --i)
		SiftDown(i-1, nums.size());
	for (size_t i = nums.size(); i>0; --i){
		swap(0, i-1);
		SiftDown(0, i-1);
	}
}

template<typename T>
void heapsortstl(vector<T>& nums){
	make_heap(nums.begin(), nums.end());
	for (auto iter = nums.end(); iter != nums.begin(); --iter)
		pop_heap(nums.begin(), iter);
}

void getRandomNumbers(vector<int>& v, int num, int lo, int hi){
	v.reserve(num);
	for(int i = 0; i < num; ++i){
		v.push_back(rand() % (hi-lo) + lo);
	}
}

template<class It>
bool compare(It a_begin, It a_end, It b_begin, It b_end){
	while (1){
		if (a_begin == a_end || b_begin == b_end){
			if (a_begin == a_end && b_begin == b_end)
				return true;
			else
				return false;
		}
		if (*a_begin != *b_begin) return false;
		a_begin++;
		b_begin++;
	}
}

int main(){
	vector<int> v;
	int n;
	std::cin >> n;
	getRandomNumbers(v, n, 0, 100);

	vector<int> v1(v);

	sort(v.begin(),v.end());
	//quicksort2(v1.begin(),v1.end());
	// quicksort(v1,0,v1.size()-1);
	heapsortstl(v1);

	std::cout << compare(v.begin(),v.end(),v1.begin(),v1.end());

	return 0;
}
