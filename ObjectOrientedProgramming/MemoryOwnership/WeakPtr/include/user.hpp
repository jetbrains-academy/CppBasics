#ifndef CPPBASICS_USER_HPP
#define CPPBASICS_USER_HPP

#include <memory>
#include <string>
#include <utility>

#include "../include/chat.hpp"

class User {
public:
    explicit User(std::string name)
        : id(nextId++)
        , name(std::move(name))
        , chat(nullptr)
    {
        counter++;
    };

    ~User() {
        counter--;
    }

    User(const User&) = default;
    User(User&&) = default;

    User& operator=(const User&) = default;
    User& operator=(User&&) = default;

    inline int getId() const {
        return id;
    }

    inline std::string getName() const {
        return name;
    }

    inline const std::shared_ptr<Chat>& getChat() const {
        return chat;
    }

    inline static int getUserCount() {
        return counter;
    }

    void joinChatByInvite(const User& user);

    void leaveChat();

    friend std::shared_ptr<Chat> createNewChat(std::string name, const std::shared_ptr<User>& host);
private:
    int id;
    std::string name;
    std::shared_ptr<Chat> chat;
    static int nextId;
    static int nextChatId;
    static int counter;
};


#endif // CPPBASICS_USER_HPP