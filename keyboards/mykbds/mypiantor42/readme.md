# keybow2040

![keybow2040](imgur.com image replace me!)

_A short description of the keyboard/project_

-   Keyboard Maintainer: [Nelson Martins](https://github.com/iamnelsonmartins)
-   Hardware Supported: Keybow2040 by Pimoroni

## How to use the keyboard

    - Clone the file or Download the zip from github
    - Copy folder to keyboards inside QMK_FIRMWARE (and change to keybow2040)
    - RUN qmk compile --keyboard keybow2040 --keymap default

## Bootloader

Enter the bootloader in 3 ways:

-   **Physical reset button right**: Press and Hold top right button while connecting usb-c cable
-   **Physical reset button left**: Press and Hold top right button and click the top left
-   **Keycode in layout**: Press the key mapped to `RESET` if it is available - bottom left key+bottom right key and top right key
