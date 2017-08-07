// String Matching
// KMP & BM

#include <iostream>
#include <cstdlib>

// hashmap is used for BM. If characters from input are limited, hashmaps can be replaced by arrays.
#include <unordered_map>

const size_t LEN_TEXT = 10000;
const size_t LEN_FIND = 1000;
const size_t MAX_RESULT_NUM = 100;

template<typename T>
void print(T *array, char *s, size_t max_len){
	std::cout << s;
	for ( ; max_len > 0; --max_len){
		std::cout << *array << '\n';
		++array;
	}
}

template<typename T>
void printUntil(T *array, char *s, T delimiter){
	std::cout << s;
	while (*array != delimiter){
		std::cout << *array << '\n';
		++array;
	}
}

size_t getLen(char *s){ size_t len; for(len=0; s[len]!='\0'; ++len); return len;}

template<typename T>
T max(T a, T b){
	return a>b?a:b;
}

size_t *KMP_prep(char *find){
	//auto getLen = [](char *s){ size_t len; for(len=0; s[len]!='\0'; ++len); return len;};
	size_t find_len = getLen(find);
	size_t *prep = new size_t[find_len];
	prep[0] = 0;
	for (size_t i = 2, j = 0; i < find_len; ){
		if (find[i-1]==find[j]){
			prep[i] = j+1;
			++i;
			++j;
		} else if (j == 0){
			prep[i] = j;
			++i;
		} else {
			j = prep[j];
		}
	}
	for (size_t i = 0; i < find_len; ++i)
		if (find[i] == find[prep[i]])
			prep[i] = prep[prep[i]];
	return prep;
}

int *KMP(char *text, char *find, size_t max_result_num = 20){
	size_t *prep = KMP_prep(find);
	// matching
	int *results = new int[max_result_num];
	size_t result_num = 0;
	for(size_t i = 0, j = 0; text[i] != '\0'; ++i){
		if (text[i] == find[j]){
			if (find[j+1] == '\0'){
				results[result_num++] = i-j;
				if (j == prep[j]) ++i;
				else j = prep[j];
			} else {
				++i;
				++j;
			}
		} else if (j == 0){
			while (j > 0) j = prep[j];
			++i;
		} else {
			j = prep[j];
		}
	}
	results[result_num] = -1;
	delete [] prep;
	return results;
}

int *BM(char *text, char *find, size_t max_result_num = 20){
	int *results = new int[max_result_num+1];
	size_t result_num = 0;
	results[0] = -1;

	size_t m = getLen(find), n = getLen(text);
	if (m>n) return results;

	// bad-character preprocessing
	std::unordered_map<char, size_t> hashmap;
	int *prevs = new int[m];
	for (size_t i = 0; i<m; ++i){
		if (hashmap.count(find[i]))
			prevs[i] = hashmap[find[i]];
		else
			prevs[i] = -1;
		hashmap[find[i]] = i;
	}
	print(prevs, "Prevs:\n", m);


	// good-suffix-preprocessing
	int i = m - 1, j = prevs[i];
	int *gs = new int[m];
	int min_pos = m;
	for (int i = 0; i < m; ++i) gs[i] = -1;
	while (j>=0 && i >=0){
		if (find[i] == find[j]){
			if (j>gs[i]) gs[i] = j;
			if (min_pos > i) min_pos = i;
			--i; --j;
		} else {
			int tmp = i;
			while (tmp >= j)
				tmp = prevs[tmp];
			if (tmp<0) break;
			j = tmp + m - 1 - i;
			i = m - 1;
		}
	}
	for (i = min_pos -1; i>=0; --i)
		gs[i] = i - min_pos;
	print(gs, "Good Suffices:\n", m);


	// BM matching
	j = m-1; i = m-1;
	while (i < n && result_num < max_result_num){
		if (text[i] == find[j]){
			--i;
			--j;
		} else {
			int tmp = -1;
			if (hashmap.count(text[i])){
				tmp = hashmap[text[i]];
				while (tmp >= j)
					tmp = prevs[tmp];
			}
			if (j < m-1 && tmp < gs[j+1] - 1) tmp = gs[j+1] - 1;
			i += m - 1 - tmp; //???
			j = m - 1;
		}
		if (j<0){
			// found
			results[result_num++] = i+1;
			// find next
			i += m+1;
			j = m-1;
		}
	}

	delete [] prevs;
	delete [] gs;

	results[result_num] = -1;
	return results;
}

int main(){
	std::cout << "Text:\n";
	char a[LEN_TEXT];
	std::cin.getline(a, LEN_TEXT);
	std::cout << "Find:\n";
	char b[LEN_FIND];
	std::cin.getline(b, LEN_FIND);
	int *res = BM(a, b, MAX_RESULT_NUM);
	printUntil(res,"--------\nResult:\n", -1);
	delete [] res;
	return 0;
}
