#include <SPI.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2); 
// LiquidCrystal_I2C lcd(0x27,16,2); // LCD của Vinh
#include "DHT.h"
#define DHT11Pin 4 
#define DHTType DHT11 // Chọn loại cảm biến DHT11
DHT HT(DHT11Pin, DHTType);

float humi; // Biến để lưu giá trị độ ẩm
float tempC; // Biến để lưu giá trị nhiệt độ theo độ C
float tempF; // Biến để lưu giá trị nhiệt độ theo độ F

int pin = 7; // Nút ấn 
int lastButtonState = LOW;
int buttonState;
unsigned long lastPressTime = 0; // Biến để lưu thời gian lần nhấn cuối cùng
bool displayTempC = true; // Biến để kiểm tra hiển thị nhiệt độ theo độ C hoặc độ F
bool lcdActive = true; // Biến để kiểm tra xem LCD có đang hoạt động hay không

int countButton = 0;

void setup() {
  pinMode(pin, INPUT);
  digitalWrite(pin, HIGH); // Kích hoạt pull-up resistor

  lcd.init();                    
  lcd.backlight(); // Bật đèn nền
  lcd.setCursor(2,0);
  Serial.begin(9600); // Bắt đầu kết nối với Serial Monitor ở tốc độ 9600 baud rate (bit mỗi giây)
  HT.begin(); // Khởi động cảm biến DHT
  delay(1000); // Chờ 1 giây
}

void loop() {
  buttonState = digitalRead(pin);
  unsigned long currentTime = millis();
  

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) { // Nếu nút được nhấn
      if (currentTime - lastPressTime < 500) { // Nếu thời gian giữa hai lần nhấn nhỏ hơn 500ms
        lcdActive = false;
        if (!lcdActive) { // Nếu LCD bị tắt
          lcd.clear();
          lcd.noBacklight(); // Tắt đèn nền của LCD
        }
      } else {
        if (!lcdActive) {
          lcdActive = true;
          lcd.backlight();
        };
        displayTempC = !displayTempC; // Đảo ngược giá trị hiển thị nhiệt độ
        lcd.clear(); // Xóa màn hình LCD
        // delay(200); // Chờ 200ms để tránh xử lý nhanh quá khi nút được nhấn
      }
      lastPressTime = currentTime; // Cập nhật thời gian lần nhấn cuối cùng
    }
  }

  lastButtonState = buttonState;

  if (lcdActive) { // Nếu LCD đang hoạt động
    humi = HT.readHumidity(); // Đọc giá trị độ ẩm từ cảm biến
    tempC = HT.readTemperature(); // Đọc giá trị nhiệt độ theo độ C từ cảm biến
    tempF = HT.readTemperature(true); // Đọc giá trị nhiệt độ theo độ F từ cảm biến

    lcd.setCursor(0,0);
    if (displayTempC) { // Nếu đang hiển thị theo độ C
      lcd.print("Nhiet do: ");
      lcd.print(tempC, 1);
      lcd.print(char(223));
      lcd.print("C");
    } else { // Nếu đang hiển thị theo độ F
      lcd.print("Do F: ");
      lcd.print(tempF, 1);
      lcd.print(char(223));
      lcd.print("F");
    }
  }

  delay(10);
}