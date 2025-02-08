# KalaKhatta

## Dynamic Memory Allocation

### **Static Memory Allocation:**
Memory allocated at **compilation time** is called **static memory**. The memory size is fixed and **cannot be increased or decreased** later. Since it cannot be freed, there are **high chances of memory wastage**.

**Example:**
```c
int arr[5] = {1, 2, 3, 4, 5};
```

### **Dynamic Memory Allocation:**
Memory allocated at **run time** is called **dynamic memory**. It is allocated from the **heap**, which allows flexible memory allocation and deallocation **without any order**, unlike the stack. This means memory can be **increased, decreased, and freed** as needed.

### **Built-in Functions for Dynamic Memory Allocation:**
- `malloc()`
- `calloc()`
- `realloc()`
- `free()`

## **Memory Allocation Functions**

### **1. malloc()**
Declared in the header file `<stdlib.h>`.

- Allocates a **single large block** of **contiguous** memory according to the specified size.
- Returns a **void pointer** to the first byte of the allocated memory or `NULL` if allocation fails.

**Syntax:**
```c
(int*) malloc(sizeof(int) * 5);
```

### **2. calloc()**
- Allocates **multiple blocks** of memory dynamically.
- **Difference from `malloc()`:**
  1. `calloc()` requires **two arguments**:
     ```c
     (int*) calloc(5, sizeof(int));
     ```
  2. **Memory is initialized to zero**, unlike `malloc()`, which initializes memory to **garbage values**.

### **3. realloc()**
The `realloc()` function is used to **resize a memory block** **without losing old data**.

**Syntax:**
```c
(int*) realloc(ptr, sizeof(int) * 10);
```

- The data is moved to a **new memory block**.
- **Newly allocated bytes remain uninitialized**.

### **4. free()**
- Used to **deallocate dynamically allocated memory**.
- Prevents **memory leaks**.
- Syntax:
  ```c
  free(ptr);
  ```

---

## **Singly Linked List**
A **singly linked list** is a fundamental data structure consisting of **nodes**, where each node contains:
- A **data field** (to store values)
- A **reference to the next node** in the linked list

The **next pointer of the last node is `NULL`**, indicating the end of the list.

### **Why Use a Linked List?**
- **Efficient insertion and deletion operations** compared to arrays.
- **No fixed size** (unlike arrays, which require predefined memory allocation).

---


