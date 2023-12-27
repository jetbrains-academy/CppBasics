#ifndef CPPBASICS_CHAT_HPP
#define CPPBASICS_CHAT_HPP

#include <memory>
#include <string>
#include <utility>

class User;

class Chat {
public:
    Chat(int id, std::string name, const std::shared_ptr<User>& owner)
        : id(id)
        , name(std::move(name))
        , host(owner)
    {};

    inline int getId() const {
        return id;
    }

    inline std::string getName() const {
        return name;
    }

    inline std::shared_ptr<User> getHost() const {
        return host.lock();
    }
private:
    int id;
    std::string name;
    std::weak_ptr<User> host;
};

std::shared_ptr<Chat> createNewChat(std::string name, const std::shared_ptr<User>& host);

#endif // CPPBASICS_CHAT_HPP
