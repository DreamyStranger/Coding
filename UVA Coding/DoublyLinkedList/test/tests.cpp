#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../external/doctest/doctest.h"
#include "../src/List.h"

TEST_CASE("Empty list is initialized correctly")
{
    List<int> list;
    CHECK(list.isEmpty());
    CHECK(list.size() == 0);
}

TEST_CASE("Inserting elements increases the size of the list")
{
    List<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    CHECK(list.size() == 3);
}

TEST_CASE("Find returns the correct iterator position")
{
    List<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    ListItr<int> itr = list.find(20);
    CHECK(itr.retrieve() == 20);
}

TEST_CASE("Removing an element reduces the size of the list")
{
    List<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.remove(20);
    CHECK(list.size() == 2);
}

TEST_CASE("Test insertAfter and insertBefore")
{
    List<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    ListItr<int> itr = list.find(20);
    list.insertAfter(25, itr);
    list.insertBefore(15, itr);

    CHECK(list.size() == 5);
    CHECK(list.first().retrieve() == 10);
    CHECK(list.last().retrieve() == 30);

    std::ostringstream oss;
    auto coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf()); // Redirect cout to ostringstream
    list.print(true);
    std::cout.rdbuf(coutBuf); // Restore cout's original buffer
    CHECK(oss.str() == "10 15 20 25 30 \n");
}

TEST_CASE("Test remove")
{
    List<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    list.remove(30);

    CHECK(list.size() == 2);
    CHECK(list.first().retrieve() == 10);
    CHECK(list.last().retrieve() == 20);

    std::ostringstream oss;
    auto coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf()); // Redirect cout to ostringstream
    list.print(true);
    std::cout.rdbuf(coutBuf); // Restore cout's original buffer
    CHECK(oss.str() == "10 20 \n");
}

TEST_CASE("Test copy constructor")
{
    List<int> list1;
    list1.insertAtTail(10);
    list1.insertAtTail(20);
    list1.insertAtTail(30);

    List<int> list2(list1);

    CHECK(list1.size() == 3);
    CHECK(list2.size() == 3);

    list1.insertAtTail(40);

    CHECK(list1.size() == 4);
    CHECK(list2.size() == 3);

    std::ostringstream oss;
    auto coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf()); // Redirect cout to ostringstream
    list2.print(true);
    std::cout.rdbuf(coutBuf); // Restore cout's original buffer
    CHECK(oss.str() == "10 20 30 \n");
}

TEST_CASE("Test assignment operator")
{
    List<int> list1;
    list1.insertAtTail(10);
    list1.insertAtTail(20);
    list1.insertAtTail(30);

    List<int> list2;
    list2.insertAtTail(40);
    list2.insertAtTail(50);

    list2 = list1;

    CHECK(list1.size() == 3);
    CHECK(list2.size() == 3);

    list1.insertAtTail(40);

    CHECK(list1.size() == 4);
    CHECK(list2.size() == 3);

    std::ostringstream oss;
    auto coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf()); // Redirect cout to ostringstream
    list2.print(true);
    std::cout.rdbuf(coutBuf); // Restore cout's original buffer
    CHECK(oss.str() == "10 20 30 \n");
}

TEST_CASE("Printing the list")
{
    List<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    SUBCASE("Printing forward")
    {
        std::ostringstream oss;
        auto coutBuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf()); // Redirect cout to ostringstream
        list.print(true);
        std::cout.rdbuf(coutBuf); // Restore cout's original buffer
        CHECK(oss.str() == "10 20 30 \n");
    }

    SUBCASE("Printing backward")
    {
        std::ostringstream oss;
        auto coutBuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf()); // Redirect cout to ostringstream
        list.print(false);
        std::cout.rdbuf(coutBuf); // Restore cout's original buffer
        CHECK(oss.str() == "30 20 10 \n");
    }
}