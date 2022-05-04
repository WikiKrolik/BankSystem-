#include <boost/test/unit_test.hpp>
#include "ContainerStack.h"
#include "Container.h"

BOOST_AUTO_TEST_SUITE(ContainerSuiteCorrect);

    BOOST_AUTO_TEST_CASE(EmptinessTest){
        ContainerStack  a;
        Container c = Container(1);
        a.take(c);
        BOOST_CHECK_EQUAL(a.getSize(),1);
    }
    BOOST_AUTO_TEST_CASE(PackingTest){
        ContainerStack  a;
        Container c;
        a.take(c);
        a.take(c);
        a.take(c);
        a.take(c);
        BOOST_CHECK_EQUAL(a.getSize(),4);
    }
    BOOST_AUTO_TEST_CASE(Overloading) {
        ContainerStack  a;
        Container c = Container(2);
        int i=11;
        for(i;i<=0;i--){
            a.take(c);
        }
        BOOST_CHECK(a.getSize() <= a.getCapacity());
    }
    BOOST_AUTO_TEST_CASE(Unloading) {
        ContainerStack  a;
        Container c = Container(3);
        a.take(c);
        a.give();
        BOOST_CHECK_EQUAL(a.getSize(),0);
        BOOST_CHECK_EQUAL(c.getNumber(),3);

    }
    BOOST_AUTO_TEST_CASE(Unloading_More){
        ContainerStack  a;
        Container b = Container(4);
        Container c = Container(5);
        Container d = Container(6);
        a.take(b);
        a.take(c);
        a.take(d);
        a.give();
            BOOST_CHECK_EQUAL(a.getSize(),2);
            BOOST_CHECK_EQUAL(c.getNumber(),5);
            BOOST_CHECK_EQUAL(b.getNumber(),4);

    }
BOOST_AUTO_TEST_CASE(Checking_is_loading_correct){
        ContainerStack a;
        Container b = Container(4);
        Container c = Container(5);
        Container d = Container(6);
        a.take(b);
        a.take(c);
        a.take(d);
        //BOOST_CHECK_EQUAL(a.at(0),4);
        BOOST_CHECK_EQUAL(a.at(1).getNumber(),5);
        BOOST_CHECK_EQUAL(a.at(2).getNumber(),6);
    }


BOOST_AUTO_TEST_SUITE_END()