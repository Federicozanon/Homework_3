#include "../include/ej3.hpp"

int main(){
    variables_generator<vec_string> vector_strings;
    variables_generator<vec_doubles> vector_doubles;
    variables_generator<matrix_int> matriz_int;
    vector_doubles.complete_data(1.3);
    vector_doubles.complete_data(2.1);
    vector_doubles.complete_data(3.2);

    string vec_double = vector_doubles.data_process();

    vector_strings.complete_data("Hola");
    vector_strings.complete_data("Mundo");

    string vec_string = vector_strings.data_process();

    matriz_int.complete_data(vector<int>{1,2});
    matriz_int.complete_data(vector<int>{3,4});

    string m_int = matriz_int.data_process();

    variables_conversion_Json lista_datos_json;

    lista_datos_json.tag_association(vec_double,"vec_doubles");
    lista_datos_json.tag_association(vec_string, "palabras");
    lista_datos_json.tag_association(m_int, "listas");

    lista_datos_json.Final_Json_construction();

    return 0;
}