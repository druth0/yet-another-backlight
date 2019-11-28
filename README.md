# Yet Another Backlight

Yet Another Backlight is just another simple backlight control tool.

It is capable of managing both keyboard and LCD backlights.

Yet Another Backlight is not an official Google product.

# Usage

yabl -i, --increment: increases backlight (optionally by a specified amount)

yabl -d, --decrement: decreases backlight (optionally by a specified amount)

yabl -s, --status: prints the percentage of maximum that is currently set for the backlight

# Installation

In order to use yabl with your hardware, you'll need to manually modify config.h
to point to the correct /sys/class interface(s) to modify. You'll also likely
have to install a udev rule that grants access to those files (an example is
included in 90-lights.rule).
