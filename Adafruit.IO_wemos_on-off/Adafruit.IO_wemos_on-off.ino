#include "config.h"

AdafruitIO_Feed *reciveddata = io.feed("onoff");

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  reciveddata->onMessage(handleMessage);
  while(io.mqttStatus() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  reciveddata->get();

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
}

void loop() {
  io.run();
}

void handleMessage(AdafruitIO_Data *data) {
  Serial.print("received <- ");
  Serial.println(data->value());
}
