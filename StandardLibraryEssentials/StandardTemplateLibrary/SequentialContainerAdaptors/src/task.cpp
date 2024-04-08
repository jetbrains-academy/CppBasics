#include <iostream>
#include "../include/textEditor.h"

void TextEditor::insert(const std::string& w, std::size_t pos) {
    undoStack.push(text);
    text.insert(pos, w);
}

void TextEditor::erase(std::size_t pos, std::size_t len) {
    undoStack.push(text);
    text.erase(pos, len);
}

void TextEditor::undo() {
    if (!undoStack.empty()) {
        redoStack.push(text);
        text = undoStack.top();
        undoStack.pop();
    }
}

void TextEditor::redo() {
    if (!redoStack.empty()) {
        undoStack.push(text);
        text = redoStack.top();
        redoStack.pop();
    }
}

std::string TextEditor::getText() const {
    return text;
}

int main() {
    TextEditor editor;

    editor.insert("Hello", 0);
    editor.insert(", World!", 5);
    std::cout << editor.getText() << std::endl; // Should print: Hello, World!

    editor.erase(5, 8);
    std::cout << editor.getText() << std::endl; // Should print: Hello

    editor.undo();
    std::cout << editor.getText() << std::endl; // Should print: Hello, World!

    editor.redo();
    std::cout << editor.getText() << std::endl; // Should print: Hello

    return 0;
}