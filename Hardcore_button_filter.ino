
bool filter_button(int *button_pin ,bool *state, int *push_count,int *filter_limit,long *current_time, int *period) {
  if (*state == 0)
  {
    if (digitalRead(*button_pin)&&digitalRead(*button_pin)&&digitalRead(*button_pin)) {
      *push_count+=1;

    } else {
      *push_count = 0;

    }
    if (*push_count > *filter_limit && millis()-*current_time>*period)
    {
      *current_time = millis();
      *push_count = 0;
      *state = true;
      return true;
    }
  }
  else
  {
    if (!digitalRead(*button_pin) && !digitalRead(*button_pin) && !digitalRead(*button_pin)) {
      *push_count+=1;
    } else {
      *push_count = 0;
    }
    if (*push_count > *filter_limit)
    {
      *state = false;
      *push_count = 0;
    }
  }
  return false;
}


struct Button
{
  int pin;
  bool state;
  int push_count;
  int filter_limit;
  long current_time;
  int period;
} ;


Button START = {2, false, 0, 1000, 0, 1000};

//but_mark = &START;

bool filter_struct(struct Button *button) {
  if (button->state == 0)
  {
    if (digitalRead(button->pin)&&digitalRead(button->pin)&&digitalRead(button->pin)) {
      button->push_count+=1;

    } else {
      button->push_count = 0;

    }
    if (button->push_count > button->filter_limit && millis()-button->current_time>button->period)
    {
      button->current_time = millis();
      button->push_count = 0;
      button->state = true;
      return true;
    }
  }
  else
  {
    if (!digitalRead(button->pin) && !digitalRead(button->pin) && !digitalRead(button->pin)) {
      button->push_count+=1;
    } else {
      button->push_count = 0;
    }
    if (button->push_count > button->filter_limit)
    {
      button->state = false;
      button->push_count = 0;
    }
  }
  return false;
}

int START_BUTTON = 2;
bool strt = false;
int psh_strt = 0;
int filter_limit = 400;
long strt_current = 0;
int strt_period = 1000;













void setup() {
  // put your setup code here, to run once:
 pinMode(START_BUTTON, INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

//    if (filter_button(&START_BUTTON, &strt, &psh_strt, &filter_limit, &strt_current, &strt_period)) {
if (filter_struct(&START)) {

    Serial.println("start");
   
  }

}
