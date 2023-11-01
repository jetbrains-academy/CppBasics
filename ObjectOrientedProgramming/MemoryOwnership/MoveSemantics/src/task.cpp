#include <memory>
#include <utility>
#include <iostream>

std::unique_ptr<int> transfer_ownership(std::unique_ptr<int> &ptr) {
    return std::unique_ptr<int>(std::move(ptr));
}

void swap_ownership(std::unique_ptr<int>& ptr1, std::unique_ptr<int>& ptr2) {
    std::unique_ptr<int> temp(ptr1.release());
    ptr1 = std::move(ptr2);
    ptr2 = std::move(temp);
}

int main() {
    auto ptr1 = std::make_unique<int>(42);
    auto ptr2 = transfer_ownership(ptr1);
    if (ptr1 == nullptr) {
        std::cout << "Ownership is transferred!" << std::endl;
    }

    auto ptr3 = std::make_unique<int>(10);
    auto ptr4 = std::make_unique<int>(20);

    swap_ownership(ptr3, ptr4);

    std::cout << "ptr1: " << *ptr3 << std::endl;
    std::cout << "ptr2: " << *ptr4 << std::endl;
    return 0;
}

