Sleep_n0m1
===========

Arduino Library to place the arduino into sleep mode for a specific length of time, or a specific number of sleep cycles.

#### Authors

* [Noah Shibley](https://github.com/nullboundary)
* [Michael Grant](http://krazatchu.ca)

#### Dependencies
* none

#### Supported Devices

* Uno - Tested
* Leonardo - Tested
* Pro Mini - Tested
* Nano - Tested
* Mega - Tested
* Zero - Not supported
* Due - Not supported

#### List of Methods
```cpp

//------------------------------------------------------
// Description: sets the Arduino into idle Mode sleep,
// the least power saving, The idle mode stops the MCU
// but leaves peripherals and timers running.
//------------------------------------------------------
void idleMode();

//------------------------------------------------------
// Description: sets the Arduino into adc Mode sleep,
// This mode makes the MCU enter ADC Noise Reduction mode,
// stopping the CPU but allowing the ADC, the external interrupts,
// the 2-wire Serial Interface address watch, Timer/Counter2
// and the Watchdog to continue operating.
//------------------------------------------------------
void adcMode();

//------------------------------------------------------
// Description: sets the Arduino into power Save Mode sleep,
// The timer crystal will continue to operate in this mode,
// Timer2 still active.
//------------------------------------------------------
void pwrSaveMode();

//------------------------------------------------------
// Description: sets the Arduino into extStandby Mode sleep,
// This mode is identical to Power-save with the exception
// that the Oscillator is kept running for fast wake up
//------------------------------------------------------
void extStandbyMode();

//------------------------------------------------------
// Description: sets the Arduino into standby Mode sleep,
// This mode is identical to Power-down with the exception
// that the Oscillator is kept running for fast wake up
//------------------------------------------------------
void standbyMode();

//------------------------------------------------------
// Description: sets the Arduino into power Down Mode sleep,
// The most power saving, all systems are powered down
// except the watch dog timer and external reset
//------------------------------------------------------
void pwrDownMode();

//------------------------------------------------------  
// Description: Works like the Arduino delay function, sets the
// Arduino into sleep mode for a specified time.
// Parameters: (unsigned long) time in ms of the sleep cycle
//------------------------------------------------------  
void sleepDelay(unsigned long sleepTime);

//------------------------------------------------------
// Description: Works like the Arduino delay function, sets the
// Arduino into sleep mode for a specified time.
// Parameters: (unsigned long) time in ms of the sleep cycle
//            (boolean) prevents the Arduino from entering sleep
//------------------------------------------------------
void sleepDelay(unsigned long sleepTime,boolean &abortCycle);

//------------------------------------------------------
// Description: the WDT needs to be calibrated against timer 0
// periodically to keep the sleep time accurate. Default calibration
// occurs every 100 wake/sleep cycles. recalibrate too often will
// waste power and too rarely will make the sleep time inaccurate.
// Parameters: (int) set the # of wake/sleep cycles between calibrations
//------------------------------------------------------
void setCalibrationInterval(int interval);

//------------------------------------------------------
// Description: set the Arduino into sleep mode until an interrupt is
// triggered. The interrupt pin is passed in as parameter
// Parameters: (int) interrupt pin value, 2, 3, etc, see attachinterrupt()
//      (int) mode of trigger, HIGH,LOW,RISING,CHANGE
//------------------------------------------------------
void sleepPinInterrupt(int interruptPin,int mode);

//------------------------------------------------------
// Deprecated, please use sleepPinInterrupt()
// Description: set the Arduino into sleep mode until an interrupt is
// triggered. The interrupts are passed in as parameters
// Parameters: (int) interrupt value, 0, 1, etc, see attachinterrupt()
//      (int) mode of trigger, HIGH,LOW,RISING,CHANGE
//------------------------------------------------------
void sleepInterrupt(int interrupt,int mode);

```	    
