#include <gtest/gtest.h>
#include <memory>

#include "../include/chat.hpp"

TEST(UserTest, CreateNewChatTest) {
    User bob("Bob");
    bob.createNewChat("Chat");
    ASSERT_NE(nullptr, bob.getChat());
    ASSERT_EQ("Test", bob.getChat()->getName());
    ASSERT_EQ(1, bob.getChat().use_count());

    std::shared_ptr<Chat> chat = bob.getChat();
    bob.createNewChat("New Chat");
    ASSERT_NE(nullptr, bob.getChat());
    ASSERT_NE(chat, bob.getChat());
    ASSERT_NE(chat->getId(), bob.getChat()->getId());
    ASSERT_EQ("New Chat", bob.getChat()->getName());
    ASSERT_EQ(1, bob.getChat().use_count());
}

TEST(UserTest, JoinChatByInviteTest) {
    User bob("Bob");
    User alice("Alice");
    bob.createNewChat("Chat");
    alice.joinChatByInvite(bob);
    ASSERT_NE(nullptr, alice.getChat());
    ASSERT_EQ(bob.getChat(), alice.getChat());
    ASSERT_EQ(2, bob.getChat().use_count());
}

TEST(UserTest, LeaveChatTest) {
    User bob("Bob");
    User alice("Alice");
    bob.createNewChat("Chat");
    alice.joinChatByInvite(bob);
    bob.leaveChat();
    ASSERT_EQ(nullptr, bob.getChat());
    ASSERT_NE(nullptr, alice.getChat());
    ASSERT_EQ(1, alice.getChat().use_count());
}