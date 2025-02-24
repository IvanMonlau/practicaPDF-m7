#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "pdf.h"
#include "metrics.h"

using namespace std;

struct Producto {
    string nom;
    string categoria;
    double preu;
};

vector<Producto> llistaProductes = {
    {"Llibre A", "Educació", 12.5},
    {"Llibre B", "Literatura", 9.0},
    {"Llibre C", "Educació", 15.0},
    {"Llibre D", "Ficció", 8.5}
};

int main() {
    PDF pdf(612, 792); // A4 size

    stringstream content;

    pdf.setFillColor(0, 0, 0); // Set fill color to black
    pdf.setFont(PDF::HELVETICA_BOLD, 16);
    pdf.showTextXY("Llista de Productes", 50, 750);

    pdf.setFont(PDF::HELVETICA, 12);

    int y = 700;
    for (const auto& producto : llistaProductes) {
        pdf.showTextXY("Nom: " + producto.nom, 50, y);
        pdf.showTextXY("Categoria: " + producto.categoria, 200, y);
        pdf.showTextXY("Preu: " + to_string(producto.preu), 400, y);
        y -= 20;
    }

    ofstream pdfFile("productes.pdf", ios::binary);
    if (pdfFile.is_open()) {
        pdfFile << pdf.toString();
        pdfFile.close();
        cout << "Informe PDF generat correctament: productes.pdf" << endl;
    } else {
        cerr << "Error al generar l'informe PDF." << endl;
        return 1;
    }

    return 0;
}