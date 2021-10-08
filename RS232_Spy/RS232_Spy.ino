
/*
  SerialSpy: intercept ASCII-based serial communications between two devices
  (c) Loic74 <loic74650@gmail.com> 2020

  The setup is based on two RS232-to-TTL converters connected to each other
  RX from one is connected to TX from the other
  Two RS232 devices, a master (eg. a computer running a software) and a slave (eg.  a robot) are connected together with this setup in between
  The Arduino (Mega 2560) reads the RX pins from both devices and prints the output to the Serial monitor
  This is useful to debug or reverse-engineer the command set to drive RS232 devices
*/

//DIP Switch inputs pins for baud-rate selection
//Default config SERIAL_8N1 is used
//If another config is to be used, firmware must be changed
#define SW1 22
#define SW2 23
#define SW3 24
#define SW4 25

uint8_t DigInputs = 0;
long BaudRate = 9600;

static short LF = 10;        // ASCII linefeed
static short CR = 13;        // ASCII Carriage Return
static String S1 = "S1: ";
static String S2 = "S2: ";

void setup()
{
  //DIP Switch inputs for baud-rate selection
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);

  //read selected baud rate from DIP switch
  writeBitmap(false, false, false, false, digitalRead(SW4), digitalRead(SW3), digitalRead(SW2), digitalRead(SW1));

  // start serial ports
  Serial.begin(115200);

  switch (DigInputs)
  {
    case 0://baud rate: 110
      BaudRate = 110;
      break;
    case 1://baud rate: 300
      BaudRate = 300;
      break;
    case 2://baud rate: 600
      BaudRate = 600;
      break;
    case 3://baud rate: 1200
      BaudRate = 1200;
      break;
    case 4://baud rate: 2400
      BaudRate = 2400;
      break;
    case 5://baud rate: 4800
      BaudRate = 4800;
      break;
    case 6://baud rate: 9600
      BaudRate = 9600;
      break;
    case 7://baud rate: 14400
      BaudRate = 14400;
      break;
    case 8://baud rate: 19200
      BaudRate = 19200;
      break;
    case 9://baud rate: 38400
      BaudRate = 38400;
      break;
    case 10://baud rate: 57600
      BaudRate = 57600;
      break;
    case 11://baud rate: 115200
      BaudRate = 115200;
      break;
    case 12://baud rate: 128000
      BaudRate = 128000;
      break;
    case 13://baud rate: 256000
      BaudRate = 256000;
      break;
    default://baud rate: 9600
      BaudRate = 9600;
      break;
  }

  BaudRate = 19200;
  Serial1.begin(BaudRate);
  Serial2.begin(BaudRate);
  delay(200);
  while (! Serial);
}

void loop()
{
  if (Serial1.available() > 0) {
    //Serial.println("S1 received chars...");
    String s = S1 + Serial1.readStringUntil('\r');
    Serial.println(s);
  }
  if (Serial2.available() > 0) {
    //Serial.println("S2 received chars...");
    String s = S2 + Serial2.readStringUntil('\r');
    Serial.println(s);
  }
  delay(1);
}

//Set individual bits of the DigInputs Byte
void writeBitmap(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h)
{
  // LSB first
  DigInputs = 0;
  DigInputs |= (a & 1) << 7;
  DigInputs |= (b & 1) << 6;
  DigInputs |= (c & 1) << 5;
  DigInputs |= (d & 1) << 4;
  DigInputs |= (e & 1) << 3;
  DigInputs |= (f & 1) << 2;
  DigInputs |= (g & 1) << 1;
  DigInputs |= (h & 1) << 0;
}
