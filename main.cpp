#include <iostream>
#include <string>
#include "ToDoList.h"
#include "ToDo.h"
#include "Date.h"
using namespace std;

void showMenu()
{
    cout << "\n========== MENU PRINCIPALE ==========" << endl;
    cout << "1. Aggiungi un nuovo todo" << endl;
    cout << "2. Visualizza tutti i todos" << endl;
    cout << "3. Visualizza todos da completare" << endl;
    cout << "4. Completa un todo" << endl;
    cout << "5. Rimuovi un todo" << endl;
    cout << "6. Mostra statistiche" << endl;
    cout << "7. Modifica descrizione di un todo" << endl;
    cout << "0. Esci" << endl;
    cout << "=====================================" << endl;
    cout << "Scegli un'opzione: ";
}

int main()
{
    cout << "********** Benvenuto nella mia ToDo List! **********" << endl;
    cout << "\nQuesto è un semplice programma per gestire i tuoi task." << endl;

    // Creiamo una lista todo
    ToDoList myList("La mia lista personale");

    // Aggiungiamo alcuni todos di esempio per iniziare
    cout << "\nAggiungo alcuni task di esempio..." << endl;
    myList.addTodo("Studiare programmazione C++");
    myList.addTodo("Fare la spesa");
    myList.addTodo("Chiamare il dottore");

    int choice;
    bool running = true;

    while (running)
    {
        showMenu();
        cin >> choice;
        cin.ignore(); // Per pulire il buffer di input

        switch (choice)
        {
        case 1:
        {
            string description;
            cout << "Inserisci la descrizione del todo: ";
            getline(cin, description);
            myList.addTodo(description);
            break;
        }
        case 2:
            myList.displayAll();
            break;
        case 3:
            myList.displayPending();
            break;
        case 4:
        {
            if (myList.isEmpty())
            {
                cout << "Non ci sono todos da completare!" << endl;
                break;
            }
            myList.displayAll();
            int todoNum;
            cout << "Quale todo vuoi completare? (numero): ";
            cin >> todoNum;
            myList.markCompleted(todoNum);
            break;
        }
        case 5:
        {
            if (myList.isEmpty())
            {
                cout << "Non ci sono todos da rimuovere!" << endl;
                break;
            }
            myList.displayAll();
            int todoNum;
            cout << "Quale todo vuoi rimuovere? (numero): ";
            cin >> todoNum;
            myList.removeTodo(todoNum);
            break;
        }
        case 6:
            myList.showStats();
            break;
        case 7:
        {
            if (myList.isEmpty())
            {
                cout << "Non ci sono todos da modificare!" << endl;
                break;
            }
            myList.displayAll();
            int todoNum;
            cout << "Quale todo vuoi modificare? (numero): ";
            cin >> todoNum;
            cin.ignore();
            string nuovaDescrizione;
            cout << "Inserisci la nuova descrizione: ";
            getline(cin, nuovaDescrizione);
            myList.editDescription(todoNum, nuovaDescrizione);
            break;
        }
        case 0:
            cout << "\nGrazie per aver usato la ToDo List!" << endl;
            cout << "Arrivederci!" << endl;
            running = false;
            break;
        default:
            cout << "Opzione non valida! Riprova." << endl;
            break;
        }
    }

    return 0;
}
