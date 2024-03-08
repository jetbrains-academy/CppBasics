#include <gtest/gtest.h>
#include "../include/textEditor.h"

TEST(TextEditor, AppendAndDelete) {
    TextEditor editor;

    editor.append("Hello, World!");
    ASSERT_EQ(editor.getText(), "Hello, World!");

    editor.deleteLast(7);
    ASSERT_EQ(editor.getText(), "Hello,");
}

TEST(TextEditor, UndoAndRedo) {
    TextEditor editor;

    editor.append("Hello, World!");
    editor.deleteLast(7);
    editor.undo();
    ASSERT_EQ(editor.getText(), "Hello, World!");

    editor.redo();
    ASSERT_EQ(editor.getText(), "Hello,");
}

TEST(TextEditor, UndoAndRedoMultiple) {
    TextEditor editor;

    editor.append("Hello, World!");
    editor.deleteLast(7);
    editor.undo();
    editor.redo();
    editor.undo();
    editor.redo();
    editor.undo();
    ASSERT_EQ(editor.getText(), "Hello, World!");
}

TEST(TextEditor, UndoAndRedoEmpty) {
    TextEditor editor;

    editor.undo();
    ASSERT_EQ(editor.getText(), "");

    editor.redo();
    ASSERT_EQ(editor.getText(), "");
}

TEST(TextEditor, BigText) {
    TextEditor editor;

    editor.append("I am a big text");
    editor.append(" and I am getting bigger");
    editor.append(" and bigger...");
    ASSERT_EQ(editor.getText(), "I am a big text and I am getting bigger and bigger...");
    editor.deleteLast(1);
    editor.deleteLast(1);
    editor.deleteLast(1);
    editor.undo();
    editor.redo();
    editor.undo();
    ASSERT_EQ(editor.getText(), "I am a big text and I am getting bigger and bigger.");
}