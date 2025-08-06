#include <gtest/gtest.h>
#include "../ToDoList.h"
#include "../ToDo.h"
#include "../Date.h"
#include <string>

using namespace std;

// Test 1: Creare una lista vuota
TEST(ToDoListTest, CreaListaVuota)
{
    ToDoList lista("Mia Lista");

    EXPECT_TRUE(lista.isEmpty());
    EXPECT_EQ(lista.getSize(), 0);
}

// Test 2: Aggiungere un todo semplice
TEST(ToDoListTest, AggiungiUnTodo)
{
    ToDoList lista("Mia Lista");

    lista.addTodo("Comprare il pane");

    EXPECT_FALSE(lista.isEmpty());
    EXPECT_EQ(lista.getSize(), 1);
}

// Test 3: Aggiungere più todo
TEST(ToDoListTest, AggiungiPiuTodo)
{
    ToDoList lista("Mia Lista");

    lista.addTodo("Task 1");
    lista.addTodo("Task 2");
    lista.addTodo("Task 3");

    EXPECT_EQ(lista.getSize(), 3);
}

// Test 4: Aggiungere todo con data
TEST(ToDoListTest, AggiungiTodoConData)
{
    ToDoList lista("Mia Lista");
    Date scadenza(25, 12, 2024);

    lista.addTodo("Comprare regali", scadenza);

    EXPECT_EQ(lista.getSize(), 1);
}

// Test 5: Rimuovere un todo
TEST(ToDoListTest, RimuoviTodo)
{
    ToDoList lista("Mia Lista");

    lista.addTodo("Task da rimuovere");
    lista.addTodo("Task da tenere");
    EXPECT_EQ(lista.getSize(), 2);

    lista.removeTodo(1); // Rimuovi il primo
    EXPECT_EQ(lista.getSize(), 1);
}

// Test 6: Completare un todo
TEST(ToDoListTest, CompletaTodo)
{
    ToDoList lista("Mia Lista");

    lista.addTodo("Task da completare");

    // Non possiamo facilmente testare se è completato senza getter,
    // ma possiamo testare che l'operazione non crashi
    lista.markCompleted(1);

    EXPECT_EQ(lista.getSize(), 1); // Il task c'è ancora
}

// Test 7: Costruttore di default
TEST(ToDoListTest, CostruttoreDefault)
{
    ToDoList lista;

    EXPECT_TRUE(lista.isEmpty());
    EXPECT_EQ(lista.getSize(), 0);
}
