/*
*   Create by Bassirou NGOM 
*   09/09/2018
*/

#ifndef GATEWAY_PUBSUBMQTTMESSAGEHANDLER_H
#define GATEWAY_PUBSUBMQTTMESSAGEHANDLER_H

#include <PubSubClient.h>
#include "CoreInterface.h"
#include "IPAddress.h"
#include "Client.h"
#include "Stream.h"

#define DEFAULT_GATEWAY

class PubSubMqttMessageHandler : public MqttMessageHandlerInterface{
private:
    PubSubClient &pubSubClient;

public:
    PubSubMqttMessageHandler(PubSubClient& pubSubClient);
    PubSubMqttMessageHandler(Client& client);
    PubSubMqttMessageHandler(IPAddress, uint16_t, Client& client);
    //PubSubMqttMessageHandler(IPAddress, uint16_t, MQTT_CALLBACK_SIGNATURE,Client& client);

    bool begin();

    void setCore(Core *core) override;

    void setLogger(LoggerInterface *logger) override;

    void setServer(uint8_t *ip, uint16_t port) override;

    void setServer(const char* hostname, uint16_t port) override;

    bool connect(const char *id) override;

    bool connect(const char *id, const char *user, const char *pass) override;

    bool
    connect(const char *id, 
            const char *willTopic, 
            uint8_t willQos, 
            bool willRetain, 
            const uint8_t *willMessage,
            const uint16_t willMessageLength) override;

    bool
    connect(const char *id, 
            const char *user, 
            const char *pass, 
            const char *willTopic, 
            uint8_t willQos, 
            bool willRetain,
            const uint8_t *willMessage, 
            const uint16_t willMessageLength) override;

    void disconnect();

    bool publish(const char *topic, 
                const uint8_t *payload, 
                uint16_t plength, 
                uint8_t qos, 
                bool retained) override;

    bool subscribe(const char *topic, uint8_t qos) override;

    bool unsubscribe(const char *topic) override;

    bool receive_publish(char *topic, uint8_t *payload, uint32_t length) override;

    bool loop();

    PubSubClient& getPubSubClient();

private:
    Core *core = nullptr;
    LoggerInterface *logger;
};


#endif //GATEWAY_PUBSUBMQTTMESSAGEHANDLER_H
