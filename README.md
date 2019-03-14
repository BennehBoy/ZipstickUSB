# ZipstickUSB
8 bit C64/Amiga/Atari Joystick to USB adapter

This allows you to convert an 8pin sub-d C64/Amiga/Atari joystick to a USB HID joystick - it will report as a USB Competition Pro, or whatever you wish to set the VID/PID/Description to.

The sketch is currently setup to work with a HYTiny STM32 board https://www.hotmcu.com/stm32f103tb-arm-cortex-m3-development-board-p-222.html but should work equally well with a bluepill/blackpill/maple mini.

##Pinout:
*Pin 8 to 3.3V on MCU
*Pin 1 to PA5 (Up/Forward)
*Pin 2 to PA4 (Down/Back)
*Pin 3 to PA7 (Left)
*Pin 4 to PA6 (Rght)
*Pin 6 to PA3 (Button 1)
