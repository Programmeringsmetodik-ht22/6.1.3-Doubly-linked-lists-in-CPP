/*******************************************************************************
* main.cpp: Implementering av länkade listor av olika datatyper via klassen
*           std::list från C++-standardbibliotek, som möjliggör lagring av
*           olika datatyper via så kallade templates. Templates saknas i C,
*           men liknande funktionalitet kan realiseras via användning av unioner.
*
*           Kompilera programmet via GCC-kompilatorn och skapa en körbar fil
*           döpt main.exe med följande kommando:
*           $ g++ main.cpp main.exe -o Wall
*
*           För att köra programmet med liststorlekar x, y, och z, mata in
*           följande kommando (ersätt x, y och z med önskade storlekar).
*           $ main.exe x y z
*
*           Som exempel, för att lagra 10 signerade heltal, 4 flyttal samt
*           6 osignerade heltal via var sin lista skrivs följande kommando:
*           $ main.exe 10 4 6
*******************************************************************************/
#include <iostream>
#include <list>

/*******************************************************************************
* list_print: Skriver ut innehållet lagrat i en länkad lista av valfri datatyp
*             via angiven utström, där standardutenheten std::cout används som
*             default för utskrift i terminalen.
*             - self: Referens till den länkade listan.
*             - ostream: Referens till angiven utström.
*******************************************************************************/
template<class T>
static void list_print(const std::list<T>& self, 
                       std::ostream& ostream = std::cout)
{
   if (!self.size()) return;
   ostream << "--------------------------------------------------------------------------------\n";
   for (auto& i : self)
   {
      ostream << i << "\n";
   }
   ostream << "--------------------------------------------------------------------------------\n\n";
   return;
}

/*******************************************************************************
* main: Initierar tre dubbellänkade listor av datatyper int, double samt size_t. 
*       Storleken för respektive lista läses in från terminalen via parametrar 
*       passerade vid programkörning. Listorna fylls till bredden med tal av
*       den datatyp de tillhör, följt av att deras respektive innehåll skrivs 
*       ut i terminalen.
*       - argc: Antalet argument inlästa från terminalen vid start.
*       - argv: Array innehållande argument inlästa från terminalen.
*******************************************************************************/
int main(const int argc,
         const char** argv)
{
   if (argc != 4)
   {
      std::cerr << "Error! Too few command line arguments were entered!\n";
      return 1;
   }

   std::list<int> l1(static_cast<std::size_t>(std::atoi(argv[1])));
   std::list<double> l2(static_cast<std::size_t>(std::atoi(argv[2])));
   std::list<std::size_t> l3(static_cast<std::size_t>(std::atoi(argv[3])));
   
   int integer = 0;
   double decimal = -100.0;
   std::size_t natural = 50;

   for (auto& i : l1)
   {
      i = integer += 2;
   }
   for (auto& i : l2)
   {
      i = decimal /= 2.0;
   }
   for (auto& i : l3)
   {
      i = natural--;
   }

   list_print(l1);
   list_print(l2);
   list_print(l3);
   return 0;
}

