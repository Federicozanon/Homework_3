#include <vector>
#include <string>
#include <iostream>
#include <type_traits>

using namespace std;
using vec_doubles = vector<double>;
using vec_string = vector<string>;
using matrix_int = vector<vector<int>>;

template <typename T>
class variables_generator {
    private:
        vector<T> values;
    public:
        variables_generator() = default;
        void complete_data(T value){
            values.push_back(value);
        }
        void data_process(){
            if constexpr(is_same_v<T, vec_doubles>){
                cout<<"[";
                for(i: values){
                    cout<<i<<",";
                }
                cout<<"]\n";
            }
            if constexpr(is_same_v<T, vec_string>){
                cout<<"\"[";
                for(i: values){
                    cout<<"\""<<i<<"\",";
                }
                cout<<"]\n";
            }
            if constexpr(is_same_v<T, matrix_int>){
                cout<<"[\n";
                for(int i=0, i<n, i+=2){
                    cout<<"["<<values[i/n][(i+1)%n]<<", "<<values[(i+1)/n][(i+1)%n]<<"],\n"
                }
                cout<<"]\n";
            }
        }
};
template <typename T>
class variables_conversion_Json : public variables_generator {
    private:
        vector<T> *values;
        vector<T*> pointers_values;
        string name;
    public:
        variables_conversion_Json() = variables_generator(), default;
        void tag_association(vector<T> valores, string nombre){
            values=&valores;
            name=nombre;
            pointers_values.push_back(*valores)

        }
        template<>
        void Json_construction<matrix_int>(){
            
        }
        template<>
        void Json_construction<vec_doubles>(){
            
        }
        template<>
        void Json_construction<vec_string>(){

        }

};


/*
while(true){
                    T value;
                    cout<<"ingrese un dato, si desea salir aprete escape: ";
                    cin>>value;
                    if(cin.good()){
                        if(char(value)==27){
                            break;
                        }
                        values.push_back(value);
                        cout<<"\n";
                    }
                    else{
                        cout<<"Error al ingresar el dato, ingrese nuevamente el tipo adecuado\n";
                    }
                }*/