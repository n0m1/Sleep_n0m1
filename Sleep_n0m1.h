/************************************************************************************
 *
 * 	Name    : Sleep_n0m1.h
 * 	Author  : Noah Shibley / NoMi Design
 * 	Date    : July 10th 2011
 * 	Version : 0.1
 * 	Notes   : Some of this code comes from "Cloudy" on the arduino forum
 *			  http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1292898715
 *
 * 		    Sleep_n0m1 is free software: you can redistribute it and/or modify
 * 		    it under the terms of the GNU General Public License as published by
 * 		    the Free Software Foundation, either version 3 of the License, or
 * 		    (at your option) any later version.
 *
 * 		    Sleep_n0m1 is distributed in the hope that it will be useful,
 * 		    but WITHOUT ANY WARRANTY; without even the implied warranty of
 * 		    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * 		    GNU General Public License for more details.
 *
 * 		    You should have received a copy of the GNU General Public License
 * 		    along with Sleep_n0m1.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************************/

#ifndef SLEEP_H
#define SLEEP_H



#include <avr/sleep.h>
#include <avr/wdt.h>
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

extern "C" void WDT_vect(void) __attribute__ ((signal));
extern "C" void sleepHandler(void) __attribute__ ((signal));

class Sleep {

public:

	friend void WDT_vect(void);
	friend void sleepHandler(void);

Sleep();

  /* modes of sleep
   SLEEP_MODE_IDLE
   SLEEP_MODE_ADC
   SLEEP_MODE_PWR_SAVE
   SLEEP_MODE_EXT_STANDBY
   SLEEP_MODE_STANDBY
   SLEEP_MODE_PWR_DOWN
   */

	//------------------------------------------------------
	// Description: sets the Arduino into idle Mode sleep,
	// the least power saving, The idle mode stops the MCU
	// but leaves peripherals and timers running.
	//------------------------------------------------------
	void idleMode() { setSleepMode(SLEEP_MODE_IDLE);}

	//------------------------------------------------------
	// Description: sets the Arduino into adc Mode sleep,
	// This mode makes the MCU enter ADC Noise Reduction mode,
	// stopping the CPU but allowing the ADC, the external interrupts,
	// the 2-wire Serial Interface address watch, Timer/Counter2
	// and the Watchdog to continue operating.
	//------------------------------------------------------
	void adcMode() {setSleepMode(SLEEP_MODE_ADC);}

	//------------------------------------------------------
	// Description: sets the Arduino into power Save Mode sleep,
	// The timer crystal will continue to operate in this mode,
	// Timer2 still active.
	//------------------------------------------------------
	void pwrSaveMode() {setSleepMode(SLEEP_MODE_PWR_SAVE);}

	//------------------------------------------------------
	// Description: sets the Arduino into extStandby Mode sleep,
	// This mode is identical to Power-save with the exception
	// that the Oscillator is kept running for fast wake up
	//------------------------------------------------------
	void extStandbyMode(){setSleepMode(SLEEP_MODE_EXT_STANDBY);}

	//------------------------------------------------------
	// Description: sets the Arduino into standby Mode sleep,
	// This mode is identical to Power-down with the exception
	// that the Oscillator is kept running for fast wake up
	//------------------------------------------------------
	void standbyMode(){setSleepMode(SLEEP_MODE_STANDBY);}

	//------------------------------------------------------
	// Description: sets the Arduino into power Down Mode sleep,
	// The most power saving, all systems are powered down
	// except the watch dog timer and external reset
	//------------------------------------------------------
	void pwrDownMode(){setSleepMode(SLEEP_MODE_PWR_DOWN);}

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
	void setCalibrationInterval(int interval){ sleepCycleInterval = interval; }

	//------------------------------------------------------
	// Deprecated, please use sleepPinInterrupt()
	// Description: set the Arduino into sleep mode until an interrupt is
	// triggered. The interrupts are passed in as parameters
	// Parameters: (int) interrupt value, 0, 1, etc, see attachinterrupt()
	//      (int) mode of trigger, HIGH,LOW,RISING,CHANGE
	//------------------------------------------------------
	void sleepInterrupt(int interruptPin,int mode) __attribute__ ((deprecated));

	//------------------------------------------------------
	// Description: set the Arduino into sleep mode until an interrupt is
	// triggered. The interrupt pin is passed in as parameter
	// Parameters: (int) interrupt pin value, 2, 3, etc, see attachinterrupt()
	//      (int) mode of trigger, HIGH,LOW,RISING,CHANGE
	//------------------------------------------------------
	void sleepPinInterrupt(int interrupt,int mode);





private:

	int sleepMode_;
	unsigned long timeSleep;
	float calibv;
	volatile byte isrcalled;
	static Sleep* pSleep; //static ptr to Sleep class for the ISR
	int sleepCycleCount;
	int sleepCycleInterval;

   void setSleepMode(int mode);
   void WDT_Off();
   void WDT_On(byte psMask);
   int sleepWDT(unsigned long remainTime,boolean &abortCycle);
   void calibrateTime(unsigned long sleepTime,boolean &abortCycle); //calibrate the time keeping difference between WDT and Timer0
   unsigned long WDTMillis();	// Estimated millis is real clock + calibrated sleep time

};

#endif
