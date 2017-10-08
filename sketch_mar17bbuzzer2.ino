#include <Adafruit_GFX.h>  //גלאי רוורסר גירסא סופית
#include <Adafruit_PCD8544.h>
#define PIN_SCE   4
#define PIN_RESET 3
#define PIN_DC    5
#define PIN_SDIN  6
#define PIN_SCLK  7
#define LCD_CMD   0

#define LCD_C     LOW
#define LCD_D     HIGH

#define LCD_X     84
#define LCD_Y     48
#include <Ultrasonic.h>
Ultrasonic ultrasonic(11,9);
 int i=0;
int dist,dist2,inv,bar=0;
boolean stan=0;
long interval = 1800;

boolean SoundOn=false;
 long previousMillis = 0;
  long previousMillis2 = 0;
    long previousMillis3 = 0;
 long currentminusprevious = 0;
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);









void setup(void)
{
  Serial.begin(9600);
     pinMode(13, OUTPUT);  
  display.begin();
display.setContrast(57); 
  display.clearDisplay();
    dist=ultrasonic.Ranging(CM);
       dist=dist - 2;
    dist2 = dist;
  if (dist>=100) { 
      display.setCursor(25,15);
        display.setTextSize(2);
         display.setTextColor(BLACK);
          display.println(dist);
          display.setTextSize(1);
           display.setCursor(60,23);
          display.println("Cm"); 
          
     display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
    display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
    display.fillRect(48, 33, 10,15, 1);
    display.fillRect(59, 33, 10,15, 1);
     display.fillRect(70, 33, 10,15, 1);
     interval  = 999999999;


          
             
           display.display();}
          else if (dist>=10) {
          display.setCursor(30,15);
        display.setTextSize(2);
         display.setTextColor(BLACK);
          display.println(dist);
          display.setTextSize(1);
           display.setCursor(60,23);
          display.println("Cm"); 
          switch (bar)
          {
             case 9 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
     display.fillRect(48, 33, 10,15, 1);
    display.fillRect(59, 33, 10,15, 1);
  display.fillRect(70, 33, 10,15, 1);
}
    case 8 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
     display.fillRect(48, 33, 10,15, 1);
    display.fillRect(59, 33, 10,15, 1);
  display.fillRect(70, 33, 10,15, 1);
}
     case 7 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
     display.fillRect(48, 33, 10,15, 1);
    display.fillRect(59, 33, 10,15, 1);
  display.fillRect(70, 33, 10,15, 1);
 
}
    case 6 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
     display.fillRect(48, 33, 10,15, 1);
    display.fillRect(59, 33, 10,15, 1);

  }
     case 5 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
     display.fillRect(48, 33, 10,15, 1);
     
    }
     case 4 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
    }
     case 3 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
 }
     case 2 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
   }
     case 1 :{ interval = 400; display.fillRect(4, 33, 10,15, 1);}
}
    
    
                 
                   display.display();if (dist<20 && dist >=10)
                   { interval = 100; }
                 if (dist<40 && dist >=20 )
                   { interval = 200; }
                 if (dist<60 && dist >=40)
                   { interval = 400; }
                 if (dist<80 && dist >=60)
                   { interval = 800; }
                 if (dist<100 && dist >=80)
                   { interval = 1000; }}
                 
          else if (dist>=5) 
   
{
   display.setCursor(35,0);
        display.setTextSize(3);
         display.setTextColor(BLACK);
          display.println(dist);
             display.display();
  display.setCursor(0,25);
       display.setTextSize(2);
 display.setTextColor(BLACK);
  display.println("-ALERT-");  
   display.display();
   digitalWrite(13, HIGH);
   interval = 0;
  } else  
   
{
   display.setCursor(35,0);
        display.setTextSize(3);
         display.setTextColor(BLACK);
          display.println(dist);
             display.display();
  display.setCursor(7,25);
       display.setTextSize(2);
    display.setTextColor(WHITE,BLACK);
  display.println("-STOP-");  
   display.display();
   digitalWrite(13, HIGH);
   interval = 0;
  }
  
  
  
  }




void loop(void)
{

unsigned long currentMillis = millis();



if( currentMillis - previousMillis >100) {

previousMillis = previousMillis+100;  // Geymir tímann frá síðustu aðgerð






  dist=ultrasonic.Ranging(CM);
  if (dist!= dist2) {
    dist2 = dist;
    display.clearDisplay(); 
   dist=dist - 2;
   bar = dist/10;
  
  if (dist>500){  display.setCursor(0,15);
        display.setTextSize(2);
         display.setTextColor(BLACK);display.println("TOO FAR");
    display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
    display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
    display.fillRect(48, 33, 10,15, 1);
    display.fillRect(59, 33, 10,15, 1);
     display.fillRect(70, 33, 10,15, 1); display.display();
        interval  = 999999999;}

   
  if (dist>=100 && dist<=500) { 
      display.setCursor(25,15);
        display.setTextSize(2);
         display.setTextColor(BLACK);
          display.println(dist);
          display.setTextSize(1);
           display.setCursor(60,23);
          display.println("Cm"); 
          
     display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
    display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
    display.fillRect(48, 33, 10,15, 1);
    display.fillRect(59, 33, 10,15, 1);
     display.fillRect(70, 33, 10,15, 1);
     interval  = 999999999;


          
             
           display.display();}
          else if (dist>=10 && dist<=500) {
          display.setCursor(30,15);
        display.setTextSize(2);
         display.setTextColor(BLACK);
          display.println(dist);
          display.setTextSize(1);
           display.setCursor(60,23);
          display.println("Cm"); 
          switch (bar)
          {
             case 9 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
     display.fillRect(48, 33, 10,15, 1);
    display.fillRect(59, 33, 10,15, 1);
  display.fillRect(70, 33, 10,15, 1);
}
    case 8 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
     display.fillRect(48, 33, 10,15, 1);
    display.fillRect(59, 33, 10,15, 1);
  display.fillRect(70, 33, 10,15, 1);
}
     case 7 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
     display.fillRect(48, 33, 10,15, 1);
    display.fillRect(59, 33, 10,15, 1);
  display.fillRect(70, 33, 10,15, 1);
 
}
    case 6 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
     display.fillRect(48, 33, 10,15, 1);
    display.fillRect(59, 33, 10,15, 1);

  }
     case 5 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
     display.fillRect(48, 33, 10,15, 1);
     
    }
     case 4 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
    display.fillRect(37, 33, 10,15, 1);
    }
     case 3 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
      display.fillRect(26, 33, 10,15, 1);
 }
     case 2 :{ display.fillRect(4, 33, 10,15, 1);
      display.fillRect(15, 33, 10,15, 1);
   }
     case 1 :{ display.fillRect(4, 33, 10,15, 1);}
}
    
    
                 
                   display.display();if (dist<20 && dist >=10)
                   { interval = 100; }
                 if (dist<40 && dist >=20 )
                   { interval = 200; }
                 if (dist<60 && dist >=40)
                   { interval = 400; }
                 if (dist<80 && dist >=60)
                   { interval = 800; }
                 if (dist<100 && dist >=80)
                   { interval = 1000; }}
                 
          else if (dist>=5 && dist <=500) 
   
{
   display.setCursor(35,0);
        display.setTextSize(3);
         display.setTextColor(BLACK);
          display.println(dist);
             display.display();
  display.setCursor(0,25);
       display.setTextSize(2);
 display.setTextColor(BLACK);
  display.println("-ALERT-");  
   display.display();
   digitalWrite(13, HIGH);
   interval = 0;
  } else  if (dist<5)
   
{
   display.setCursor(35,0);
        display.setTextSize(3);
         display.setTextColor(BLACK);
          display.println(dist);
             display.display();
  display.setCursor(7,25);
       display.setTextSize(2);
    display.setTextColor(WHITE,BLACK);
  display.println("-STOP-");  
   display.display();
   digitalWrite(13, HIGH);
   interval = 0;
  }
  
  
  
  }}


unsigned long currentMillis2 = millis();

if( currentMillis2 - previousMillis2 >100) {

previousMillis2 = previousMillis2+100;  // Geymir tímann frá síðustu aðgerð

if (SoundOn == false)

{



SoundOn = true;

digitalWrite(13,LOW);
}




}


unsigned long currentMillis3 = millis();

if( currentMillis3 - previousMillis3 >interval) {

previousMillis3 = previousMillis3+interval;  // Geymir tímann frá síðustu aðgerð

if (SoundOn == true)

{



SoundOn = false;

digitalWrite(13, HIGH);

}


}




















}





