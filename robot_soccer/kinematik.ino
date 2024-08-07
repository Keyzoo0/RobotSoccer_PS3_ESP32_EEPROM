
void setup_motor(){
  pinMode(EN , OUTPUT);
  ledcAttachPin(M1A, PWM_M1A);
  ledcSetup(PWM_M1A, freq, res);

  ledcAttachPin(M1B, PWM_M1B);
  ledcSetup(PWM_M1B, freq, res);

  ledcAttachPin(M2A, PWM_M2A);
  ledcSetup(PWM_M2A, freq, res);

  ledcAttachPin(M2B, PWM_M2B);
  ledcSetup(PWM_M2B, freq, res);
}




void kinMotor(int x, int y, int th) {
  m1 = lambda * (cos(d2r(0))*x + sin(d2r(0))*y    + LengthAlpha*d2r(th));
  m2 = lambda * (cos(d2r(180))*x + sin(d2r(180))*y  + LengthAlpha*d2r(th));
  
  Serial.printf("lx:%3d,ly:%3d,rx:%3d,ry:%3d  | ", xL, yL , xR, yR );
  Serial.printf("m1=%4d m2=%4d  " , m1 , m2 );
  Serial.println();
  // // Serial.printf("th = %5d \n" , LengthAlpha*d2r(th) ); 
  if(abs(m1) < 50){
    m1 = 0 ;
  }

  if(abs(m2) < 50){
    m2 = 0 ;
  }

  

  if(m1 > 1022) m1 = 1022;
  else if(m1 < -1022) m1 = -1022;
  
  if(m2 > 1022) m2 = 1022;
  else if(m2 < -1022) m2 = -1022;
  
  
  
  set_pwm(M1, m1);
  set_pwm(M2, m2);
 }

 void set_pwm(byte MTR , int val_pwm){
  switch(MTR){
    case M1 : 
      if(val_pwm > 0){
        digitalWrite(EN , HIGH);
        ledcWrite(PWM_M1A, val_pwm);
        ledcWrite(PWM_M1B, 0);
      }else if(val_pwm < 0){
        digitalWrite(EN , HIGH);
        ledcWrite(PWM_M1B, abs(val_pwm));
        ledcWrite(PWM_M1A, 0);
      }else{
        digitalWrite(EN , LOW);
        ledcWrite(PWM_M1B, 0);
        ledcWrite(PWM_M1A, 0);
      }
      break;
    
    case M2 : 
      if(val_pwm > 0){
        digitalWrite(EN , HIGH);
        ledcWrite(PWM_M2A, val_pwm);
        ledcWrite(PWM_M2B, 0);
      }else if(val_pwm < 0){
        digitalWrite(EN , HIGH);
        ledcWrite(PWM_M2B, abs(val_pwm));
        ledcWrite(PWM_M2A, 0);
      }else{
        digitalWrite(EN , LOW);
        ledcWrite(PWM_M2B, 0);
        ledcWrite(PWM_M2A, 0);
      }
      break;

    

   }

} 

