int HRmonitor = A0;    
int i = 0;  
int LED13 = 13; 
int UpperThreshold = 550;          
int LowerThreshold = 490;
int reading = 0;
float BPM = 0.0;
bool IgnoreReading = false;
bool FirstPulseDetected = false;
unsigned long FirstPulseTime = 0;
unsigned long SecondPulseTime = 0;
unsigned long PulseInterval = 0;
int count=0;

void setup() {
pinMode(LED13,OUTPUT);        
Serial.begin(9600);
}

void loop() 
{

      
if(i > UpperThreshold && IgnoreReading == false)// Heart beat leading edge detected.
{ 
        if(FirstPulseDetected == false){
          FirstPulseTime = millis();
          FirstPulseDetected = true;
        }
        else{
          SecondPulseTime = millis();
          PulseInterval = SecondPulseTime - FirstPulseTime;
          FirstPulseTime = SecondPulseTime;
        }
        IgnoreReading = true;
     }

      
 if(i < LowerThreshold)// Heart beat trailing edge detected.
 {
        IgnoreReading = false;
      }  

      BPM = (1.0/PulseInterval) * 60.0 * 1000;

      delay(10);
//      Serial.print("Count: ");
//      Serial.print(count);
//      Serial.print("\t");
//      Serial.print("\t");
//      Serial.print(i);
//      Serial.print("\t");
      Serial.print(BPM);
//      Serial.println(" BPM");
//      Serial.print("\t");
//      Serial.flush();
 
}
