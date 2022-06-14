
void init_running_mode() {
  cli();
 
  ADCSRA = 0;
  ADCSRB = 0;
  ADMUX |= MIC_PORT;      //set up continuous sampling of analog pin adport
  ADMUX |= (1 << REFS0);  //reference voltage
  ADMUX |= (1 << ADLAR);  //left align the ADC value

  // 128 prescalar - 9.6 Khz sampling
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  ADCSRA |= (1 << ADATE);  //enable auto trigger
  ADCSRA |= (1 << ADIE);
  ADCSRA |= (1 << ADEN);  //enable ADC
  ADCSRA |= (1 << ADSC);  //start ADC measurements on interrupt
  sei();
}

void calculate_midpoint(){
  take_sample = true;
  sei();
  while (take_sample) {
    delay(10);
  };

  for (int i = 0; i < SAMPLE_LENGTH; i++) {
    sum += sample[i];
  }

  middle_point = sum / SAMPLE_LENGTH;
//  
//  Serial.println(middle_point);
//  Serial.println("");
}

void calculate_ambient_squared_sum(){
  take_sample = true;
  sei();
  while (take_sample) {
    delay(10);
  };
Serial.print("squared sum ");
  Serial.println(squared_sum);

}

void reset_adc(){
  hasdata = false;
  take_sample = true;
  max_value = 0;
  squared_sum = 0;
}

ISR(ADC_vect) {
  if (take_sample) {
    if (counter < SAMPLE_LENGTH) {
      sample[counter] = (ADCH - middle_point);
      sample_imag[counter] = 0.0; // reset the imaginary part

      squared_sum += sample[counter]*sample[counter];
      // total_amplitude += abs(sample[counter]);
      if(counter > PADDING && counter < SAMPLE_LENGTH-PADDING){
        if(max_value < abs(sample[counter])){
          max_value = abs(sample[counter]);
        }  
      }
      counter++;
    } else {
      hasdata = true;
      take_sample = false;
      counter = 0;
    }
  }
}
