// Length of Last Word

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int id = s.length() - 1;
        int len = 0;

        while (id >= 0 && s[id] == ' ')
            id--;

        while (id >= 0 && s[id] != ' ') {
            len++;
            id--;
        }

        return len;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    int result = obj.lengthOfLastWord(s);
    cout << "Length of last word: " << result << endl;

    return 0;
}