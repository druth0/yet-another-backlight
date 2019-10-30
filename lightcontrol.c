/*
 * Copyright 2019 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * File operations for virtual file interfaces that contain only integers.
 */
#include <stdio.h>
#include <stdlib.h>
#include "config.h"

int fread_int(FILE* stream) {
  char* level = malloc(sizeof(char)*LIGHT_DIGITS);
  fread(level, sizeof(level), 1, stream);
  return atoi(level);
}

int read_int(char* fname) {
  FILE* stream = fopen(fname, "r");
  int rv = fread_int(stream);
  fclose(stream);
  return rv;
}

void fincrease(char* fname, int amount) {
  FILE* stream = fopen(fname, "r+");
  fprintf(stream, "%d", fread_int(stream) + amount);
  fclose(stream);
}

int get_percent(char* max_fname, char* fname) {
  return (read_int(fname) * 100)/read_int(max_fname);
}
