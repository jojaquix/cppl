#include <catch2/catch.hpp>
#

#include "EntityManager.hpp"

#include <ranges>
#include <numeric>

//ExecFunctionT executeFunction = nullptr;

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

//test for sprite data 
TEST_CASE("Test sprite data", "[ecs]")
{
    std::vector<KColor> spriteData = {KColor::Black, KColor::White, KColor::Black, KColor::White};
    ecs::Sprite sprite{{2, 2}, spriteData};
    auto data = sprite.data();
    REQUIRE(data.size() == 4);
    REQUIRE(data[0] == KColor::Black);
    REQUIRE(data[1] == KColor::White);
    REQUIRE(data[2] == KColor::Black);
    REQUIRE(data[3] == KColor::White);

    spriteData[0] = KColor::White;
    REQUIRE(data[0] == KColor::Black); //data is a copy of spriteData so it should not change

    //now if spiteData is inicialized with an std array
    std::array<KColor, 4> spriteData2 = {KColor::Transparent, KColor::White, KColor::Black, KColor::White};
    ecs::Sprite sprite2{{2, 2}, spriteData2};
    auto data2 = sprite2.data();
    REQUIRE(data2.size() == 4);
    REQUIRE(data2[0] == KColor::Transparent);
    REQUIRE(data2[1] == KColor::White);
    REQUIRE(data2[2] == KColor::Black);
    REQUIRE(data2[3] == KColor::White);

    spriteData2[0] = KColor::White;
    REQUIRE(data2[0] == KColor::White); //data2 is a spand of spriteData2 so it should change
}