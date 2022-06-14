#include "arduinoFFT.h"

arduinoFFT FFT = arduinoFFT();

void perform_fft(){
  FFT.Windowing(sample, SAMPLE_LENGTH, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(sample, sample_imag, SAMPLE_LENGTH, FFT_FORWARD);
  FFT.ComplexToMagnitude(sample, sample_imag, SAMPLE_LENGTH);
}
