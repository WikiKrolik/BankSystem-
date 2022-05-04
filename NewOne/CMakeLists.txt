cmake_minimum_required(VERSION 3.4)

#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Project)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

#Source files here
set(SOURCE_FILES
        include/Bank.h
        include/Client.h
        src/Bank.cpp
        src/main.cpp
        src/Client.cpp src/Account.cpp include/Account.h src/Transfer.cpp include/Transfer.h src/NormalAccount.cpp include/NormalAccount.h src/CreditAccount.cpp include/CreditAccount.h src/SavingsAccount.cpp include/SavingsAccount.h src/Loan.cpp include/Loan.h src/Interface.cpp include/Interface.h)

add_executable(FinalProject ${SOURCE_FILES} src/Client.cpp src/Interface.cpp include/Interface.h)

#TESTS

target_include_directories(FinalProject PUBLIC include)

find_package (Boost 1.65.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#Test source files
set(SOURCE_TEST_FILES
        test/Config.cpp
        test/BankTest.cpp
        src/Bank.cpp
        src/Client.cpp src/Interface.cpp include/Interface.h src/Interface.cpp
        src/Loan.cpp
        src/Account.cpp
        src/CreditAccount.cpp
        src/NormalAccount.cpp
        src/SavingsAccount.cpp
        src/Transfer.cpp)

add_executable(TestFinalProject ${SOURCE_TEST_FILES} src/Client.cpp src/Interface.cpp include/Interface.h src/Interface.cpp include/Transfer.h src/Transfer.cpp src/Bank.cpp)

target_include_directories(TestFinalProject PUBLIC include)

target_link_libraries (TestFinalProject
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})