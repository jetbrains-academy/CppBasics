#ifndef CPPBASICS_TEXTEDITOR_H
#define CPPBASICS_TEXTEDITOR_H
#include <string>
#include <stack>

class TextEditor {
public:
    void append(const std::string& w);
    void deleteLast(int k);
    void undo();
    void redo();
    std::string getText() const;
private:
    std::string text;
    std::stack<std::string> undoStack;
    std::stack<std::string> redoStack;
};

#endif //CPPBASICS_TEXTEDITOR_H
