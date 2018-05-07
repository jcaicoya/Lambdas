#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include "application.h"

enum class Implementation { WithLoop, STL98, WithLambda };

class Functional
{
public:
    static ApplicationList LiveServerFilter(ApplicationList appList, Implementation implementationType = Implementation::WithLambda);

private:
    static ApplicationList LiveServerFilterWithLoop(ApplicationList appList);
    static ApplicationList LiveServerFilterSTL98(ApplicationList appList);
    static ApplicationList LiveServerFilterWithLambda(ApplicationList appList);
};

#endif // FUNCTIONAL_H
