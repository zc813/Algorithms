// longest common subsequence

#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cin;
using std::cout;

int main(){
  // input
	string a,b;
	cin >> a >> b;
	if (a.size() > b.size()) swap(a,b);

	int max = 0, max_i = 0, max_j = 0;
	vector<int> v(a.size()+1,0);
	for (int j = 0; j<b.size(); ++j)
		for (int i = a.size()-1; i >= 0; --i){
			if (a[i] == b[j])
				v[i+1] = v[i] + 1;
			else
				v[i+1] = 0;
			if (v[i+1] > max){
				max = v[i+1];
				max_i = i;
				max_j = j;
			}
		}

  // output
	if (max > 0){
		string output;
		output.append(max_i - max + 1, ' ');
		output.append(max, '\'');
		output.append(a.size()-max_i+max_j-max+1 ,' ');
		output.append(max,'\'');

		cout << "------\n";
		cout << a << ' ' << b << '\n';
		cout << output <<'\n';
		cout << "Longest Common Subsequence: (" << max << ")\n";
	} else
		cout << "------\nNo Common Subsequence!\n";
	
	return 0;
}
