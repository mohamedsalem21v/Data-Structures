# Stack (C++)

A simple generic (templated) stack implementation backed by a singly linked list.

## Features
- Push item onto stack (`push`)
- Pop top item (`pop`)
- View top item (`peek`)
- Check if stack is empty (`empty`)
- Linear search for a value (`found`)
- Print stack contents from top to bottom (`display`)

## Quick Example
Only the usage (main) is shown here—implementation lives in `stack_implementation.cpp`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    MyStack<int> st;

    st.push(10);          // Stack: 10 (top)
    st.push(20);          // Stack: 20 -> 10
    st.push(30);          // Stack: 30 -> 20 -> 10

    cout << "Top (peek): " << st.peek() << "\n";  // 30

    st.pop();             // removes 30
    cout << "After pop: ";
    st.display();         // 20 10
    cout << "\n";

    cout << "Found 10? " << (st.found(10) ? "Yes" : "No") << "\n";
    cout << "Found 99? " << (st.found(99) ? "Yes" : "No") << "\n";

    while (!st.empty()) st.pop();
    cout << "Empty? " << (st.empty() ? "Yes" : "No") << "\n";
    return 0;
}
```

### Expected Output (example)
```
Top (peek): 30
After pop: 20 10
Found 10? Yes
Found 99? No
Empty? Yes
```

## Build
```bash
g++ -std=c++17 stack_implementation.cpp -o stack
./stack
```

## Complexity
- push: O(1)
- pop: O(1)
- peek: O(1)
- found: O(n)
- display: O(n)
- space: O(n) (one node per element)

## Notes
- Backed by a singly linked list (no fixed capacity).
- No destructor implemented; remaining nodes are not freed automatically if the program ended earlier—safe for short-lived programs, but you can add one for completeness.
- `peek()` assumes the stack is not empty; add a guard or exception if desired.
- Uses dynamic allocation per pushed element.
