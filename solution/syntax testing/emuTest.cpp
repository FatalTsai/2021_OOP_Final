#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <typeinfo>

using namespace std;
#if 0
glasses
what is the frame model of glasses?
what is the lens prescription of glasses?
what is the lens color of glasses?
does it have the glasses plus sunglasses?

dumbbells:
what is the weight of dumbbells
what is the size of dumbbells
what is the material of dumbbells

mouse:
what is the size of the mouse?
what is the category of the mouse?
what is the color of the mouse?
what is the button of the mouse
#endif

#define SIZE_LIST (vector<string>){"fuck","the","axue"})
// enum cATR{Question=0, Answer=1, Detail=2}commodityAtr;


//Q
#define Glasses \
	X(Prototype, = 0, ((vector<string>){"glasses","",""}))\
	X(Question,  = 1, ((vector<string>){"q0","q1","q2"}))\
	X(Detail,  = 8, ((vector<string>){"d1","d2","d3"}))\


#define X(a, b, c) a b,
enum EValue { Glasses };
#undef X

 std::map<EValue, vector<string> >table;
// #define X(a, b, c) table[a] = {c};
// 	Glasses
// #undef X

#if 1
const string ToString(EValue value,int k)
{
	static std::map<EValue, vector<string>> table;
	static bool isInit = false;
	if (isInit)
		return table[value][k];

#define X(a, b, c) table[a] = c;
	Glasses
#undef X

	isInit = true;
	return table[value][k];
}
#endif


int main()
{


    for(int i=0;i<3;i++){
        cout<<ToString(Question,i);
    }

    // for(auto x:SIZE_LIST){
    //     cout<<x<<endl;
    // }
    // table[KZero]=SIZE_LIST;

    // #define X(a, b, c) table[a] = c;
	//     Glasses
    // #undef X


    
        // cout<<table[KZero][2]<<endl;
    // cout<<ToString(KZero)<<endl;
    // cout<<table[KZero][1] << '\n';
}