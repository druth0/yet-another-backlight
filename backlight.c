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
 * keybaord backlights.
 */
#include <stdio.h>
#include "config.h"
#include "lightcontrol.h"

int main(int argc, const char* argv[]) {
  if (argc > 1) {
    switch(argv[1][0]) {
      case 'i':
        /* increment, increase, inc */
        fincrease(argv[1][1] == 'k' ? KEYBOARD_BACKLIGHT_FILENAME : DISPLAY_BACKLIGHT_FILENAME, INCREMENT_AMOUNT);
        break;
      case 'd':
        /* decrement, decrease, dec */
        fincrease(argv[1][1] == 'k' ? KEYBOARD_BACKLIGHT_FILENAME : DISPLAY_BACKLIGHT_FILENAME, DECREMENT_AMOUNT);
        break;
      case 'p':
        /* percentage */
        if (argv[1][1] == 'k') {
          printf("%d%%\n", get_percent(MAX_KEYBOARD_BACKLIGHT_FILENAME, KEYBOARD_BACKLIGHT_FILENAME));
          break;
        }
        printf("%d%%\n", get_percent(MAX_DISPLAY_BACKLIGHT_FILENAME, DISPLAY_BACKLIGHT_FILENAME));
        break;
    }
  } else {
    printf("Valid options are i,d,s or p.\n\nUsage:\tbacklight increase (increases by 10)\n\tbacklight decrease (decreases by 10)\n\tbacklight percentage (prints the current percentage of the total backlight potential)\n\n");
  }
  return 0;
}
