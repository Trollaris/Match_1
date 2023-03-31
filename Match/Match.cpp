#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Miembro {
public:
    string nombre;
    int edad;
    string genero;
    vector<string> intereses;
};

int main() {
    // Creamos 5 arreglos con datos ficticios
    vector<Miembro> grupo1 = { {"Juan", 25, "Masculino", {"deportes", "música"}},
                              {"María", 30, "Femenino", {"lectura", "cine"}},
                              {"Pedro", 20, "Masculino", {"videojuegos", "deportes"}} };
    vector<Miembro> grupo2 = { {"Ana", 27, "Femenino", {"cine", "teatro"}},
                              {"Carlos", 35, "Masculino", {"viajes", "naturaleza"}},
                              {"Lucía", 22, "Femenino", {"deportes", "música"}} };
    vector<Miembro> grupo3 = { {"David", 28, "Masculino", {"videojuegos", "tecnología"}},
                              {"Laura", 29, "Femenino", {"lectura", "cine"}},
                              {"Miguel", 26, "Masculino", {"deportes", "música"}} };
    vector<Miembro> grupo4 = { {"Paola", 31, "Femenino", {"viajes", "naturaleza"}},
                              {"Jorge", 27, "Masculino", {"deportes", "música"}},
                              {"Carmen", 23, "Femenino", {"cine", "teatro"}} };
    vector<Miembro> grupo5 = { {"Diego", 24, "Masculino", {"videojuegos", "música"}},
                              {"Isabel", 33, "Femenino", {"deportes", "cine"}},
                              {"Santiago", 19, "Masculino", {"deportes", "videojuegos"}} };

    // Pedimos al usuario que introduzca las características que busca en la persona ideal
    int edad;
    string genero, intereses;
    cout << "¿Qué edad buscas? ";
    cin >> edad;
    cout << "¿Qué género prefieres? ";
    cin >> genero;
    cout << "¿Qué intereses te gustaría que tenga? ";
    cin >> intereses;

    // Recorremos los arreglos y buscamos los miembros que cumplan con las características especificadas
    vector<Miembro> matches;
    for (const auto& grupo : { grupo1, grupo2, grupo3, grupo4, grupo5 }) {
        for (const auto& miembro : grupo) {
            if (miembro.edad == edad && miembro.genero == genero &&
                find(miembro.intereses.begin(), miembro.intereses.end(), intereses) != miembro.intereses.end()) {
                matches.push_back(miembro);
            }
        }
    }

    // Mostramos los datos de los posibles candidatos al "match"
    cout << "Posibles candidatos al 'match':" << endl;
    for (const auto& miembro : matches) {
        cout << "Nombre: " << miembro.nombre << endl;
        cout << "Edad: " << miembro.edad << endl;
        cout << "Género: ";
        cout << "Intereses:";
        for (const auto& interes : miembro.intereses) {
            cout << " " << interes;
        }
        cout << endl << endl;
    }

    return 0;
}
