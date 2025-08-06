#include <gtest/gtest.h>
#include "../Date.h"

// Test semplici per la classe Date

// Test 1: Creare una data vuota
TEST(DateTest, CreaDataVuota)
{
    Date data;
    EXPECT_EQ(data.getDay(), 0);
    EXPECT_EQ(data.getMonth(), 0);
    EXPECT_EQ(data.getYear(), 0);
}

// Test 2: Creare una data con valori
TEST(DateTest, CreaDataConValori)
{
    Date data(15, 6, 2024);
    EXPECT_EQ(data.getDay(), 15);
    EXPECT_EQ(data.getMonth(), 6);
    EXPECT_EQ(data.getYear(), 2024);
}

// Test 3: Verificare se una data è valida
TEST(DateTest, DataValida)
{
    Date dataOk(15, 6, 2024);
    Date dataSbagliata(32, 13, 1999);

    EXPECT_TRUE(dataOk.isValid());
    EXPECT_FALSE(dataSbagliata.isValid());
}

// Test 4: Confrontare due date
TEST(DateTest, ConfrontaDate)
{
    Date data1(15, 6, 2024);
    Date data2(15, 6, 2024);
    Date data3(16, 6, 2024);

    EXPECT_TRUE(data1 == data2);
    EXPECT_FALSE(data1 == data3);
}

// Test 5: Convertire data in stringa
TEST(DateTest, DataInStringa)
{
    Date data(15, 6, 2024);
    string risultato = data.toString();

    EXPECT_FALSE(risultato.empty());
}

// Test 6: Cambiare i valori della data
TEST(DateTest, CambiaValori)
{
    Date data;

    data.setDay(10);
    data.setMonth(5);
    data.setYear(2023);

    EXPECT_EQ(data.getDay(), 10);
    EXPECT_EQ(data.getMonth(), 5);
    EXPECT_EQ(data.getYear(), 2023);
}
