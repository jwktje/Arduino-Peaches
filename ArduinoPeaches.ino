#include <CapacitiveSensor.h>
#include <MIDI.h>
#include <peaches.ino>

boolean debug = false;

MIDI_CREATE_DEFAULT_INSTANCE();

//Inputs
int o1 =  13;
int o2 =  12;
int o3 =  11;
int o4 =  10;
int o5 =  9;
int o6 =  8;
int o7 =  14;
int o8 =  15;
int o9 =  16;
int o10 = 17;

int o11 = 18;
int o12 = 19;
int o13 = 20;
int o14 = 21;
int o15 = 62;
int o16 = 63;
int o17 = 64;
int o18 = 65;
int o19 = 66;
int o20 = 67;

int o21 = 68;
int o22 = 69;
int o23 = 53;
int o24 = 52;
int o25 = 51;
int o26 = 50;
int o27 = 49;

//Peaches
CapacitiveSensor p1 = CapacitiveSensor(o1,22);
CapacitiveSensor p2 = CapacitiveSensor(o2,23);
CapacitiveSensor p3 = CapacitiveSensor(o3,24);
CapacitiveSensor p4 = CapacitiveSensor(o4,25);

CapacitiveSensor p5 = CapacitiveSensor(o5,26);
CapacitiveSensor p6 = CapacitiveSensor(o6,27);
CapacitiveSensor p7 = CapacitiveSensor(o7,28);
CapacitiveSensor p8 = CapacitiveSensor(o8,29);

CapacitiveSensor p9 = CapacitiveSensor(o9,30);
CapacitiveSensor p10 = CapacitiveSensor(o10,31);
CapacitiveSensor p11 = CapacitiveSensor(o11,32);
CapacitiveSensor p12 = CapacitiveSensor(o12,33);

CapacitiveSensor p13 = CapacitiveSensor(o13,34);
CapacitiveSensor p14 = CapacitiveSensor(o14,35);
CapacitiveSensor p15 = CapacitiveSensor(o15,36);
CapacitiveSensor p16 = CapacitiveSensor(o16,37);

CapacitiveSensor p17 = CapacitiveSensor(o17,38);
CapacitiveSensor p18 = CapacitiveSensor(o18,39);
CapacitiveSensor p19 = CapacitiveSensor(o19,40);
CapacitiveSensor p20 = CapacitiveSensor(o20,41);

CapacitiveSensor p21 = CapacitiveSensor(o21,42);
CapacitiveSensor p22 = CapacitiveSensor(o22,43);
CapacitiveSensor p23 = CapacitiveSensor(o23,44);
CapacitiveSensor p24 = CapacitiveSensor(o24,45);

CapacitiveSensor p25 = CapacitiveSensor(o25,46);
CapacitiveSensor p26 = CapacitiveSensor(o26,47);
CapacitiveSensor p27 = CapacitiveSensor(o27,48);

int samples = 6;
int timeout = 10;
int debugState = 0;
int currentState;

void setup() {
  if(debug == false) {
    MIDI.begin();
  } 
  else {
    Serial.begin(9600);
  }
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);

  //Pinmodes
  pinMode(o1,OUTPUT);
  pinMode(o2,OUTPUT);
  pinMode(o3,OUTPUT);
  pinMode(o4,OUTPUT);

  pinMode(o5,OUTPUT);
  pinMode(o6,OUTPUT);
  pinMode(o7,OUTPUT);
  pinMode(o8,OUTPUT);

  pinMode(o9,OUTPUT);
  pinMode(o10,OUTPUT);
  pinMode(o11,OUTPUT);
  pinMode(o12,OUTPUT);

  pinMode(o13,OUTPUT);
  pinMode(o14,OUTPUT);
  pinMode(o15,OUTPUT);
  pinMode(o16,OUTPUT);

  pinMode(o17,OUTPUT);
  pinMode(o18,OUTPUT);
  pinMode(o19,OUTPUT);
  pinMode(o20,OUTPUT);

  pinMode(o21,OUTPUT);
  pinMode(o22,OUTPUT);
  pinMode(o23,OUTPUT);
  pinMode(o24,OUTPUT);

  pinMode(o25,OUTPUT);
  pinMode(o26,OUTPUT);
  pinMode(o27,OUTPUT);

  //Set timeouts
  p1.set_CS_Timeout_Millis(timeout);
  p2.set_CS_Timeout_Millis(timeout);
  p3.set_CS_Timeout_Millis(timeout);
  p4.set_CS_Timeout_Millis(timeout);

  p5.set_CS_Timeout_Millis(timeout);
  p6.set_CS_Timeout_Millis(timeout);
  p7.set_CS_Timeout_Millis(timeout);
  p8.set_CS_Timeout_Millis(timeout);

  p9.set_CS_Timeout_Millis(timeout);
  p10.set_CS_Timeout_Millis(timeout);
  p11.set_CS_Timeout_Millis(timeout);
  p12.set_CS_Timeout_Millis(timeout);

  p13.set_CS_Timeout_Millis(timeout);
  p14.set_CS_Timeout_Millis(timeout);
  p15.set_CS_Timeout_Millis(timeout);
  p16.set_CS_Timeout_Millis(timeout);

  p17.set_CS_Timeout_Millis(timeout);
  p18.set_CS_Timeout_Millis(timeout);
  p19.set_CS_Timeout_Millis(timeout);
  p20.set_CS_Timeout_Millis(timeout);

  p21.set_CS_Timeout_Millis(timeout);
  p22.set_CS_Timeout_Millis(timeout);
  p23.set_CS_Timeout_Millis(timeout);
  p24.set_CS_Timeout_Millis(timeout);

  p25.set_CS_Timeout_Millis(timeout);
  p26.set_CS_Timeout_Millis(timeout);
  p27.set_CS_Timeout_Millis(timeout);

}

void loop() {

  readThreshold();
  readRetrigger();

  //Get peach
  int r1 =  p1.capacitiveSensor(samples);
  int r2 =  p2.capacitiveSensor(samples);
  int r3 =  p3.capacitiveSensor(samples);
  int r4 =  p4.capacitiveSensor(samples);

  int r5 =  p5.capacitiveSensor(samples);
  int r6 =  p6.capacitiveSensor(samples);
  int r7 =  p7.capacitiveSensor(samples);
  int r8 =  p8.capacitiveSensor(samples);

  int r9 =  p9.capacitiveSensor(samples);
  int r10 =  p10.capacitiveSensor(samples);
  int r11 =  p11.capacitiveSensor(samples);
  int r12 =  p12.capacitiveSensor(samples);

  int r13 =  p13.capacitiveSensor(samples);
  int r14 =  p14.capacitiveSensor(samples);
  int r15 =  p15.capacitiveSensor(samples);
  int r16 =  p16.capacitiveSensor(samples);

  int r17 =  p17.capacitiveSensor(samples);
  int r18 =  p18.capacitiveSensor(samples);
  int r19 =  p19.capacitiveSensor(samples);
  int r20 =  p20.capacitiveSensor(samples);

  int r21 =  p21.capacitiveSensor(samples);
  int r22 =  p22.capacitiveSensor(samples);
  int r23 =  p23.capacitiveSensor(samples);
  int r24 =  p24.capacitiveSensor(samples);

  int r25 =  p25.capacitiveSensor(samples);
  int r26 =  p26.capacitiveSensor(samples);
  int r27 =  p27.capacitiveSensor(samples);

  if(debug == false) {
    //Parse peach
    peachRead(0, r1, 0, 2);
    peachRead(1, r2, 1, 2);
    peachRead(2, r3, 2, 2);
    peachRead(3, r4, 3, 2);

    peachRead(4, r5, 4, 2);
    peachRead(5, r6, 5, 2);
    peachRead(6, r7, 6, 2);
    peachRead(7, r8, 7, 2);

    peachRead(8, r9, 8, 2);
    peachRead(9, r10, 9, 2);
    peachRead(10, r11, 0, 3);
    peachRead(11, r12, 0, 16);

    peachRead(12, r13, 1, 16);
    peachRead(13, r14, 13, 4);
    peachRead(14, r15, 17, 4);
    peachRead(15, r16, 18, 4);

    peachRead(16, r17, 7, 6);
    peachRead(17, r18, 8, 6);
    peachRead(18, r19, 10, 6);
    peachRead(19, r20, 10, 5);

    peachRead(20, r21, 10, 1);
    peachRead(21, r22, 12, 1);
    peachRead(22, r23, 14, 1);
    peachRead(23, r24, 15, 1);

    peachRead(24, r25, 17, 1);
    peachRead(25, r26, 19, 1);
    peachRead(26, r27, 0, 7);
  } 
  else {
    Serial.println(r1);
    /*
    if(r2 > 120) {
     currentState = 1;
     if(debugState != currentState) {
     Serial.println("on"); 
     debugState = 1;
     }
     } else {
     currentState = 0;
     if(debugState != currentState) {
     Serial.println("off"); 
     debugState = 0;
     }
     delay(20);
     } 
     */
    delay(500);
  }
}

