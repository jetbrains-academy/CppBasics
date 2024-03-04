#include <gtest/gtest.h>
#include "../include/Cache.h"


TEST(CacheTest, PutAndGet) {
    Cache cache;
    cache.put("Alice", "123-456-7890");
    ASSERT_EQ(cache.get("Alice"), "123-456-7890");
}

TEST(CacheTest, Remove) {
    Cache cache;
    cache.put("Alice", "123-456-7890");
    cache.remove("Alice");
    ASSERT_EQ(cache.get("Alice"), "");
}

TEST(CacheTest, GetNonExistentKey) {
    Cache cache;
    ASSERT_EQ(cache.get("NonExistentKey"), "");
}

TEST(CacheTest, PrintElement) {
    Cache cache;
    cache.put("Alice", "123-456-7890");
    testing::internal::CaptureStdout();
    cache.print_element("Alice");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Alice: 123-456-7890\n");
}

TEST(CacheTest, PrintElementNonExistentKey) {
    Cache cache;
    testing::internal::CaptureStdout();
    cache.print_element("NonExistentKey");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "NonExistentKey not found\n");
}

TEST(CacheTest, PrintCache) {
    Cache cache;
    cache.put("Alice", "123-456-7890");
    cache.put("Bob", "234-567-8901");
    cache.put("Charlie", "345-678-9012");
    testing::internal::CaptureStdout();
    cache.print_cache();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output == "Alice: 123-456-7890\nBob: 234-567-8901\nCharlie: 345-678-9012\n" ||
                output == "Bob: 234-567-8901\nAlice: 123-456-7890\nCharlie: 345-678-9012\n" ||
                output == "Charlie: 345-678-9012\nBob: 234-567-8901\nAlice: 123-456-7890\n");
}