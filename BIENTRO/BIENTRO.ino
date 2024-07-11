// - 10 đèn sáng từ trái sang phải -----Tốc độ chuyển theo giá trị biến trở
// const int numLed=10;
// int ledPin[numLed]={2,3,4,5,6,7,8,9,10,11};
// int value=0;
// int pin=0;
// void setup()
// {
//   for(int i=0; i<numLed; i++)
//   {
//     pinMode(ledPin[i], OUTPUT);
//   }
// }

// void loop()
// {
//   // từng đèn sáng từ trái sang phải theo giá trị biến trở
// 	for (int i = 0; i < numLed; i++) {
//     value = analogRead(pin);
//     value/=4;
//      	digitalWrite(ledPin[i], HIGH);
//       	delay(value);
//   	}
//  // sáng xong tắt (nếu có)
//   for (int i = 0; i < numLed; i++) {
//     value = analogRead(pin);
//     value/=4;
//      	digitalWrite(ledPin[i], LOW);
//       	delay(value);
//   	}
// }




// -----------------------------------------------------------------------
// - 10 đèn Sáng từ hai bên vào trong -----Tốc độ chuyển theo giá trị biến trở
// const int numLed = 10;
// int ledPin[numLed] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
// int value = 0;
// int pin = 0;
// void setup() {
//   for (int i = 0; i < numLed; i++) {
//     pinMode(ledPin[i], OUTPUT);
//   }
// }

// void loop() {

//   for (int i = 2; i <= 6; i++) {
//     value = analogRead(pin);
//     value /= 4;
//     digitalWrite(i, HIGH);
//     digitalWrite(13 - i, HIGH);  // 13 - i để chọn đúng pin từ phía bên kia
//     delay(value);
//   }

//   for (int i = 6; i >= 2; i--) {
//     value = analogRead(pin);
//     value /= 4;
//     digitalWrite(i, LOW);
//     digitalWrite(13 - i, LOW);  // 13 - i để chọn đúng pin từ phía bên kia
//     delay(value);
//   }
// }





// -----------------------------------------------------------------------
// Sáng chẵn lẻ 1 3 5 7 9 10 8 6 4 2 -----Tốc độ chuyển theo giá trị biến trở

// const int numLed=10;
// int ledPin[numLed]={2,3,4,5,6,7,8,9,10,11};
// int value=0;
// int pin=0;

// void setup()
// {
//   for(int i=0; i<numLed; i++)
//   {
//     pinMode(ledPin[i], OUTPUT);
//   }
// }

// void loop()
// {
//   value = analogRead(pin);
//   value/=4;
// 	for (int i = 0; i < numLed; i++) {
//     if(i%2==0){
//       digitalWrite(ledPin[i], HIGH);
//       delay(value);
//     }
//   }

//   for (int i = numLed-1; i >=0; i--) {
//     if(i%2!=0){
//       digitalWrite(ledPin[i], HIGH);
//       delay(value);
//     }
//   }

//   for (int i = 0; i < numLed; i++) {
//     if(i%2==0){
//       digitalWrite(ledPin[i], LOW);
//       delay(value);
//     }
//   }

//   for (int i = numLed-1; i >=0; i--) {
//     if(i%2!=0){
//       digitalWrite(ledPin[i], LOW);
//       delay(value);
//     }
//   }
// }




// -----------------------------------------------------------------------
// - 10 đèn Sáng dần theo giá trị biến trở
const int n_leds = 6;
const int led_pins[] = { 11, 10, 9, 6, 5, 3 };

void setup() {
  Serial.begin(9600);

  for (int p : led_pins) {
    pinMode(p, OUTPUT);
  }
}

void loop() {
  int bright = analogRead(A0) >> 2;
  int step = 10;

  if (bright < step) {
    bright = step;
  }
  int delay_ms = 2500 / (bright / step);

  Serial.print("Bright: ");
  Serial.println(bright);

  Serial.print("Delay ms: ");
  Serial.println(delay_ms);

  Serial.println("---");

  for (int b = 0; b < bright; b += step) {
    for (int i = 0; i < n_leds; i++) {
      analogWrite(led_pins[i], b);
    }
    // delay(delay_ms);
  }
}