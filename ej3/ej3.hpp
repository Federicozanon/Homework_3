#include <vector>
#include <string>//puede ser descartado?
#include <iostream>
#include <type_traits>//puede ser descartado?
#include <sstream> //puede ser descartado?
using namespace std;
using vec_doubles = vector<double>;
using vec_string = vector<string>;
using matrix_int = vector<vector<int>>;

//hace falta los constructores?

template <typename T>
class variables_generator {
    private:
        T values;
    public:
        using value_type = typename T::value_type;
        void complete_data(const value_type& value){
            values.push_back(value);
        }
        string data_process() const {
            ostringstream string_vec;
            if constexpr(is_same_v<T, vec_doubles>){
                string_vec<<"[";
                for(size_t i=0; i<values.size(); i++){
                    string_vec<<values[i]<<",";
                }
                string_vec<<"]\n";
            }
            else if constexpr(is_same_v<T, vec_string>){
                string_vec<<"[";
               for(size_t i=0; i<values.size();i++){
                    string_vec<<"\""<<values[i]<<"\",";
                }
                string_vec<<"]\n";
            }
            else if constexpr(is_same_v<T, matrix_int>){
                string_vec<<"[\n";
                int n=values[0].size();
                for(int i=0; i<n; i+=2){ // como puedo hacer para sacar el size de la matriz de forma mas segura?
                    string_vec<<"["<<values[i/n][(i+1)%n]<<", "<<values[(i+1)/n][(i+1)%n]<<"],\n";
                }
                string_vec<<"]\n";
            }
            else{
                throw std::invalid_argument("El tipo de dato no es compatible");
            }
            return string_vec.str();
        }
};
class variables_conversion_Json{
    private:
        vector<pair<string, string>> vec_name_and_values;
    public:
        void tag_association(string valores, string nombre){
            vec_name_and_values.push_back({nombre, valores});
        }
        void Final_Json_construction(){
            cout<<"{ ";
            for(size_t i=0; i<vec_name_and_values.size(); i++){
                cout<<"\""<<vec_name_and_values[i].first<<"\" : "<<vec_name_and_values[i].second;
            }
            cout<<"}";
        }
};
