int threshold = 30;
int thresholdS = 20;
int thresholdE = 300;

int retriggerDelay = 50;
int retriggerS = 5;
int retriggerE = 150;

int floorThreshold = 110;

long debounceDelay = 100;

long lastDebounceTimes[] = {0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,
                             0,0};

int buttonStates[]     = {0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0};
int buttonLastStates[] = {0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0};

void readThreshold() {
  int thresh = analogRead(0);
  threshold = map(thresh, 0, 1023, thresholdS, thresholdE);
}

void readRetrigger() {
  int rettr = analogRead(1);
  retriggerDelay = map(rettr, 0, 1023, retriggerS, retriggerE);
}


void peachRead(int number, int reading, int midiNote, int midiChannel){
  
  if(number == 3) {
    if(reading > floorThreshold ) {
       buttonStates[number] = 1;
    }  else {
       buttonStates[number] = 0;
    }
  } else {
    if(reading > threshold ) {
       buttonStates[number] = 1;
    }  else {
       buttonStates[number] = 0;
    }
  }
  
  if (buttonStates[number] != buttonLastStates[number]){
   if ((millis() - lastDebounceTimes[number]) < retriggerDelay && buttonStates[number] == 1) {
     return;
   }
   if(buttonStates[number] == 1) {
     MIDI.sendNoteOn(midiNote,127,midiChannel);
     digitalWrite(6,LOW);
   } else {
     MIDI.sendNoteOff(midiNote,0,midiChannel);
     digitalWrite(6,HIGH);
     lastDebounceTimes[number] = millis();
   }
  }
  
  buttonLastStates[number] = buttonStates[number];
}

