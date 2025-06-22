#include <bits/stdc++.h>
using namespace std;
void print(){
    cout<<"Good Morning!! Atit"<<endl;
}

void explainPair(){
    pair<int,int>p={1,3}; //it is also basically a data type
    cout<<p.first<<" "<<p.second;
    pair<int,pair<int,int>>p1={1,{1,3}};
    cout<<p1.first<<" "<<p1.second.first<<p1.second.second;
    pair<int,int>arr[]={{1,3},{2,4}};
    cout<<arr[1].second;
}

void explainVector(){
    vector<int> v; // vector is basically dynamic in nature whose size can be increased or decreased.
    v.push_back(1);
    v.emplace_back(2);
    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,5);
    vector<int> v1(5,100);
    vector<int>v2(v1); // copies v1 into v2
    vector<int>v3(5); // create a vector of size 5 initially but lator on it can be explaned as per need ysing push back and emplace back
    cout<<v[0]<<endl;
    //how to use iterator
    vector<int>::iterator it=v.begin(); //iterator basically points to memeory
    it++;
    cout<<*(it)<<" ";
    vector<int> :: iterator it=v.end(); // points to memory location after last element
    cout<<v.back()<<" "; //gives last element of the vector

 // Printing a vector 
    for(vector <int>:: iterator it=v.begin(); it!=v.end();it++){
          cout<<*(it)<<" ";
    }
 // auto automatically asigns data type
    for (auto it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }
    
    for (auto it:v){
        cout<<it<<" ";
    }

 // erase functions in vecor
v.erase(v.begin()+1);
v.erase(v.begin()+1,v.begin()+4); // end is after the element to be deleted 

//Insert function
vector<int> v1(5,100);
v.insert(v.begin(),5);
v.insert(v.begin()+1,2,5);
vector<int> copy(5,100);
v.insert(v.begin(),copy.begin(),copy.end());
 
 
cout<<v.size();
v.pop_back(); // removes a element from end
v1.swap(v); // swaps two vectors
v.clear(); // makes a vector empty
v.empty();
}


void explainList(){
    list <int> ls;
    ls.push_back(1);
    ls.emplace_back(4);
    ls.push_front(5);
    ls.emplace_front(1); // {1,5,1,4}
    //rest function same as vector
    //begin,end,rbegin,clear,insert,size,swap

    //List is application of doubly linked list whereas Vector is application of Singly linked list
}

void explainDeque(){
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(4);
    dq.push_front(5);
    dq.emplace_front(6);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();
     //rest functions are same as vector
     //begin,end,clear,insert,size,swap,rbegin
}

void explainStack(){
    stack<int> s; //Last in First Out
    s.push(1);
    s.push(2);
    s.emplace(3); // {3,2,1}
    cout<<s.top()<<" "; // prints 3 and indexing is not there
    s.pop(); //delete 3
    cout<<s.size();
    cout<<s.empty(); //it will print False as stack is not empty

    stack<int> s1;
    s1.swap(s);  //O(1) time required for every operation
}


void explainQueue(){
    queue<int> q; //First in First Out
    q.push(1);
    q.push(2);
    q.emplace(3); //{1,2,3}
    q.back()+=5; // {1,2,8}
    cout<<q.back()<<" ";//prints 8
    cout<<q.front()<<" "; //prints 1
    q.pop(); //{2.9}
    cout<<q.front();
 // O(1) time for every operation
}

void explainPQ(){
    priority_queue<int> pq; //Largest element always remain at top
    pq.push(2); // push happens in logn
    pq.emplace(3); //{2,3}
    pq.top(); //happens in O(1)
    pq.pop(); // happens in logn
    
    cout<<pq.top()<<" ";

    //Minimum heap
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(5);
    pq.emplace(2); // {5,2} smaller element remain at top

    cout<<pq.top(); //prints 2(smallest)
    
}

void explainSets(){
    set<int>st; //stores only unique element in sorted order
    st.insert(1);
    st.insert(5);
    st.insert(1); // {1,5}

    auto it=st.find(1); //returns a address pointing to 1
    auto ir=st.find(6); //points to element after end 
    st.erase(5);

    int cnt=st.count(5); //will always be one or zero
    st.erase(it);

    auto it=st.lower_bound(1); //similarly upper bound

}

void explainMultiSets(){
    multiset<int> ms; //Only obey sorted but can have duplicate elements
    ms.insert(1);
    ms.insert(1);
    ms.erase(1); // all 1 erased 
    ms.erase(ms.find(2)); // erase only that portion
     // rest all function same as set
}

void UnSet(){
    unordered_set<int> st; //O(1) and stores elements in random order but only unique elements
    //lower and upperbound not works
}

void Map(){
    map<int,int> mpp; //stores in stored value of key and keys are unique
    map<pair<int,int>,int> pp;

    mpp[1]=2;  //here 1 is key mapped with 2 [{1,2}]
    // mpp.emplace({3,1});
    mpp.insert({2,4});
    pp[{2,3}]=10;

    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    } 

    cout<<mpp[1];
    cout<<mpp[5]; // 0

    auto it=mpp.find(1);
    // cout<<*(it).first;
    //O(logn)

}

void MutiMap(){
    //everything same as map,only it can store multiple keys
    // only mpp[key] cannot be used here
    //sorted order
}

void UnorderedMap(){
    //same as set and unoreded set difference
    //O(1) worst O(N)
}

bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;

    if(p1.first>p2.first) return true;
    return false;
}

void explainExtra(){
    int a[10]={1,2,5};
    int n=2;
    vector<int>v(5,100);
    sort(a,a+n); // [start,end)
    sort(v.begin(),v.end());
    sort(a+2,a+4);
    sort(a,a+n,greater<int>);//sorts in desending order

    pair<int,int> a[]={{1,2},{2,4}};
    // sort it according to second element
    // if second element is same,then sort
    //if same,sort it according to fist but in sescending order

    sort(a,a+n,comp); // comp is built comparator
    int num=7;
    int cnt=__builtin_popcount(); //count number in binary of 7
    long long num=172829;
    int cnt=__builtin_popcountll();

    string s="123";
    sort(s.begin(),s.end());
     do{
        cout<<s<<endl;
     }while(next_permutation(s.begin(),s.end()));

    int maxi=*max_element(a,a+n); 

}


 int main(){
 print();
 int x;
 cin>>x;
 cout<<x;

 return 0;
 }
