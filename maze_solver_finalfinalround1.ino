int leftsensor,midleftsensor,midrightsensor,rightsensor;
int in1=7,in2=6,in3=5,in4=4,pwmright=11,pwmleft=10;
int error=0;
int ls=13,mls=12,mrs=9,rs=8;
int downnode=1;
volatile int z=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(leftsensor,INPUT);
  pinMode(midleftsensor,INPUT);
  pinMode(midrightsensor,INPUT);
  pinMode(rightsensor,INPUT);
  pinMode(2,OUTPUT);
  pinMode(A0,OUTPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(pwmright,OUTPUT);
  pinMode(pwmleft,OUTPUT);

}

void readsensor()
{ leftsensor = !digitalRead(ls);
  midleftsensor = !digitalRead(mls);
  midrightsensor = !digitalRead(mrs);
  rightsensor= !digitalRead(rs);
  //Serial.print(leftsensor);
  //Serial.print(midleftsensor);
  //Serial.print(midrightsensor);
  //Serial.print(rightsensor);
  //Serial.println(" ");
  
  
  if ((leftsensor == 1) && (midleftsensor == 0) && (midrightsensor == 0) && (rightsensor == 0))
    error = 3;
  else if ((leftsensor == 1) && (midleftsensor == 1) && (midrightsensor == 0) && (rightsensor == 0))
    error = 2;
  else if ((leftsensor == 0) && (midleftsensor == 1) && (midrightsensor == 0) && (rightsensor == 0))
    error = 1;
  else if ((leftsensor == 0) && (midleftsensor == 1) && (midrightsensor == 1) && (rightsensor == 0))
    error = 0;
  else if ((leftsensor == 0) && (midleftsensor == 0) && (midrightsensor == 1) && (rightsensor == 0))
    error = -1;
  else if ((leftsensor == 0) && (midleftsensor == 0) && (midrightsensor == 1) && (rightsensor == 1))
    error = -2;
  else if ((leftsensor == 0) && (midleftsensor == 0) && (midrightsensor == 0) && (rightsensor == 1))
    error = -3;
  else if ((leftsensor == 1) && (midleftsensor == 1) && (midrightsensor == 1) && (rightsensor == 0)) // Turn robot left side
    error = 100;
  else if ((leftsensor == 0) && (midleftsensor == 1) && (midrightsensor == 1) && (rightsensor == 1)) // Turn robot right side
    error = 101;
  else if ((leftsensor == 0) && (midleftsensor == 0) && (midrightsensor == 0) && (rightsensor == 0)) // Make U turn
    error = 102;
  else if ((leftsensor == 1) && (midleftsensor == 1) && (midrightsensor == 1) && (rightsensor == 1)) // Turn left side or stop
    error = 103;

   
}
void normal()
{
       analogWrite(pwmright,250);
        analogWrite(pwmleft,250); 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);

}
void straight()
{
        analogWrite(pwmright,250);
        analogWrite(pwmleft,250); 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
}
void back()
{
        analogWrite(pwmright,200);
        analogWrite(pwmleft,200); 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        //Serial.println("back");
}
void right()
{
        analogWrite(pwmright,200);
        analogWrite(pwmleft,200); 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
}
void left()
{       analogWrite(pwmright,200);
        analogWrite(pwmleft,200); //appropriate speed to reach the back wheel axil
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
}
void rightturn()
{
        analogWrite(pwmright,150);
        analogWrite(pwmleft,250); 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
}
void leftturn()
{
        analogWrite(pwmright,250);
        analogWrite(pwmleft,150); 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
}

void sharprightturn()
{
        analogWrite(pwmright,100);
        analogWrite(pwmleft,200); 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
}


void sharpleftturn()
{
        analogWrite(pwmright,200);
        analogWrite(pwmleft,100); 
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
}
void vsharprightturn() {
        analogWrite(pwmright,0);
        analogWrite(pwmleft,200); 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
}
void vsharpleftturn() {
        analogWrite(pwmright,200);
        analogWrite(pwmleft,0); 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
}
void stop_bot()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void axil()
{
        analogWrite(11,200);
        analogWrite(10,200); //appropriate speed to reach the back wheel axil
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        delay(450);


}
void inter()
{
  z=2;
}




void loop() 
{ 
  attachInterrupt(digitalPinToInterrupt(3),inter,RISING);
  
  if(z==0)
  {
  //Serial.println(error);
  readsensor();
  
  if((leftsensor == 1) && ((midleftsensor == 0) || (midrightsensor == 0)) && (rightsensor == 1))
{ 
  delay(50);
  readsensor();  
  if((leftsensor == 1) && ((midleftsensor == 0) || (midrightsensor == 0)) && (rightsensor == 1))

    {
   digitalWrite(2,HIGH);
    }
}
  if (error == 100) {  
    delay(100);
    stop_bot();
    readsensor();
    if(error==100)
    {
    axil();
    left();
    delay(300);
    do { 
      readsensor();
      left();
    } while (error != 0);
    }
    else {
      digitalWrite(2,HIGH);
      normal();
      delay(350);
    }
    
  }
    
else if (error == 101) {
  delay(40);
  readsensor();
  if(error==101) 
  {         
    axil();
    readsensor();
    if (error == 102) {   
    right();
    delay(300);
      do {

        right();
        readsensor();
      } while (error != 0);
    }
    else if(error == 0 || error == 1 ||error== -1)
    {
      normal();
    }
  }

}

else if (error == 102) {        // Make left turn untill it detects straight path
    axil();
    do {
      back();
      readsensor();
      if (error == 0) {
        stop_bot();
        delay(200);
      }
    } while (error != 0);
}

else if (error == 103)
{   delay(40);
    readsensor();
    if(error==103)
    { 
      axil();
      readsensor();
      if (error == 103)
      {     /**** Dead End Reached, Stop! ****/
        stop_bot();
        z=3;
      } 
      else 
      { left();
        delay(300);
        do 
        {
          left();
          readsensor();
        } while (error != 0);
      }
    }
    
}


else if (error == -3)
{
  vsharprightturn();
}
else if (error == -2)
{
  sharprightturn();
}
else if (error == -1)
{
  rightturn();
}
else if (error == 0)
{
  normal();
  //Serial.println("a");
     digitalWrite(2,LOW);

}
else if (error == 1)
{
  leftturn();
}
else if (error == 2)
{
  sharpleftturn();
}
else if (error == 3)
{
  vsharpleftturn();
}
else
{
  normal();
}


}

if(z==2)
{
  delay(5000);
  z=1;
}

if(z==1)
{
  //Serial.println(error);
  //Serial.println("value is 1");
    //Serial.println(error);
  readsensor();
  
  if((leftsensor == 1) && ((midleftsensor == 0) || (midrightsensor == 0)) && (rightsensor == 1))
{
   digitalWrite(2,HIGH);
   
}
  if (error == 100) {  //left
    delay(40);
  readsensor();
  if(error==100) 
  {         
    axil();
    readsensor();
    if (error == 102) {   
    left();
    delay(300);
      do {

        left();
        readsensor();
      } while (error != 0);
    }
    else if(error == 0 || error == 1 ||error== -1)
    {
      normal();
    }
  }
  }
    
else if (error == 101) { //right 
  delay(40);
    readsensor();
    if(error==101)
    {
    axil();
    right();
    delay(300);
    do { 
      readsensor();
      right();
    } while (error != 0);
    }
}

else if (error == 102) {       //back // Make left turn untill it detects straight path
  axil();
    do {
      back();
      readsensor();
      if (error == 0) {
        stop_bot();
        delay(200);
      }
    } while (error != 0);
}

else if (error == 103)
{   delay(40);                      //T point
    readsensor();
    if(error==103)
    { 
      axil();
      readsensor();
      if (error == 103)
      {     /**** Dead End Reached, Stop! ****/
        stop_bot();
        z=3;

      } 
      else 
      { right();
        delay(300);
        do 
        {
          right();
          readsensor();
        } while (error != 0);
      }
    }
    
}


else if (error == -3)
{
  vsharprightturn();
}
else if (error == -2)
{
  sharprightturn();
}
else if (error == -1)
{
  rightturn();
}
else if (error == 0)
{
  normal();
  //Serial.println("a");
     digitalWrite(2,LOW);

}
else if (error == 1)
{
  leftturn();
}
else if (error == 2)
{
  sharpleftturn();
}
else if (error == 3)
{
  vsharpleftturn();
}
else
{ //Serial.println("challa");
  normal();
}


}

if(z==3)
{
  digitalWrite(A0,HIGH);
  delay(500);
  digitalWrite(A0,LOW);
  delay(500);
  digitalWrite(A0,HIGH);
  delay(500);
  digitalWrite(A0,LOW);
  delay(500);
  digitalWrite(A0,HIGH);
  delay(500);
  digitalWrite(A0,LOW);
  delay(500);
  z=4;
}

}
