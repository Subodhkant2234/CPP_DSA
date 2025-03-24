void* aligned_malloc(size_t required_bytes, size_t alignment) {
    void* p1; // original block
    void** p2; // aligned block
    int offset = alignment - 1 + sizeof(void*);
    // Allocate extra memory to store the original pointer
    if ((p1 = (void*)malloc(required_bytes + offset)) == NULL) {
        return NULL;
    }
    // Align the pointer
    p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
    // Store the original pointer before the aligned memory
    p2[-1] = p1;
    return p2;
}
 
void aligned_free(void *p) {
    free(((void**)p)[-1]);
}


/*
#include <stdio.h>
#include <stdlib.h>

void* aligned_malloc(size_t required_bytes, size_t alignment) {
    if (alignment & (alignment - 1)) {
        // Alignment must be a power of two
        return NULL;
    }

    void* original;  // Original memory block from malloc
    void** aligned;  // Aligned memory block
    size_t offset = alignment - 1 + sizeof(void*);

    // Allocate extra memory to ensure proper alignment and store original pointer
    if ((original = malloc(required_bytes + offset)) == NULL) {
        return NULL;
    }

    // Align the pointer
    aligned = (void**)(((size_t)(original) + offset) & ~(alignment - 1));

    // Store the original pointer just before the aligned block
    aligned[-1] = original;

    return aligned;
}

void aligned_free(void* aligned) {
    if (aligned) {
        free(((void**)aligned)[-1]);  // Retrieve the original pointer and free it
    }
}

int main() {
    size_t alignment = 16;
    size_t size = 64;

    void* ptr = aligned_malloc(size, alignment);
    if (ptr) {
        printf("Aligned memory address: %p\n", ptr);
        aligned_free(ptr);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
=============================================
Improvements & Fixes
Check if alignment is a power of two

Alignment must be a power of two (16, 32, 64, ...), which is a common requirement for aligned allocations.

The condition alignment & (alignment - 1) checks if the number is a power of two.

Use size_t for pointer arithmetic

(size_t)p1 + offset ensures correct calculations, preventing type mismatches.

Ensure Memory Alignment is Correct

The adjusted pointer calculation ensures that the allocated memory is correctly aligned.

Properly Free the Memory

aligned_free() retrieves the original pointer and deallocates it.
*/
