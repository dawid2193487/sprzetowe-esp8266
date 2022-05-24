#define byte uint8_t

#include "Arduino.h"
#include "WebServer.h"

void setup() {
  WebServer::init();
}

void loop() {
  WebServer::tick();
}
