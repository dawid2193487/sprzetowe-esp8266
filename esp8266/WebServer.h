#pragma once

#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK  "your-password"
#endif
#include <ESP8266WebServer.h>

const char* const ssid = STASSID;
const char* const password = STAPSK;

class WebServer {
    public:
    static void init();
    static void index();
    static void tick();
};