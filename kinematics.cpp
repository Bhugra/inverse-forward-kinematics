#include <iostream>
#include <cmath>

using namespace std;

struct vec2{
    float x;
    float y;
};

       void fk_pos(int N, float L[], float theta[], vec2 joints[]){
            //for N no. of links with link length L
            float X = 0.0f;
            float Y = 0.0f;
            float angle_sum = 0.0f;
            for (int k = 0; k < N; k++){
                angle_sum += theta[k];
                X += L[k] * cos(angle_sum);
                Y += L[k] * sin(angle_sum);
                
                joints[k].x = X;
                joints[k].y = Y;
                
            }

        }


int main(){
/*    //distance vector
    vec2 d;
    //local frame position vector
    vec2 x;
*/
int choice = 1;


while (true){

    if (choice == 1){
        int N;

        cout <<" To find initial position of your bot please enter following details \n"
             <<"Enter number of links" << endl;
        cin >> N;
        float theta[N];
        vec2 joints[N];
        float link_length[N];


//float lenght_i = 0;
        for (int i = 0; i < N; i++){
            cout << "Enter lenght of link " << i << " " ;
            cin >> link_length[i];
  //  link_length[i] = lenght_i;

}


        for (int j = 0; j < N; j++){
            cout << "Enter angle between links ";
            cin >> theta[j];
            theta[j] = theta[j] * M_PI /180.0f;
  //  link_length[i] = lenght_i;
}
        fk_pos(N, link_length, theta, joints);

        cout << "\nJoint positions:\n";
        for (int i = 0; i < N; i++) {
            cout << "Joint " << i + 1 << ": ("
                 << joints[i].x << ", "
                 << joints[i].y << ")\n";
}
        // algo to enter distance between EE(End Efector) and target with direction or just coordinates we might need vec3 for z axis or just coordinates of target wrt the bot 

            if(N == 2){ 
                        //end result or end effector(X,Y)
                vec2 EE;
                EE.x = joints[N-1].x;
                EE.y = joints[N-1].y;

                //target(X,Y)
                vec2 target;
                cout << "Enter 2D coordinates of the Target " << endl;
                cin >> target.x;
                cout << " and ";
                cin >> target.y;

                float Tx = target.x;
                float Ty = target.y;

                float r2 = Tx*Tx + Ty*Ty;
                float L1 = link_length[0];
                float L2 = link_length[1];

                float B = sqrt( r2 ); //length from base origin to target(X,Y)
                 //Where |L1 - L2| <= B <= L1 + L2

                 if ( fabs(L1 - L2) <= B && B <= (L1 + L2) ){

                        float cos_theta_2 = (r2 - L1*L1 - L2*L2) / (2.0f * L1 * L2);
                        float theta_2 = acos(cos_theta_2);

                        float theta_a = atan2(Ty, Tx);

                        float theta_0 = asin((L2*sin(theta_2))/B);

                        float theta_1 = theta_a - theta_0; 

                        cout << "Angles to reach the Target by End Effector: \n"
                             << " first angle " << theta_1 << "\n"
                             << " second angle " << theta_2 << endl;
                    }

                    else {
                        cout << "wrong parameters" << endl;
                    }
                }

            else{
                    cout << "Inverse Kinematics is not available for more than 2 links" << endl;
                }

    cout << "if you want to find another, press 1 otherwise any other number" << endl;
    cin >> choice;

    }
    else {
        break;
    }
}


return 0;
}