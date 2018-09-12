//
// Created by bele on 06.01.17.
//

#ifndef ESPARDUINOMQTTSNGATEWAY_LOGGERINTERFACE_H
#define ESPARDUINOMQTTSNGATEWAY_LOGGERINTERFACE_H

#include <stdint.h>

class LoggerInterface {

public:

    virtual ~LoggerInterface() {};
    virtual bool begin()=0;
    virtual void set_log_lvl(uint8_t log_lvl)=0;
    virtual void log(char *msg, uint8_t log_lvl)=0;
    virtual void log(const char *msg, uint8_t log_lvl)=0;
    virtual void start_log(char *msg, uint8_t log_lvl)=0;
    virtual void start_log(const char *msg, uint8_t log_lvl)=0;
    virtual void set_current_log_lvl(uint8_t log_lvl)=0;
    virtual void append_log(char *msg)=0;
    virtual void append_log(const char *msg)=0;

};

#endif //ESPARDUINOMQTTSNGATEWAY_LOGGERINTERFACE_H
