inline void print_samples() {
  for (int i = 0; i < SAMPLE_LENGTH; i++) {
    Serial.print(float(sample[i])/max_value);
    Serial.print(i == (SAMPLE_LENGTH -1) ? ' ' : ',');
  }
  Serial.println("");
}

inline void print_samples_noise() {
  for (int i = 0; i < SAMPLE_LENGTH; i++) {
    Serial.print(float(sample[i])/max_value);
    Serial.print(',');
  }
  Serial.println(2);
}

inline void print_samples_for_audacity() {
  for (int i = 0; i < SAMPLE_LENGTH; i++) {
    Serial.print(float(sample[i])/max_value);
    Serial.print(' ');
  }
  Serial.println("");
}
