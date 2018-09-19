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

class Allocator {

    public: 
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
     * Usage: char *newPointer = (char *)malloc(requestedSize);
     * --------------------------------------------------------
     * This function returns a pointer to an allocated segment of memory
     * that is equal to or greater than the requested size. No assumptions
     * should be made about the state of the memory segment. Returns a valid
     * address upon success and nullptr upon system failure.
     */
    void *malloc(size_t segmentSize);

    /*
     * Function: calloc
     * Usage: char *newPointer = (char *)calloc(requestedSize, clearCharacter);
     * -----------------------------------------------------------------------
     * This is functionally the same as malloc per a requested size when the
     * clear character is not passed as an argument, but the segment of memory
     * will be null initialized by default. An optional character may be specified
     * that will dictate the initial state of the memory segment upon successful
     * allocation. Returns a valid address pointing to a memory segment with
     * bytes allocated greater than or equal to the specified segment size. Returns
     * nullptr upon system failure and handles errors the same as malloc.
     */
    void *calloc(size_t segmentSize, char ch = kDefaultChar);


    /*
     * Function: realloc
     * Usage: char *newPointer = (char *)realloc(oldPointer, updatedSize);
     * -------------------------------------------------------------------
     * This function reallocates the memory segment pointed to by oldPointer spanning
     * the range of oldPointer to (oldPointer + originalSegmentSize) to the updated
     * request size. Note: the starting pointer of the memory segment will likely
     * not be the original, handle accordingly. Although realloc may be used to request a 
     * smaller segment size, depending upon implementation, this may result in no system
     * changes. Returns a valid address with size equal to or greater than the
     * updatedSize, and nullptr upon system failure.
     */
    void *realloc(void *oldPointer, size_t updatedSize);

    /*
    * Function: dealloc
    * Usage: dealloc(oldPointer);
    * ----------------------------
    * This function returns a previously allocated memory segment to the collection
    * of segments that are able to be allocated. In the event that the pointer to
    * recycle is not part of a memory system that is actively allocated, the function
    * will return the pointer passed to the function. Upon successful deallocation,
    * the function will return nullptr.
    */
    void *dealloc(void *oldPointer);

    /*
     * Function: dealloc2
     * Usage: dealloc2(oldPointer, sizeOfSegment);
     * ------------------------------------------
     * This is implementation dependent, but is functionally similar to
     * dealloc, but may preserve a segment of memory as allocated if the following
     * conditions are met: 1) oldPointer is a valid starting address and 2) the
     * size of the segment to deallocate is smaller than the previously allocated
     * segment and 3) the remaining size of the segment to remain allocated is
     * greater or equal to the minimum block size as defined per the allocator. Returns
     * nullptr upon successful deallocation and the original pointer passed as an
     * argument to the function upon system failure.
     */
    
    /*
     * Function: validateSegment
     * Usage: if (!validateSegment()) exit(errorCode);
     * -----------------------------------------------
     * This function is meant to internally validate the structure of all
     * allocated and deallocated memory segments. Returns a boolean to indicate
     * that the internal structure, as defined per the implementation of the allocator,
     * is in appropriate order - false when corrupt and true when validated.
     */
    bool validateSegment();

}
#endif
