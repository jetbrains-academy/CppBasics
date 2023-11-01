#include <iostream>
#include <memory>

class Laptop;

class Student : public std::enable_shared_from_this<Student> {
public:
    explicit Student(int studentID) : studentID(studentID) {}

    int GetStudentID() const {
        return studentID;
    }

    void SetLaptop(const std::shared_ptr<Laptop>& laptop_pointer) {
        laptop = laptop_pointer;
    }

    std::shared_ptr<Laptop> GetLaptop() const {
        return laptop;
    }

private:
    int studentID;
    std::shared_ptr<Laptop> laptop;
};

class Laptop {
public:
    explicit Laptop(const std::shared_ptr<Student>& owner) : owner(owner) {}

    void DisplayInfo() const {
        if (auto lockedOwner = owner.lock()) {
            std::cout << "Laptop belongs to Student ID: " << lockedOwner->GetStudentID() << std::endl;
        } else {
            std::cout << "Laptop owner has been released.\n";
        }
    }

private:
    std::weak_ptr<Student> owner;
};

int main() {
    auto student1 = std::make_shared<Student>(1);
    auto student2 = std::make_shared<Student>(2);

    // Create a laptop with an owner (student1)
    auto laptop = std::make_shared<Laptop>(student1);

    // Set the laptop for student1
    student1->SetLaptop(laptop);

    // Display laptop owner info
    std::cout << "Initial Laptop Owner Info:\n";
    laptop->DisplayInfo();

    // Student2 borrows the laptop
    student2->SetLaptop(laptop);

    // Display laptop owner info after borrowing
    std::cout << "\nAfter Student2 Borrowed the Laptop:\n";
    laptop->DisplayInfo();

    // Display laptop owner info after student1 release
    student1.reset(); // Release student1
    std::cout << "\nAfter Student1 Released the Laptop:\n";
    laptop->DisplayInfo();

    return 0;
}
