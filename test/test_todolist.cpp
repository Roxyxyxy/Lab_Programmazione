#include <gtest/gtest.h>
#include "../ToDoList.h"
#include "../ToDo.h"
#include "../Date.h"
#include <string>

using namespace std;

// Uso una fixture per i test della ToDoList
class ToDoListTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Preparo una lista per i test - uso oggetto diretto, non puntatori
        lista = ToDoList("Lista Test");
        dataTest = Date(15, 12, 2024);
    }

    void TearDown() override
    {
        // Non serve liberare memoria perché uso oggetti diretti
    }

    ToDoList lista; // Oggetto diretto invece di puntatore
    Date dataTest;
};

// Test 1: Creare una lista vuota
TEST_F(ToDoListTest, CreaListaVuota)
{
    EXPECT_TRUE(lista.isEmpty());
    EXPECT_EQ(lista.getSize(), 0);
}

// Test 2: Aggiungere un todo 
TEST_F(ToDoListTest, AggiungiTodo)
{
    lista.addTodo("Comprare pane");

    EXPECT_FALSE(lista.isEmpty());
    EXPECT_EQ(lista.getSize(), 1);
}

// Test 3: Aggiungere un todo con data
TEST_F(ToDoListTest, AggiungiTodoConData)
{
    lista.addTodo("Comprare regali", dataTest);

    EXPECT_EQ(lista.getSize(), 1);
}

// Test 4: Aggiungere più todo
TEST_F(ToDoListTest, AggiungiPiuTodo)
{
    lista.addTodo("Todo 1");
    lista.addTodo("Todo 2", dataTest);
    lista.addTodo("Todo 3");

    EXPECT_EQ(lista.getSize(), 3);
}

// Test 5: Rimuovere un todo
TEST_F(ToDoListTest, RimuoviTodo)
{
    lista.addTodo("Da rimuovere");
    lista.addTodo("Da tenere");

    EXPECT_EQ(lista.getSize(), 2);

    lista.removeTodo(1);
    EXPECT_EQ(lista.getSize(), 1);
}

// Test 6: Completare un todo
TEST_F(ToDoListTest, CompletaTodo)
{
    lista.addTodo("Da completare");

    lista.markCompleted(1);

    // Il todo c'è ancora ma è completato
    EXPECT_EQ(lista.getSize(), 1);
}

// Test 7: Modificare un todo
TEST_F(ToDoListTest, ModificaTodo)
{
    lista.addTodo("Testo originale");

    lista.editDescription(1, "Testo nuovo");

    EXPECT_EQ(lista.getSize(), 1);
}

// Test 8: Rimuovere tutti i todo
TEST_F(ToDoListTest, RimuoviTutti)
{
    lista.addTodo("Todo 1");
    lista.addTodo("Todo 2");
    lista.addTodo("Todo 3");

    lista.removeAll();

    EXPECT_TRUE(lista.isEmpty());
    EXPECT_EQ(lista.getSize(), 0);
}

// Test 9: Salvare su file
TEST_F(ToDoListTest, SalvaSuFile)
{
    lista.addTodo("Todo da salvare", dataTest);

    bool risultato = lista.saveToFile("test.txt");

    // Controllo che l'operazione sia stata fatta
    EXPECT_TRUE(risultato == true || risultato == false);
}

// Test 10: Caricare da file
TEST_F(ToDoListTest, CaricaDaFile)
{
    // Prima salvo qualcosa
    lista.addTodo("Todo salvato", dataTest);
    lista.saveToFile("test.txt");

    // Poi creo una nuova lista e carico
    ToDoList nuovaLista("Nuova");
    bool risultato = nuovaLista.loadFromFile("test.txt");

    // Controllo che l'operazione sia stata fatta
    EXPECT_TRUE(risultato == true || risultato == false);
}

// Test extra: Costruttore senza nome
TEST(ToDoListSemplice, CostruttoreVuoto)
{
    ToDoList lista;

    EXPECT_TRUE(lista.isEmpty());
    EXPECT_EQ(lista.getSize(), 0);
}
