cmake_minimum_required(VERSION 3.20)
project(FinalProject)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        library/include/model/Account.h
        library/include/model/Client.h
        library/include/model/Bank.h
        library/src/model/Account.cpp
        library/src/model/Bank.cpp
        library/src/model/Client.cpp
        library/src/model/SavingAccount.cpp
        library/include/model/SavingAccount.h
        library/src/main.cpp library/src/model/NormalAccount.cpp library/include/model/NormalAccount.h
        library/src/model/CreditAccount.cpp library/include/model/CreditAccount.h library/src/model/Storage.cpp library/include/model/Storage.h library/include/controller/AccountManager.h library/src/model/Address.cpp library/include/model/Address.h library/src/controller/SavingAccountManager.cpp library/include/controller/SavingAccountManager.h library/src/controller/NormalAccountManager.cpp library/include/controller/NormalAccountManager.h library/src/controller/CreditAccountManager.cpp library/include/controller/CreditAccountManager.h library/src/model/Transfer.cpp library/include/model/Transfer.h library/src/controller/TransferManager.cpp library/include/controller/TransferManager.h library/src/model/Loan.cpp library/include/model/Loan.h library/src/controller/LoanManager.cpp library/include/controller/LoanManager.h library/test/ClientTest.cpp library/test/master.cpp)


set(Qt5_DIR "~/Qt/5.12.2/clang_64/lib/cmake/Qt5")

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

include_directories(library/include)

add_executable(FinalProject ${SOURCE_FILES}
        )

target_link_libraries(FinalProject Qt5::Widgets)

##TESTs
#find_package(Boost 1.65 COMPONENTS "unit_test_framework" REQUIRED)
#
#include_directories(
#        ${CMAKE_CURRENT_SOURCE_DIR}/include
#        ${Boost_INCLUDE_DIRS}
#)
#set(SOURCE_TEST_FILLES
#        test/master.cpp)
#
##Test source files here
#set(SOURCE_FILES
#        test/master.cpp
#        test/ClientTest.cpp
#        src/model/Client.cpp
#        src/model/Bank.cpp
#)
#
#
#
#target_include_directories(FinalProject PUBLIC include)
#
#target_link_libraries(FinalProject
#        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
#
#enable_testing()
#
#add_test(NAME Test COMMAND TestProject
#        --report_level=detailed
#        --log_level=all
#        --color_output=yes)
#
#add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
#        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
#        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
#
