#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

auto server = new ESP8266WebServer(80);

void setup_wifi_ap_mode(void) {
	struct softap_config apconfig;
	if(wifi_softap_get_config(&apconfig))
	{
		wifi_softap_dhcps_stop();
		memset(apconfig.ssid, 0, sizeof(apconfig.ssid));
		memset(apconfig.password, 0, sizeof(apconfig.password));
        strncpy((char*)apconfig.ssid, "ESP8266", sizeof(apconfig.ssid) - 1);
        strncpy((char*)apconfig.password, "haslohaslo", sizeof(apconfig.password) - 1);
		apconfig.authmode = AUTH_WPA_WPA2_PSK;
		apconfig.ssid_hidden = 0;
		apconfig.channel = 7;
		apconfig.max_connection = 4;
		if(!wifi_softap_set_config(&apconfig))
		{
			#ifdef PLATFORM_DEBUG
			os_printf("ESP8266 not set AP config!\r\n");
			#endif
		};
		struct ip_info ipinfo;
		wifi_get_ip_info(SOFTAP_IF, &ipinfo);
		IP4_ADDR(&ipinfo.ip, 192, 168, 4, 1);
		IP4_ADDR(&ipinfo.gw, 192, 168, 4, 1);
		IP4_ADDR(&ipinfo.netmask, 255, 255, 255, 0);
		wifi_set_ip_info(SOFTAP_IF, &ipinfo);
		wifi_softap_dhcps_start();
	}
	#ifdef PLATFORM_DEBUG
	os_printf("ESP8266 in AP mode configured.\r\n");
	#endif
}

void WebServer::index() {
    String response;

    ap_list* aps = Sniffing::aps;
    ap_node* ap = aps->head;
    response += "<h1>Lista access_pointów</h1>";
    while (aps->head != nullptr) {
        response += "<tr>";
        response += "<td>" + String(ap->ap->SSID) + "</td>";
        response += "<td>" + String(ap->ap->last_seen) + "</td>";
        response += "</tr>";
        ap = (ap_node*)ap->next;
    }

    server->send(200, "text/html", response);
}

void WebServer::init() {

    setup_wifi_ap_mode();

    server->on("/", index);
    server->begin();
    Serial.println("HTTP server started");
}

void WebServer::tick() {
    server->handleClient();
    MDNS.update();
}