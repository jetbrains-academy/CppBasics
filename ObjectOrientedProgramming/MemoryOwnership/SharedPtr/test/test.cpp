#include <gtest/gtest.h>
#include <memory>
#include <utility>
#include <iostream>

struct chat{
private:
    std::string name;

public:
    explicit chat(std::string  name) : name(std::move(name)) {};

    ~chat() {
        std::cout << "Chat deleted!\n";
    }
};

struct user {
private:
    std::string name;
    int id;

public:
    std::shared_ptr<chat> current_chat;

    user(std::string  name, int id) : name(std::move(name)), id(id) {};

    void create_chat(std::string chat_name) {
        current_chat = std::make_shared<chat>(std::move(chat_name));;
    }

    void join_chat_by_invite(user & other_user) {
        current_chat = other_user.current_chat;
    }

    void leave_chat() {
        current_chat = nullptr;
    }
};

int user_count(std::shared_ptr<chat> & sharedPtr);

TEST(SharedPtrTest, ChatTest) {
    user user1("User1", 1);
    user user2("User2", 2);
    user user3("User3", 3);
    user1.create_chat("name");
    user2.join_chat_by_invite(user1);
    EXPECT_EQ(user_count(user1.current_chat), 2);
    user1.leave_chat();
    EXPECT_EQ(user_count(user2.current_chat), 1);
    user3.join_chat_by_invite(user2);
    EXPECT_EQ(user_count(user3.current_chat), 2);
    user2.leave_chat();
    user3.leave_chat();
    EXPECT_EQ(user1.current_chat, nullptr);
}
