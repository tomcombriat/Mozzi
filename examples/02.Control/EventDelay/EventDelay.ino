/*  Example of a sound being toggled on an off,
    using Mozzi sonification library.

    Demonstrates scheduling with EventDelay.
    EventDelay is a way to make non-blocking
    time delays for events.  Use this instead of
    the Arduino delay() function, which doesn't
    work with Mozzi.

    Circuit: Audio output on digital pin 9 on a Uno or similar, or
    DAC/A14 on Teensy 3.1, or
    check the README or http://sensorium.github.io/Mozzi/

   Mozzi documentation/API
   https://sensorium.github.io/Mozzi/doc/html/index.html

   Mozzi help/discussion/announcements:
   https://groups.google.com/forum/#!forum/mozzi-users

   Copyright 2012-2024 Tim Barrass and the Mozzi Team

   Mozzi is licensed under the GNU Lesser General Public Licence (LGPL) Version 2.1 or later.
*/

#define MOZZI_CONTROL_RATE 64
#include <Mozzi.h>
#include <Oscil.h> // oscillator template
#include <tables/sin8192_int8.h> // sine table for oscillator
#include <EventDelay.h>

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN8192_NUM_CELLS, MOZZI_AUDIO_RATE> aSin(SIN8192_DATA);

// for scheduling audio gain changes
EventDelay kGainChangeDelay;

char gain = 1;

void setup(){
  startMozzi();
  aSin.setFreq(330); // set the frequency
  kGainChangeDelay.set(1000); // 1 second countdown, within resolution of MOZZI_CONTROL_RATE
}


void updateControl(){
  if(kGainChangeDelay.ready()){
    gain = 1-gain; // flip 0/1
    kGainChangeDelay.start();
  }
}


AudioOutput updateAudio(){
  return AudioOutput::from8Bit(aSin.next()*gain);
}


void loop(){
  audioHook();
}
