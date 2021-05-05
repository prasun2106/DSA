#include <iostream>
using namespace std;

int main(){
int newarray[] = {2,3,4,6};
if (4%2 == 0){
    cout<<newarray[0]+15;
       float median_value = (newarray[4/2] + newarray[(4/2)- 1])/2.0;
    //    std::cout << std::setprecision (2) << median_value <<" L"<< std::endl;
       cout<< median_value << " L";
   }
   else{
       cout<<newarray[(4-1)/2] << "L";

}
}