#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class DataDetails
{
public:
    int ari, pno, bur;
    int ct, tat, wt;
};
bool comparator(DataDetails d1, DataDetails d2)
{
    if (d1.ari != d2.ari)
        return (d1.ari < d2.ari);
    else
        return (d1.pno < d2.pno);
}
bool comparatorPno(DataDetails d1, DataDetails d2)
{
    return (d1.pno < d2.pno);
}
int main()
{
    cout << " FCFS SCHEDULING" << endl;
    int size, t = 0;
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
    }
    sort(vrr.begin(), vrr.end(), comparator);
    for (int i = 0; i < size; i++)
    {
        if (t >= vrr[i].ari)
        {
            t += vrr[i].bur;
            vrr[i].ct = t;
            vrr[i].tat = vrr[i].ct - vrr[i].ari;
            avgtat += vrr[i].tat;
            vrr[i].wt = vrr[i].tat - vrr[i].bur;
            avgwt += vrr[i].wt;
        }
        else
        {
            i--;
            t++;
        }
    }
    sort(vrr.begin(), vrr.end(), comparatorPno);
    cout << "\n SOLUTION" << endl;
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