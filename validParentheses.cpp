#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string expression) {
        stack<char> st;
        for (int i = 0; i < expression.length(); i++) {
            char ch = expression[i];

            // if opening bracket, push
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                // if closing bracket but stack is empty->check stack top and pop if same
                if (st.empty()) return false;

                char top = st.top();
                if ((ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();  // stack must be empty at the end
    }
};

int main() {
    Solution sol;
    string expr;

    cout << "Enter an expression with brackets: ";
    cin >> expr;

    if (sol.isValid(expr)) {
        cout << "Valid expression " << endl;
    } else {
        cout << "Invalid expression " << endl;
    }

    return 0;
}
