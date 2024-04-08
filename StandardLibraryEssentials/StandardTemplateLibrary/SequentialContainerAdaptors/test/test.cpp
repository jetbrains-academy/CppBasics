#include <gtest/gtest.h>
#include "../include/textEditor.h"

TEST(TextEditor, Insert) {
    TextEditor editor;

    editor.insert("Hello", 0);
    ASSERT_EQ(editor.getText(), "Hello");
}

TEST(TextEditor, Erase) {
    TextEditor editor;

    editor.insert("Hello, World!", 0);
    editor.erase(5, 8);

    ASSERT_EQ(editor.getText(), "Hello");
}

TEST(TextEditor, Undo) {
    TextEditor editor;

    editor.insert("Hello, World!", 0);
    editor.erase(5, 8);
    editor.undo();
    ASSERT_EQ(editor.getText(), "Hello, World!");
}

TEST(TextEditor, Redo) {
    TextEditor editor;

    editor.insert("Hello, World!", 0);
    editor.erase(5, 8);
    editor.undo();
    ASSERT_EQ(editor.getText(), "Hello, World!");

    editor.redo();
    ASSERT_EQ(editor.getText(), "Hello");
}

TEST(TextEditor, UndoAndRedoMultiple) {
    TextEditor editor;

    editor.insert("Hello, World!", 0);
    editor.erase(5, 8);
    editor.undo();
    editor.redo();
    editor.undo();
    editor.redo();
    editor.undo();
    ASSERT_EQ(editor.getText(), "Hello, World!");
}

TEST(TextEditor, UndoEmpty) {
    TextEditor editor;

    editor.undo();
    ASSERT_EQ(editor.getText(), "");
}

TEST(TextEditor, RedoEmpty) {
    TextEditor editor;

    editor.redo();
    ASSERT_EQ(editor.getText(), "");
}

TEST(TextEditor, BigText) {
    TextEditor editor;

    editor.insert("I am a big text", 0);
    editor.insert(" and I am getting bigger", 15);
    editor.insert(" and bigger...", 39);
    ASSERT_EQ(editor.getText(), "I am a big text and I am getting bigger and bigger...");
    editor.erase(52, 1);
    editor.erase(51, 1);
    editor.erase(50, 1);
    editor.undo();
    editor.redo();
    editor.undo();
    ASSERT_EQ(editor.getText(), "I am a big text and I am getting bigger and bigger.");
}