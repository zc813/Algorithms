#include <iostream>
#include <vector>
#include <utility>
using std::cin;
using std::cout;
using std::vector;
using std::swap;

class RotateMatrix{
/*private:
	vector<vector<int>> matrix;
	int getElement(vector<vector<int>>& m, int x, int y){
	    return m[y][x];
	}
	void rotateElement(vector<vector<int>>& m,int size, int x, int y){
	    m[x][size-y-1] = m[y][x];
	    //cout << '(' << x << ',' << y << ") -> (" << size-y-1 << ',' << x << ")\n";
	}
	void rotateElementValue(vector<vector<int>>& m,int size, int x, int y, int value){
	    m[x][size-y-1] = value;
	}*/

public:
	void rotate() {
	    int n = matrix.size();
	    /*for(int row = 0; row < n >>1; ++row){
	    	//cout << "ROTATING ROW " << row;
	        for (int i=row; i<n-row-1; ++i){
	        	//cout << "ROTATING"
	            int temp = getElement(matrix,n-row-1,i);
	            rotateElement(matrix,n,i,row);
	            rotateElement(matrix,n,row,n-i-1);
	            rotateElement(matrix,n,n-i-1,n-row-1);
	            rotateElementValue(matrix,n,n-row-1,i,temp);
	        }
	    }*/
        for(int row = 0; row < n-1; ++row)
            for (int i=0; i<n-row-1; ++i)
                swap(matrix[row][i],matrix[n-i-1][n-row-1]);
        for(int row = 0; row < n >> 1; ++row)
            swap(matrix[row],matrix[n-row-1]);	    
	}

	void ReadData(){
		int n = 1;
		cout << "Input n:"; 
		cin >> n;
		cout << "Input matrix:\n";
		vector<int> row(n);
		for (int i = 0; i< n; ++i){
			for (int j = 0; j<n; ++j)
				cin >> row[j];
			matrix.push_back(row);
		}
	}

	void PrintData(){
		cout << "Rotated:\n";
		int n = matrix.size();
		for (int i = 0; i < n; ++i){
			for (int j = 0; j<n; ++j)
				cout << matrix[i][j] << ' ';
			cout << '\n';
		}
	}
};

int main(){
	RotateMatrix rotate_matrix;
	rotate_matrix.ReadData();
	rotate_matrix.rotate();
	rotate_matrix.PrintData();
}
