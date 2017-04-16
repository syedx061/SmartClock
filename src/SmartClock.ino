int speakerPin = D0;
int buttonPin = D2;

bool ButtonNow = FALSE;//Create two states to compare so that the button doesn't continously count
bool ButtonLast = FALSE;


enum led_mode_t {
    OFF,
    ON,
};
led_mode_t mode = OFF;

void setup() {
    pinMode(buttonPin, INPUT_PULLDOWN);
    Serial.begin(9600);
}

void loop() {


    //play alarm if the mode is ON
    if (mode == ON)
    {
        //the pin, the frequency of tone in hertz, the duration of tone in milliseconds
        tone(speakerPin, 880, 1000);
        delay(1100);
        tone(speakerPin, 440, 1000);
        delay(1100);
    }
    else
    {
    noTone(speakerPin);
    }

    ButtonNow = digitalRead(buttonPin);

    if(ButtonNow == HIGH && ButtonLast == LOW)
    {
        mode = ON;

    }
    else if (ButtonNow == LOW)
    {
        ButtonLast = OFF;
    }
}

    
