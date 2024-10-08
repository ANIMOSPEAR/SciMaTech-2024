              // motor one
int enA = 10;
int in1 = 8;
int in2 = 9;
// motor two
int enB = 7;
int in3 = 5;
int in4 = 6;
//REMINDER DAPAT TAMANG SOCKET NAKA SAK SAK ANG WIRES!!!

char t;

void left()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}

void right()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
}

void backward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
}

void forward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
} 

void forwardleft(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enB, 255);
  analogWrite(enA, 50);
}

void forwardright(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enB, 50);
  analogWrite(enA, 255);
}

void backleft(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enB, 255);
  analogWrite(enA, 50);
}

void backright(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enB, 50);
  analogWrite(enA, 255);
}

void Stop()
{
  //side R
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()){    
  t = Serial.read();
  Serial.println(t);
  }
   if(t == 'F')
   {         
    Serial.println("f");   
  // forwardMotorA();
  // forwardMotorB();
  forward();
 }
  if(t == 'B')
  {         
    Serial.println("b");   
  backward();  
 }
  if(t == 'L')
  {            
    Serial.println("l");
  left();
 }
  if(t == 'R')
  {            
    Serial.println("r");
  right();
 }
 if (t == 'G') {
  Serial.println("g");
  forwardleft();
 }
  if (t == 'I') {
    Serial.println("t");
    forwardright();
 }
  if (t == 'H') {
    Serial.println("h");
    backleft();
 }
  if (t == 'J') {
    Serial.println("j");
    backright();
 }

  if(t == 'S')
  {            
  Stop();
 }
}

// void setup(){

// }

// void loop(){

// }