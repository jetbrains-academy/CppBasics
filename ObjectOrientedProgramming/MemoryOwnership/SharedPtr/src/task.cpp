#include <iostream>

#include "../include/chat.hpp"

int User::nextId = 0;
int User::nextChatId = 0;

void User::createNewChat(std::string name) {
    chat = std::make_shared<Chat>(nextChatId++, std::move(name));
}

void User::joinChatByInvite(const User& user) {
    chat = user.chat;
}

void User::leaveChat() {
    chat.reset();
}

int main() {
    User bob("Bob");
    User alice("Alice");
    bob.createNewChat("C++ discussion");
    alice.joinChatByInvite(bob);

    std::cout << "Bob is currently in the chat " << bob.getChat()->getName() << "\n";
    std::cout << "Alice is currently in the chat " << alice.getChat()->getName() << "\n";

    return 0;
}