#include <gtest/gtest.h>
#include "../ToDoList.h"
#include "../ToDo.h"
#include "../Date.h"
#include <string>
#include <fstream>

using namespace std;

// Fixture class per i test di ToDoList
class ToDoListTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Setup eseguito prima di ogni test
        todoList = new ToDoList("Test List");
        testDate = Date(15, 12, 2024);
    }

    void TearDown() override
    {
        // Cleanup eseguito dopo ogni test
        delete todoList;
        // Rimuovi file di test se esistono
        remove("test_save.txt");
    }

    ToDoList *todoList;
    Date testDate;
};

// Test del costruttore e stato iniziale
TEST_F(ToDoListTest, ConstructorAndInitialState)
{
    EXPECT_TRUE(todoList->isEmpty());
    EXPECT_EQ(todoList->getSize(), 0);
}

// Test aggiunta di todo senza data
TEST_F(ToDoListTest, AddTodoWithoutDate)
{
    todoList->addTodo("Primo task");

    EXPECT_FALSE(todoList->isEmpty());
    EXPECT_EQ(todoList->getSize(), 1);
}

// Test aggiunta di todo con data
TEST_F(ToDoListTest, AddTodoWithDate)
{
    todoList->addTodo("Task con scadenza", testDate);

    EXPECT_FALSE(todoList->isEmpty());
    EXPECT_EQ(todoList->getSize(), 1);
}

// Test aggiunta multipla di todo
TEST_F(ToDoListTest, AddMultipleTodos)
{
    todoList->addTodo("Task 1");
    todoList->addTodo("Task 2", testDate);
    todoList->addTodo("Task 3");

    EXPECT_EQ(todoList->getSize(), 3);
    EXPECT_FALSE(todoList->isEmpty());
}

// Test rimozione di todo con indice valido
TEST_F(ToDoListTest, RemoveTodoValidIndex)
{
    todoList->addTodo("Task da rimuovere");
    todoList->addTodo("Task da mantenere");

    EXPECT_EQ(todoList->getSize(), 2);

    // Redirect cout per catturare l'output
    testing::internal::CaptureStdout();
    todoList->removeTodo(1);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(todoList->getSize(), 1);
    EXPECT_TRUE(output.find("Todo rimosso con successo!") != string::npos);
}

// Test rimozione di todo con indice non valido
TEST_F(ToDoListTest, RemoveTodoInvalidIndex)
{
    todoList->addTodo("Unico task");

    // Redirect cout per catturare l'output
    testing::internal::CaptureStdout();
    todoList->removeTodo(5); // Indice non valido
    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(todoList->getSize(), 1); // Dimensione invariata
    EXPECT_TRUE(output.find("Indice non valido!") != string::npos);
}

// Test rimozione di tutti i todo
TEST_F(ToDoListTest, RemoveAllTodos)
{
    todoList->addTodo("Task 1");
    todoList->addTodo("Task 2");
    todoList->addTodo("Task 3");

    EXPECT_EQ(todoList->getSize(), 3);

    testing::internal::CaptureStdout();
    todoList->removeAll();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(todoList->isEmpty());
    EXPECT_EQ(todoList->getSize(), 0);
    EXPECT_TRUE(output.find("Tutti i todos sono stati rimossi!") != string::npos);
}

// Test marcatura come completato
TEST_F(ToDoListTest, MarkTodoCompleted)
{
    todoList->addTodo("Task da completare");

    testing::internal::CaptureStdout();
    todoList->markCompleted(1);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Todo completato!") != string::npos);
}

// Test marcatura come completato con indice non valido
TEST_F(ToDoListTest, MarkCompletedInvalidIndex)
{
    todoList->addTodo("Task");

    testing::internal::CaptureStdout();
    todoList->markCompleted(10); // Indice non valido
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Indice non valido!") != string::npos);
}

// Test modifica descrizione
TEST_F(ToDoListTest, EditDescription)
{
    todoList->addTodo("Descrizione originale");

    testing::internal::CaptureStdout();
    todoList->editDescription(1, "Nuova descrizione");
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Descrizione modificata!") != string::npos);
}

// Test modifica descrizione con indice non valido
TEST_F(ToDoListTest, EditDescriptionInvalidIndex)
{
    todoList->addTodo("Task");

    testing::internal::CaptureStdout();
    todoList->editDescription(99, "Nuova descrizione");
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Indice non valido!") != string::npos);
}

// Test visualizzazione lista vuota
TEST_F(ToDoListTest, DisplayEmptyList)
{
    testing::internal::CaptureStdout();
    todoList->displayAll();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Nessun todo presente!") != string::npos);
    EXPECT_TRUE(output.find("Test List") != string::npos);
}

// Test visualizzazione pending su lista vuota
TEST_F(ToDoListTest, DisplayPendingEmptyList)
{
    testing::internal::CaptureStdout();
    todoList->displayPending();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Nessun todo presente!") != string::npos);
}

// Test statistiche lista vuota
TEST_F(ToDoListTest, ShowStatsEmptyList)
{
    testing::internal::CaptureStdout();
    todoList->showStats();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Todos totali: 0") != string::npos);
    EXPECT_TRUE(output.find("Todos completati: 0") != string::npos);
    EXPECT_TRUE(output.find("Test List") != string::npos);
}

// Test statistiche con todo completati e non
TEST_F(ToDoListTest, ShowStatsWithMixedTodos)
{
    todoList->addTodo("Task 1");
    todoList->addTodo("Task 2");
    todoList->addTodo("Task 3");

    // Completa un task
    todoList->markCompleted(2);

    testing::internal::CaptureStdout();
    todoList->showStats();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Todos totali: 3") != string::npos);
    EXPECT_TRUE(output.find("Todos completati: 1") != string::npos);
    EXPECT_TRUE(output.find("Todos da completare: 2") != string::npos);
    EXPECT_TRUE(output.find("Percentuale completamento: 33.3333%") != string::npos);
}

// Test salvataggio su file
TEST_F(ToDoListTest, SaveToFile)
{
    todoList->addTodo("Task per salvataggio", testDate);
    todoList->markCompleted(1);

    testing::internal::CaptureStdout();
    bool result = todoList->saveToFile("test_save.txt");
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(result);
    EXPECT_TRUE(output.find("Lista salvata nel file test_save.txt") != string::npos);

    // Verifica che il file esista
    ifstream file("test_save.txt");
    EXPECT_TRUE(file.good());
    file.close();
}

// Test caricamento da file
TEST_F(ToDoListTest, LoadFromFile)
{
    // Prima salva alcuni dati
    todoList->addTodo("Task da caricare", testDate);
    todoList->markCompleted(1);
    todoList->saveToFile("test_save.txt");

    // Crea una nuova lista e carica
    ToDoList newList("Nuova Lista");

    testing::internal::CaptureStdout();
    bool result = newList.loadFromFile("test_save.txt");
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(result);
    EXPECT_TRUE(output.find("Lista caricata dal file test_save.txt") != string::npos);
    EXPECT_EQ(newList.getSize(), 1);
}

// Test caricamento da file inesistente
TEST_F(ToDoListTest, LoadFromNonExistentFile)
{
    testing::internal::CaptureStdout();
    bool result = todoList->loadFromFile("file_inesistente.txt");
    string output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(result);
    EXPECT_TRUE(output.find("Errore: impossibile aprire il file") != string::npos);
}

// Test costruttore default
TEST(ToDoListBasicTest, DefaultConstructor)
{
    ToDoList defaultList;
    EXPECT_TRUE(defaultList.isEmpty());
    EXPECT_EQ(defaultList.getSize(), 0);
}
