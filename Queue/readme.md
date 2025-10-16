# Queue (C++)

A simple queue implementation backed by a linked list.

## Features
- Enqueue item (`EnQueue`)
- Dequeue item (`DeQueue`) 
- View front item (`frontValue`)
- View back item (`backValue`)
- Check if queue is empty (`empty`)
- Search for a value in the queue (`found`)
- Count elements in the queue (`count`)
- Display queue contents from front to back (`display`)

## Quick Example
Implementation is available in `Queue.cpp`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    MyQueue q;

    q.EnQueue(10);        // Queue: 10 (front and back)
    q.EnQueue(20);        // Queue: 10 (front) -> 20 (back)
    q.EnQueue(30);        // Queue: 10 (front) -> 20 -> 30 (back)

    cout << "Front element: " << q.frontValue() << endl;  // 10
    cout << "Back element: " << q.backValue() << endl;    // 30

    cout << "Queue elements: ";
    q.display();          // 10 20 30

    q.DeQueue();          // removes 10
    cout << "After DeQueue: ";
    q.display();          // 20 30

    cout << "Found 20? " << (q.found(20) ? "Yes" : "No") << endl;
    cout << "Found 50? " << (q.found(50) ? "Yes" : "No") << endl;
    
    cout << "Number of elements: " << q.count() << endl;

    while (!q.empty()) q.DeQueue();
    cout << "Empty? " << (q.empty() ? "Yes" : "No") << endl;
    return 0;
}
```

### Expected Output (example)
```
Front element: 10
Back element: 30
Queue elements: 10 20 30
After DeQueue: 20 30
Found 20? Yes
Found 50? No
Number of elements: 2
Empty? Yes
```
