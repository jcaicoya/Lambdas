#include "functional.h"

#include <algorithm>

ApplicationList Functional::LiveServerFilter(ApplicationList appList, Implementation implementationType)
{
    switch(implementationType)
    {
        case Implementation::WithLoop: return LiveServerFilterWithLoop(appList);
        case Implementation::STL98: return LiveServerFilterSTL98(appList);
        case Implementation::WithLambda: return LiveServerFilterWithLambda(appList);
        default: return ApplicationList{};
    }
}

ApplicationList Functional::LiveServerFilterWithLoop(ApplicationList appList)
{
    ApplicationList result;

    for(Application app: appList)
    {
        if(Server::Live == app._server)
        {
            result.emplace_back(app);
        }
    }

    return result;
}

bool NotLiveServerFiler(const Application &app)
{
    return Server::Live != app._server;
}

ApplicationList Functional::LiveServerFilterSTL98(ApplicationList appList)
{
    auto firstPosToErase = std::remove_if(appList.begin(),
                                          appList.end(),
                                          &NotLiveServerFiler);
    appList.erase(firstPosToErase, appList.end());
    return appList;
}

ApplicationList Functional::LiveServerFilterWithLambda(ApplicationList appList)
{
    auto firstPosToErase = std::remove_if(appList.begin(),
                                          appList.end(),
                                          [](const Application &app){ return Server::Live != app._server;});
    appList.erase(firstPosToErase, appList.end());
    return appList;
}
