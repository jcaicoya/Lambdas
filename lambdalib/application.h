#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <list>

enum class Server { Development, Test, Live };


class Application
{
public:
    Application(std::string name, Server server) : _name(name), _server(server) {}

    std::string _name;
    Server _server;
};


using ApplicationList = std::list<Application>;


class ApplicationBuilder
{
public:
    static ApplicationList GetApplications();

private:
    ApplicationBuilder();

    ApplicationBuilder(const ApplicationBuilder &) = delete;
    ApplicationBuilder & operator=(const ApplicationBuilder &) = delete;

    ApplicationList _applicationList;
};

#endif // APPLICATION_H
