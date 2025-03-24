#include <stdio.h>
#include <stdlib.h>

void *aligned_malloc(size_t size, size_t alignment) {
    if (alignment & (alignment - 1)) {
        // Alignment must be a power of two
        return NULL;
    }

    // Allocate extra memory to store the original pointer
    void *original = malloc(size + alignment - 1 + sizeof(void *));
    if (!original) return NULL;

    // Align the pointer
    void *aligned = (void *)(((size_t)original + alignment - 1 + sizeof(void *)) & ~(alignment - 1));

    // Store the original pointer before the aligned memory
    ((void **)aligned)[-1] = original;

    return aligned;
}

void aligned_free(void *aligned) {
    if (aligned) {
        free(((void **)aligned)[-1]);  // Retrieve and free the original pointer
    }
}

int main() {
    size_t alignment = 16;
    size_t size = 64;
    
    void *ptr = aligned_malloc(size, alignment);
    
    if (ptr) {
        printf("Aligned memory address: %p\n", ptr);
        aligned_free(ptr);
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}


Explanation
Extra Memory Allocation:

size + alignment - 1 + sizeof(void *) ensures that we have enough space for alignment adjustments and storing the original pointer.

Alignment Calculation:

((size_t)original + alignment - 1 + sizeof(void *)) & ~(alignment - 1) moves the pointer to the next aligned address.

Pointer Storage:

The original pointer (returned by malloc()) is stored just before the aligned pointer.

Deallocation:

aligned_free() retrieves the original pointer and frees it properly.
