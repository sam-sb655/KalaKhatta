# KalaKhatta
DYNAMIC MEMORY ALLOCATION:
Memory allocated at compilation time->static memory (memory is fixed and cannot be increased or decreased)          //cannot be freed, hence high chances of wastage of memory
e.g. arr[5]={1,2,3,4,5};

Mmeory allocated at run time->dynamic memory (memory is allocated from heap, where memory is allocated or deallocated without any order unlike stack)    //can be increased or decreased and freed
Built-in functions for dynamic memory allocation: malloc(), calloc(), realloc(), free()

MALLOC()
declated in the header file <stdlib.h>
allocates a single large block of contigious memory according to the size specified
SYNTAX-> (int*)malloc(sizeof(int)*5) 
returns a void pointer at the first byte of the memory or a NULL

