#include <iostream>
#include <memory>

#include "../include/chat.hpp"
#include "../include/user.hpp"

std::shared_ptr<Chat> createNewChat(std::string name, const std::shared_ptr<User>& host) {
    host->chat = std::make_shared<Chat>(User::nextChatId++, std::move(name), host);
    return host->chat;
}

int main() {
    std::shared_ptr<User> bob = std::make_shared<User>("Bob");
    std::shared_ptr<User> alice = std::make_shared<User>("Alice");
    std::shared_ptr<Chat> chat = createNewChat("C++ discussion", bob);
    alice->joinChatByInvite(*bob);

    std::cout << "Bob is currently in the chat " << bob->getChat()->getName() << "\n";
    std::cout << "Alice is currently in the chat " << alice->getChat()->getName() << "\n";
    std::cout << "Host of the chat " << chat->getName() << "is " << chat->getHost() << "\n";

    return 0;
}
