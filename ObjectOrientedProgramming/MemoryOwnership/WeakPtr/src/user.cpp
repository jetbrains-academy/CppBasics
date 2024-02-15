#include "../include/user.hpp"

int User::nextId = 0;
int User::nextChatId = 0;
int User::counter = 0;

void User::joinChatByInvite(const User& user) {
    chat = user.chat;
}

void User::leaveChat() {
    chat.reset();
}