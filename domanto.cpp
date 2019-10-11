#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <chrono>
//#include <unistd.h> // <- for linux usleep(100000)
#include <windows.h> // <- for windows Sleep(100)
#include <csignal>
using namespace std;
const int TapeLength100 = 100;
int stop = 0;


int Pabaiga() {
  return 0;
}


void sign(int q)
{
  stop = 1;
}


void TapeView(char tape[], int pos, int tapelength) {
  int ms = 1;

  for (int i = 0; i < tapelength; i++) {
  cout << tape[i];
  }
  cout << endl;
  for (int i = 1; i < pos; i++) {
    cout << " ";
  }
  cout << "^\n";
  Sleep(100);
}




int main()
{
  ////////////////////// MENU
  string choice;
Pradzia: // Gryzti i MENU pradzia.
  cout << "TURING ++||| MENU |||++" << endl;
  cout << endl;
cout << "(1,2,3,4) Pasirinkite kuri is siu failu norite atidaryti. " << endl;
  cout << "(CTRL+C) Jei norite nutraukti turingo masinos darba." << endl;
  cout << " (Q) Jei norite iseiti is programos. " << endl;
  cin >> choice;


  ////////////////////// Ivedimas ir Juostos su Juostos Pradine Pozicija nuskaitymas.
  if (choice == "Q") { // Jei spaudzia Q - jumpina i Pabaiga funkcija, kur uzbaigia darba.
  Pabaiga();
  } else // ELSE - vykdo visa programa.
  {
  ifstream fd(choice + ".txt");




  int HeadPos;
  string Tape;
  fd >> HeadPos;
  fd >> Tape;
  cout << Tape << endl;
  int TapeLength = Tape.length();
  char tape[TapeLength100];
  for (int i = 0; i < Tape.length(); i++) {
  tape[i] = Tape[i];
  // cout << tape[i] << " "; // Atspausdina visa juosta
  }
  // cout << endl; // JUST FOR ENTER
  /////////////// Isidedu visas instrukcijas i abcde, del memory - reikes veliau sugalvot.
  int memory = 0;
  string a[100];
  string e[100];
  char b[100], c[100], d[100];
  while (!fd.eof()) {
  fd >> a[memory] >> b[memory] >> c[memory] >> d[memory] >> e[memory];
  memory++;
  }
  for (int j = 0; j < memory - 1; j++) {
  // cout << a[j] << " " << b[j] << " " << c[j] << " " << d[j] << " " << e[j] << endl; // Atspausdina visas taisykles.
    }
  //cout << endl; // JUST FOR ENTER


  /////////////////////// Programos pradzia
  string terminationString = "0";
  string newstate = e[0];
  int END = 0;
  start:
  // cout << e[0] << " e" << endl;
  for (int i = 0; i < memory - 1; i++) {
  stop = 0;
    signal(SIGINT, sign);
  if (newstate == a[i]) { // jei Q5 atitinka Q1 = tesiame zingsnius toliau.
  // cout << newstate << " <-newstate currentStateIfRead-> " << a[i] << endl;
  if (tape[HeadPos - 1] == b[i]) { // Jei galvutes pozicijoje tinkamas skaiciui norint testi - einama toliau.


          newstate = e[i]; //NEW STATE automatiskai taps einamo -i- Q5.
          tape[HeadPos - 1] = c[i]; // Pakeiciu is kazko i 0 arba 1; Q3
                      system("CLS");
          //printf("\033[H\033[J");
          TapeView(tape, HeadPos, TapeLength); // Juostos ir galvutes spausdinimas.
          if (d[i] == 'L') HeadPos--; //Galvutes pozcija -1 Q4
          if (d[i] == 'R') HeadPos++; // arba +1 priklausomai nuo L or R. Q4


            if (HeadPos<1 || HeadPos>Tape.length()) {
            terminationString = "ERROR: galvute isejo uz juostos ribu"; // Jei klaida, GOTO termination.
            goto termination;
        }

        }
      }


      if (i == memory - 2) i = -1; // Kai i==5, vel i paverciu 0, kad ciklas suktusi.
      if (stop == 1) {
        char ate;
          cout << endl;
          cout << "(Y)-Grizti i menu | (N) - Iseiti is programos" << endl;
          cin >> ate;
          if (ate=='Y') {
            //printf("\033[H\033[J");
            system("CLS");
          goto Pradzia; // CTRl + C sustojimo mechanizmas.
          } else goto Pabaiga;
      }
      if (newstate == "X") {
        char ate;
        cout << "(Y)-Grizti i menu |  - Iseiti is programos" << endl;
          cin >> ate;
          if (ate=='Y') {
            printf("\033[H\033[J");
          goto Pradzia; // CTRl + C sustojimo mechanizmas.
          } else goto Pabaiga;
      }
    } // PROGRAMOS CIKLO PABAIGA.
    termination:
      cout << terminationString << endl;
  Pabaiga:
    return 0;
  } // ELSE pabaiga
}
