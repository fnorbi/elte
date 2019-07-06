#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int sigma(int n)
{
    //Önmagán kívüli osztója legfeljebb a feléig lehet
    int sum = 0;
    for (int i = 1; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            sum += i;
        }
    }
    sum += n;
    return sum;
}

bool isPrime(int n)
{
    int i = 2;
    while(i <= sqrt(n) && n % i != 0)
    {
        i++;
    }
    return i > sqrt(n) && n > 1;
}

void Eratoszthenesz(int n, vector<int> &primes)
{
    vector<bool> numbers;
    for (int i = 0; i < n; i++)
    {
        numbers.push_back(true);
    }
    
    int i = 1;
    while(i < n)
    {
        if(numbers[i])
        {
            primes.push_back(i + 1);
            for (int j = i; j < n; j += i + 1) //itt most a számunk i + 1
            {
                numbers[j] = false;
            }
        }
        i++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> primes;
    cout << "Osztok osszege: " << sigma(n) << endl;
    cout << "Prim-e: " << isPrime(n) << endl;
    cout << "Primek " << n << "-ig: " << endl;
    Eratoszthenesz(n, primes);
    for(int p : primes)
    {
        cout << p << " ";
    }
    
    return 0;
}