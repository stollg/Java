//Garrett Stoll gstoll
/* intList.h
 The purpose of this file is to declare the functions
 by providing prototypes to be implemented in the intlist.c file. 
 */

#ifndef C101IntList
#define C101IntList
/* Multiple typedefs for the same type are an error in C. */

typedef struct IntListNode * IntList;

/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
 * (what are the preconditions?)
 */

/** first
 The precondition is that Intlist oldL is not NULL.
 */
int intFirst(IntList oldL);

/** rest
the preconditions are that oldL exists and is not NULL.
 */
IntList intRest(IntList oldL);

/* Constructors
 * (what are the preconditions and postconditions?)
 
 */

/** cons
 */
IntList intCons(int newE, IntList oldL);

#endif

