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
        // Preparo una lista per i test
        lista = ToDoList("Lista Test");
        dataTest = Date(15, 12, 2024);
    }

    ToDoList lista;
    Date dataTest;
};

// Test 1: Verifica lista completamente vuota
TEST_F(ToDoListTest, CreaListaVuota)
{
    // Creo una nuova lista vuota (non uso quella del SetUp che ha già un titolo)
    ToDoList listaVuota;

    EXPECT_TRUE(listaVuota.isEmpty());
    EXPECT_EQ(listaVuota.getSize(), 0);
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
    // Verifico che parta vuota
    EXPECT_EQ(lista.getSize(), 0);

    lista.addTodo("Comprare regali", dataTest);

    EXPECT_EQ(lista.getSize(), 1);
    EXPECT_FALSE(lista.isEmpty());
}

// Test 4: Aggiungere più todo
TEST_F(ToDoListTest, AggiungiPiuTodo)
{
    // Verifico che parta vuota
    EXPECT_EQ(lista.getSize(), 0);

    lista.addTodo("Todo 1");
    lista.addTodo("Todo 2", dataTest);
    lista.addTodo("Todo 3");

    EXPECT_EQ(lista.getSize(), 3);
    EXPECT_FALSE(lista.isEmpty());
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

    // Prima del completamento
    EXPECT_EQ(lista.getSize(), 1);

    lista.markCompleted(1);

    // Dopo il completamento: il todo c'è ancora ma è completato
    EXPECT_EQ(lista.getSize(), 1);
}

// Test 7: Modificare un todo
TEST_F(ToDoListTest, ModificaTodo)
{
    lista.addTodo("Testo originale");

    // Verifico che sia stato aggiunto
    EXPECT_EQ(lista.getSize(), 1);

    lista.editDescription(1, "Testo nuovo");

    // Verifico che sia ancora presente (non rimosso)
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

    // Verifico che il salvataggio sia andato a buon fine
    EXPECT_TRUE(risultato);
}

// Test 10: Caricare da file
TEST_F(ToDoListTest, CaricaDaFile)
{
    // Prima salvo qualcosa
    lista.addTodo("Todo salvato", dataTest);
    lista.saveToFile("test.txt");

    // Creo una nuova lista vuota e carico
    ToDoList nuovaLista("Nuova");
    bool risultato = nuovaLista.loadFromFile("test.txt");

    // Verifico che il caricamento sia andato a buon fine
    EXPECT_TRUE(risultato);
    EXPECT_EQ(nuovaLista.getSize(), 1);
}

// Test extra: Costruttore senza nome
TEST(ToDoListBasico, CostruttoreVuoto)
{
    ToDoList lista;

    EXPECT_TRUE(lista.isEmpty());
    EXPECT_EQ(lista.getSize(), 0);
}

// Test extra: Gestione indici non validi
TEST(ToDoListBasico, IndiciNonValidi)
{
    ToDoList lista("Test");

    // Aggiungo un todo
    lista.addTodo("Test");
    EXPECT_EQ(lista.getSize(), 1);

    // Provo a rimuovere con indice non valido (dovrebbe non fare nulla)
    lista.removeTodo(0); // Indice troppo basso
    EXPECT_EQ(lista.getSize(), 1);

    lista.removeTodo(5); // Indice troppo alto
    EXPECT_EQ(lista.getSize(), 1);
}
