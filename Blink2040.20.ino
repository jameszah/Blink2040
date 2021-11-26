/*

  Blink2040

  Software version of the BigClive SuperComputer

  This basically blinks a 10x8 matrix of normal leds, using a rp2040, but lets you change the blink frequency,
  and add shapes, and sublimal text of regular text to the display.

  Currently is plays a 90 second cycle with
  - subliminal text on first run after reboot
  - some sublimal images, ending in a quick look at it
  - some blank part of matrix,
  - some floating text following by happy face
  - and some clear text at the end

  Next step
  - add a potentiometer to change blink frequency
  - add a capacitive touch to disable subliminal message and shapes and return to simple blink supercomputer


  https://github.com/jameszah/Blink2040 is licensed under the
    GNU General Public License v3.0

  by James Zahary  Nov 17, 2021
  jamzah.plc@gmail.com

  The is Arduino code for the Raspberry Pi 2040
    using the earlephilhower arduino 2040 system https://github.com/earlephilhower/arduino-pico

  Compiled with Arduino 1.8.13 Nov 19, 2021

  Linking everything together...
  "C:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\tools\\pqt-python3\\1.0.1-base-3a57aed/python3" -I "C:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\hardware\\rp2040\\1.9.5/tools/simplesub.py" --input "C:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\hardware\\rp2040\\1.9.5/lib/memmap_default.ld" --out "C:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258/memmap_default.ld" --sub __FLASH_LENGTH__ 2093056 --sub __EEPROM_START__ 270528512 --sub __FS_START__ 270528512 --sub __FS_END__ 270528512 --sub __RAM_LENGTH__ 256k
  "C:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\tools\\pqt-gcc\\1.3.1-a-7855b0c/bin/arm-none-eabi-gcc" -Werror=return-type "-IC:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\hardware\\rp2040\\1.9.5/tools/libpico" -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DUSB_VID=0x2e8a -DUSB_PID=0x000a "-DUSB_MANUFACTURER=\"Raspberry Pi\"" "-DUSB_PRODUCT=\"Pico\"" -Os -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -u _printf_float -u _scanf_float -c "C:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\hardware\\rp2040\\1.9.5/boot2/boot2_w25q080_2_padded_checksum.S" "-IC:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\hardware\\rp2040\\1.9.5/pico-sdk/src/rp2040/hardware_regs/include/" "-IC:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\hardware\\rp2040\\1.9.5/pico-sdk/src/common/pico_binary_info/include" -o "C:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258/boot2.o"
  "C:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\tools\\pqt-gcc\\1.3.1-a-7855b0c/bin/arm-none-eabi-g++" "-LC:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258" -Werror=return-type "-IC:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\hardware\\rp2040\\1.9.5/tools/libpico" -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DUSB_VID=0x2e8a -DUSB_PID=0x000a "-DUSB_MANUFACTURER=\"Raspberry Pi\"" "-DUSB_PRODUCT=\"Pico\"" -Os -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections -fno-exceptions -u _printf_float -u _scanf_float "@C:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\hardware\\rp2040\\1.9.5/lib/platform_wrap.txt" -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common "-Wl,--script=C:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258/memmap_default.ld" "-Wl,-Map,C:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258/Blink2040.16.ino.map" -o "C:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258/Blink2040.16.ino.elf" -Wl,--start-group "C:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258\\sketch\\Blink2040.16.ino.cpp.o" "C:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258/core\\core.a" "C:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258/boot2.o" "C:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\hardware\\rp2040\\1.9.5/lib/libpico.a" -lm -lc -lstdc++ -lc -Wl,--end-group
  "C:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\tools\\pqt-elf2uf2\\1.3.1-a-7855b0c/elf2uf2" "C:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258/Blink2040.16.ino.elf" "C:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258/Blink2040.16.ino.uf2"
  "C:\\ArduinoPortable\\arduino-1.8.13\\portable\\packages\\rp2040\\tools\\pqt-gcc\\1.3.1-a-7855b0c/bin/arm-none-eabi-size" -A "C:\\Users\\James\\AppData\\Local\\Temp\\arduino_build_930258/Blink2040.16.ino.elf"
  Sketch uses 63032 bytes (3%) of program storage space. Maximum is 2093056 bytes.
  Global variables use 15196 bytes (5%) of dynamic memory, leaving 246948 bytes for local variables. Maximum is 262144 bytes.

  - update Nov 26, 2021 - v20
  - switch to 2 minute cycle
  - add code to run of a usb-powerbank to burn just enough current every 15 second cycle to keep the powerbank alive 
    https://github.com/jameszah/usb-powerbank-keepalive
  - add a poteniometer to change the blink frquency
  - add a capacitive touch switch to shut off the subliminal messages and just to the "supercomputer" blinking
  - change the patterns a little -- more faces, less beer
  
  Sketch uses 63528 bytes (3%) of program storage space. Maximum is 2093056 bytes.
  Global variables use 14608 bytes (5%) of dynamic memory, leaving 247536 bytes for local variables. Maximum is 262144 bytes.

*/
// https://github.com/dhepper/font8x8/blob/master/font8x8_basic.h
#include "font8x8_basic.h"

//https://github.com/willmendesneto/arduino-matrix-8x8/blob/master/libraries/LEDMatrix/5x6/font.h
#include "font.h"

// here are the gpio pins for the 0->7 anode and 0->9 cathode
uint8_t Anode[] = {12, 13, 14, 15, 16, 17, 18, 19};
uint8_t Cathode[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int prev_row = 0;
int prev_col = 0;
long blink_interval = 333333;
long blink_inter[8][10];
long blink_remain[8][10];
long blink_start = 0;
int do_it_once = 1;
long boot;
long loopcount = 0;
long total_loop_len = 0;

int smile[8][10] = {
  { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 },
  { 1, 0, 1, 0, 0, 1, 0, 1, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
  { 1, 0, 1, 0, 0, 1, 0, 1, 0, 0 },
  { 1, 0, 0, 1, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
};

int smilem[8][10] = {
  { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
};

int smilef[8][10] = {
  { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
};

int smileb[8][10] = {
  { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 1, 1, 1, 1, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
};
int smiler[8][10] = {
  { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
  { 0, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
  { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
  { 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0 },
};

int clive[8][10] = {
  { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 1, 1, 0, 0, 0, 1, 1, 0, 0 },
  { 0, 1, 0, 1, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
};

int beer0[8][10] = {
  { 1, 1, 0, 1, 1, 1, 0, 0, 0, 0 },
  { 1, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
  { 1, 1, 0, 1, 0, 1, 0, 1, 0, 0 },
  { 1, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
  { 1, 1, 0, 1, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
};

int beerB[8][10] = {
  { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

int beerE1[8][10] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

int beerE2[8][10] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

int beerR[8][10] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 }
};

int four[8][10] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void turn_on(int row, int col) {

  pinMode(prev_row, INPUT);
  pinMode(prev_col, INPUT_PULLUP);

  prev_row = Anode[row];
  prev_col = Cathode[col];
  pinMode(prev_row, OUTPUT);
  pinMode(prev_col, OUTPUT);
  digitalWrite(prev_row, HIGH);
  digitalWrite(prev_col, LOW);
  delayMicroseconds(20);
}

void turn_off() {
  pinMode(prev_row, INPUT);
  pinMode(prev_col, INPUT_PULLUP);
}

// provide the ascii code of 8x8 char to display in middle of 10x8

void display8x8(int ascii) {
  for (int row = 0; row < 8; row++) {
    int onerow = font8x8_basic[ascii][row];
    for (int col = 1; col < 9; col++) {  // 0->9 becomes 1->8 with blank left and right
      if (bitRead(onerow, col - 1) > 0) {
        turn_on(row, col);
      }
    }
  }
  turn_off();
}


void display5x6(int ascii) {
  for (int row = 0; row < 7; row++) {
    int onerow = Font[ascii][row];
    for (int col = 0; col < 5; col++) {
      if (bitRead(onerow, col ) > 0) {
        turn_on(row, 4 - col + 2);
      }
    }
  }
  turn_off();
}

// display a string big 8x8 font, with perchar ms per character
void displayString(String me, int perchar) {
  int len = me.length();
  long start = millis();
  for (int i = 0; i < len; i++) {
    int ch = me.charAt(i);
    do {
      display8x8(ch);
    } while (millis() < start + perchar);
    start = millis();
  }
}

String globString;
int globStringRemain = 0;
int globStringPos = 0;
int globStringPerchar = 0;
int globStringPercharRemain = 0;

// display a string one char at a time, for perchar ms, and call displayNext every loop until done
// - the string is mixed with other things playing on the display
void displayStringStart(String me, int perchar) {
  Serial.print("Start string ");
  Serial.print(me);
  Serial.printf(" at %d\n", millis());
  globString = me;
  globStringPos = 0;
  globStringRemain = me.length();
  globStringPerchar = perchar;
  globStringPercharRemain = millis() + globStringPerchar;
}

void displayNext() {
  long start = millis();
  if (globStringRemain > 0) {
    int ch = globString.charAt(globStringPos);
    display5x6(ch);
    if (globStringPercharRemain < millis() ) {
      globStringPos++;
      globStringRemain--;
      if (globStringRemain == 0) {
        Serial.printf("String is done at %d\n", millis());
      }
      globStringPercharRemain = millis() + globStringPerchar;
    }
  }
}

// play the 8x10 matrix of flashing leds, one time
void reg() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      if (blink_remain[row][col] > 0) {
        turn_on(row, col);
      }
    }
  }
  turn_off();
}

// play other matrix of pre-defined shapes
// each mattix turns on the led for 20 microseconds, then shut it off, so must be played many times to see it

void f_smile() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      if (smile[row][col] > 0) {
        turn_on(row, col);
      }
    }
  }
  turn_off();
}

void f_smilem() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      if (smilem[row][col] > 0) {
        turn_on(row, col);
      }
    }
  }
  turn_off();
}

void f_smilef() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      if (smilef[row][col] > 0) {
        turn_on(row, col);
      }
    }
  }
  turn_off();
}

void f_smileb() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      if (smileb[row][col] > 0) {
        turn_on(row, col);
      }
    }
  }
  turn_off();
}
void f_clive() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      if (clive[row][col] > 0) {
        turn_on(row, col);
      }
    }
  }
  turn_off();
}

void f_no_four() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      if (four[row][col] == 1) {
        blink_remain[row][col] = 0;
      } else {
        if (blink_remain[row][col] > 0 ) {
          turn_on(row, col);
        }
      }
    }
  }
  turn_off();
}

void f_beerB() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      if (beerB[row][col] > 0) {
        turn_on(row, col);
      }
    }
  }
  turn_off();
}
void f_beerE1() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      if (beerE1[row][col] > 0) {
        turn_on(row, col);
      }
    }
  }
  turn_off();
}
void f_beerE2() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      if (beerE2[row][col] > 0) {
        turn_on(row, col);
      }
    }
  }
  turn_off();
}
void f_beerR() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      if (beerR[row][col] > 0) {
        turn_on(row, col);
      }
    }
  }
  turn_off();
}

void f_test() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      turn_on(row, col);
      delay(5);
    }
  }
  turn_off();
}

// reset the blinking matrix to plus/minus 10% of blink interval
// start with random point in the blink cycle or start all on

void resetRandom( ) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      blink_inter[row][col] =  random(0.9 * blink_interval, 1.1 * blink_interval );
      blink_remain[row][col] = blink_inter[row][col];
    }
  }
}

// reset the blinking matrix to plus/minus 10% of blink interval
// start with random point in the blink cycle
void resetRandomZero( ) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      blink_inter[row][col] =  random(0.9 * blink_interval, 1.1 * blink_interval );
      blink_remain[row][col] = random(-blink_interval, blink_interval);
    }
  }
}

//////////////////////////////////////////////////////////////////////////
void setup() {

  //delay(3000);

  // setup led gpios
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      pinMode(Anode[row], INPUT);
      pinMode(Cathode[col], INPUT_PULLUP);
    }
  }

  // turn on every led for a test - could make this slower to see they all work
  f_test();

  /*
    // display the entire alphabet of fonts
    for (int letter = 48; letter < 127; letter++) {
      for (int x = 0; x < 250; x++) {
        display5x6(int(letter));
      }
    }
  */

  // set length of blink
  resetRandomZero();

  // display this string for 200ms each, while blinking continues
  displayStringStart("http://github.com/jameszah", 300);

  boot = millis();
  pinMode(22, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(26, INPUT);
  pinMode(11, INPUT);
}

int phase = 0;
int avgval = 2000;
int touchdebounce = 0;
int touch = 1;

//////////////////////////////////////////////////////////////////////////
/*
  Every loop we blink the matrix once **note
  - the "phases" are advanced within the 90 second cycle, to blink new shapes at different times
  - the blink_interval matrix contains the time on/off which is plus/minus 10% of target
  - the blink_remain runs from the blink_interval reduced every loop, until 0 when the led is off
  - when blink_remain hits negative blink_interval it is boosted back to its orginal blink_interval and will turn on again
  - (added code to change the plus/minus 10% after every expiration, so patterns should always change)
  **note - the displayString("QED", 1000); procedure breaks the rule and takes control of the loop for 5-10 seconds while it plays its message
*/

void loop() {
  loopcount++;
  long loop_start = micros();
  long start = (millis() - boot) % 180000;
  int reset_the_leds_after = 0;

  if (start < 1) {
    Serial.println("Phase 0");
    phase = 0;
  }

  long boost = millis() % 15000;
  if (boost > 14500) {
    digitalWrite(22, HIGH);
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(22, LOW);
    digitalWrite(10, LOW);
  }

  digitalWrite(21, HIGH);
  int val = analogRead(26);
  avgval = (avgval * 99 + val) / 100;
  if (loopcount % 5000 == 250) { //map(value, fromLow, fromHigh, toLow, toHigh)
    blink_interval = map (avgval, 20, 4000, 150000, 600000); //int(avgval * 3 * (333333 / 2000 ));
    //Serial.printf("val %d, avgval %d, blink %d \n", val, avgval, blink_interval );
  }

  int newtouch = digitalRead(11);
  if (millis() > (touchdebounce + 500)) {
    if (newtouch > 0) {
      touch++;

      Serial.printf("%d, newtouch %d, touch was %d\n", millis(), newtouch, touch);
      touchdebounce = millis();
      if (touch % 2 == 0){
        resetRandom();
      }
    }
  } 

  if (touch % 2 == 0) {
    reg();
  } else {
    switch (phase) {
      case 0:
        if (start > 13000) {
          Serial.printf("%d clive\n", millis());
          phase = 1;
        }
        if (loopcount % 6 > 0) {
          displayNext();
        } else {
          reg();
        }
        break;
      case 1:
        if (start > 15000) {
          Serial.printf("%d clive 2\n", millis());
          phase = 2;
        }
        if (loopcount % 10 > 6) {
          f_clive();
        } else {
          reg();
        }
        break;
      case 2:
        if (start > 17000) {
          Serial.printf("%d clive 3\n", millis());
          phase = 3;
        }
        if (loopcount % 10  > 2) {
          f_clive();
        } else {
          reg();
        }
        break;
      case 3:
        if (start > 17400) {
          Serial.printf("%d no four\n", millis());
          displayStringStart("f r e e b e e r", 500);
          phase = 4;
        }
        f_clive();
        break;
      case 4:
        if (start > 25000) {
          Serial.printf("%d normal and reset\n", millis());
          resetRandomZero();
          phase = 5;
        }
        f_no_four();
        displayNext();
        break;

      case 5:
        if (start > 35000) {
          Serial.printf("%d smile f \n", millis());
          phase = 6;
        }
        if (loopcount % 6 > 0) {
          displayNext();
        } else {
          reg();
        }
        break;
      case 6:
        if (start > 37000) {
          Serial.printf("%d smile b \n", millis());
          phase = 7;
        }
        if (loopcount % 6  > 0) {
          f_smilef();
        } else {
          reg();
        }
        break;
      case 7:
        if (start > 39000) {
          Serial.printf("%d smile \n", millis());
          phase = 10;
        }
        if (loopcount % 6 > 0) {
          f_smileb();
        } else {
          reg();
        }
        break;

      case 10:
        if (start > 42000) {
          Serial.printf("%d normal \n", millis());
          phase = 11;
        }
        if (loopcount % 6  > 0) {
          f_smilem();
        } else {
          reg();
        }
        break;
      case 11:
        if (start > 59000) {
          Serial.printf("%d happy \n", millis());
          phase = 12;
        }
        if (loopcount % 6 > 0) {
          displayNext();
        } else {
          reg();
        }
        break;
      case 12:
        phase = 121;
        for (int row = 0; row < 8; row++) {
          for (int col = 0; col < 10; col++) {
            if (smilem[row][col] > 0) {
              blink_remain[row][col] =   5 * blink_interval;
            }
          }
        }
        break;
      case 121:
        if (start > 64000) {
          phase = 13;
          resetRandom();
        }
        if (loopcount % 6 > 0) {
          displayNext();
        } else {
          reg();
        }
        break;
      case 13:
        if (start > 75000) {
          phase = 14;
        }
        if (loopcount % 6 > 0) {
          displayNext();
        } else {
          reg();
        }
        break;
      case 14:
        Serial.printf("%d QED\n", millis());
        phase = 15;
        reset_the_leds_after = 1;
        displayString("QED", 1000);
        Serial.printf("%d done QED\n", millis());
        break;
      case 15:
        if (start > 180000) {
          Serial.printf("%d 120000 \n", millis());
          phase = 0;
        }
        if (loopcount % 6 > 0) {
          displayNext();
        } else {
          reg();
        }
        break;
      default:
        phase = 0;
        if (loopcount % 6 > 0) {
          displayNext();
        } else {
          reg();
        }
        break;
    }
  }

  long loop_len =  micros() - loop_start;

  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 10; col++) {
      blink_remain[row][col] = blink_remain[row][col] - loop_len;
      if ( blink_remain[row][col] < 0) {
        if (abs(blink_remain[row][col]) > blink_inter[row][col] ) {
          blink_inter[row][col] = blink_interval - 0.1 * blink_interval   +  random(0, 0.2 * blink_interval );
          blink_remain[row][col] = blink_inter[row][col];
        }
      }
    }
  }

  if (reset_the_leds_after == 1) resetRandomZero();

  if (loopcount % 100000 == 10000) {
    Serial.printf("Loop Length %d usec, blink_interval %d usec, touch %d\n",  total_loop_len / 100000, blink_interval, touch );
    total_loop_len = 0;
  }
  total_loop_len += loop_len;

}
