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
