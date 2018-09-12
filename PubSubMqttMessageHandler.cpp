/*
*	Create by Bassirou NGOM 
*	09/09/2018
*/

#include "PubSubMqttMessageHandler.h"

MqttMessageHandlerInterface *__mqttMessageHandler = nullptr;


PubSubMqttMessageHandler::PubSubMqttMessageHandler(PubSubClient& pubSub): pubSubClient(pubSub){}

PubSubMqttMessageHandler::PubSubMqttMessageHandler(Client& client){
	pubSubClient = PubSubClient(client);
}

PubSubMqttMessageHandler::PubSubMqttMessageHandler(IPAddress addr, uint16_t port, Client& client){
	pubSubClient = PubSubClient(addr, port, client);
}

/*PubSubMqttMessageHandler::PubSubMqttMessageHandler(IPAddress addr, uint16_t port, MQTT_CALLBACK_SIGNATURE,Client& client){
	pubSubClient = PubSubClient(addr, port, MQTT_CALLBACK_SIGNATURE, client);
}*/

bool PubSubMqttMessageHandler::begin(){
	if (core == nullptr) {
        return false;
    }
    __mqttMessageHandler = this;
    
    return true;
}

void PubSubMqttMessageHandler::setCore(Core *core) {
	this->core = core;
}

void PubSubMqttMessageHandler::setLogger(LoggerInterface *logger) {
    this->logger = logger;
}

void PubSubMqttMessageHandler::setServer(uint8_t *ip, uint16_t port) {
	pubSubClient.setServer(ip, port);
}

void PubSubMqttMessageHandler::setServer(const char *hostname, uint16_t port) {
    pubSubClient.setServer(hostname, port);
}


bool PubSubMqttMessageHandler::connect(const char *id) {
    return pubSubClient.connect(id);
}

bool PubSubMqttMessageHandler::connect(const char *id, const char *user, const char *pass) {
    return pubSubClient.connect(id, user, pass);
}

bool PubSubMqttMessageHandler::connect(const char *id, const char *willTopic, uint8_t willQos, bool willRetain, const uint8_t *willMessage,
            const uint16_t willMessageLength) {
    return pubSubClient.connect(id, willTopic, willQos, willRetain, willMessage);//,
            //willMessageLength);
}

bool PubSubMqttMessageHandler::connect(const char *id, const char *user, const char *pass, const char *willTopic, uint8_t willQos, bool willRetain,
            const uint8_t *willMessage, const uint16_t willMessageLength) {
    return this->pubSubClient.connect(id, user, pass, willTopic, willQos, willRetain,
            willMessage); //willMessageLength);
}

void PubSubMqttMessageHandler::disconnect() {
    pubSubClient.disconnect();
}

bool PubSubMqttMessageHandler::subscribe(const char *topic, uint8_t qos) {
	return pubSubClient.subscribe(topic, qos);
}
bool PubSubMqttMessageHandler::publish(const char *topic, const uint8_t *payload, uint16_t plength, uint8_t qos, bool retained){
	return pubSubClient.publish(topic, 
						payload,
						plength, 
						//qos, 
						retained);
}

bool PubSubMqttMessageHandler::unsubscribe(const char *topic){
	return pubSubClient.unsubscribe(topic);
}

bool PubSubMqttMessageHandler::receive_publish(char *topic, uint8_t *payload, uint32_t length){
	int16_t publish_result = core->publish(topic, payload, length, false);
    return publish_result == SUCCESS;
}

bool PubSubMqttMessageHandler::loop(){
	return pubSubClient.loop();
}

PubSubClient& PubSubMqttMessageHandler::getPubSubClient(){
	return pubSubClient;
}

