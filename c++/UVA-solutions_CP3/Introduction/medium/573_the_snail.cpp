#include <iostream>
using namespace std;
int main(){
    int H,U,D,F, c = 0;
    double feetdrop,initialHeight, distanceClimbed, heightAfterClimb, heightAfterslide;
    while(cin >> H >> U >> D >> F && H){
        feetdrop = F*U/100.0;
        //cout << feetdrop << endl;
        c = 0;
        initialHeight = 0;
        distanceClimbed = 0;
        heightAfterClimb = 0;
        heightAfterslide = 0;
        while(heightAfterslide >= 0 && heightAfterClimb <= H){
            initialHeight = heightAfterslide;
            distanceClimbed = U - feetdrop*c;
            if(distanceClimbed < 0) distanceClimbed = 0;
            c++;
            heightAfterClimb = initialHeight + distanceClimbed;
            heightAfterslide = heightAfterClimb - D;
            //if(H == 56)
            //printf("H %d fd %f hac %f dc %f has %f\n",H,feetdrop,heightAfterClimb, distanceClimbed,heightAfterslide);
        }
        if (heightAfterClimb > H)
            cout << "success";
        else cout << "failure";
        cout << " on day " << c << endl;
    }

}