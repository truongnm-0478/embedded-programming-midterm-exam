/*
  SDA  -->  D10
  SCK  -->  D13
  MOSI -->  D11
  MISO -->  D12
  IRQ  -->
  GND  -->  GND
  RST  -->   D9
  3.3V --> 3.3V
*/
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10
#define MAX_IDS 5  // Số lượng ID tối đa được chấp nhận

int led = 8;  // Pin số 8 kết nối với đèn LED

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Khởi tạo đối tượng MFRC522

void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT); 
  digitalWrite(led, LOW);  // Tắt đèn LED

  SPI.begin();         // Khởi động giao tiếp SPI
  mfrc522.PCD_Init();  // Khởi tạo module MFRC522
}

int acceptedIDs[MAX_IDS][4] = {
  { 155, 163, 118, 17 }
  // Thêm các ID được chấp nhận khác ở đây
};

bool nhapnhay = false;     // Biến kiểm soát nhấp nháy đèn
bool sang = false;         // Biến kiểm soát bật đèn
int time = 0;              // Biến đếm thời gian giữa các lần đọc thẻ
bool xung = true;          // Biến kiểm soát trạng thái của xung
int thoiGianGiua2Lan = 15;

void loop() {
  if (sang) {
    digitalWrite(led, HIGH);  // Bật đèn LED
  }

  if (nhapnhay) {
    Serial.println("ĐÈN NHẤP NHÁY");
    digitalWrite(led, xung);  // Nhấp nháy đèn LED
    delay(200);
    xung = !xung;  // Đảo trạng thái xung
  }

  // Thời gian giữa hai lần liên tiếp = time * 100 
  // Điều chỉnh 
  if (time > thoiGianGiua2Lan) {
    time = 0;  
  }
  if (time > 0) {
    time += 1;  // Tăng thời gian lên sau mỗi lần
  }

  delay(100);  // Chỉnh thời gian giữa hai lần quẹt thẻ

  if (!mfrc522.PICC_IsNewCardPresent()) {  // Kiểm tra xem có thẻ RFID mới được đặt lên không
    return;                                // Nếu không, thoát khỏi hàm loop()
  }

  if (!mfrc522.PICC_ReadCardSerial()) {  // Đọc dữ liệu từ thẻ RFID
    return;                              // Nếu không đọc được, thoát khỏi hàm loop()
  }

  Serial.println("Thoi gian giua hai lan lien tiep: " + (String)time);

  Serial.print("UID của thẻ: ");  // In ra Serial UID của thẻ
  int UID[4];                                                  // Mảng lưu trữ UID của thẻ
  for (byte i = 0; i < mfrc522.uid.size; i++) {                // Lặp qua từng byte của UID
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");  // In ra Serial mỗi byte, đảm bảo là 2 ký tự
    UID[i] = mfrc522.uid.uidByte[i];                           // Lưu giá trị byte vào mảng UID
    Serial.print(UID[i]);                                      // In giá trị byte ra Serial
  }

  Serial.println("   ");  // In ra Serial dòng mới

  if (isAcceptedID(UID)) {       // Kiểm tra xem UID có được chấp nhận không
    Serial.println("ĐÈN SÁNG");  // In ra Serial "ĐÈN SÁNG"
    nhapnhay = false;            // Tắt chế độ nhấp nháy
    sang = true;                 // Bật chế độ bật đèn

    if (time > 0 && time < 1000) {
      sang = false;  // Nếu đèn đã bật trong khoảng thời gian ngắn, tắt đèn
      digitalWrite(led, LOW);
      time = 0;  // Đặt lại thời gian
    } else {
      time = 1;  // Nếu không, đặt thời gian là 1
    }
  } else {
    nhapnhay = true;  // Bật chế độ nhấp nháy
    sang = false;     // Tắt chế độ bật đèn
  }

  mfrc522.PICC_HaltA();       // Tạm dừng module MFRC522
  mfrc522.PCD_StopCrypto1();  // Dừng tiến trình mã hóa
}

bool isAcceptedID(int UID[]) {
  for (int i = 0; i < MAX_IDS; i++) {
    bool match = true;
    for (int j = 0; j < 4; j++) {
      if (UID[j] != acceptedIDs[i][j]) {
        match = false;
        break;
      }
    }
    if (match) {
      return true;  // UID khớp với một ID được chấp nhận
    }
  }
  return false;  // Không có ID nào khớp
}