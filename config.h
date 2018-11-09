/*
 * Compile time constants intended to be modified to change the behavior of the
 * program.
 */


/* The maximum number of digits to support in a number contained in a file. */
#define LIGHT_DIGITS 8

/*
 * The name identifying the file to interact with as the current display
 * backlight level.
 */
#define DISPLAY_BACKLIGHT_FILENAME "/sys/class/backlight/intel_backlight/brightness"

/*
 * The name identifying the file to interact with as the maximum display
 * backlight level.
 */
#define MAX_DISPLAY_BACKLIGHT_FILENAME "/sys/class/backlight/intel_backlight/max_brightness"

/*
 * The name identifying the file to interact with as the current keyboard
 * backlight level.
 */
#define KEYBOARD_BACKLIGHT_FILENAME "/sys/class/leds/tpacpi::kbd_backlight/brightness"

/*
 * The name identifying the file to interact with as the maximum keyboard
 * backlight level.
 */
#define MAX_KEYBOARD_BACKLIGHT_FILENAME "/sys/class/leds/tpacpi::kbd_backlight/max_brightness"

/* The relative amount to increase the backlight by. */
#define INCREMENT_AMOUNT 10

/* The relative amount to decrease the backlight by. */
#define DECREMENT_AMOUNT -10
