// Find duplicates in an array of n numbers in [0, n-1]
// O(n)
//
// Zhenbang Chen

#include <iostream>
#include <vector>
#include <ctime>

using std::vector;

template <typename T>
vector<T> sort_in_place(vector<T>& v){
	auto swap = [](T& a, T& b){
		T tmp = a;
		a = b;
		b = tmp;
	};

	vector<T> duplicates;
	for (size_t i = 0; i < v.size(); ++i)
		while ((int)i != v[i]){
			if (v[i]==v[v[i]]) break;
			swap(v[i],v[v[i]]);
		}

	for (size_t i = 0; i < v.size(); ++i)
		if ((int)i != v[i])
			duplicates.push_back(v[i]);
	return duplicates;
}

template <typename T>
void print(const vector<T>& v){
	for_each(v.begin(),v.end(),[](const T& val){ std::cout << val << ' '; });
	std::cout << '\n';
}

template <typename T>
void print(T t){
	std::cout << t << '\n';
}


int main(){
	srand(std::time(nullptr));
    size_t n;
    std::cin >> n;
    vector<int> v;
    v.reserve(n);
    for (size_t i = 0; i<n; ++i)
    	v.push_back((int)(rand() % n));
    print("source array:");
    print(v);
    print("duplicates:");
    print(sort_in_place(v));
    print("sorted array:");
    print(v);
    return 0;
}
