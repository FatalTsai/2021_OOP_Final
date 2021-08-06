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
enum cATR{base=0, Question=1, Detail=2}commodityAtr;




//Q
#define commodityS \
	X(glasses, = 0, ((vector<vector<string> >)(vector<string>){"glasses","",""} ,(vector<string>){"q0","q1","q2"},(vector<string>){"a0","a1","a2"}))\
	X(dumbbells,  = 1, ((vector<vector<string> >)(vector<string>){"dumbbells","",""} ,(vector<string>){"q0","q1","q2"},(vector<string>){"a0","a1","a2"}))\
	X(mouse,  = 8, ((vector<vector<string> >)(vector<string>){"mouse","",""} ,(vector<string>){"q0","q1","q2"},(vector<string>){"a0","a1","a2"}))\


#define X(a, b, c) a b,
enum EValue { commodityS };
#undef X

 std::map<EValue, vector< vector<string> >>table;
// #define X(a, b, c) table[a] = {c};
// 	commodityS
// #undef X

#if 1
const string ToString(EValue value,int k)
{
	static std::map<EValue, vector<string>> table;
	static bool isInit = false;
	if (isInit)
		return table[value][k];

#define X(a, b, c) table[a] = c;
	commodityS
#undef X

	isInit = true;
	return table[value][k];
}
#endif


int main()
{


    for(int i=0;i<3;i++){
        cout<<ToString(dumbbells,i);
    }

    // for(auto x:SIZE_LIST){
    //     cout<<x<<endl;
    // }
    // table[KZero]=SIZE_LIST;

    // #define X(a, b, c) table[a] = c;
	//     commodityS
    // #undef X


    
        // cout<<table[KZero][2]<<endl;
    // cout<<ToString(KZero)<<endl;
    // cout<<table[KZero][1] << '\n';
}