// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

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
