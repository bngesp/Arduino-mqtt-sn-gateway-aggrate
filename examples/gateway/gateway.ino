#include <Bridge.h>
#include <Console.h>
#include "PubSubMqttMessageHandler.h"
#include "SX1276Socket.h"
#include "Gateway.h"
#include "SDPersistentImpl.h"
#include "ArduinoLogger.h"
#include "ArduinoSystem.h"


 
Gateway gateway;
SX1276Socket udpSocket(sx1276);
SDPersistentImpl persistent;
chrono
PubSubMqttMessageHandler mqtt;
ArduinoLogger logger;
ArduinoSystem systemImpl;


void setup() {
	Bridge.begin(115200);
	Console.begin();

    logger.start_log("Linux MQTT-SN Gateway version 0.0.1a starting", 1);
    logger.append_log("Ethernet connected!");

    gateway.setLoggerInterface(&logger);
    gateway.setSocketInterface(&udpSocket);
    gateway.setMqttInterface(&mqtt);
    gateway.setPersistentInterface(&persistent);
    gateway.setSystemInterface(&systemImpl);

    while (!gateway.begin()) {
        logger.log("Error starting gateway components", 0);
        systemImpl.sleep(5000);
        systemImpl.exit();
    }
    logger.log("Gateway ready", 1);
}

void loop(){
	gateway.loop();
}


