/*
 * File: driver.h
 * --------------
 * This file exports the functionality of the dynamic memory
 * mangament driver and any necessary dependent subroutines.
 */

#ifndef _DRIVER_H_
#define _DRIVER_H_

#include <stddef.h> //for size_t

/*
 * Method: getSegmentStart
 * Usage: char* heapStart = (char*)getSegmentStart();
 * --------------------------------------------------
 * This method returns the start of the allocated dynamic memory segment, 
 * as a pointer to void. Returns nullptr if the segment has not yet been
 * initialized or was unable to be initialized.
 */
void* getSegmentStart();

/*
 * Method: getHeapSize
 * Usage: size_t heapSize = getHeapSize();
 * ---------------------------------------
 * This method returns the total bytes allocated to the dynamic memory
 * segment, as a signed integer. Returns 0 if the segment has not yet
 * been initialized or was unable to be initialized.
 */
size_t getHeapSize();

/*
 * Method: initHeapSegment
 * Usage: char* heapStart = (char*)initHeapSegment(kDefaultSegmentSize);
 * ---------------------------------------------------------------------
 * This method initializes the heap segment according to the specified
 * number of bytes, returning a valid address if successfully mapped
 * by the kernel, and nullptr upon failure.
 */
void* initHeapSegment(size_t requestedSize);

/*
 * Method: freeHeapSegment
 * Usage: freeHeapSegment(kSegmentStart, kSegmentSize);
 * ----------------------------------------------------
 * This method unmaps the dynamically managed memory segment, raising
 * an error and setting the exit status upon failure. Note this method
 * does not reinitialize the segment start or the segment size.
 */
void freeHeapSegment(void* segmentStart, size_t kSegmentSize);

#endif
