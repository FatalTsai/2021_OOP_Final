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

enum cATR{Prototype=0, Question=1, Detail=2}commodityAtr;
enum cS{glasses=0, dumbbells=1, mouse=2}commodityS;


//Q
#define Glasses \
	X(Prototype, ((vector<string>){"glasses","",""}))\
	X(Question, ((vector<string>){"q0","q1","q2"}))\
	X(Detail, ((vector<string>){"d1","d2","d3"}))\

#define Dumbbells \
	X(Prototype, ((vector<string>){"dumbbells","",""}))\
	X(Question, ((vector<string>){"q0","q1","q2"}))\
	X(Detail, ((vector<string>){"d1","d2","d3"}))\

#define Mouse \
	X(Prototype, ((vector<string>){"mouse","",""}))\
	X(Question, ((vector<string>){"q0","q1","q2"}))\
	X(Detail, ((vector<string>){"d1","d2","d3"}))\

// #define X(a, b, c) a b,
// enum EValue { Glasses };
// enum EValue { Dumbbells };
// enum EValue { Mouse };
// #undef X

 vector < map<int, vector<string>> >bigtable;
// #define X(a, b, c) table[a] = {c};
// 	Glasses
// #undef X








int main()
{
    map<int, vector<string>> table;
    #define X(a, c) table[a] = c; 
	Glasses
    #undef X
    bigtable.push_back(table);

    #define X(a, c) table[a] = c; 
	Dumbbells
    #undef X
    bigtable.push_back(table);

    #define X(a, c) table[a] = c; 
	Mouse
    #undef X
    bigtable.push_back(table);



    for(int i=0;i<3;i++){
        cout<<bigtable[mouse][Prototype][i];
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