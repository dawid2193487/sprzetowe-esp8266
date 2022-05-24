#define byte uint8_t

extern "C" {
  #include "user_interface.h"
}

#include "Arduino.h"
#include "WebServer.h"
#include "UART.h"
#include "Time.h"

static uint32_t currentTime;


void setup() {
  WebServer::init();
}

void loop() {
  WebServer::tick();
}
