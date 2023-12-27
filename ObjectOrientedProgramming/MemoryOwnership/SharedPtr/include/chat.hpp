#ifndef CPPBASICS_CHAT_HPP
#define CPPBASICS_CHAT_HPP

#include <memory>
#include <string>
#include <utility>

class Chat {
public:
    Chat(int id, std::string name)
        : id(id)
        , name(std::move(name))
    {};

    inline int getId() const {
        return id;
    }

    inline std::string getName() const {
        return name;
    }
private:
    int id;
    std::string name;
};

class User {
public:

    explicit User(std::string name)
        : id(nextId++)
        , name(std::move(name))
        , chat(nullptr)
    {};

    inline int getId() const {
        return id;
    }

    inline std::string getName() const {
        return name;
    }

    inline const std::shared_ptr<Chat>& getChat() const {
        return chat;
    }

    void createNewChat(std::string name);

    void joinChatByInvite(const User& user);

    void leaveChat();
private:
    int id;
    std::string name;
    std::shared_ptr<Chat> chat;
    static int nextId;
    static int nextChatId;
};

#endif // CPPBASICS_CHAT_HPP
