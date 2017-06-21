// AT W5 Dynamic Programming
// Editing Distance
// 
// Zhenbang Chen
// Wed, Jun 21, 2017

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
	int len1 = str1.size(), len2 = str2.size();
	int v[len1+1][len2+1];
	auto min = [&] (int a, int b, int c){
		int tmp = (a<b)?a:b;
		return (tmp<c)?tmp:c;
	};
	for (int i = 0; i <= len1; ++i)
		v[i][0] = i;
	for (int j = 0; j <= len2; ++j)
		v[0][j] = j;
	for (int i = 1; i <= len1; ++i)
		for (int j = 1; j <= len2; ++j){
			int v1 = v[i-1][j-1] + (str1[i-1] == str2[j-1]? 0: 1);
			//int v2 = 500, v3 = 500;
			//if (i>=2 && str1[i-2] == str2[j-1]) v2 = v[i-1][j] + 1; this condition is wrong
			//if (j>=2 && str1[i-1] == str2[j-2]) v3 = v[i][j-1] + 1; think about a abc
			int v2 = v[i-1][j] + 1;
			int v3 = v[i][j-1] + 1;			
			v[i][j] = min(v1,v2,v3);
		}
	return v[len1][len2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
