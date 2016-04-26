#define echoPin 13 //Pino 13 recebe o pulso do echo  
#define trigPin 12 //Pino 12 envia o pulso para gerar o echo  
// rename these for your sensors:

int Apin = A0;    // analog
int Bpin = A1;    // analog 
int Cpin = 2;     // digital pin
int A, B, C;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)  
  pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)  
}  



void loop()
{  //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0  
    digitalWrite(trigPin, LOW);  
  // delay de 2 microssegundos  
    delayMicroseconds(2);  
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1  
    digitalWrite(trigPin, HIGH);  
  //delay de 10 microssegundos  
    delayMicroseconds(10);  
  //seta o pino 12 com pulso baixo novamente  
    digitalWrite(trigPin, LOW);  
  //pulseInt lê o tempo entre a chamada e o pino entrar em high  
    long duration = pulseIn(echoPin,HIGH);  
  //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado  
  //porque é o tempo de ida e volta do ultrassom  
    long distancia = duration /29 / 2 ;  
    
   A = analogRead(Apin);       // 0-1023 (in theory)
   B = analogRead(Bpin);       // 0-1023 (in theory)
   C = distancia;   // 0-1

   Serial.print(A);
   Serial.print(",");
   Serial.print(B);
   Serial.print(",");
   Serial.println(C*2);

  delay(100);                  // slight delay to slow down data flow
}


