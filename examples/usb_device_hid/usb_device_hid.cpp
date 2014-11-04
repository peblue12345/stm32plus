/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013,2014 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#include "config/stm32plus.h"
#include "config/usb.h"


using namespace stm32plus;


/**
 */

class UsbDeviceHidTest {

  UsbHidDevice<UsbInternalFsPhy> usb;

  public:

    void run() {

      for(;;);
    }
};


/*
 * Main entry point
 */

int main() {

  UsbDeviceHidTest test;
  test.run();

  // not reached
  return 0;
}
