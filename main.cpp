#include <iostream>
#include <fstream>
#include "vector"


using namespace std;


string csvPath;
vector<vector<string>> dataVector;


int mainMenu() {
    string choice;
    int ret = 0;
    cout << "Choisissez ce que vous voulez faire :" << endl;
    cout << "\t1. Lire un fichier CSV." << endl;
    cout << "\t2. Afficher le fichier CSV." << endl;
    cout << "\t3. Selectionner une periode d'extraction" << endl;
    cout << "\t4. Supprimer des informations d'un fichier importe." << endl;
    cout << "\t5. Exporter en CSV." << endl;
    cout << "Votre choix : ";
    try {
        cin >> choice;
        ret = stoi(choice);
        if (ret < 1 or ret > 5) {
            throw invalid_argument("");
        }
    } catch (...) {
        cout << "Impossible de prendre votre choix en compte, veuillez recommencer." << endl << endl;
        mainMenu();
    }
    return ret;
}


//D:\C++\csv_meteo\temperature-quotidienne-regionale.csv
int menuRead() {
    cout << "Entrez le chemin absolu de votre fichier CSV : ";
    cin >> csvPath;
    try {
        ifstream file(csvPath);
        int count = 0;
        string stream, line;
        while (getline (file, line)) {
            vector<string> tmpVector;
            for (int i = 0; i <= line.size(); i++) {
                if (line[i] != ',' and line[i] != ';' and line[i] != '\r') {
                    stream += line[i];
                } else {
                    tmpVector.insert(tmpVector.end(), stream);
                    stream = "";
                }
            }
            tmpVector.insert(tmpVector.end(), stream);
            stream = "";
            count++;
            dataVector.insert(dataVector.end(), tmpVector);
        }
    } catch (...) {
        cout << "Fichier invalide" << endl;
        return -1;
    }
    cout << "Votre fichier a bien ete charge" << endl;
    return 0;
}


int menuPrint() {
    for (int i = 0; i < dataVector.size(); i++) {
        for (int j = 0; j < dataVector[i].size(); j++) {
            cout << dataVector[i][j] << "\t\t";
        }
        cout << endl;
    }
    return 0;
}


int menuSelect() {
    cout << "menuSelect" << endl;
    return 0;
}


int menuDelete() {
    cout << "menuDelete" << endl;
    return 0;
}


int menuExport() {
    cout << "menuExport" << endl;
    return 0;
}


int main() {
    while (1) {
        int choice = mainMenu();
        switch (choice) {
            case 1:
                menuRead();
                break;
            case 2:
                menuPrint();
                break;
            case 3:
                menuSelect();
                break;
            case 4:
                menuDelete();
                break;
            case 5:
                menuExport();
                break;
            default:
                mainMenu();
        }
    }
    return 0;
}
