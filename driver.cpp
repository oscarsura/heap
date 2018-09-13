/*
 * File: driver.cpp
 * ----------------
 * This file initializes the dynamic memory segment, spawns algorithms
 * for testing, and builds the environment to record algorithm statistics.
 */

#include <sys/mman.h> //for mmap, munmap
#include <assert.h>   //for assert
#include <iostream>   //for cerr

#define HEAP_START_ADDR 0x0 //define heap start at address 0x0
#define MEM_PROTECTION (PROT_READ|PROT_WRITE) //default memory protection
#define FLAGS (MAP_PRIVTE|MAP_ANONYMOUS) //privately mapped region, no file

static void* kSegmentStart = nullptr; //default segment address
static size_t kSegmentSize = 0; //default segment size

void* getSegmentStart {
    return kSegmentStart;
}

size_t getHeapSize {
    return kSegmentSize;
}

static size_t fd = -1; //memory segment is not oriented around a file descriptor
static size_t offset = 0; //offset within a file, but no file is being mapped
void* initHeapSegment(size_t requestedSize) {
    if (kSegmentStart != nullptr) {
        if (munmap(kSegmentStart, kSegmentSize) == -1) return nullptr;
        kSegmentStart = nullptr;
        kSegmentSize = 0;
    }
    kSegmentStart = mmap(HEAP_START_ADDR, requestedSize, MEM_PROTECTION, FLAGS, fd, offset);
    assert(segment_start != MAP_FAILED);
    kSegmentSize = requestedSize;
    return kSegmentStart;
}

static size_t kSegmentUnmapError = -1;
void freeHeapSegment(void* segmentStart, size_t segmentSize) {
    if (munmap((segmentStart, segmentSize) == -1) {
        cerr << "Could not unmap the region of memory at addr: " << (char*)sgmentStart << endl;
        exit(kSegmentUnmapError);
    }
}

static size_t kDefaultHeapSize = (1 << 20);
int main() {
    initHeapSegment(kDefaultHeapSize); //mmap
    freeHeapSegment(kSegmentStart, kSegmentSize); //munmap
    return 0;
}
