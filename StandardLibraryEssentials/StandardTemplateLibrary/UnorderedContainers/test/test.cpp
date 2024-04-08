#include <gtest/gtest.h>
#include "../include/Cache.h"

TEST(LRUCacheTest, OneElementTest) {
    LRUCache cache(1);
    cache.put("1", "one");
    ASSERT_STREQ("one", cache.get("1").c_str());
}

TEST(LRUCacheTest, BasicCacheTest) {
    LRUCache cache(4);
    cache.put("1", "one");
    cache.put("2", "two");
    cache.put("3", "three");
    cache.put("4", "four");
    ASSERT_STREQ("one", cache.get("1").c_str());
    cache.put("5", "five");
    ASSERT_STREQ("Key: <2> not found!\n", cache.get("2").c_str());
}

TEST(LRUCacheTest, RandomCacheTest) {
    LRUCache cache(5);
    cache.put("1", "one");
    cache.put("2", "two");
    cache.put("3", "three");
    cache.put("4", "four");
    cache.put("5", "five");
    cache.put("6", "six");
    cache.put("7", "seven");
    cache.put("8", "eight");
    cache.put("9", "nine");
    cache.put("10", "ten");
    ASSERT_STREQ("Key: <3> not found!\n", cache.get("3").c_str());
    ASSERT_STREQ("Key: <4> not found!\n", cache.get("4").c_str());
    ASSERT_STREQ("Key: <5> not found!\n", cache.get("5").c_str());
    ASSERT_STREQ("six", cache.get("6").c_str());
    ASSERT_STREQ("seven", cache.get("7").c_str());
    ASSERT_STREQ("eight", cache.get("8").c_str());
    ASSERT_STREQ("nine", cache.get("9").c_str());
    ASSERT_STREQ("ten", cache.get("10").c_str());
}