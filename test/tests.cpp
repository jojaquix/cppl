#include <catch2/catch.hpp>
#

#include "lib.h"

#include <ranges>
#include <numeric>

LoopFunctionT loopFunction = nullptr;

TEST_CASE("Test with zero", "[dummy]")
{   
   REQUIRE(0 == 0);
}

TEST_CASE("Test some std algorithms", "[std]")
{   
    std::vector<int> v = {1, 2, 3, 4, 5};
    REQUIRE(std::accumulate(v.begin(), v.end(), 0) == 15);
    REQUIRE(std::count(v.begin(), v.end(), 3) == 1);
    REQUIRE(std::find(v.begin(), v.end(), 3) != v.end());
    REQUIRE(std::find(v.begin(), v.end(), 6) == v.end());
    // partitions
    std::vector<int> v2 = {1, 2, 3, 4, 5};
    std::partition(v2.begin(), v2.end(), [](int i){return i % 2 == 0;});
    REQUIRE(std::is_partitioned(v2.begin(), v2.end(), [](int i){return i % 2 == 0;}));
    std::sort(std::begin(v2), std::end(v2));
    REQUIRE(std::is_sorted(std::begin(v2), std::end(v2)));
    // using views and ranges
    std::vector<int> v3 = {1, 2, 3, 4, 5};
    auto even = std::views::filter(v3, [](int i){return i % 2 == 0;});
    REQUIRE(std::accumulate(even.begin(), even.end(), 0) == 6);
    auto square = std::views::transform(v3, [](int i){return i * i;});
    REQUIRE(std::accumulate(square.begin(), square.end(), 0) == 55);


    
}