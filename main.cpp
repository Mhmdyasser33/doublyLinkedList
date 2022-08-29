#include <bits/stdc++.h>
#include<utility>
#include<vector>
#include<set>
#include<set>
#include<unordered_set>
#include<unordered_map>
#define all(s) s.begin(),s.end()
#define allr(i) i.rbegin(),i.rend()
#define sz(s) (int)(s.size())
#define ceil(x,y) ((x+y-1)/y)
#define F first
#define S second
#define pb push_back
#define pop pop_back
#define vi vector<int>
#define si set<int>
#define uns unordered_set<int>
#define pq_max priority_queue<int>
#define pq_min priorrity_queue<int,pqi,greater<int>>
#define khaled_kasmeri ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef  long long ll;
typedef long double ld;
typedef  double dd;
using namespace std;
class doubleLinkedlist{
    private :
    struct Node{
        int date ;
        Node * next ;
        Node * prev ;
        // constructor from struct
         Node(){
        next = NULL ;
        prev = NULL ;
    }

    };
    Node *head = NULL;
    public :
        void append( int val ){
        Node * newnode = new Node ;
        newnode->date = val ;
        if(head == NULL)
            head = newnode ;
        else{
            Node * temp = head ;
            while( temp->next != NULL){
               temp= temp->next ;
            }
           temp->next = newnode ;
           newnode->prev = temp ;
        }

        }
        void insert_at_pos(int val , int pos ){
            Node*newnode = new Node ;
            newnode->date = val ;
            // special case
            if ( head == NULL){
                head = newnode ;
                return ;
            }
            if( pos ==  0){
                newnode->next = head;
                 head->prev = newnode;
                head = newnode ;
                return ;
            }
            Node*temp = head ;
            for (int i = 0 ; i < pos  && temp->next !=NULL; i++)
            {
                temp = temp->next ;
            }
            if( temp == NULL){
                    this->append(val);
                return ;
            }
            newnode->prev = temp->prev ;
            temp->prev->next = newnode;
            temp->prev = newnode ;
            newnode->next = temp ;

        }
        void Remove( int val){
            if(head == NULL)
                return ;
                    Node * temp = head ;
            if(temp->date == val){

                    head = temp->next;
                    if(head !=NULL)
                    temp->prev = NULL;
                    delete temp;
            }
            while(temp!=NULL && temp->date !=val){
                temp = temp->next ;

            }
            if(temp == NULL )
                return ;
            else{
                 temp->prev->next = temp->next;
                 if(temp->next !=NULL)
                 temp->next->prev = temp->prev;
                 delete temp ;

            }



        }
        void remove_at_pos(int pos){
            if(head == NULL)
                return ;
            Node *temp = head ;
            if(pos == 0){
            head =temp->next;
            if(head !=NULL)
            temp->prev = NULL;
            delete temp;
            }
            for( int i = 0 ; i < pos && temp->next !=NULL ; i++){
                temp = temp->next ;
            }
            if( temp == NULL)
                return ;
            else{
                temp->prev->next = temp->next;
                if(temp->next != NULL)
            temp->next->prev = temp->prev ;
            delete temp;
            }

        }
        void Reverse(){
            Node * temp = head ;
            // loop to move temp from node to another
            while( temp ->next  != NULL){
                temp = temp ->next;
            }
            // another loop to print element
            while( temp != NULL){
                cout << temp->date <<" ";
                temp = temp->prev ;
            }
            cout << endl ;

        }
        void display(){
            Node * temp = head ;
            while(temp != NULL){
                cout << temp->date  << endl;
                temp = temp->next;
            }
        }




};
int main(){
    doubleLinkedlist dll ;
    dll.append(10);
     dll.append(20);
      dll.append(30);
       dll.append(40);
        dll.append(50);
         dll.append(60);
         dll.insert_at_pos(70 , 1);
         dll.Remove(60);
         dll.remove_at_pos(3);
         cout <<"values after reverse is " <<endl;
         dll.Reverse();
         cout << "values without reverse is " <<endl;
         dll.display();



}
