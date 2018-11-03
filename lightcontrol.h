/*
 * File operations for virtual file interfaces that contain only integers.
 */

#include<stdio.h>

/*
 * Increases the integer in a file identified by fname by the integer amount.
 */
void fincrease(char* fname, int amount);

/*
 * Gets the value of the integer stored in the file identified by fname
 * multiplied by 100 and divided by the value of the integer stored in the file
 * identified by max_fname.
 */
int get_percent(char* max_fname, char* fname);
