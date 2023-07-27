/*controlling multiple LED's with a single push down button*/
/*what I learn from this project is that a=b is not the same as b=a form a logical point of view & for most applications of an arduino, if you do not implement
a delay() in your code, the execution will hapen to fast for you to observe it*/

int const blueled=0;/*delaration of constants and variables*/
int const redled=1;
int const greenled=2;
int const button=6;
int count=0;
int newcount=0;
int buttonstate=0;
void setup(){
  pinMode(blueled,OUTPUT);  /*initalization of pins*/
  pinMode(greenled,OUTPUT);
  pinMode(redled,OUTPUT);
  pinMode(button,INPUT);
}
void loop(){
  buttonstate=digitalRead(button);/*to know to the state of the button*/
  if(buttonstate==LOW){
    digitalWrite(greenled,LOW);/*all LED's should be off when button is low*/
    digitalWrite(redled,LOW);
    digitalWrite(blueled,LOW);
  }
  else{delay(200);}/*rate at which control between the LED's by the button changes i.e. every 100ms the pushdown button will contorl a different LED8*/
if(buttonstate==HIGH){
  count=newcount+1;/*for going through different cases with the same input per time*/
}
  switch(count){
      case 1:
      digitalWrite(blueled,HIGH);
      digitalWrite(greenled,LOW);
      digitalWrite(redled,LOW);
      newcount = count ;/*for going through different cases with the same input per time remeber: a=b is not the same as b=a*/
      break;
      case 2:
      digitalWrite(greenled,HIGH);
      digitalWrite(blueled,LOW);
      digitalWrite(redled,LOW);
      newcount = count;
      break;
      case 3:
      digitalWrite(redled,HIGH);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,LOW);
      newcount=0;  /* for re-initializing the newconter so it ggoes through the cases in a loop*/
      break;
      
    }

}
