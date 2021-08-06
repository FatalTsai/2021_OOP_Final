#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Test
{
   unsigned int Value;

   Test( unsigned int v ) : Value( v )
   {
   }

    int getval(){
        return Value;
    }
};

struct TestComparator
{
   bool operator()(  Test& t, unsigned int Value ) const
   {
      return t.getval() < Value;
   }

//    bool operator()( unsigned int Value, const Test& t ) const
//    {
//       // Why not return t.Value < Value ?
//       return Value < t.Value;
//    }
};

int main()
{
   vector<Test> v;

   for( unsigned int uiIndex = 0; uiIndex < 10; ++uiIndex )
   {
      v.push_back( Test( uiIndex ) );
   }
//    vector<Test>::iterator b = lower_bound( v.begin(), v.end(), 5, TestComparator() );
   vector<Test>::iterator e = lower_bound( v.begin(), v.end(), 1, TestComparator() );
   e != v.end()
        ? cout <<  " at index " << distance(v.begin(), e)
        : cout << "not found";
    cout<<endl;
}

//https://forums.codeguru.com/showthread.php?466650-RESOLVED-lower_bound-upper_bound-comparison-function-objects