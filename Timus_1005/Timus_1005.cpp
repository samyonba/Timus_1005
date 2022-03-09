// Timus_1005.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    size_t n;
    cin >> n;

    int total = 0;
    int left_sum = 0;
    int right_sum = 0;

    vector<int> left_part;
    vector<int> right_part;

    vector<int> data;
    data.reserve(n);

    for (size_t i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        data.push_back(value);
        total += value;
    }

	sort(data.begin(), data.end(), [](int a, int b) {
		return a > b;
		});

    int mid_value = total / 2;

    size_t k = 0;
    while (left_sum < mid_value)
    {
        left_part.push_back(data[k]);
        left_sum += data[k];
        k++;
    }
    for (size_t i = k; i < data.size(); i++)
    {
        right_part.push_back(data[i]);
        right_sum += data[i];
    }

    //if (left_sum * 2 == total)

    int min_difference = abs(left_sum - right_sum);

    

    for (size_t i = 0; i < right_part.size(); i++)
    {
        vector<int> add_left = left_part;
        vector<int> add_right = right_part;

        int add_left_sum = left_sum;
        int add_right_sum = right_sum;


        add_left_sum -= add_left.back();
        add_left_sum += add_right[i];
        add_right_sum -= add_right[i];
        add_right_sum += add_left.back();

        int buf = add_left.back();
        add_left.back() = add_right[i];
        add_right[i] = buf;

        size_t j = right_part.size() - 1;
        int inner_left_sum = add_left_sum;
        while (inner_left_sum < mid_value && j >= 0 && j < add_right.size())
        {
            vector<int> inner_left = add_left;
            vector<int> inner_right = add_right;

            inner_left_sum = add_left_sum;
            int inner_right_sum = add_right_sum;

            inner_left_sum += inner_right[j];
            inner_right_sum -= inner_right[j];

            if (abs(inner_left_sum - inner_right_sum) < min_difference)
            {
                min_difference = abs(inner_left_sum - inner_right_sum);
            }

            inner_left.push_back(inner_right[j]);
            inner_right.erase(inner_right.end() - 1);

            if (inner_left_sum > mid_value)
            {
                sort(inner_left.begin(), inner_left.end(), [](int a, int b) {
                    return a > b;
                    });

                inner_left_sum -= inner_left.back();
                inner_right_sum += inner_left.back();

                if (abs(inner_left_sum - inner_right_sum) < min_difference)
                {
                    min_difference = abs(inner_left_sum - inner_right_sum);
                }

                inner_right.push_back(inner_left.back());
                inner_left.erase(inner_left.end() - 1);
                
            }

            j--;
        }

        if (abs(add_left_sum - add_right_sum) < min_difference)
        {
            min_difference = abs(add_left_sum - add_right_sum);
        }
    }

    cout << min_difference << endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
