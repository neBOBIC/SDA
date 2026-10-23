
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s = "([])";
    stack<char> brackets;
    bool valid = true;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            brackets.push(s[i]);
        } else {
            if (brackets.empty()) {
                valid = false;
                break;
            }

            char last = brackets.top();
            brackets.pop();

            if (s[i] == ')' && last != '(') {
                valid = false;
                break;
            }

            if (s[i] == ']' && last != '[') {
                valid = false;
                break;
            }

            if (s[i] == '}' && last != '{') {
                valid = false;
                break;
            }
        }
    }

    if (!brackets.empty()) {
        valid = false;
    }

    cout << boolalpha << valid << endl;

    return 0;
}
