#include "application.h"


ApplicationList ApplicationBuilder::GetApplications()
{
    static ApplicationBuilder builder;
    return builder._applicationList;
}

ApplicationBuilder::ApplicationBuilder() : _applicationList{ {"RequestManager", Server::Development},
                                                             {"Balancer", Server::Test},
                                                             {"FrontEnd", Server::Live},
                                                             {"BackEnd", Server::Live},
                                                             {"LightSpeedSocket", Server::Development},
                                                             {"FastSocket", Server::Test},
                                                             {"Pipes", Server::Test}
                                                            }
{}
