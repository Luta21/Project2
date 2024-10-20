#include <iostream>
#include <cstring> // pentru strlen, strcpy_s
#include <string> // pentru std::string

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
class Student {
private:
    string nume;
    char* facultate;
    char serie;
    int grupa;
    int anStudiu;
    int nrNote;
    int* note;//vector alocat dinamic 
    char* sport;

public:
    int getAnStudiu() {
        return anStudiu;
    }

    void SetNrNote(int nr) {
        if (nrNote != 0)
            this->nrNote = nr;
    }

    int getNrNote()
    {
        return nrNote;
    }

    int getNote() {
        int n = nrNote;
        cout << "Nume---Facultate---Seria---An Studiu---";
        for (int i = 1; i <= n; i++) {
            cout << "Nota" << i << "---";

        }
        cout << endl << "                                          " << note[0];
        for (int i = 1; i < n; i++) {
            cout << "      " << note[i];
        }
        cout << endl;
        return nrNote;
    }


    void SetAnStudiu(int anStud) {
        if (anStud >= 1 && anStud <= 3)
            this->anStudiu = anStud;
        else
            cout << "EROARE";
    }

    void SetNote(int nrNote) {

        if (this->note != nullptr)
        {
            delete[] this->note;
            this->nrNote = nrNote;
        }
        this->note = new int[this->nrNote];
        cout << "Introduceti cele " << nrNote << " elemente";
        for (int i = 0; i < this->nrNote; i++)
            cin >> this->note[i];
    }

    void setSport(const char* sportNou)
    {
        if (sport != nullptr) {
            delete[] sport;
            sport = nullptr;
        }
            sport = new char[strlen(sportNou) + 1];
            strcpy_s(sport, strlen(sportNou) + 1, sportNou);
  
    }

    const char* getSport() {
        return sport;
    }



    void setFacultate(const char* facultateNoua)
    {
        if (strlen(facultateNoua) >= 3)
        {
            if (facultate != nullptr)
            {
                delete[] facultate;
                facultate = nullptr;
            }
            facultate = new char[strlen(facultateNoua) + 1];
            strcpy_s(facultate, strlen(facultateNoua) + 1, facultateNoua);
        }
    }

    const char* getFacultate() {
        return facultate != nullptr ? facultate : "";
    }

    //Constructor
    Student(string nume, const char* facultate, char serie, int anStudiu, int nrNote, int* note, const char* sport) {
        this->nume = nume;
        this->serie = serie;
        this->grupa = 0;  // nu ai inițializat în mod explicit în codul original
        this->anStudiu = anStudiu;

        if (facultate != nullptr) {
            this->facultate = new char[strlen(facultate) + 1];
            strcpy_s(this->facultate, strlen(facultate) + 1, facultate);
        }
        else {
            this->facultate = nullptr;
        }

        if (sport != nullptr) {
            this->sport = new char[strlen(sport) + 1];
            strcpy_s(this->sport, strlen(sport) + 1, sport);
        }
        else {
            this->sport = nullptr;
        }
        
        if (note != nullptr && nrNote > 0) {
            
            this->nrNote = nrNote;
            this->note = new int[this->nrNote];
            for (int i = 0; i < this->nrNote; i++)
                this->note[i] = note[i];

        }
        else
            this->note = nullptr;
    }

    void numar_note_per_elev(int) {

    }

    //Destructor pentru eliberarea memoriei
    ~Student() {
        if (facultate != nullptr) {
            delete[] facultate;
        }
        if (note != nullptr) {
            delete[] note;
        }
    }
};


int main() {
    int note[] = { 0,0,0,0 };
    Student studenti[5] = {
    Student("Denis", "CSIE", 'F', 2, 3, note,"A"),
    Student("Denis", "CSIE", 'F', 2, 5, note,"A"),
    Student("Denis", "CSIE", 'F', 2, 4, note,"A"),
    Student("Denis", "CSIE", 'F', 2, 4, note,"A"),
    Student("Denis", "CSIE", 'F', 2, 4, note,"A")
    };

    for (int i = 0; i <5; i++) {
        //Definim numarul de note si care sunt acestea pentru fiecare student in parte
        int nrNote = 0;
        cout << "Dati numarul de note pentru studentul " << i+1 << endl;
        cin >> nrNote;
        studenti[i].SetNrNote(nrNote);
        studenti[i].SetNote(studenti[i].getNrNote());
        studenti[i].getNote();

        //Creem o matrice bidimensionala in care coloanele reprezinta id-ul sportului (1.fotbal, 2.basket,3.fitness), iar coloanele reprezinta
        //numarul de locuri totale si numarul de locuri ocupate, iar o functie va informa administratorul daca studentul nu mai are loc la o anumita disciplina
        //si ii va recomanda altele unde mai sunt locuri disponobile

        int** sporturi = new int* [3];
        for (int i = 0; i < 3; i++)
            sporturi[i] = new int[3];

        for (int i = 0; i < 3; i++)
        {
            sporturi[0][i] = i + 1;
        }

        for (int i = 0; i < 3; i++) {
            int nr_total = 0;
            int nr_ocupat = 0;
            cout << "selectati numarul de locuri totale disponibile pentru disciplina " << i+1 << endl;
            cin >> nr_total;

            cout << "selectati numarul de locuri ocupate disponibile pentru disciplina " << i + 1 << endl;
            cin >> nr_ocupat;
                      
                sporturi[1][i]= nr_total;
                sporturi[2][i] = nr_ocupat;

        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                cout << sporturi[i][j]<<"  ";
            }
            cout << endl;
        }

        //eliberam meemoria alocata vectorului 
        for (int i = 0; i < 3; i++)
            delete[] sporturi[i];
        delete[] sporturi;


        //Seletam un sport pentru fiecare dintre studenti 
        studenti[i].setSport("Fotbal");
       cout<<"Sportul pentru studentul "<<i<<" este: "<< studenti[i].getSport() << endl;
        
        //alegem cate un sport pentru fiecare student in functie de locurile disponibile 



    }
   // cout << "An studiu: " << s1.getAnStudiu() << endl;
  //  cout << "Facultate: " << s1.getFacultate() << endl;


   // s1.setFacultate("Fabiz");
   // cout << "Facultate dupa schimbare: " << s1.getFacultate() << endl;

    return 0;
}
