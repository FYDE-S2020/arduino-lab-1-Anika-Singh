#define LED_BUILTIN 2
int number = 1;
void setup() {
  // put your setup code here, to run once:
 pinMode(LED_BUILTIN, OUTPUT);
}

void timeBlink(int number){
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250*number);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(250*number);                       // wait for a second 
}


void dimmer(int freq, int duty) {
  int period, onTime, offTime;
  period = 1000/freq;
  onTime = period * duty / 100;
  offTime = period - onTime;
  digitalWrite(LED_BUILTIN, HIGH);
  delay(onTime);
  digitalWrite(LED_BUILTIN, LOW);
  delay(offTime);
}

void loop() {
  dimmer(20, number);  //increase the freq so that the dimming will occur
  number++;
   if(number == 4){
    number = 1;
    
}
}
