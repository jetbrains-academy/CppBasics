In C++, iterators are classified into several categories based on their capabilities and behaviors. These categories are important to understand as different STL containers provide different categories of iterators. They include:
1. **Input Iterators**: supports reading values from the pointed-to elements. Once read, the iterator can be incremented to point to the next element.
2. **Output Iterators**: supports writing values to the pointed-to elements. Once written, the iterator can be incremented to point to the next element.
3. **Forward Iterators**: combines the features of both input and output iterators. Allows multiple passes through a range and supports both read and write operations.
4. **Bidirectional Iterators**: enhances forward iterators by adding the ability to move backward through a range using the `--` operator.
5. **Random Access Iterators**: the most feature-rich iterators, providing constant time access to any element in the range, arithmetic operations, and pointer-like behavior.

Here's a simplified comparison table of iterator categories:

| Category      | Read | Write | Forward | Backward | Random Access |
|---------------|------|-------|---------|----------|---------------|
| Input         | Yes  | No    | Yes     | No       | No            |
| Output        | No   | Yes   | Yes     | No       | No            |
| Forward       | Yes  | Yes   | Yes     | No       | No            |
| Bidirectional | Yes  | Yes   | Yes     | Yes      | No            |
| Random Access | Yes  | Yes   | Yes     | Yes      | Yes           |

Iterators can be invalidated by certain operations performed on the container it is tied to. Understanding iterator invalidation is crucial to avoid undefined behavior. Common scenarios leading to iterator invalidation are:
- **Insertion and Deletion**: inserting or deleting elements in the container may invalidate iterators pointing to the modified elements.
- **Resizing the Container**: resizing operations may cause reallocation, leading to the invalidation of all iterators.
- **Clearing the Container**: clearing the container invalidates all iterators pointing to its elements.

For more cases, please refer to this [article](http://kera.name/articles/2011/06/iterator-invalidation-rules-c0x/).

Different STL containers provide different categories of iterators. Here's a mapping of each discussed STL container to the category of iterator it provides, and the invalidation rules for this container:

| Container     | Iterator Category | Invalidation Rules               |
|---------------|-------------------|----------------------------------|
| vector        | Random Access     | Insertion, deletion, resizing    |
| string        | Random Access     | Insertion, deletion, resizing    |
| list          | Bidirectional     | None                             |
| deque         | Random Access     | Insertion, deletion at both ends |
| stack         | N/A               | N/A                              |
| queue         | N/A               | N/A                              |
| set           | Bidirectional     | Insertion, deletion              |
| map           | Bidirectional     | Insertion, deletion              |
| unordered_set | Forward           | Insertion, deletion, rehashing   |
| unordered_map | Forward           | Insertion, deletion, rehashing   |

Please note that stack and queue do not provide iterators. More information about the iterator categories, as well as comprehensive table, can be found in the [C++ reference](https://en.cppreference.com/w/cpp/iterator).