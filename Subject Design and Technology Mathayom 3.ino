//วิชาออกแบบและเทคโนโลยี ม.3
//นำทีมโดย ด.ช.พีรพล โกละกะ เลขที่ 14
//โค้ดต่อไปนี้ ใช้สำหรับแปลงสัญญาณ ถ้าให้พูดง่ายๆคือ ตามปกติแล้ว เซ็นเซอร์วัดความชื้นจะไม่ทำงานเมื่อดินไม่ชื้น แต่จุดประสงค์ของเราคือ จะให้เซ็นเซอร์ทำงานเมื่อดินไม่ชื้น ก็เลยได้มีโค้ดนี้ขึ้นมา เพื่อแปลงสัญญาณ

int sensorPin = A0;  // ขา A0 ใช้สำหรับเซนเซอร์วัดความชื้นของดิน
int relayPin = 2;    // ขา 2 ใช้สำหรับรีเลย์

void setup() {
  pinMode(sensorPin, INPUT);  // กำหนดขา A0 เป็นขาอินพุต
  pinMode(relayPin, OUTPUT);  // กำหนดขา 2 เป็นขาเอาต์พุต
  digitalWrite(relayPin, LOW); // เริ่มต้นให้รีเลย์ปิด (ไม่ทำงาน)
  Serial.begin(9600);  // เริ่มต้น Serial สำหรับการดีบัก
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // อ่านค่าจากเซนเซอร์วัดความชื้น

  // แสดงค่าที่อ่านได้จากเซนเซอร์ทาง Serial Monitor
  Serial.print("Soil Moisture Sensor Value: ");
  Serial.println(sensorValue);

  // ถ้าค่าเซนเซอร์น้อยกว่า 300 (หมายถึงความชื้นน้อย)
  if (sensorValue < 300) {
    digitalWrite(relayPin, HIGH);  // สั่งให้รีเลย์ทำงาน (เปิด)
    Serial.println("Relay ON");    // แสดงสถานะทาง Serial Monitor
  } else {
    digitalWrite(relayPin, LOW);   // สั่งให้รีเลย์หยุดทำงาน (ปิด)
    Serial.println("Relay OFF");   // แสดงสถานะทาง Serial Monitor
  }
  
  delay(500);  // หน่วงเวลา 0.5 วินาที
}
