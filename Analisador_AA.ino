#define gatilho 9
#define tensao A0
#define led_ok 6
#define led_res 7
#define led_des 8

float vca;
float vcf;
float raux = 1.2;
float rin;
boolean flag;

void setup() {
  pinMode (led_ok, OUTPUT);
  pinMode (led_res, OUTPUT);
  pinMode (led_des, OUTPUT);
  pinMode (gatilho, OUTPUT);
  digitalWrite(gatilho, HIGH);
  pinMode (tensao, INPUT);
}

void loop() {
  vca = analogRead(tensao) * 0.0067; //ajuste realizado para adequar o resultado entregue pelo ADC e pelo divisor de tensão 
  if (vca >= 1 && !flag) {
    flag = 1;
    digitalWrite(led_ok, HIGH);
    digitalWrite(led_res, LOW);
    digitalWrite(led_des, LOW);
    delay(100);
    digitalWrite(led_ok, HIGH);
    digitalWrite(led_res, HIGH);
    digitalWrite(led_des, LOW);
    delay(100);
    digitalWrite(led_ok, HIGH);
    digitalWrite(led_res, HIGH);
    digitalWrite(led_des, HIGH);
    delay(100);
    digitalWrite(led_ok, LOW);
    digitalWrite(led_res, HIGH);
    digitalWrite(led_des, HIGH);
    delay(100);
    digitalWrite(led_ok, LOW);
    digitalWrite(led_res, LOW);
    digitalWrite(led_des, HIGH);
    delay(100);
    digitalWrite(led_ok, LOW);
    digitalWrite(led_res, HIGH);
    digitalWrite(led_des, HIGH);
    delay(100);
    digitalWrite(led_ok, HIGH);
    digitalWrite(led_res, HIGH);
    digitalWrite(led_des, HIGH);
    delay(100);
    digitalWrite(led_ok, LOW);
    digitalWrite(led_res, LOW);
    digitalWrite(led_des, LOW);
    //transição para experiencia do usuário (UX - expectativa)
    digitalWrite(gatilho, LOW);
    delay(100);
    vcf = analogRead(tensao) * 0.0067;
    digitalWrite(gatilho, HIGH);
    rin = (raux * (vca - vcf)) * (1 / vcf); //fórmula para calcular resistência interna
    if (rin <= 0.2) { //SAUDÁVEL
      digitalWrite(led_ok, HIGH);
    } else if (rin <= 0.5) { //RESERVA
      digitalWrite(led_res, HIGH);
    } else { //DESCARTE
      digitalWrite(led_des, HIGH);
    }
  }
  if (vca > 0.01 && vca < 1 && !flag) { //PILHA DESCARREGADA, NÃO APTA PARA ANÁLISE
    digitalWrite(led_ok, !digitalRead(led_ok));
    digitalWrite(led_res, !digitalRead(led_res));
    digitalWrite(led_des, !digitalRead(led_des));
  }
  if (vca <= 0.01) { //PILHA DESCONECTADA
    digitalWrite(led_ok, LOW);
    digitalWrite(led_res, LOW);
    digitalWrite(led_des, LOW);
    flag = 0;
  }
  delay(500);
}
