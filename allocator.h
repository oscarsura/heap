/*
 * File: allocator.h
 * -----------------
 * This file exports the generic prototypes of any dynamic
 * memory allocator, namely initialization, initial allocation,
 * re-allocation, freeing of any previously initialized and allocated
 * segments as well as validating the segment's internal structure.
 */

#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

/*
 * Function: init
 * Usage: init(segmentStart, segmentSize); 
 * ---------------------------------------
 * This function initializes the heap segment, within the range of
 * segmentStart to segmentStart + segmentSize and may be used to 
 * reinitialize and zero the segment while running an allocator. This
 * function returns true upon initialization success and false upon a
 * critical failure that cannot be handled.
 */
bool init(void *segmentStart, size_t segmentSize);

/*
 * Function: malloc
 * Usage: char *newPointer = (char *)malloc(requestsize);
 * ------------------------------------------------------
 */
void malloc();

void realloc();

void free();

bool validateSegment();

#endif
