#include <vector>
#include <iostream>
#include <type_traits>
#include <sstream>
using namespace std;
using vec_doubles = vector<double>;
using vec_string = vector<string>;
using matrix_int = vector<vector<int>>;

template <typename T>
class variables_generator {
    protected:
        T values;
    public:
        using value_type = typename T::value_type;
        void complete_data(const value_type& value){
            values.push_back(value);
        }
        string data_process() const{
            unsigned int tam = values.size();
            if(tam==0){
                throw std::invalid_argument("La variable es vacia");
            }
            ostringstream string_vec;
            if constexpr(is_same_v<T, vec_doubles>){
                string_vec<<"[";
                for(unsigned int i=0; i<tam-1; i++){
                    string_vec<<values[i]<<", ";
                }
                string_vec<<values[tam-1]<<"],\n";
            }
            else if constexpr(is_same_v<T, vec_string>){
                string_vec<<"[";
               for(unsigned int i=0; i<tam-1;i++){
                    string_vec<<"\""<<values[i]<<"\", ";
                }
                string_vec<<"\""<<values[tam-1]<<"\"],\n";
            }
            else if constexpr(is_same_v<T, matrix_int>){
                string_vec<<"[\n";
                unsigned int n=values[0].size();
                for(unsigned int i=0; i<n-1; i+=2){ 
                    string_vec<<"["<<values[i/n][i%n]<<", "<<values[(i+1)/n][(i+1)%n]<<"],\n";
                }
                string_vec<<"["<<values[n/n][n%n]<<", "<<values[(n+1)/n][(n+1)%n]<<"]\n";
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
        void Final_Json_construction() const{
            cout<<"{ ";
            for(size_t i=0; i<vec_name_and_values.size(); i++){
                cout<<"\""<<vec_name_and_values[i].first<<"\" : "<<vec_name_and_values[i].second;
            }
            cout<<"}\n";
        }
};
