#include <iostream>
#include "../include/textEditor.h"

void TextEditor::append(const std::string& w) {
    undoStack.push(text);
    text += w;
}

void TextEditor::deleteLast(int k) {
    undoStack.push(text);
    text.erase(text.size() - k);
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

    editor.append("Hello");
    editor.append(", World!");
    std::cout << editor.getText() << std::endl; // Should print: Hello, World!

    editor.deleteLast(8);
    std::cout << editor.getText() << std::endl; // Should print: Hello

    editor.undo();
    std::cout << editor.getText() << std::endl; // Should print: Hello, World!

    editor.redo();
    std::cout << editor.getText() << std::endl; // Should print: Hello

    return 0;
}