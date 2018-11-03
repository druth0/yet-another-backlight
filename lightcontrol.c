/*
 * File operations for virtual file interfaces that contain only integers.
 */
#include <stdio.h>
#include <stdlib.h>
#include "config.h"

void fincrease(char* fname, int amount) {
  File* stream = fopen(fname, "r+");
  fprintf(stream, "%d", fread_int(stream) + amount);
  fclose(stream);
}

int fread_int(FILE* stream) {
  char* level = malloc(sizeof(char)*LIGHT_DIGITS);
  fread(level, sizeof(level), 1, stream);
  return atoi(level);
}

int read_int(char* fname) {
  FILE* stream = fopen(fname, "r+");
  int rv = fread_int(stream);
  fclose(stream);
  return rv;
}

int get_percent(char* max_fname, char* fname) {
  return (read_int(fname) * 100)/read_int(max_fname);
}
