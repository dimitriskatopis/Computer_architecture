/*
This code was designed by Katopis Dimitrios.
It is intended for academic use at the Department of Informatics and Telecommunication
of University of Ioannina 
*/
/*
This code was designed and compiled at Arduino ver. 1.8.13
Αυος ο κωδικας μετραει την αποσταση αντικειμων χρησιμοποιωντας εναν αισθητηρα Ulstrasonic
*/



#define echoPin 2 // συνδέστε την ακίδα D2 Arduino στην ακίδα Echo του HC-SR04
#define trigPin 3 // συνδέστε την ακίδα D3 Arduino στην ακίδα Trig του HC-SR04

long duration; // μεταβλητή για τη διάρκεια της διαδρομής των ηχητικών κυμάτων
double distance; // μεταβλητή για τη μέτρηση της απόστασης
const int buzzer = 9; //buzzer στο pin 9
int led1=12;
int led2=11;
int led3=10;
int led4=8;
int led5=7;  //αρχικοποιηση λεντ αποστασεων 
int led6=6;
int led7=5;
int led8=4; 

void setup() {
  pinMode(trigPin, OUTPUT); // Ορίζει το trigPin ως OUTPUT
  pinMode(echoPin, INPUT); // Ορίζει το echoPin ως INPUT
  Serial.begin(9600);    // Η σειριακή επικοινωνία ξεκινά με ταχύτητα baudrate 9600
  Serial.println("Ultrasonic Sensor HC-SR04");
  pinMode(buzzer, OUTPUT); // buzzer - pin 9 ως output
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  
}
void loop() {
  // Αρχικοποίηση του trigPin ως LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Θέτουμε το trigPin HIGH (ACTIVE) για 10 μικροδευτερόλεπτα
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Διαβάζει το echoPin, επιστρέφει το χρόνο διαδρομής του ηχητικού κύματος σε μικροδευτερόλεπτα
  duration = pulseIn(echoPin, HIGH);

  // Υπολογισμός της απόστασης
  distance = duration * 0.034 / 2; // Ταχύτητα ηχητικού κύματος διαιρούμενη με 2 (πηγαινει και πίσω)

  // Εμφανίζει την απόσταση στη σειριακή οθόνη
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  
  if (distance>=1.0 && distance<=5.0 )
  {	
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led8,LOW);
    tone(buzzer, 1000);  // Αποστολή 1KHz ηχητικού σήματος...
  	delay(100);        // για 1sec
  	noTone(buzzer);     // Σταματάμε τον ήχο
  	delay(100);    
  }
  else if (distance>5.0 && distance<=7.0)
  { 
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led8,LOW);
    tone(buzzer, 1000);  
  	delay(200);        
  	noTone(buzzer);  
  	delay(200);   
    
  }
  else if (distance>7.0 && distance<=8.0)
  { 
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led8,LOW);
    tone(buzzer, 1000);  
  	delay(300);        
  	noTone(buzzer);  
  	delay(300);
  }
  else if(distance>8.0 && distance<=10.0)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led8,LOW);
    tone(buzzer, 1000);  
  	delay(400);        
  	noTone(buzzer);  
  	delay(400);
  }
  else if (distance>10.0 && distance<=11.0)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,HIGH);
    digitalWrite(led6,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led8,LOW);
    tone(buzzer, 1000);  
  	delay(500);        
  	noTone(buzzer);  
  	delay(500);
    
  }
  else if (distance>11.0 && distance <=15.0)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,HIGH);
    digitalWrite(led7,LOW);
    digitalWrite(led8,LOW);
    tone(buzzer, 1000);  
  	delay(600);        
  	noTone(buzzer);  
  	delay(600);
  }
  else if (distance>15.0 && distance<=20.0)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led7,HIGH);
    digitalWrite(led8,LOW);
    tone(buzzer, 1000);  
  	delay(700);        
  	noTone(buzzer);  
  	delay(700);
                 
  }
  else if(distance>20.0)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led8,HIGH);
    tone(buzzer, 1000);  
  	delay(800);        
  	noTone(buzzer);  
  	delay(800);
  }
  
}





