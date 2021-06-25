// demoes hashmap implementation
// Mikhail Nesterenko
// 4/15/2014

#include "hashmap.h"
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main() {
   hashmap<int, int> testHash;
   auto p1 = testHash.insert(make_pair(1, 10));
   auto p2 = testHash.insert(make_pair(2, 20));
   auto p3 = testHash.insert(make_pair(3, 30));
   auto p4 = testHash.insert(make_pair(4, 40));
   auto p5 = testHash.insert(make_pair(5, 50));
   auto p6 = testHash.insert(make_pair(6, 60));

   cout << "Key: " << p1.first->first << '\n';
   cout << "Value: " << p1.first->second << '\n';
   cout << "Bool: " << p1.second << '\n';

   cout << "Key: " << p2.first->first << '\n';
   cout << "Value: " << p2.first->second << '\n';
   cout << "Bool: " << p2.second << '\n';

   cout << "\n Insert value that already exists: \n";

   auto p7 = testHash.insert(make_pair(4, 40));

   cout << "Key: " << p7.first->first << '\n';
   cout << "Value: " << p7.first->second << '\n';
   cout << "Bool: " << p7.second << "\n\n\n";

   // x will have type hashmap<int, int>::value_type*
   auto x = testHash.find(4);

   if (x != nullptr)
      cout << "Key 4 maps to: " << x->second << '\n';
   else
      cout << "Cannot find 4 in map" << '\n';
   
   auto e = testHash.erase(4);
   if(e.second){
      cout << "Successfully removed 4.\n";
      if(e.first != nullptr){
           cout << "The next element is: " << e.first->second << '\n';
      }else{
           cout << "There is no next element.\n";
      }
   }else{
         cout << "Failed to remove 4. Not in the map.\n";
   }
   
    testHash[4] = 35;
    testHash[4] = 60;

   auto x3 = testHash.find(4);
   if (x3 != nullptr)
      cout << "4 maps to " << x3->second << endl;
   else
      cout << "Cannot find 4" << endl;

    testHash.rehash(200);
   std::cout << "rehashed...\n";

}
