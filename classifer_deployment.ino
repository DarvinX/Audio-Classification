#include "pca.h"
#include "classifiers.h"

#define SAMPLE_LENGTH 256
#define samplingFreq 9400
#define MIC_PORT 1
#define PADDING 32
#define SQUARED_SUM_THRESHOLD 8500

double sample[SAMPLE_LENGTH] = {0.0};
double sample_imag[SAMPLE_LENGTH] = {0.0};
uint8_t middle_point = 0;
uint8_t max_value = 0;
uint8_t binary_class = 1;
uint8_t threshold;

boolean hasdata = false, take_sample = false;

unsigned long counter = 0;
unsigned long sum = 0;
unsigned long squared_sum = 0;
double FFT_sum;
double pca_output[2];

Eloquent::ML::Port::PCA pca;
Eloquent::ML::Port::DecisionTree clf;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  init_running_mode();
  reset_adc();
  calculate_midpoint();
  reset_adc();
}

void loop() {
  if (hasdata) {
    cli();
    if (squared_sum > SQUARED_SUM_THRESHOLD) {
//      remove_after_2nd_decimal();
      perform_fft();
      normalise_data();
      pca.transform(sample, pca_output);
      Serial.print(clf.predict(pca_output));
    }
    reset_adc();
    sei();
  }
}
