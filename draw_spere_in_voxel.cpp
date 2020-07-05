#include <iostream> 
#include <cmath> 
  
// this header file contains get<0> and get<1> function 
#include <utility> 
  
#include <list> 
#include <map> 
using namespace std; 
  
// map to store the voxels 
map<int, list<pair<int, int> > > mymap; 
map<int, list<pair<int, int> > >::iterator itr; 
  
// this function will store single voxel 
void putpixelone(int m, int n, int p) 
{ 
    mymap[m].push_back(make_pair(n, p)); 
} 
  
// function to store some particular type of voxel 
void putpixelmiddle(int a, int b, int c, int x, int y, int z) 
{ 
    putpixelone(a + x, b + y, c + z); 
    putpixelone(a + x, b + y, -c + z); 
    putpixelone(a + x, c + y, b + z); 
    putpixelone(a + x, -c + y, b + z); 
    putpixelone(c + x, a + y, b + z); 
    putpixelone(-c + x, a + y, b + z); 
} 
  
// This program will generate 24 voxels 
void putpixeldouble(int a, int b, int c, int x, int y, int z) 
{ 
    for (int j = 0; j < 3; j++) { 
        putpixelone(a + x, b + y, c + z); 
        swap(b, c); 
        swap(a, b); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(-a + x, b + y, c + z); 
        swap(b, c); 
        swap(a, b); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(a + x, -b + y, c + z); 
        swap(b, c); 
        swap(a, b); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(-a + x, -b + y, c + z); 
        swap(b, c); 
        swap(a, b); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(a + x, b + y, -c + z); 
        swap(b, c); 
        swap(a, b); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(-a + x, b + y, -c + z); 
        swap(b, c); 
        swap(a, b); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(a + x, -b + y, -c + z); 
        swap(b, c); 
        swap(a, b); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(-a + x, -b + y, -c + z); 
        swap(b, c); 
        swap(a, b); 
    } 
} 
  
// Explained above 
void putpixelsingle(int a, int b, int c, int x, 
                    int y, int z) 
{ 
    putpixelone(a + x, b + y, c + z); 
    putpixelone(-a + x, b + y, c + z); 
    putpixelone(a + x, -b + y, c + z); 
    putpixelone(-a + x, -b + y, c + z); 
    putpixelone(a + x, b + y, -c + z); 
    putpixelone(-a + x, b + y, -c + z); 
    putpixelone(a + x, -b + y, -c + z); 
    putpixelone(-a + x, -b + y, -c + z); 
} 
// This program will generate 24 voxels. 
void putpixeledge2(int a, int b, int c, int x, 
                   int y, int z) 
{ 
  
    for (int j = 0; j < 3; j++) { 
        putpixelone(a + x, b + y, c + z); 
        swap(a, b); 
        swap(b, c); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(-a + x, b + y, c + z); 
        swap(a, b); 
        swap(b, c); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(a + x, -b + y, c + z); 
        swap(a, b); 
        swap(b, c); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(-a + x, -b + y, c + z); 
        swap(a, b); 
        swap(b, c); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(a + x, b + y, -c + z); 
        swap(a, b); 
        swap(b, c); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(-a + x, b + y, -c + z); 
        swap(a, b); 
        swap(b, c); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(a + x, -b + y, -c + z); 
        swap(a, b); 
        swap(b, c); 
    } 
    for (int j = 0; j < 3; j++) { 
        putpixelone(-a + x, -b + y, -c + z); 
        swap(a, b); 
        swap(b, c); 
    } 
} 
// after excluding the repeated pixels from the set all 48 
// pixels we will left with only 24 pixels so, we have 
// defined all the voxels given below. 
void putpixeledge1(int a, int b, int c, int x, int y, int z) 
{ 
    putpixelone(a + x, b + y, c + z); 
    putpixelone(a + x, c + y, b + z); 
    putpixelone(a + x, -b + y, c + z); 
    putpixelone(a + x, b + y, -c + z); 
    putpixelone(a + x, -b + y, -c + z); 
    putpixelone(a + x, -c + y, b + z); 
    putpixelone(a + x, c + y, -b + z); 
    putpixelone(a + x, -c + y, -b + z); 
    putpixelone(b + x, c + y, a + z); 
    putpixelone(b + x, a + y, c + z); 
    putpixelone(b + x, -c + y, a + z); 
    putpixelone(b + x, c + y, -a + z); 
    putpixelone(b + x, -c + y, -a + z); 
    putpixelone(b + x, a + y, -c + z); 
    putpixelone(b + x, -a + y, c + z); 
    putpixelone(b + x, -a + y, -c + z); 
    putpixelone(c + x, a + y, b + z); 
    putpixelone(c + x, -a + y, b + z); 
    putpixelone(c + x, a + y, -b + z); 
    putpixelone(c + x, -a + y, -b + z); 
    putpixelone(c + x, b + y, a + z); 
    putpixelone(c + x, -b + y, a + z); 
    putpixelone(c + x, b + y, -a + z); 
    putpixelone(c + x, -b + y, -a + z); 
} 
  
// voxel formation by 48 symmetry. 
void putpixelall(int a, int b, int c, int x, 
                 int y, int z) 
{ 
    putpixelone(a + x, b + y, c + z); 
    putpixelone(b + x, a + y, c + z); 
    putpixelone(c + x, b + y, a + z); 
    putpixelone(a + x, c + y, b + z); 
    putpixelone(c + x, a + y, b + z); 
    putpixelone(b + x, c + y, a + z); 
    putpixelone(-a + x, -b + y, c + z); 
    putpixelone(-b + x, -a + y, c + z); 
    putpixelone(c + x, -b + y, -a + z); 
    putpixelone(-a + x, c + y, -b + z); 
    putpixelone(c + x, -a + y, -b + z); 
    putpixelone(-b + x, c + y, -a + z); 
    putpixelone(a + x, -b + y, -c + z); 
    putpixelone(-b + x, a + y, -c + z); 
    putpixelone(-c + x, -b + y, a + z); 
    putpixelone(a + x, -c + y, -b + z); 
    putpixelone(-c + x, a + y, -b + z); 
    putpixelone(-b + x, -c + y, a + z); 
    putpixelone(-a + x, b + y, -c + z); 
    putpixelone(b + x, -a + y, -c + z); 
    putpixelone(-c + x, b + y, -a + z); 
    putpixelone(-a + x, -c + y, b + z); 
    putpixelone(-c + x, -a + y, b + z); 
    putpixelone(b + x, -c + y, -a + z); 
    putpixelone(-a + x, b + y, c + z); 
    putpixelone(b + x, -a + y, c + z); 
    putpixelone(c + x, b + y, -a + z); 
    putpixelone(-a + x, c + y, b + z); 
    putpixelone(c + x, -a + y, b + z); 
    putpixelone(b + x, c + y, -a + z); 
    putpixelone(a + x, -b + y, c + z); 
    putpixelone(-b + x, a + y, c + z); 
    putpixelone(c + x, -b + y, a + z); 
    putpixelone(a + x, c + y, -b + z); 
    putpixelone(c + x, a + y, -b + z); 
    putpixelone(-b + x, c + y, a + z); 
    putpixelone(a + x, b + y, -c + z); 
    putpixelone(b + x, a + y, -c + z); 
    putpixelone(-c + x, b + y, a + z); 
    putpixelone(a + x, -c + y, b + z); 
    putpixelone(-c + x, a + y, b + z); 
    putpixelone(b + x, -c + y, a + z); 
    putpixelone(-a + x, -b + y, -c + z); 
    putpixelone(-b + x, -a + y, -c + z); 
    putpixelone(-c + x, -b + y, -a + z); 
    putpixelone(-a + x, -c + y, -b + z); 
    putpixelone(-c + x, -a + y, -b + z); 
    putpixelone(-b + x, -c + y, -a + z); 
} 
  
// detailed explanation of this algorithm is 
// given in above link. 
void drawsphere(int x, int y, int z, int r) 
{ 
    int i = 0, j = 0; 
    int k0 = r; 
    int k = k0; 
    int s0 = 0; 
    int s = s0; 
    int v0 = r - 1; 
    int v = v0; 
    int l0 = 2 * v0; 
    int l = l0; 
  
    // this while loop will form naive arcs 
    while (i <= k) { 
  
        // this while will form voxels in naive arcs 
        while (j <= k) { 
            if (s > v) { 
                k = k - 1; 
                v = v + l; 
                l = l - 2; 
            } 
            if ((j <= k) && ((s != v) || (j != k))) { 
  
                // this if, else and else if condition 
                // can easily build using figure 2, 3 
                if (i == 0 && j != 0) 
  
                    // First naive arc pixels and each 
                    // pixel is shared with two q-octants 
                    putpixeledge1(i, j, k, x, y, z); 
  
                // voxels shared between q1 and q2 
                else if (i == j && j != k && i != 0) 
                    putpixeledge2(i, j, k, x, y, z); 
  
                // center voxel of c-octants 
                else if (i == j && j == k) 
                    putpixelsingle(i, j, k, x, y, z); 
  
                // voxels shared between q1 and q6 
                else if (j == k && i < k && i < j) 
                    putpixeldouble(i, j, k, x, y, z); 
  
                // starting voxel of q-octant 
                else if (i == 0 && j == 0) 
                    putpixelmiddle(i, j, k, x, y, z); 
  
                // voxels inside the q-octant 
                else
                    putpixelall(i, j, k, x, y, z); 
            } 
            s = s + 2 * j + 1; 
            j = j + 1; 
        } 
        s0 = s0 + 4 * i + 2; 
        i = i + 1; 
  
        while ((s0 > v0) && (i <= k0)) { 
            k0 = k0 - 1; 
            v0 = v0 + l0; 
            l0 = l0 - 2; 
        } 
        j = i; 
        k = k0; 
        v = v0; 
        l = l0; 
        s = s0; 
    } 
} 
// Print out all the voxels of discrete sphere 
void showallpoints(map<int, list<pair<int, int> > >& mymap) 
{ 
    int count = 0; 
  
    for (itr = mymap.begin(); itr != mymap.end(); ++itr) { 
        list<pair<int, int> > l = itr->second; 
        list<pair<int, int> >::iterator it; 
        for (it = l.begin(); it != l.end(); ++it) { 
            cout << itr->first << ", " << get<0>(*it) 
                 << ", " << get<1>(*it) << endl; 
            count += 1; 
        } 
    } 
    cout << endl; 
    cout << count << endl; 
} 
// Driver program 
int main() 
{ 
    int cx, cy, cz; 
    cin >> cx >> cy >> cz; 
    int r; 
    cin >> r; 
    drawsphere(cx, cy, cz, r); 
    showallpoints(mymap); 
} 