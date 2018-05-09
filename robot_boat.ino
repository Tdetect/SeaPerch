// connect motor controller pins to Arduino digital pins
// motor one
int enA = A0;
int in1 = 2;
int in2 = 3;

// motor two
int enB = A1;
int in3 = 4;
int in4 = 5;

// motor three
int enC = A2;
int in5 = 6;
int in6 = 7;

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    int num = Serial.read();

    switch (num) {

      case '2':
        analogWrite(enA, 255);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);

        analogWrite(enB, 255);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);

        Serial.println(".....Backward.....");

        break;

      case '8':

        analogWrite(enA, 255);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);

        analogWrite(enB, 255);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);

        Serial.println(".....Forward.....");

        break;

      case '4':
        analogWrite(enB, 0);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);

        analogWrite(enA, 255);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);

        Serial.println(".....Left.....");

        break;

      case '6':

        analogWrite(enA, 0);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);

        analogWrite(enB, 255);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);

        Serial.println(".....Right.....");

        break;

      case '5':

        analogWrite(enB, 0);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);

        analogWrite(enA, 0);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);

        Serial.println(".....Stop Forward/Backward.....");

        break;

      case 's':

        analogWrite(enC, 255);
        digitalWrite(in5, LOW);
        digitalWrite(in6, HIGH);

        Serial.println(".....Down.....");
        break;

      case 'w':

        analogWrite(enC, 255);
        digitalWrite(in5, HIGH);
        digitalWrite(in6, LOW);

        Serial.println(".....Up.....");
        break;

      case 'f':

        analogWrite(enC, 0);
        digitalWrite(in5, LOW);
        digitalWrite(in6, HIGH);

        Serial.println(".....Stop Down/Up.....");
        break;

      default:

        for (int pin = 2; pin < 8; pin++)
        {
          digitalWrite(pin, LOW);
        }
    }
  }
}
