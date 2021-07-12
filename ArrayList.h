#ifndef ARRAYLIST_H
#define ARRAYLIST_C
#include "Address.h"
#include <stdbool.h>

/**
 * Nongeneric ArrayList used to hold Addresses. This ArrayList supports
 * basic functions such as adding, locating, finding, and cleaning
 * elements. This ArrayList will automaticaly expand if needed. 
 * 
 * ArrayList is proper if:
 * 	- data points to a block of memory large enough to hold 
 * 		up to capacity number of addresses.
 * 	- usage is <= capacity
 * 	- capacity is maximum number of elements stored in ArrayList.
 * 	- cleanElem function actually frees all data from Address structs including
 * 		pElem itself. 
 * 	- compareElem returns >0 if token exists in pElem, <0 if does not exists
 * 	
 * 	and:
 * 	All fields are NULL or 0
 */
struct _ArrayList{
	Address* data;		// Array containing all Addresses
	uint32_t usage;		// Number of slots used in data
	uint32_t capacity;	// Total number of slots in data
	void (*cleanElem)(Address* pElem);	// Function which cleans Addresses
	void (*compareElems)(char* token, Address* pElem);	// Function which checks if a token exists in pElem.
};
typedef struct _ArrayList ArrayList;

/**
 * Creates an ArrayList according to the given parameters and returns it.
 * Pre:	all params follow proper ArrayList guidelines.
 * Post: proper ArrayList returned. Improper ArrayList returned if guidelines
 * 		are not followed.
 */
ArrayList* AL_create(uint32_t capacity, void (*cleanElem)(Address* pElem), 
						void (*compareElems)(char* token, Address* pElem));

/**
 * Returns Address located at position index.
 * Pre: list is proper
 * Post: Returns Address at the provided index (not a copy as only the listener 
 * 		interacts with it and does not modify anything). Returns NULL if out
 * 		of bounds. 
 */						
Address* AL_elemAt(ArrayList* list, uint32_t index);

/**
 * Returns an integer array with -1 in the last occupied index containing
 * all the indexes in the list that contains the token.
 * Pre: token is not NULL and points to a null termainated string. List is
 * 		proper.
 * Post: integer array all matching indexes with -1 in last index is returned.
 */
int64_t* AL_findAll(ArrayList* list, char* token);

/**
 * Inserts elem at next avalable index.
 * Pre: list is proper
 * Post: Inserts element to the next avalable spot in the ArrayList, expands
 * 		ArrayList if needed (if capacity is 0, function returns false). Returns
 * 		true if successful. 
 */
bool AL_insert(ArrayList* list, Address* elem);

/**
 * Replaces element at specified index in list with elem.
 * Pre: elem is proper and contains no NULL fields. list is proper and
 * 		contains no NULL fields.
 * Post: Returns true if replacement was successful, false if not (if out
 * of bounds). 
 */
bool AL_replace(ArrayList* list, Address* elem, uint32_t index);

/**
 * Frees and NULLs all elements within list using cleanElems as well as list
 * itself. 
 * Pre: cleanElems is proper.
 * Post: All dynamically allocated data freed and NULL. All non dynamic data 
 * zeroed. 
 */
void AL_clean(ArrayList* list);

#endif
