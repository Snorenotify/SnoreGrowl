#ifndef GROWLXX_HPP_
#define GROWLXX_HPP_

#include "growl.h"
#include <string>
#include <vector>

enum Growl_Protocol { GROWL_UDP , GROWL_TCP };

class Growl;

class GROWL_CPP_EXPORT GrowlNotificationData {
private:
    friend class Growl;

    growl_notification_data data(const Growl* sender) const;

    std::string notification;
    int id;
    std::string title;
    std::string message;
    std::string url;
    std::string icon;

    char *icon_data;
    size_t icon_data_size;

    std::string callback_data;

public:
    GrowlNotificationData(const std::string &notification, const int id, const std::string &title, const std::string &message);
    ~GrowlNotificationData();

    void setIcon(const std::string& icon);
    void setIconData(const char *icon_data, const size_t icon_data_size);
    void setUrl(const std::string& url);
    void setCallbackData(const std::string& data);




};

class GROWL_CPP_EXPORT Growl {
private:
    friend class GrowlNotificationData;
    std::string server;
    std::string password;
    Growl_Protocol protocol;
    std::string application;
public:
    Growl(const Growl_Protocol _protocol, const std::string &_password, const std::string &_appliciation);
    Growl(const Growl_Protocol _protocol, const std::string &_server, const std::string &_password, const std::string &_application);
    ~Growl();

    void Register(const std::vector<std::string> &notifications, const std::string &icon = std::string());

    void Notify(const GrowlNotificationData &notification);

    static void setCallback(GROWL_CALLBACK callback);
};

#endif // GROWLXX_HPP_

/* vim:set et sw=2 ts=2 ai: */
