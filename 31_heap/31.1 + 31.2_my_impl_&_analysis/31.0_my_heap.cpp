#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

template <typename T>
class heap
{
#define DEFAULT_ARRAY_SIZE (int)10e6
#define DEFAULT_ARRAY_INCREMENT_SIZE 100
    int size = DEFAULT_ARRAY_SIZE;
    T *data;
    int pos;

    void increase_data_size();

public:
    heap() : pos(-1)
    {
        data = new T[DEFAULT_ARRAY_SIZE];
    }

    void insert_elem(const T &elem);
    T delete_elem();

    ~heap() { delete[] data; }
};

template <typename T>
void heap<T>::increase_data_size()
{
    size = size + DEFAULT_ARRAY_INCREMENT_SIZE;
    T *new_ptr = new T[size];

    for (int i = 0; i <= pos; i++)
        new_ptr[i] = data[i];

    delete[] data;
    data = new_ptr;
}

template <typename T>
void heap<T>::insert_elem(const T &elem)
{
    if (pos == size - 1)
        increase_data_size();

    pos++;

    int ptr = pos;

    while (ptr > 0)
    {
        int par = ceil(((float)ptr) / 2) - 1;

        if (data[par] > elem)
        {
            data[ptr] = elem;
            return;
        }

        data[ptr] = data[par];
        ptr = par;
    }
    //now ptr will be 0
    data[ptr] = elem;
}

template <typename T>
T heap<T>::delete_elem()
{
    if (pos == -1)
        throw invalid_argument("heap already empty");

    T to_be_returned = data[0];

    T copy = data[pos];
    pos--;

    int ptr = 0;
    int left = 1;
    int right = 2;

    while (right <= pos)
    {
        if (copy > data[left] && copy > data[right])
        {
            data[ptr] = copy;
            return to_be_returned;
        }

        if (data[left] > data[right])
        {
            data[ptr] = data[left];
            ptr = left;
        }
        else
        {
            data[ptr] = data[right];
            ptr = right;
        }

        left = ptr * 2 + 1;
        right = left + 1;
    }

    if (left == pos)
        if (copy < data[left])
        {
            data[ptr] = data[left];
            ptr = left;
        }

    data[ptr] = copy;

    return to_be_returned;
}

//tc: O(nlgn)
void heap_sort(vector<int> &data)
{
    heap<int> hep;

    int arr_size = data.size();

    for (int i = 0; i < arr_size; i++)
        hep.insert_elem(data[i]);

    for (int i = 0; i < arr_size; i++)
        data.pop_back();

    for (int i = 0; i < arr_size; i++)
    {
        data.push_back(hep.delete_elem());
    }
}

bool is_vector_sorted_desc(vector<int> &data)
{
    for (int i = 1; i < data.size(); i++)
        if (data[i] > data[i - 1])
            return false;

    return true;
}

#define AVG_NUM 100
int main()
{
    srand(time(0));

    ofstream fout("./dataset.csv", ios::out);
    fout << "size,avg_time_ms\n";
    fout.close();

    for (int n = 100000; n <= (int)10e6; n += 100000)
    {
        double avg_time_ms = 0;
        for (int x = 0; x < AVG_NUM; x++)
        {
            vector<int> input;

            for (int i = 0; i < n; i++)
                input.push_back(rand() % 100);

            float initial = clock();
            heap_sort(input);
            float final = clock();

            float time_taken_ms = (final - initial) * 1000 / CLOCKS_PER_SEC;
            if (is_vector_sorted_desc(input))
            {
                cout << "size: " << n << " Time: " << time_taken_ms << " ms\n";
                avg_time_ms += time_taken_ms;
            }
            else
                throw invalid_argument("array was not sorted");
        }

        avg_time_ms /= AVG_NUM;
        ofstream fout("./dataset.csv", ios::out | ios::app);
        fout << n << "," << avg_time_ms << "\n";
        fout.close();
    }

    fout.close();
}