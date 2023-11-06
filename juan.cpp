#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string subsecuencia_comun_mas_larga(string secuencia1, string secuencia2)
{
    int longitud1 = secuencia1.size();
    int longitud2 = secuencia2.size();
    vector<vector<string>> matriz(longitud1 + 1, vector<string>(longitud2 + 1, ""));
    for (int i = 0; i < longitud1; ++i)
    {
        for (int j = 0; j < longitud2; ++j)
        {
            if (secuencia1[i] == secuencia2[j])
            {
                matriz[i + 1][j + 1] = matriz[i][j] + secuencia1[i];
            }
            else
            {
                matriz[i + 1][j + 1] = (matriz[i + 1][j].size() > matriz[i][j + 1].size()) ? matriz[i + 1][j] : matriz[i][j + 1];
            }
        }
    }
    return matriz[longitud1][longitud2];
}

int main()
{
    vector<pair<string, string>> secuencias = {{"ctgactga", "actgagc"}, {"cgtaattgcgat", "cgtacagtagc"}, {"ctgggccttgaggaaaactg", "gtaccagtactgatagt"}};
    for (auto const &par : secuencias)
    {
        cout << subsecuencia_comun_mas_larga(par.first, par.second) << endl;
    }
    return 0;
}
