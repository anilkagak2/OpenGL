#include <vector>
#include <iostream>
using namespace std;

typedef struct pt {
    float x;
    float y;
} pt;

int main () {
    pt p1={0,0},p2={1,0},p3={0,1};
    int division = 5;
    vector<pt> triangleMesh;
    vector<int> indicesMesh;

    triangleMesh.push_back (p1);
    for (int i=1; i<=division; i++) {
        pt pl, pr;
        pl.x = ( p1.x * (division - i) + p2.x * i ) / division;
        pl.y = ( p1.y * (division - i) + p2.y * i ) / division;
        pr.x = ( p1.x * (division - i) + p3.x * i ) / division;
        pr.y = ( p1.y * (division - i) + p3.y * i ) / division;

        triangleMesh.push_back (pl);
        for (int j=1; j<i; j++) {
            pt p;
            p.x = ( pl.x * (i-j) + pr.x * j ) / i;
            p.y = ( pl.y * (i-j) + pr.y * j ) / i;
            triangleMesh.push_back (p);
        }

        triangleMesh.push_back (pr);
    }

    int prev = 0, cur = 1;
    for (int i=1; i<=division; i++) {
        indicesMesh.push_back (prev);
        indicesMesh.push_back (cur);
        indicesMesh.push_back (cur+1);

        for (int j=prev, k=cur+1; j<cur-1; j++, k++) {
            indicesMesh.push_back (j);
            indicesMesh.push_back (j+1);
            indicesMesh.push_back (k);

            indicesMesh.push_back (j+1);
            indicesMesh.push_back (k);
            indicesMesh.push_back (k+1);
        }

        prev = cur;
        cur += i+1;
    }

    for (int i=0; i<triangleMesh.size (); i++)
        cout << triangleMesh[i].x << ", " <<  triangleMesh[i].y << " " ;
    cout <<  endl;

    for (int i=0; i<indicesMesh.size (); i++)
        cout << indicesMesh[i] << " " ;
    cout << endl;
    return 0;
}
