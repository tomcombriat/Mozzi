/*
 * LowPassFilter.h
 *
 * Copyright 2012 Tim Barrass
 *
 * This file is part of Mozzi.
 *
 * Mozzi is licensed under a Creative Commons
 * Attribution-NonCommercial-ShareAlike 4.0 International License.
 *
 */

#ifndef LOWPASS_H_
#define LOWPASS_H_

/*
simple resonant filter posted to musicdsp.org by Paul Kellett
http://www.musicdsp.org/archive.php?classid=3#259

// set feedback amount given f and q between 0 and 1
fb = q + q/(1.0 - f);

// for each sample...
buf0 = buf0 + f * (in - buf0 + fb * (buf0 - buf1));
buf1 = buf1 + f * (buf0 - buf1);
out = buf1;

fixed point version of the filter
"dave's blog of art and programming" http://www.pawfal.org/dave/blog/2011/09/
*/

// we are using .n fixed point (n bits for the fractional part)
//#define FX_SHIFT 8
//#define SHIFTED_1 ((uint8_t)255)

/** A resonant low pass filter for audio signals.
 */
template<typename su=uint8_t, typename ms=int, typename mu=unsigned int, typename ls1=int, typename ls2=long>
class LowPassFilterNbits
{

public:
  /** Constructor.
   */
  LowPassFilterNbits() { ; }

  /** deprecated.  Use setCutoffFreqAndResonance(uint8_t cutoff, uint8_t
  resonance).

  Set the cut off frequency,
  @param cutoff use the range 0-255 to represent 0-8191 Hz (AUDIO_RATE/2).
  Be careful of distortion at the lower end, especially with high resonance.
  */
  void setCutoffFreq(su cutoff)
	{
    f = cutoff;
    fb = q + ucfxmul(q, SHIFTED_1 - cutoff);
  }

  /** deprecated.  Use setCutoffFreqAndResonance(uint8_t cutoff, uint8_t
  resonance).

  Set the resonance. If you hear unwanted distortion, back off the resonance.
  After setting resonance, you need to call setCuttoffFreq() to hear the change!
  @param resonance in the range 0-255, with 255 being most resonant.
  @note	Remember to call setCuttoffFreq() after resonance is changed!
  */
  void setResonance(su resonance) { q = resonance; }

  /**
  Set the cut off frequency and resonance.  Replaces setCutoffFreq() and
  setResonance().  (Because the internal calculations need to be done whenever either parameter changes.)
  @param cutoff range 0-255 represents 0-8191 Hz (AUDIO_RATE/2).
  Be careful of distortion at the lower end, especially with high resonance.
  @param resonance range 0-255, 255 is most resonant.
  */
  void setCutoffFreqAndResonance(su cutoff, su resonance)
	{
    f = cutoff;
    q = resonance; // hopefully optimised away when compiled, just here for
                   // backwards compatibility
    fb = q + ucfxmul(q, SHIFTED_1 - cutoff);
  }

  /** Calculate the next sample, given an input signal.
  @param in the signal input.
  @return the signal output.
  @note Timing: about 11us.
  */
  //	10.5 to 12.5 us, mostly 10.5 us (was 14us)
  inline ms next(ms in)
	{
    // setPin13High();
    buf0 += fxmul(((in - buf0) + fxmul(fb, buf0 - buf1)), f);
    buf1 += ifxmul(buf0 - buf1, f); // could overflow if input changes fast
    // setPin13Low();
    return buf1;
  }

private:
  su q;
  su f;
  mu fb;
  ms buf0, buf1;
const su FX_SHIFT = sizeof(su) << 3;
const su SHIFTED_1 = (1<<FX_SHIFT)-1;

  // // multiply two fixed point numbers (returns fixed point)
  // inline
  // long fxmul(long a, long b)
  // {
  // 	return (a*b)>>FX_SHIFT;
  // }

  // multiply two fixed point numbers (returns fixed point)
  inline mu ucfxmul(su a, su b)
	{
    return (((mu)a * b) >> FX_SHIFT);
  }

  // multiply two fixed point numbers (returns fixed point)
  inline ms ifxmul(ls1 a, su b) { return ((a * b) >> FX_SHIFT); }

  // multiply two fixed point numbers (returns fixed point)
  inline ls2 fxmul(ls2 a, ms b) { return ((a * b) >> FX_SHIFT); }
};

typedef LowPassFilterNbits<> LowPassFilter;
typedef LowPassFilterNbits<uint16_t, int32_t, uint32_t, int64_t, int64_t> LowPassFilter16;


/**
@example 10.Audio_Filters/LowPassFilter/LowPassFilter.ino
This example demonstrates the LowPassFilter class.
*/

#endif /* LOWPASS_H_ */
