const int redPin = 9;     // Chân kết nối LED màu đỏ
const int greenPin = 10;  // Chân kết nối LED màu xanh lá
const int bluePin = 11;   // Chân kết nối LED màu xanh dương

int redValue = 0;    // Độ sáng LED màu đỏ
int greenValue = 0;  // Độ sáng LED màu xanh lá
int blueValue = 0;   // Độ sáng LED màu xanh dương

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');

    // Xác định vị trí của các chữ cái R, G, B, D trong dữ liệu
    int redIndex = data.indexOf('R');
    int greenIndex = data.indexOf('G');
    int blueIndex = data.indexOf('B');
    int durationIndex = data.indexOf('D');


    // Nếu tìm thấy chữ cái R, điều chỉnh độ sáng của LED màu đỏ
    if (redIndex != -1) {
      int i = redIndex + 1;
      int count = 0;
      while (isdigit(data[i])) {
        count++;
        i++;
      }
      redValue = data.substring(redIndex + 1, redIndex + count + 1).toInt();
      analogWrite(redPin, min(redValue, 255));
    }

    // Nếu tìm thấy chữ cái G, điều chỉnh độ sáng của LED màu xanh lá
    if (greenIndex != -1) {
      int i = greenIndex + 1;
      int count = 0;
      while (isdigit(data[i])) {
        count++;
        i++;
      }
      greenValue = data.substring(greenIndex + 1, greenIndex + count + 1).toInt();
      analogWrite(greenPin, min(greenValue, 255));
    }

    // Nếu tìm thấy chữ cái B, điều chỉnh độ sáng của LED màu xanh dương
    if (blueIndex != -1) {
      int i = blueIndex + 1;
      int count = 0;
      while (isdigit(data[i])) {
        count++;
        i++;
      }
      blueValue = data.substring(blueIndex + 1, blueIndex + count + 1).toInt();
      analogWrite(bluePin, min(blueValue, 255));
    }

    // Nếu tìm thấy chữ cái D, điều chỉnh thời gian sáng của các LED
    if (durationIndex != -1) {
      int i = durationIndex + 1;
      int count = 0;
      while (isdigit(data[i])) {
        count++;
        i++;
      }
      int duration = data.substring(durationIndex + 1, durationIndex + count + 1).toInt();
      delay(duration);  // Chờ thời gian được chỉ định trước khi tắt đèn
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
    }
  }
}