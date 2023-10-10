#include<iostream>
using namespace std;

int min(int a, int b)
{
    if (a >= b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int restrok(int teksum, int newa[], size_t n, int ostan, int sum)
{
    int poluch, i, newsum, sumpop, dopsumpop, promez;
    poluch = 9999999999;
    newsum = 0;
    if (sum % 2 == 0)
    {
        sumpop = sum / 2;
        dopsumpop = sumpop;
    }
    else
    {
        sumpop = (sum + 1) / 2;
        dopsumpop = (sum - 1) / 2;
    }
    for (i = ostan; i < n; i++)
    {
        newsum = teksum + newa[i];
        if (newsum > sumpop)
        {
            poluch = min(poluch, newsum - sumpop);
        }
        else if (newsum == sumpop or newsum == dopsumpop)
        {
            return 0;
        }
        else
        {
            promez = restrok(newsum, newa, n, i + 1, sum);
            poluch = min(promez, poluch);
        }
    }
    return poluch;
}

int main()
{
    int n, i;
    cin >> n;
    int a[32];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int vspom, newa[32], max, j, zapj;
    for (i = 0; i < n; i++)
    {
        max = a[i];
        j = 0;
        zapj = 0;
        for (j = i; j < n; j++)
        {
            if (max < a[j])
            {
                max = a[j];
                zapj = j;
            }
        }
        newa[i] = max;
        a[zapj] = a[i];
        a[i] = 0;

    }

    int sum, sumpop, dopsumpop;
    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += newa[i];
    }
    if (sum % 2 == 0)
    {
        sumpop = sum / 2;
        dopsumpop = sumpop;
    }
    else
    {
        sumpop = (sum + 1) / 2;
        dopsumpop = (sum - 1) / 2;
    }

    int maxmisks, flajok, otvet;
    otvet = 0;
    maxmisks = 0;
    flajok = 0;
    for (j = n - 1; j > 0; j--)
    {
        flajok += newa[j];
        maxmisks++;
        if (flajok > dopsumpop)
        {
            if (flajok == sumpop)
            {
                otvet = 1;
                cout << 1 << endl;
            }
            break;
        }
        else if (flajok == dopsumpop)
        {
            otvet = 1;
            if (dopsumpop == sumpop)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
            break;
        }
    }
    maxmisks = n - maxmisks + 1;
    if (otvet == 0)
    {
        int k, poluch;
        poluch = restrok(newa[0], newa, n, 1, sum);
        if (sumpop == dopsumpop)
        {
            poluch = poluch * 2;
        }
        else
        {
            poluch = poluch * 2 + 1;
        }
        cout << poluch << endl;
    }
    for (i = 0; i < n; i++)
    {
        cout << newa[i] << endl;
    }
}