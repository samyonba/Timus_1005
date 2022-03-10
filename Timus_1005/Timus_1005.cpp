// Timus_1005.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>

using namespace std;

int main()
{
    size_t n;
    cin >> n;

    int total = 0;
    int left_sum = 0;

    vector<int> data;
    /*data.resize(20);*/

    for (size_t i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        data.push_back(value);
        total += value;
    }
    int min_difference = total;

    

    for (size_t i = 1; i < pow(2, n) - 1; i++)
    {
        bitset<20> mask{ i };
        
        int local_sum = 0;

        for (size_t j = 0; j < n; j++)
        {
            if (mask[j])
            {
                local_sum += data[j];
            }
        }

        int local_difference = abs(total - 2 * local_sum);
        if (local_difference == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        if (local_difference < min_difference)
        {
            min_difference = local_difference;
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
