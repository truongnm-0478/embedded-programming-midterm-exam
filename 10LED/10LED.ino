
// ----------------------------------------------------------------------------------
// //10led
// Duyệt từ trái sang phải
// void setup() {
//   // put your setup code here, to run once:
//   for (int i = 2; i <= 11; i++)
//     pinMode(i, OUTPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   for (int i = 2; i <= 11; i++){
//     digitalWrite(i, HIGH);
//     delay(300);
//   }
//   for (int i = 11; i >= 2; i--){
//     digitalWrite(i, LOW);
//     delay(300);
//   }
// }

// ----------------------------------------------------------------------------------
// // //10led
// Duyệt từ Hai bên vào trong và tắt dần từ trong ra hai bên
// void setup() {
//   // put your setup code here, to run once:
//   for (int i = 2; i <= 11; i++)
//     pinMode(i, OUTPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   for (int i = 2; i <= 6; i++) {
//     digitalWrite(i, HIGH);
//     digitalWrite(13 - i, HIGH); // 13 - i để chọn đúng pin từ phía bên kia
//     delay(300);
//   }
  
//   for (int i = 6; i >= 2; i--) {
//     digitalWrite(i, LOW);
//     digitalWrite(13 - i, LOW); // 13 - i để chọn đúng pin từ phía bên kia
//     delay(300);
//   }
// }

// ========================================================================================
//Duyệt sáng từ trong ra hai bên, tắt dần 2 bên vào trong
// void setup() {
//   // put your setup code here, to run once:
//   for (int i = 2; i <= 11; i++)
//     pinMode(i, OUTPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:

//   for (int i = 6; i >= 2; i--) {
//     digitalWrite(i, HIGH);
//     digitalWrite(13 - i, HIGH); // 13 - i để chọn đúng pin từ phía bên kia
//     delay(300);
//   }
//   for (int i = 2; i <= 6; i++) {
//     digitalWrite(i, LOW);
//     digitalWrite(13 - i, LOW); // 13 - i để chọn đúng pin từ phía bên kia
//     delay(300);
//   }
// }

// ==============================================================================
// ----------------------------------------------------------------------------------
// Đèn sáng 13579, 108642, tắt theo tứ tự như vậy
// const int numLed=10;
// int ledPin[numLed]={2,3,4,5,6,7,8,9,10,11};
// void setup()
// {
//   for(int i=0; i<numLed; i++)
//   {
//     pinMode(ledPin[i], OUTPUT);
//   }
// }

// void loop()
// {
// 	for (int i = 0; i < numLed; i++) {
//     if(i%2==0){
//       digitalWrite(ledPin[i], HIGH);
//       delay(300);
//     }
//   }

//   for (int i = numLed-1; i >=0; i--) {
//     if(i%2!=0){
//       digitalWrite(ledPin[i], HIGH);
//       delay(300);       
//     }
//   }

//   for (int i = 0; i < numLed; i++) {
//     if(i%2==0){
//       digitalWrite(ledPin[i], LOW);
//       delay(300);
//     }
//   }

//   for (int i = numLed-1; i >=0; i--) {
//     if(i%2!=0){
//       digitalWrite(ledPin[i], LOW);
//       delay(300);
//     }
//   }
// }

// =========================================================================
// Đèn sáng 246810, 97531, tắt dần theo như vậy
// const int numLed=10;
// int ledPin[numLed]={2,3,4,5,6,7,8,9,10,11};
// void setup()
// {
//   for(int i=0; i<numLed; i++)
//   {
//     pinMode(ledPin[i], OUTPUT);
//   }
// }

// void loop()
// {
//    	for (int i = 0; i < numLed; i++) {
//     if(i%2!=0){
//       digitalWrite(ledPin[i], HIGH);
//       delay(300);
//     }
//   }
//   for (int i = numLed-1; i >=0; i--) {
//     if(i%2==0){
//       digitalWrite(ledPin[i], HIGH);
//       delay(300);       
//     }
//   }

//   for (int i = 0; i < numLed; i++) {
//     if(i%2!=0){
//       digitalWrite(ledPin[i], LOW);
//       delay(300);
//     }
//   }
//   for (int i = numLed-1; i >=0; i--) {
//     if(i%2==0){
//       digitalWrite(ledPin[i], LOW);
//       delay(300);
//     }
//   }
// }

// =========================================================================
// Đèn sáng 13579, 246810, tắt dần 108642->97531
// const int numLed=10;
// int ledPin[numLed]={2,3,4,5,6,7,8,9,10,11};
// void setup()
// {
//   for(int i=0; i<numLed; i++)
//   {
//     pinMode(ledPin[i], OUTPUT);
//   }
// }

// void loop()
// {
// 	for (int i = 0; i < numLed; i++) {
//     if(i%2==0){
//       digitalWrite(ledPin[i], HIGH);
//       delay(300);
//     }
//   }

//   for (int i = 0; i < numLed; i++) {
//     if(i%2!=0){
//       digitalWrite(ledPin[i], HIGH);
//       delay(300);
//     }
//   }
//   for (int i = numLed-1; i >=0; i--) {
//     if(i%2!=0){
//       digitalWrite(ledPin[i], LOW);
//       delay(300);       
//     }
//   }
//   for (int i = numLed-1; i >=0; i--) {
//     if(i%2==0){
//       digitalWrite(ledPin[i], LOW);
//       delay(300);
//     }
//   }
// }



// ////////////////////////////////////////////////////////////////////
// //vặn biến trở đèn sáng
// int led = 11;
// int pin = 0;
// int value = 0;

// void setup(){
//   for (int i = 2; i <= 11; i++)
//     pinMode(i, OUTPUT);
    
// }

// void loop(){
//   value = analogRead(pin);
//   value /= 4;
//   analogWrite(led, value);
// }


////////////////////////////////////////////////////////////////////

// - 10 đèn sáng cùng lúc theo giá trị biến trở
// int value = 0;
// int pin = 0;
// void setup(){
//   for(int i = 2; i<=12; i++){
//   	pinMode(i, OUTPUT);
//   }
//   Serial.begin(9600);
// }
// void loop(){
//   value = analogRead(pin);
//   value/=4;
//   Serial.println(value);
//   for(int i = 2; i<=12; i++){
//   	  analogWrite(i, value);
//   }
// }



// ////////////////////////////////////////////////////////////////////

// - 10 đèn sáng từ trái sang phải theo giá trị biến trở
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
//   // từng đèn sáng từ trái sang phải theo giá trị biến trở
// 	for (int i = 0; i < numLed; i++) {
//      	analogWrite(ledPin[i], value);
//       	delay(value);
//   	} 
//  // sáng xong tắt (nếu có)
//   for (int i = 0; i < numLed; i++) {
//      	analogWrite(ledPin[i], LOW);
//       	delay(value);
//   	}

// }


