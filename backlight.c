/**
 * Backlight is a simple program to interact with the sys/class set of backlight interfaces.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
  int value;
  /* TODO: Use getopt the right way.  For now just assume the second argument is a valid one. */
  switch(argv[1][0]) {
    case 'i':
      /* increment, increase, inc */
      value = 10;
     break;
    case 'd':
      /* decrement, decrease, dec */
      value = -10;
      break;
    case 's':
    case 'p':
      /* statistics, percentage */
      value = 0;
      break;
    default:
      printf("Valid options are i,d,s or p.\n\nUsage:\tbacklight increase (increases by 10)\n\tbacklight decrease (decreases by 10)\n\tbacklight percentage (prints the current percentage of the total backlight potential)\n\n");
      return 0;
  }

  /* Open up the intel_backlight brightness file.
  * TODO: This should scan the appropriate directory and try to find the right backlight.
  * TODO: Error handling.
  */
  FILE* brightness_file = fopen("/sys/class/backlight/intel_backlight/brightness","r");
  char level[8];
  fread(level, sizeof(level), 1, brightness_file);
  fclose(brightness_file);
  if (value) {
    int new_level = atoi(level) + value;
    /* Restart the pointer at the beginning of the file.  There's probably a better way to do this. */
    brightness_file = fopen("/sys/class/backlight/intel_backlight/brightness","w");
    snprintf(level, sizeof(level), "%d", new_level);
    fwrite(level, sizeof(level), 1, brightness_file);
    fclose(brightness_file);
  } else {
    FILE* max_file = fopen("/sys/class/backlight/intel_backlight/max_brightness", "r");
    char max[8];
    fread(max, sizeof(max), 1, max_file);
    printf("%d%%\n", (atoi(level)*100)/atoi(max));
    fclose(max_file);
  }
  return 0;
}
