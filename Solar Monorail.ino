int ir_input=7;
int m_forward=8;
int m_backward=9;

void setup() {
  Serial.begin(115200);
  moveFront();
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);    
}

void loop() {
  Serial.println("Checking...");
  
  int ir_sensor=digitalRead(ir_input);
  if(ir_sensor==HIGH){
    Serial.println("Running");
    moveFront();
  }
  if(ir_sensor==LOW){
    Serial.println("Junction ahead. STOP");
    moveStop();
    delay(10000);
    moveFront();
  }
delay(200);
}

void moveFront() {
    digitalWrite(m_forward, HIGH);
    digitalWrite(m_backward, HIGH);   
    delay(300);
}

void moveStop() {
    digitalWrite(m_forward, LOW);
    digitalWrite(m_backward, LOW);    
    delay(200);
}
