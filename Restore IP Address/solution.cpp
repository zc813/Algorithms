class Solution {
private:
    const int max_value = 255;
    const int max_length = 3;
    const bool multiple_zero = false;
    int len = 0;
    string s_;
    vector<string> parseIp(int section_num, int start_index){
        // condition of termination
        if (section_num <= 0 && start_index == len) return {""};
        if (len-start_index < section_num ||  len-start_index > max_length * section_num) return {};
        
        vector<string> result;
        vector<string> children;
        for (int l = 1; l <= max_length; ++l){
            // get section
            string section = s_.substr(start_index, l);
            
            // validation
            int value = stoi(section);
            if (value > max_value) continue;
            if (value == 0 && !(multiple_zero || section.size() == 1)) continue;
            if (value > 0 && section[0] == '0' && !multiple_zero) continue;
            
            // combination
            children = parseIp(section_num - 1 ,start_index + l);
            for (string child : children){
                if (child == "") result.push_back(section);
                else result.push_back(section + '.' + child);
            }
        }
        return result;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        s_ = s;
        len = s_.size();
        if (len > 12 || len < 4) return {};
        return parseIp(4,0);
    }
};
