// DMX_Relay_8ch_v01 - September 15, 2012
 // receives DMX data and operates an 8-channnel relay board via digital outs
 //
 // DMX routines Copyright (c) 2011 by Matthias Hertel, http://www.mathertel.de
 //

 #include

 //this device's DMX start address
 #define DMX_START_ADDRESS 1
 // number of DMX channels to reserve for this device
 #define DMX_NUM_CHANNELS 8

 //output pin setup
 byte relay_pin[8] = {2,3,4,5,6,7,8,9};

 void setup()
 {
   //initialize DMX receiver
   DMXSerial.init(DMXReceiver);

   //initialize pin outputs
   for (int p=0; p<8; p++){
     pinMode(relay_pin[p], OUTPUT);
     digitalWrite(relay_pin[p], LOW);
   }
 }

 void loop()
 {
   for (int p=0; p<8; p++){

     if (DMXSerial.read(DMX_START_ADDRESS+p) < 128)
     {
       digitalWrite(relay_pin[p], LOW);
     }
     else
     {
       digitalWrite(relay_pin[p], HIGH);
     }
   }
 }

