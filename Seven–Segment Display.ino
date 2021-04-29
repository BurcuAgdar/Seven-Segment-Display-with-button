int ledArr[7] = {5, 6, 7, 8, 9, 10, 11};//Ports that provide connection between arduino and seven segment display
/*
port 5  -> b
port 6  -> a
port 7  -> c
port 8  -> e
port 9  -> d
port 10 -> g
port 11 -> f
*/
int COUNTER_VALUE =1;//The variable that determines how many numbers will increase
int count = 0;//Variable determining the number in the loop
int delayTime=50;//delay time
int buton_id=2;//The port where the button is connected to the arduino
boolean first, second;//Variables depending on the state of the button being pressed
boolean buton = false;//variable holding the high low status of the button

void setup()//Setup function
{
  for (int i = 0; i < 7; i++)
  {
    pinMode(ledArr[i], OUTPUT);
  }
  pinMode(buton,INPUT);
}
void lowAll()//The function that turns off all LEDs in the seven segment display
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(ledArr[i], LOW);
  }
}
void highAll()//The function that turns on all the LEDs in the seven segment display
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(ledArr[i], HIGH);
  }
}

//In order for the code to be short, I wrote the functions written on the segment display that likes the numbers in different ways. For example, to write 'A', all other leds except 1 led must be lit. Instead of writing HIGH to all of them one by one, I used the highAll function and wrote LOW with only one led. Because this is getting shorter.
//Another example is the number 1. To write 1, only two leds need to be lit. For this, it will be shorter to use the lowAll function, which turns off all the LEDs, and write HIGH for only two LEDs.
//I used whichever method would be shorter for each number.

void zero()//The function used to write 0 on the seven segment display
{
  highAll();
  digitalWrite(ledArr[5], LOW);
}
void one()//The function used to write 1 on the seven segment display
{
  lowAll();
  digitalWrite(ledArr[0], HIGH);
  digitalWrite(ledArr[2], HIGH);
  
}
void two()//The function used to write 2 on the seven segment display
{
  highAll();
  digitalWrite(ledArr[2], LOW);
  digitalWrite(ledArr[6], LOW);
}
void three()//The function used to write 3 on the seven segment display
{
  highAll();
  digitalWrite(ledArr[3], LOW);
  digitalWrite(ledArr[6], LOW);
}
void four()//The function used to write 4 on the seven segment display
{
  highAll();
  digitalWrite(ledArr[1], LOW);
  digitalWrite(ledArr[3], LOW);
  digitalWrite(ledArr[4], LOW);
}
void five()//The function used to write 5 on the seven segment display
{
  highAll();
  digitalWrite(ledArr[0], LOW);
  digitalWrite(ledArr[3], LOW);
}
void six()//The function used to write 6 on the seven segment display
{
  highAll();
  digitalWrite(ledArr[0], LOW);
}
void seven()//The function used to write 7 on the seven segment display
{
  lowAll();
  digitalWrite(ledArr[0], HIGH);
  digitalWrite(ledArr[1], HIGH);
  digitalWrite(ledArr[2], HIGH);
  
}
void eight()//The function used to write 8 on the seven segment display
{
  highAll();
}
void nine()//The function used to write 9 on the seven segment display
{
  highAll();
  digitalWrite(ledArr[3], LOW);
}
void ten()//The function used to write 'A' on the seven segment display
{
  highAll();
  digitalWrite(ledArr[4], LOW);
}
void eleven()//The function used to write 'b' on the seven segment display
{
  highAll();
  digitalWrite(ledArr[0], LOW);
  digitalWrite(ledArr[1], LOW);
}
void twelve()//The function used to write 'C' on the seven segment display
{
  lowAll();
  digitalWrite(ledArr[1], HIGH);
  digitalWrite(ledArr[3], HIGH);
  digitalWrite(ledArr[4], HIGH);
  digitalWrite(ledArr[6], HIGH);
}
void thirteen()//The function used to write 'd' on the seven segment display
{
  highAll();
  digitalWrite(ledArr[1], LOW);
  digitalWrite(ledArr[6], LOW);
}
void fourteen()//The function used to write 'E' on the seven segment display
{
  twelve();//I used the twelve function because there is only 1 led difference between 'C' and 'E'.
  digitalWrite(ledArr[5], HIGH);
}
void fiveteen()//The function used to write 'F' on the seven segment display
{
  fourteen();//I used the fourteen function because there is only 1 led difference between 'E' and 'F'.
  digitalWrite(ledArr[4], LOW);
}


void loop()//Loop function
{ 
  
  first = digitalRead(buton_id);//reading whether the button is HIHG or LOW
  buton=false;//It is defined as false so that it only moves to the next number when the button is pressed.
  if (second != first)//The if block runs if the previous value of the button is not equal to its current value
  {
      if (first == HIGH)//If the button is pressed, the if block works.
      {
          buton = true;//It is set to true when the button is pressed, in order to move to the next number.  
      }
  }
  second = first;//The current state of the button is stored in a variable
  
  
  //if-else if blocks that determine which function will run based on the next value of count
  if(count==0){zero();}
  else if(count==1){one();}
  else if(count==2){two();}
  else if(count==3){three();}
  else if(count==4){four();}
  else if(count==5){five();}
  else if(count==6){six();}
  else if(count==7){seven();}
  else if(count==8){eight();}
  else if(count==9){nine();}
  else if(count==10){ten();}
  else if(count==11){eleven();}
  else if(count==12){twelve();}
  else if(count==13){thirteen();}
  else if(count==14){fourteen();}
  else if(count==15){fiveteen();}
  delay(delayTime);
  
  if (first==HIGH && buton){ //According to the value of COUNTER_VALUE, it is determined how many numbers will increase. The number increases as the button is pressed
  count=(count+COUNTER_VALUE)%16;
  }
  

  
}
