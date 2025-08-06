#include <gtest/gtest.h>
#include "../ToDo.h"
#include "../Date.h"

// Test semplici per la classe ToDo

// Test 1: Creare un todo vuoto
TEST(ToDoTest, CreaTodoVuoto)
{
    ToDo todo;

    EXPECT_TRUE(todo.getDescription().empty());
    EXPECT_FALSE(todo.isCompleted());
}

// Test 2: Creare un todo con testo e data
TEST(ToDoTest, CreaTodoCompleto)
{
    Date data(25, 12, 2024);
    ToDo todo("Comprare regali", data);

    EXPECT_EQ(todo.getDescription(), "Comprare regali");
    EXPECT_FALSE(todo.isCompleted());
    EXPECT_TRUE(todo.getDate() == data);
}

// Test 3: Cambiare la descrizione
TEST(ToDoTest, CambiaDescrizione)
{
    ToDo todo;
    todo.setDescription("Nuovo compito");

    EXPECT_EQ(todo.getDescription(), "Nuovo compito");
}

// Test 4: Completare un todo
TEST(ToDoTest, CompletaTodo)
{
    ToDo todo("Test task");

    EXPECT_FALSE(todo.isCompleted());

    todo.markCompleted();
    EXPECT_TRUE(todo.isCompleted());
}

// Test 5: Cambiare lo stato di completamento
TEST(ToDoTest, CambiaStato)
{
    ToDo todo("Test");

    todo.setCompleted(true);
    EXPECT_TRUE(todo.isCompleted());

    todo.setCompleted(false);
    EXPECT_FALSE(todo.isCompleted());
}

// Test 6: Cambiare la data
TEST(ToDoTest, CambiaData)
{
    ToDo todo;
    Date nuovaData(1, 1, 2025);

    todo.setDate(nuovaData);

    EXPECT_TRUE(todo.getDate() == nuovaData);
}

// Test 7: Ottenere le informazioni del todo
TEST(ToDoTest, OttieniInfo)
{
    Date data(25, 12, 2024);
    ToDo todo("Comprare regali", data);

    string info = todo.getInfo();

    EXPECT_FALSE(info.empty());
}
