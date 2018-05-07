#include <QtTest>

#include "lambdalib/application.h"
#include "lambdalib/functional.h"

class lambdas : public QObject
{
    Q_OBJECT

public:
    lambdas() = default;
    ~lambdas() = default;

private slots:
    void test_application_builder();

    void test_functional_live_server_filter_with_loop();
    void test_functional_live_server_filter_stl98();
    void test_functional_live_server_filter_with_lambda();

    void benchmark_functional_live_server_filter_with_loop();
    void benchmark_functional_live_server_filter_stl98();
    void benchmark_functional_live_server_filter_with_lambda();
};


void lambdas::test_application_builder()
{
    ApplicationList appList = ApplicationBuilder::GetApplications();
    QCOMPARE(appList.size(), static_cast<unsigned long>(7));
}


void lambdas::test_functional_live_server_filter_with_loop()
{
    ApplicationList appList = ApplicationBuilder::GetApplications();

    ApplicationList result = Functional::LiveServerFilter(appList, Implementation::WithLoop);

    QVERIFY(result.size() == 2);

    ApplicationList::const_iterator appListItr = appList.cbegin();
    ApplicationList::const_iterator resultItr = result.cbegin();
    ++appListItr;
    ++appListItr;
    QCOMPARE(resultItr->_name, appListItr->_name);
    QCOMPARE(resultItr->_server, appListItr->_server);

    ++resultItr;
    ++appListItr;
    QCOMPARE(resultItr->_name, appListItr->_name);
    QCOMPARE(resultItr->_server, appListItr->_server);
}


void lambdas::test_functional_live_server_filter_stl98()
{
    ApplicationList appList = ApplicationBuilder::GetApplications();

    ApplicationList result = Functional::LiveServerFilter(appList, Implementation::STL98);

    QVERIFY(result.size() == 2);

    ApplicationList::const_iterator appListItr = appList.cbegin();
    ApplicationList::const_iterator resultItr = result.cbegin();
    ++appListItr;
    ++appListItr;
    QCOMPARE(resultItr->_name, appListItr->_name);
    QCOMPARE(resultItr->_server, appListItr->_server);

    ++resultItr;
    ++appListItr;
    QCOMPARE(resultItr->_name, appListItr->_name);
    QCOMPARE(resultItr->_server, appListItr->_server);
}


void lambdas::test_functional_live_server_filter_with_lambda()
{
    ApplicationList appList = ApplicationBuilder::GetApplications();

    ApplicationList result = Functional::LiveServerFilter(appList, Implementation::WithLambda);

    QVERIFY(result.size() == 2);

    ApplicationList::const_iterator appListItr = appList.cbegin();
    ApplicationList::const_iterator resultItr = result.cbegin();
    ++appListItr;
    ++appListItr;
    QCOMPARE(resultItr->_name, appListItr->_name);
    QCOMPARE(resultItr->_server, appListItr->_server);

    ++resultItr;
    ++appListItr;
    QCOMPARE(resultItr->_name, appListItr->_name);
    QCOMPARE(resultItr->_server, appListItr->_server);
}


void lambdas::benchmark_functional_live_server_filter_with_loop()
{
    ApplicationList appList = ApplicationBuilder::GetApplications();

    QBENCHMARK
    {
        ApplicationList result = Functional::LiveServerFilter(appList, Implementation::WithLoop);
    }
}


void lambdas::benchmark_functional_live_server_filter_stl98()
{
    ApplicationList appList = ApplicationBuilder::GetApplications();

    QBENCHMARK
    {
        ApplicationList result = Functional::LiveServerFilter(appList, Implementation::STL98);
    }
}


void lambdas::benchmark_functional_live_server_filter_with_lambda()
{
    ApplicationList appList = ApplicationBuilder::GetApplications();

    QBENCHMARK
    {
        ApplicationList result = Functional::LiveServerFilter(appList, Implementation::WithLambda);
    }
}

QTEST_APPLESS_MAIN(lambdas)

#include "tst_lambdas.moc"
