// 这个没有过测试，因为测试 case 不合理

class Solution {
private:
    vector<vector<int>> dfa = // deterministic finite autonoma
        {{0,1,3,2,-1,-1},
         {-1,-1,3,2,-1,-1},
         {7,-1,3,2,-1,8},
         {-1,-1,-1,4,-1,-1},
         {7,-1,-1,4,5,8},
         {-1,-1,-1,6,-1,-1},
         {7,-1,-1,6,-1,8},
         {7,-1,-1,-1,-1,8}};
public:
    bool isNumber(const string& s) {
        int op = -1;
        int stat = 0;
        for (char c:s){
            switch(c){
                case ' ':
                    op = 0;
                    break;
                case '+': case '-':
                    op = 1;
                    break;
                case '.':
                    op = 2;
                    break;
                case 'e': case 'E':
                    op = 4;
                    break;
                default:
                    if (c >='0' && c<='9')
                        op = 3;
                    else
                        return false;
            }
            stat = dfa[stat][op];
            if (stat == -1) return false;
        }
        stat = dfa[stat][5];
        if (stat == 8) return true;
        return false;
    }
};
