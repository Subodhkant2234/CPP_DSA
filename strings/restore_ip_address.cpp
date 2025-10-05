class Solution {
public:
    /*
        bool isValid(const string& s) {
            if (s.empty() || s.size() > 3)
                return false;
            if (s[0] == '0' && s.size() > 1)
                return false; // No leading zeros
            int num = stoi(s);
            return num >= 0 && num <= 255;
        }
        vector<string> restoreIpAddresses(string s) {
            // code here
            vector<string> res;
            int n = s.size();

            // Try all combinations of 3 dots in the string
            for (int i = 1; i < min(n, 4); i++) {
                for (int j = i + 1; j < min(n, i + 4); j++) {
                    for (int k = j + 1; k < min(n, j + 4); k++) {
                        if (k >= n)
                            continue;

                        string s1 = s.substr(0, i);
                        string s2 = s.substr(i, j - i);
                        string s3 = s.substr(j, k - j);
                        string s4 = s.substr(k);

                        if (isValid(s1) && isValid(s2) && isValid(s3) &&
                            isValid(s4)) {
                            res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                        }
                    }
                }
            }
            return res;
        }
    */
    bool isValid(const string& s) {
        if (s.empty() || s.size() > 3)
            return false;
        if (s[0] == '0' && s.size() > 1)
            return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    void backtrack(string& s, int start, int dots, string path,
                   vector<string>& res) {
        if (dots == 3) {
            string last = s.substr(start);
            if (isValid(last)) {
                res.push_back(path + last);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (start + len >= s.size())
                break;
            string part = s.substr(start, len);
            if (isValid(part)) {
                backtrack(s, start + len, dots + 1, path + part + ".", res);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() < 4 || s.length() > 12)
            return res;
        backtrack(s, 0, 0, "", res);
        return res;
    }
};
