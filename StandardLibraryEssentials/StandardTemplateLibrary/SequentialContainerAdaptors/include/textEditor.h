#ifndef CPPBASICS_TEXTEDITOR_H
#define CPPBASICS_TEXTEDITOR_H
#include <string>
#include <stack>

class TextEditor {
public:
    void insert(const std::string& w, std::size_t pos);
    void erase(std::size_t pos, std::size_t len);
    void undo();
    void redo();
    std::string getText() const;
private:
    std::string text;
    std::stack<std::string> undoStack;
    std::stack<std::string> redoStack;
};

#endif //CPPBASICS_TEXTEDITOR_H
