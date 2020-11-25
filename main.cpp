#include <iostream>
#include "iomanip"

using namespace std;

int main() {

    int a[100][100];

    int n, m;
    cin >> n >> m;

    int  v_o_h, im_qnt = 0, par_qnt = 0;
    int l = 0, l1 = 1, r = 0;
    int k1 = 0;
    int kappa = 1;

    if(n - m >= 2) {
        for (int i = 1; i < n - m; ++i) {
            kappa += 2;
        }
    } else {
        kappa = 1;
    }


    for (int i = 1; i <= (2 * n) - kappa; ++i) {
        if(i % 2 == 1)
        {
            v_o_h = m;
            im_qnt++;
            if(im_qnt % 2 == 1)
                l++;
            r = l;
        }
        else if(i % 2 == 0)
        {
            v_o_h = n;
            par_qnt++;
            if(par_qnt % 2 == 1)
                l1++;
            r = l1;
        }

        for (int j = r, j_i = v_o_h + 1 - r; j <= v_o_h + 1 - r && j_i > 0; ++j,--j_i)
        {
            if(i % 2 == 1 && im_qnt % 2 == 1 )
            {
                k1++;
                a[r][j] = k1;
            }
            else if(i % 2 == 0 && par_qnt % 2 == 1)
            {
                k1++;
                a[j][m + 1 - l] = k1;
            }
            else if(i % 2 == 1 && im_qnt % 2 == 0)
            {
                k1++;
                a[n + 1 - r][j_i] = k1;
            }
            else if(i % 2 == 0 && par_qnt % 2 == 0)
            {
                k1++;
                a[j_i][l] = k1;
            }
        }
    }

    cout << setw(4);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << setw(4);
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
