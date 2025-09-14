#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) { cout << "Stack empty!\n"; return; }
        q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() { return q.empty(); }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl;
    return 0;
}
