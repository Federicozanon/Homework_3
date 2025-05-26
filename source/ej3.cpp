#include "ej3.hpp"
template<typename T>
void variables_generator<T>::complete_data(const value_type& value){
    values.push_back(value);
}
template<typename T>
string variables_generator<T>::data_process() const {
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
        for(int i=0; i<n; i+=2){ 
            string_vec<<"["<<values[i/n][(i+1)%n]<<", "<<values[(i+1)/n][(i+1)%n]<<"],\n";
        }
        string_vec<<"]\n";
    }
    else{
        throw std::invalid_argument("El tipo de dato no es compatible");
    }
    return string_vec.str();
}
void variables_conversion_Json::tag_association(string valores, string nombre){
    vec_name_and_values.push_back({nombre, valores});
    }
void variables_conversion_Json::Final_Json_construction(){
    cout<<"{ ";
    for(size_t i=0; i<vec_name_and_values.size(); i++){
        cout<<"\""<<vec_name_and_values[i].first<<"\" : "<<vec_name_and_values[i].second;
    }
    cout<<"}";
}