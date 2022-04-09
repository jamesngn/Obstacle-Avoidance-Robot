
void loop() {
     /* int previous_i;
      previous_i = i;
      myServo1.write(angle);
      

      if (angle==0) {angleState=0;}
      else if (angle == 180) {angleState=1;}

      if (angleState == 0) {angle=angle+30;delay(100);}
      else if (angleState == 1) {angle=angle-30;delay(100);};
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration_us = pulseIn(echoPin, HIGH);
      distance_cm = 0.017 * duration_us;
      delay(250);
      if (distance_cm > max_distance && distance_cm < 600) {max_distance = distance_cm;i=previous_i;}
      else {i++;}
      Serial.print("Distance = "); Serial.println(max_distance);
      Serial.print("i = "); Serial.println(i);
    }

*/

      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration_us = pulseIn(echoPin, HIGH);
      distance_cm = 0.017 * duration_us;
      current_distance = distance_cm;
      delay(10);
    
  








  if (current_distance > avoiding_distance) {forward(5);}
  else if (current_distance < avoiding_distance) {
     
    while (current_distance < avoiding_distance) {
      if (angle == 0) {angleState = 0;}
      else if (angle == 180) {angleState = 1;};  
      if      (angleState == 0) {stationary(100);angle=angle+10;myServo1.write(angle);delay(5);}
      else if (angleState == 1) {stationary(100);angle=angle-10;myServo1.write(angle);delay(5);};
       
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        duration_us = pulseIn(echoPin, HIGH);
        distance_cm = 0.017 * duration_us;
        current_distance = distance_cm;
        delay(100);
    }
    
    myServo1.write(angle); 
    int rotating_time1 = map(angle,0,90,0,624);
    int rotating_time2 = map(angle,90,180,0,624);
    
    if (angle < 90) {
      backward(50); 
      stationary(250);
      clockwise_rotation(rotating_time1);
      angle=90;
      delay(50);
      myServo1.write(angle);
      
    }
    else if (angle > 90) {
      backward(50);
      stationary(250);
      counterclockwise_rotation(rotating_time2);
      angle=90;
      delay(50);
      myServo1.write(angle);      
      
    }
  }
}
