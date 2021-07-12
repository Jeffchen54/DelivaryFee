#ifndef ADDRESS_H
#define ADDRESS_H

/**
 * An Address is a data entry in the client data file which one row
 * is one Address. name is the address/entity name and charge is 
 * the delivary charge for the address or entity.
 * 
 * An Address is proper if
 * 		- name points to a block of memory large enough to contain
 * 			address/entity name
 * 		- charge points to a block of memory large enough to contain
 * 			delivary charge for address/entity
 * 		and:
 * 		- name == charge == NULL
 */
struct _Address{
	char* name;
	char* charge;

};
typedef struct _Address Address;

/**
 * Creates an address using given name and charge info and returns it.
 * Pre:	name and charge point to a block of memory large enough to 
 * 		contain address/entity name.
 * Post: pointer to a proper Address is returned. May return an improper 
 * 		Address if name and charge do not match proper requirements.
 */
Address* createAddress(char* name, char* charge);

/**
 * Frees all data from given address
 * Pre: address contains only dynamically allocated fields.
 * Post: address fields are freed and nulled.
 */
void cleanElem(Address* address);

/**
 * Print address to the console.
 * Pre: address does not contain any NULL fields.
 * Post: address fields are displayed on the console with "\n"
 */
void printElem(Address* address);
#endif
