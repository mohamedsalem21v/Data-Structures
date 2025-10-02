# Linked List (C++)

A simple singly linked list implementation using templates.

## Features
- Insert at head (`InsertFirst`)
- Append at end (`append`)
- Insert before a value (`InsertBefore`)
- Delete a value (`erase`)
- Search (`found`)
- Count nodes (`count`)
- Print list (`display`)
- Reverse list (`reverse`)

## Quick Example
```cpp
int main() {
    Linkedlist<int> ls;
    ls.InsertFirst(10);        // 10
    ls.append(20);             // 10 -> 20
    ls.InsertFirst(5);         // 5 -> 10 -> 20
    ls.InsertBefore(15, 20);   // 5 -> 10 -> 15 -> 20
    ls.erase(10);              // 5 -> 15 -> 20
    ls.display();              // Output: 5 15 20
    cout << "\n";
    ls.reverse();              // Reverses the list in-place
    ls.display();              // Output: 20 15 5
}
```

## Build
```bash
g++ -std=c++17 LinkedList.cpp -o linkedlist
./linkedlist
```

## Notes
- `InsertFirst` currently takes `int` (can be changed to `T` for full generality).
- `reverse` uses an iterative O(n) time / O(1) extra space algorithm.
