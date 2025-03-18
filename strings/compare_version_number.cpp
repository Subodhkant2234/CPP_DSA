class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        int i = 0, j = 0;

        while (i < n1 || j < n2) {
            int ver1 = 0, ver2 = 0;
            while (i < n1 && version1[i] != '.') {
                ver1 = ver1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < n2 && version2[j] != '.') {
                ver2 = ver2 * 10 + (version2[j] - '0');
                j++;
            }

            if (ver1 != ver2) {
                return ver1 < ver2 ? -1 : 1;
            }

            i++;
            j++;
        }
        return 0;
    }
};
