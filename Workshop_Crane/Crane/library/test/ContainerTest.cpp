#include <boost/test/unit_test.hpp>
#include "Container.h"

BOOST_AUTO_TEST_SUITE(ContainerSuiteCorrect);

BOOST_AUTO_TEST_CASE(testContainer_initialState)
        {
            Container k1 = Container(234);
        BOOST_REQUIRE_EQUAL(k1.getNumber(), 234);
        BOOST_REQUIRE_EQUAL(k1.getTareWeight(), 100);
        BOOST_REQUIRE_EQUAL(k1.getMaxWeight(), 1000);
        BOOST_REQUIRE_EQUAL(k1.getNetWeight(), 0.0);
        BOOST_REQUIRE_CLOSE_FRACTION(k1.getGrossWeight(), 100, 0.00001);
        }
BOOST_AUTO_TEST_CASE(testNonContainer_initialState)
        {
            Container k0 = Container();
        BOOST_REQUIRE_EQUAL(k0.getNumber(), 0);
        BOOST_REQUIRE_EQUAL(k0.getTareWeight(), 100);
        BOOST_REQUIRE_EQUAL(k0.getMaxWeight(), 1000);
        BOOST_REQUIRE_EQUAL(k0.getNetWeight(), 0.0);
        BOOST_REQUIRE_CLOSE_FRACTION(k0.getGrossWeight(), 100, 0.00001);
        };
BOOST_AUTO_TEST_CASE (testContainer_LoadBelowMaxWeight)
        {
            Container k2 = Container();
                k2.loadCargo(300);
        BOOST_REQUIRE_EQUAL(k2.getNetWeight(), 300);
        }
BOOST_AUTO_TEST_CASE (testContainer_LoadAboveMaxWeight)
        {
            Container k3 = Container();
        k3.loadCargo(2000);
        BOOST_REQUIRE_EQUAL(k3.getNetWeight(), 0);
        }
BOOST_AUTO_TEST_CASE (testContainer_UnloadAboveContent)
        {
            Container k4 = Container();
            k4.loadCargo(200);
            k4.unloadCargo(300);
        BOOST_REQUIRE_EQUAL(k4.getNetWeight(), 0);
        }


BOOST_AUTO_TEST_SUITE_END()
