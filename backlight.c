/*
 * Interacts with files representing backlight configurations.  The program is
 * designed to be mapped to keyboard keys, and can be used to control display or
 * keybaord backlights.
 */
#include <stdio.h>
#include "config.h"
#include "lightcontrol.h"

int main(int argc, const char* argv[]) {
  switch(argv[1][0]) {
    case 'i':
      /* increment, increase, inc */
      lincrease(DISPLAY_BACKLIGHT_FILENAME, INCREMENT_AMOUNT);
     break;
    case 'd':
      /* decrement, decrease, dec */
      lincrease(DISPLAY_BACKLIGHT_FILENAME, DECREMENT_AMOUNT);
      break;
    case 'p':
      /* percentage */
      get_percent(MAX_DISPLAY_BACKLIGHT_FILENAME, DISPLAY_BACKLIGHT_FILENAME);
      break;
    default:
      printf("Valid options are i,d,s or p.\n\nUsage:\tbacklight increase (increases by 10)\n\tbacklight decrease (decreases by 10)\n\tbacklight percentage (prints the current percentage of the total backlight potential)\n\n");
  }
  return 0;
}
