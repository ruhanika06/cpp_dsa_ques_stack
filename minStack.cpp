#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<pair<int,int>> s; // {value, minSoFar}

    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
        } else {
            int minVal = (val < s.top().second) ? val : s.top().second;
            s.push({val, minVal});
        }
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
        } else {
            cout << "Stack is empty!\n";
        }
    }

    int top() {
        if (!s.empty()) return s.top().first;
        cout << "Stack is empty!\n";
        return -1;
    }

    int getMin() {
        if (!s.empty()) return s.top().second;
        cout << "Stack is empty!\n";
        return -1;
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    MinStack ms;
    int choice, val;

    while (true) {
        cout << "\n=== Min Stack Menu ===\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Get Min\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                ms.push(val);
                cout << val << " pushed.\n";
                break;

            case 2:
                ms.pop();
                break;

            case 3:
                cout << "Top element = " << ms.top() << endl;
                break;

            case 4:
                cout << "Minimum element = " << ms.getMin() << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
