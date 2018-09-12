//
// Created by bele on 01.01.17.
//

#ifndef MQTTSNGATEWAY_COREIMPL1_H
#define MQTTSNGATEWAY_COREIMPL1_H


#include "CoreInterface.h"

class CoreImpl : public Core{
private:
    PersistentInterface *persistent = nullptr;
    MqttMessageHandlerInterface *mqtt = nullptr;
    MqttSnMessageHandler *mqttsn = nullptr;
    LoggerInterface *logger = nullptr;
    System *timeout_system = nullptr;
    System *advertise_system = nullptr;

public:
    virtual bool begin();

    virtual void setPersistent(PersistentInterface *persistent);

    virtual void setMqttMessageHandler(MqttMessageHandlerInterface *mqtt);

    virtual void setMqttSnMessageHandler(MqttSnMessageHandler *mqttsn);

    virtual void setLogger(LoggerInterface *logger);

    virtual void setSystem(System *system);

    virtual void setDurationSystem(System *system);

    virtual void loop();

    virtual int16_t
    add_client(const char *client_id,  uint16_t duration, bool clean_session,device_address *address);

    virtual int16_t remove_will(device_address *address);

    virtual int16_t add_will_topic(device_address *address, char *will_topic, bool retain, uint8_t qos);

    virtual int16_t add_will_msg(device_address *address, uint8_t *will_msg, uint8_t will_msg_len);

    virtual int16_t await_message(device_address *address, message_type type);

    virtual int16_t register_topic(device_address *address, char *topic_name, uint16_t *new_topic_id);

    virtual int16_t
    notify_regack_arrived(device_address *address, uint16_t topic_id, uint16_t msg_id, return_code_t return_code);

    virtual int16_t notify_parse_error(device_address *address);

    virtual int16_t
    publish(device_address *address, const uint8_t *data, uint16_t data_len, uint16_t msg_id, uint16_t topic_id,
            bool short_topic, bool retain, int8_t qos, bool dup, uint16_t *new_topic_id);

    virtual int16_t
    add_subscription(device_address *address, uint16_t topic_id, uint16_t msg_id, bool short_topic, uint8_t qos,
                     bool dup,uint16_t* new_topic_id, uint8_t* granted_qos);

    virtual int16_t
    delete_subscription(device_address *address, uint16_t topic_id, uint16_t msg_id, bool short_topic, bool dup);

    virtual int16_t delete_subscription(device_address *address, char *topic_name, uint16_t msg_id, bool dup);

    virtual int16_t set_disconnected(device_address *address);

    virtual int16_t set_asleep(device_address *address, uint16_t duration);

    virtual int16_t set_asleep(device_address *address);

    virtual int16_t
    notify_puback_arrived(device_address *address, uint16_t msg_id, uint16_t topic_id, return_code_t return_code);

    virtual int16_t set_awake(device_address *address);

    virtual int16_t get_gateway_id(uint8_t *gateway_id);

    virtual int16_t notify_mqttsn_disconnected();

    virtual int16_t notify_mqtt_disconnected();

    virtual int16_t publish(char *topic_name, uint8_t *data, uint32_t data_length, bool retain);

    virtual int16_t get_mqtt_config(uint8_t *server_ip, uint16_t *server_port, char *client_id);

    virtual int16_t get_mqtt_login_config(char *username, char *password);

    virtual int16_t get_mqtt_will(char *will_topic, char *will_msg, uint8_t *will_qos, bool *will_retain);

    virtual int16_t notify_mqtt_connected();

    virtual int16_t notify_mqttsn_connected();
private:
    void remove_client_subscriptions(const char *client_id);
    void process_mqttsn_offline_procedure();
    void process_mqtt_offline_procedure();

    void set_all_clients_lost();

    void handle_timeout(const CLIENT_STATUS &status, uint32_t duration, uint32_t elapsed_time, char *client_id,
                        device_address &address,
                        uint32_t &timeout);

    void handle_receive_mqtt_publish_for_client(const char *topic_name, uint8_t *data, uint32_t data_length,
                                                device_address &address,
                                                bool retain);

    void handle_client_publishes(CLIENT_STATUS status, const char *client_id, device_address *address);

    void append_device_address(device_address *pAddress);

public:
    int16_t reset_timeout(device_address *address) override;
};


#endif //MQTTSNGATEWAY_COREIMPL1_H
