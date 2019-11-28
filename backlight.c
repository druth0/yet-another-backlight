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
 * Interacts with files representing backlight configurations.  The program is
 * designed to be mapped to keyboard keys, and can be used to control display or
 * keyboard backlights.
 */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "config.h"
#include "lightcontrol.h"

int get_amount(int argc, int optind, int alternative, char * const *argv) {
  return optind >= argc || argv[optind][0] == '-' ? alternative : atoi(argv[optind]);
}

int main(int argc, char * const *argv) {
  static struct option long_options[] = {
    {"increment", optional_argument, 0, 'i' },
    {"decrement", optional_argument, 0, 'd' },
    {"status", no_argument, 0, 's' },
    {"help", no_argument, 0, 'h' },
    {"version", no_argument, 0, 'V' },
    {0, 0, 0, 0 },
  };
  static char *short_options= "i::d::shV";

  int status = 0;
  int amount = 0;
  int option_index = 0;
  int shortopt = 0;

  while((shortopt = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
    switch(shortopt) {
      case 'i':
        amount = get_amount(argc, optind, INCREMENT_AMOUNT, argv);
        break;
      case 'd':
        amount = get_amount(argc, optind, DECREMENT_AMOUNT, argv) * -1;
        break;
      case 's':
        status = 1;
        break;
      case 'h':
        /* Print the help message. */
        printf("Usage: yabl [OPTION...]\n\n  -i, --increment\tincrements the backlight by an optional amount specified, or the default amount if no amount was specified\n  -d, --decrement\tdecrements the backlight by an optional amount specified, or the default amount if no amount was specified\n  -s, --status\treturns the status of the backlight, as a percentage\n -h, --help\t prints this informational message\n -V, --version\t prints the version of yabl being run\n");
        exit(EXIT_SUCCESS);
      case 'V':
        /* Print the version information. */
        printf("yabl 1.0\n");
        exit(EXIT_SUCCESS);
      default:
        printf("c: %d, c(char): %c, option_index: %d, optind: %d, argument: %s\n", shortopt, shortopt, option_index, optind, argv[optind]);
    }
  }

  if (amount) {
    fincrease(DISPLAY_BACKLIGHT_FILENAME, amount);
  }

  if (status) {
    printf("%d%%\n", get_percent(MAX_DISPLAY_BACKLIGHT_FILENAME, DISPLAY_BACKLIGHT_FILENAME));
  }

  exit(EXIT_SUCCESS);
}
