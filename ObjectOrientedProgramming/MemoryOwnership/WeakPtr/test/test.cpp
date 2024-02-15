#include <gtest/gtest.h>
#include <memory>

#include "../include/chat.hpp"
#include "../include/user.hpp"

TEST(ChatTest, HostTest) {
    std::shared_ptr<User> bob = std::make_shared<User>("Bob");
    std::shared_ptr<User> alice = std::make_shared<User>("Alice");
    std::shared_ptr<Chat> chat = createNewChat("C++ discussion", bob);
    alice->joinChatByInvite(*bob);

    ASSERT_EQ(chat, bob->getChat());
    ASSERT_EQ(chat, alice->getChat());

    ASSERT_EQ(bob, chat->getHost());
    ASSERT_EQ(2, User::getUserCount());

    alice.reset();
    ASSERT_EQ(bob, chat->getHost());
    ASSERT_EQ(1, User::getUserCount());

    bob.reset();
    ASSERT_EQ(nullptr, chat->getHost());
    ASSERT_EQ(0, User::getUserCount());
}