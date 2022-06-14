

void gen_random_binary_class(){
  binary_class = random(2);
}

void indicate_class(){
  digitalWrite(LED_BUILTIN, binary_class);
}

void remove_after_2nd_decimal(){
  for(int i=0; i< SAMPLE_LENGTH; i++){
     sample[i] = float(int(sample[i]*100))/100 ;
  }
}

void normalise_data(){
  FFT_sum = 0;
  for(int i=0; i< SAMPLE_LENGTH; i++){
    FFT_sum += sample[i];
  }
  for(int i=0; i< SAMPLE_LENGTH; i++){
    sample[i] = sample[i]/FFT_sum;
  }
}
