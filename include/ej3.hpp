#include <vector>
#include <string>//puede ser descartado?
#include <iostream>
#include <type_traits>//puede ser descartado?
#include <sstream> //puede ser descartado?
using namespace std;
using vec_doubles = vector<double>;
using vec_string = vector<string>;
using matrix_int = vector<vector<int>>;

template <typename T>
class variables_generator {
    private:
        T values;
    public:
        using value_type = typename T::value_type;
        void complete_data(const value_type& value);
        string data_process() const;
};
class variables_conversion_Json{
    private:
        vector<pair<string, string>> vec_name_and_values;
    public:
        void tag_association(string valores, string nombre);
        void Final_Json_construction();
};
