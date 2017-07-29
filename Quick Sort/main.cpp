// Two implementations of quicksort
//
// Zhenbang Chen
// Sat, Jul 29

#include <iostream>
#include <vector>
#include <algorithm>

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
	quicksort(v1,0,v1.size()-1);

	std::cout << compare(v.begin(),v.end(),v1.begin(),v1.end());

	return 0;
}
