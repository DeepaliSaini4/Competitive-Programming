class Solution {
public:
    int base = 100000;
    int repeatedStringMatch(string a, string b) {
        if (a == b)
            return 1;
        int count = 1;
        string source = a;
        while (source.size() < b.size()) {
            count++;
            source += a;
        }
        if (source == b)
            return count;
        if (rabin_karp(source, b) != -1)
            return count;
        if (rabin_karp(source + a, b) != -1)
            return count + 1;
        return -1;
    }
    int rabin_karp(string source, string target) {
        if (source == "" || target == "")return -1;
        int m = target.size();
        int power = 1;
        for (int i = 0; i < m; i++) {
            power = (power * 31) % base;
        }
        int targetcode = 0;
        for (int i = 0; i < m; i++) {
            targetcode = (targetcode * 31 + target[i]) % base;
        }
        int hashCode = 0;
        for (int i = 0; i < source.size(); i++) {
            hashCode = (hashCode * 31 + source[i]) % base;
            if (i < m - 1)
                continue;
            if (i >= m) {
                hashCode = (hashCode - source[i - m] * power) % base;
            }
            if (hashCode < 0)
                hashCode += base;
            if (hashCode == targetcode) {
                if (source.substr(i - m + 1, m) == target)
                    return i - m + 1;
            }
        }
        return -1;
    }
};
