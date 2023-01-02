#include <cctype>
using namespace std;

class Solution {
public:
    int cnt = 0;
    bool ans = false;

    void check_capital(string word, int start, int end) {
        int mid = start + (end-start)/2;
        if (start==end) {
            if (isupper(word[start])) cnt++;
        } else {
            check_capital(word, start, mid);
            check_capital(word, mid+1, end);
        }
    }

    bool detectCapitalUse(string word) {
        check_capital(word, 0, word.length()-1);
        if (word.length() == cnt) {
            ans = true;
        } else if (cnt == 0) {
            ans = true;
        } else if (cnt == 1 && isupper(word[0])) {
            ans = true;
        } else {
            ans = false;
        }
        return ans;
    }
};
