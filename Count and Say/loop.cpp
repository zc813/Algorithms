class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i=1;i<n;++i){
            string res = "";
            while (!str.empty()){
                char digit = str.back();
                int times = 0;
                for (;digit == str.back(); str.pop_back(), ++times);
                res = to_string(times) + digit + res;
            }
            str = res;
        }
        return str;
    }
};
