// Asistente para notas estudianteles, se lista en una matriz donde contiene 3 columnas id, nombre, Nota

#include <iostream>
#include <vector>
#include <string>
#include <set>

void SolicitarDatos(std::vector<std::vector<std::string> >& table) {
    int numRows;
    std::cout << "Ingrese el número de filas: ";
    std::cin >> numRows;

    table.resize(numRows, std::vector<std::string>(3));
    std::set<int> existingIDs; // Conjunto para almacenar IDs existentes
    // set -> modifica directamente el valor de la variable privada.
    for (int i = 0; i < numRows; i++) {
        int id;
        std::string name;
        double grade;

        std::cout << "Ingrese el ID del estudiante: ";
        std::cin >> id;

        // Verificar si el ID ya existe en el conjunto
        while (existingIDs.count(id) > 0) {
            std::cout << "ID repetido. Ingrese un ID diferente: ";
            std::cin >> id;
        }
        existingIDs.insert(id); // Agregar el ID al conjunto

        std::cin.ignore(); // Limpiar el buffer del teclado
        std::cout << "Ingrese el nombre del estudiante: ";
        std::getline(std::cin, name);
        std::cout << "Ingrese la nota del estudiante: ";
        std::cin >> grade;

        table[i][0] = std::to_string(id);
        table[i][1] = name;
        table[i][2] = std::to_string(grade);
    }
}

void OrdenarPorIDAscendente(std::vector<std::vector<std::string> >& table) {
    int n = table.size();
    for (int i = 1; i < n; i++) {
        std::vector<std::string> key = table[i];
        int j = i - 1;

        while (j >= 0 && std::stoi(table[j][0]) > std::stoi(key[0])) { // stoi -> convierte la secuencia de caracteres de str en un valor de tipo int y devuelve el valor. 
            table[j + 1] = table[j];
            j = j - 1;
        }
        table[j + 1] = key;
    }
}

int main() {
    std::vector<std::vector<std::string> > table;

    SolicitarDatos(table);
    OrdenarPorIDAscendente(table);

    // Mostrar la tabla ordenada
    std::cout << "\nTabla de estudiantes ordenada por ID (ascendente):\n";
    std::cout << "ID\tNombre\tNota\n";
    for (const std::vector<std::string>& row : table) {
        for (const std::string& cell : row) {
            std::cout << cell << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
