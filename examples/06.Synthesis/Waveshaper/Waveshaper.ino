/*  Example using waveshaping to modify the spectrum of an audio signal
    using Mozzi sonification library.

    Demonstrates the use of WaveShaper(), EventDelay(), Smooth(),
    rand(), and FixMath.

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

#include <Mozzi.h>
#include <Oscil.h>
#include <WaveShaper.h>
#include <EventDelay.h>
#include <mozzi_rand.h>
#include <mozzi_midi.h>
#include <Smooth.h>
#include <FixMath.h>
#include <tables/sin2048_int8.h>
#include <tables/waveshape_chebyshev_3rd_256_int8.h>
#include <tables/waveshape_chebyshev_6th_256_int8.h>
#include <tables/waveshape_compress_512_to_488_int16.h>

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN2048_NUM_CELLS, MOZZI_AUDIO_RATE> aSin(SIN2048_DATA); // sine wave sound source
Oscil <SIN2048_NUM_CELLS, MOZZI_AUDIO_RATE> aGain1(SIN2048_DATA); // to fade sine wave in and out before waveshaping
Oscil <SIN2048_NUM_CELLS, MOZZI_AUDIO_RATE> aGain2(SIN2048_DATA); // to fade sine wave in and out before waveshaping

// Chebyshev polynomial curves, The nth curve produces the n+2th harmonic component.
WaveShaper <char> aCheby3rd(CHEBYSHEV_3RD_256_DATA); // 5th harmonic
WaveShaper <char> aCheby6th(CHEBYSHEV_6TH_256_DATA); // 8th harmonic
WaveShaper <int> aCompress(WAVESHAPE_COMPRESS_512_TO_488_DATA); // to compress instead of dividing by 2 after adding signals

// for scheduling note changes
EventDelay kChangeNoteDelay;

// for random notes
UFix<7,0> octave_start_note = 42;

// smooth transitions between notes
Smooth <UFix<14,12>> kSmoothFreq(0.85f);
UFix<14,2> target_freq, smoothed_freq;  //Optimization to have the frequencies on 16bits only. 


void setup(){
  startMozzi(); // :)
  randSeed(); // reseed the random generator for different results each time the sketch runs
  aSin.setFreq(110); // set the frequency
  aGain1.setFreq(2.f); // use a float for low frequencies, in setup it doesn't need to be fast
  aGain2.setFreq(.4f);
  kChangeNoteDelay.set(4000); // note duration ms, within resolution of MOZZI_CONTROL_RATE
}

byte rndPentatonic(){
  byte note = rand((byte)5);
  switch(note){
  case 0:
    note = 0;
    break;
  case 1:
    note = 3;
    break;
  case 2:
    note = 5;
    break;
  case 3:
    note = 7;
    break;
  case 4:
    note = 10;
    break;
  }
  return note;
}

void updateControl(){
  if(kChangeNoteDelay.ready()){
    if(rand((byte)5)==0){ // about 1 in 5 or so
      // change octave to midi 24 or any of 3 octaves above
      octave_start_note = (rand((byte)4)*12)+36;
    }
    auto midi_note = octave_start_note + toUInt(rndPentatonic());
    target_freq = mtof(midi_note); // mtof return a UFix<16,16>, which is casted to UFix<14,2> (could overflow if the frequency is greater than 16kHz)
    kChangeNoteDelay.start();
  }
  smoothed_freq = kSmoothFreq.next(target_freq); // temporarily scale up target_freq to get better int smoothing at low values
  aSin.setFreq(smoothed_freq); 
}


AudioOutput updateAudio(){
  char asig0 = aSin.next(); // sine wave source
  // make 2 signals fading in and out to show effect of amplitude when waveshaping with Chebyshev polynomial curves
  // offset the signals by 128 to fit in the 0-255 range for the waveshaping table lookups
  byte asig1 = (byte)128+((asig0*((byte)128+aGain1.next()))>>8);
  byte asig2 = (byte)128+((asig0*((byte)128+aGain2.next()))>>8);
  // get the waveshaped signals
  char awaveshaped1 = aCheby3rd.next(asig1);
  char awaveshaped2 = aCheby6th.next(asig2);
  // use a waveshaping table to squeeze 2 summed 8 bit signals into the range -244 to 243
  int awaveshaped3 = aCompress.next(256u + awaveshaped1 + awaveshaped2);
  return MonoOutput::fromAlmostNBit(9, awaveshaped3);
}


void loop(){
  audioHook(); // required here
}
