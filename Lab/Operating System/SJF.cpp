#include <iostream>
#include <vector>
#include <stdbool.h>
#include <algorithm>
using namespace std;
class DataDetails
{
public:
    int ari, pno, bur;
    int ct, tat, wt;
    int visit;
};
bool comparator(DataDetails d1, DataDetails d2)
{
    if (d1.bur != d2.bur)
        return (d1.bur < d2.bur);
    else
    {
        if (d1.ari != d2.ari)
            return (d1.ari < d2.ari);
        return (d1.pno < d2.pno);
    }
}
bool comparatorPno(DataDetails d1, DataDetails d2)
{
    return (d1.pno < d2.pno);
}
int main()
{
    cout << " SJF SCHEDULING" << endl;
    int size, t = 0, ch = 0;
    float avgtat = 0, avgwt = 0;
    cout << "Enter no of process :";
    cin >> size;
    cout << "AT BT" << endl;
    vector<DataDetails> vrr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> vrr[i].ari >> vrr[i].bur;
        vrr[i].pno = i + 1;
        vrr[i].ct = vrr[i].tat = vrr[i].wt = 0;
        vrr[i].visit = 0;
    }
    sort(vrr.begin(), vrr.end(), comparator);
    for (int k = 0; k < size; k++)
    {
        int ch = 0;
        for (int i = 0; i < size; i++)
        {
            if ((vrr[i].visit == 0) && t >= vrr[i].ari)
            {
                t += vrr[i].bur;
                vrr[i].ct = t;
                vrr[i].tat = vrr[i].ct - vrr[i].ari;
                vrr[i].wt = vrr[i].tat - vrr[i].bur;
                avgtat += vrr[i].tat;
                avgwt += vrr[i].wt;
                vrr[i].visit = 1;
                ch = 1;
                break;
            }
        }
        if (!ch)
        {
            t++;
            k--;
        }
    }
    sort(vrr.begin(), vrr.end(), comparatorPno);
    cout << endl;
    cout << " SOLUTION" << endl;
    cout << "PN "
         << "AT "
         << "BT "
         << "CT "
         << "TAT "
         << "WT " << endl;
    for (int i = 0; i < size; i++)
        cout << "P" << vrr[i].pno << " " << vrr[i].ari << " " << vrr[i].bur << " " << vrr[i].ct << " " << vrr[i].tat << " " << vrr[i].wt << " " << endl;
    avgtat = avgtat / size;
    cout << "Average TurnAroundTime is :" << avgtat << endl;
    avgwt = avgwt / size;
    cout << "Average WaitingTime is :" << avgwt << endl;
    return 0;
}