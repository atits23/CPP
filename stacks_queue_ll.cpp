#include<bits/stdc++.h>
using namespace std;
struct node{
    public:
    int data;
    node* next;
    public:
    node(int data1,node* next1){
        data=data1;
        next=next1;
    }
    
    public:
    node(int data2){
        data=data2;
        next=nullptr;
    }
};
node* pop(node* start,int*size){
    if(start==nullptr){
        cout<<"Nothing to delete";
        return nullptr;
    }
    else{
        node* temp=start;
        start=start->next;
        delete(temp);
        *size=*size-1;
        return start;
    }
}
void top(node* start){
    if(start==nullptr){
        cout<<"No element to display";
    }
    else{
        cout<<"The value is:-"<<start->data;
    }
}
node* push(int data,node *start,int*size){
node* temp=new node(data);
temp->next=start;
start=temp;
*size=*size+1;
return start;
}
void sizes(int*size){
     cout<<"The current number of elements is"<<*size;
}
int main(){
    node* start=nullptr;
    int size=0;;
    int n;
    cout<<"Enter the entries";
    cin >> n;
    cin.ignore(); // Clear input buffer

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        if (s == "pop()") {
            start=pop(start,&size);
        } else if (s == "top()") {
            top(start);

        } else if (s == "size()") {
            sizes(&size);
        } else if (s.substr(0, 5) == "push(" && s.back() == ')') {
            // Extract number from push(x)
            string num_str = s.substr(5, s.size() - 6); // Extract content inside push(...)
            int val = stoi(num_str);
            start=push(val,start,&size);
        } else {
            cout << "Invalid command\n";
        }
    }

    return 0;
}
//for using stack from queue data structure only change push function for whole queue size just put what was there into front q.push_back(q.top()) and then q.pop()
//for using queue from stack remeber s1 to s2 and then  x to s1 and s2 to s1