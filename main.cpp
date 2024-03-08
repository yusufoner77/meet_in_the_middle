#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string read_file(string filename) {

    string str;
    ifstream file;
    file.open(filename);

    if (file.fail()) {
        cout << "File failed to open." << endl;
    }

    file >> str;

    file.close();
    return str;

}

vector<int> store_in_vector(string str) {

    vector<int> vec;
    string str2;
    stringstream ss(str);

    while (ss.good()) {
        getline(ss, str2, ',');
        vec.push_back(stoi(str2));
    }

    return vec;

}

int find_median_odd(vector<int> vec) {

    int number_of_elements = vec.size();
    
    int median = vec[(number_of_elements - 1) / 2];
    
    return median;

}

double find_median_even(vector<int> vec) {

    int number_of_elements = vec.size();
    int x = vec[(number_of_elements / 2) - 1];
    int y = vec[number_of_elements / 2];

    double median = (x + y) / 2;
    
    return median;

}

double find_median(vector<int> vec) {
    
    double median;
    int number_of_elements = vec.size();

    if ((number_of_elements % 2 == 0)) {
        median = find_median_even(vec);
    }

    else {
        median = find_median_odd(vec);
    }

    return median;
}

double find_mean(vector<int> vec) {

    double mean;
    double sum = 0;
    int number_of_elements = vec.size();

    for (int i = 0; i < vec.size(); i++) {
        sum = sum + vec[i];
    }

    mean = sum / number_of_elements;

    return mean;

}

void find_mode(vector<int> vec) {

    int mode = -1;
    int current_count = 1;
    int max_count = 1;

    for (int i = 1; i < vec.size(); i++) {
        
        if (vec[i] == vec [i - 1]) {
            current_count++;
        }
        
        else {
            if (current_count > max_count) {
                max_count = current_count;
                mode = vec[i - 1];
            }
            current_count = 1;
        }

    }

    if (current_count > max_count) {
        mode = vec[vec.size() - 1];
    }

    if (mode != -1) {
        cout << "The mode is " << mode << endl;
    }

    else {
        cout << "No mode found." << endl;
    }

}

int main() {
    
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    string str = read_file(filename);
    cout << str << endl;

    vector<int> vec = store_in_vector(str);

    cout << "The median is " << find_median(vec) << endl;

    cout << "The mean is " << find_mean(vec) << endl;

    find_mode(vec);
}