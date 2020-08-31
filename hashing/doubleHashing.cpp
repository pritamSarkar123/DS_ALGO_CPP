#include<iostream>
#include<cmath>
using namespace std;
class Node{
public:
	int key;
	int value;
};
class Hashing{
private:
	int tableSize;
	int elementCount;
	int Prime;
	Node ** Table;
	int *Flags;
public:
	Hashing(int tableSize){
		this->tableSize = tableSize;
		Table = new Node*[tableSize];
		Flags=new int[tableSize];
		for(int i=0;i<tableSize;i++){ Table[i] =NULL;Flags[i] =0;}
		elementCount=0;
		Prime=getPrime(tableSize);
	}
	Hashing():Hashing(50){};
	int getPrime(int x);
	void adjustHashing();
	int hashOne(int key);
	int hashTwo(int key);
	int map_insert(int key);
	int map_search(int key);
	void hashInsert(int key,int value);
	Node *hashSearch(int key);
	void hashDelete(int key);
  void showHash();
	~Hashing(){
		int i=0;
		while(i<tableSize){
			if(Table[i]){delete Table[i]; Table[i]=NULL;}
			i++;
		}
		delete[] Table;
    delete[] Flags;
	}
};
int Hashing::getPrime(int x){
	int i=x;
	int prime;
	while(i){
		prime=1;
		for(int j=2; j<=ceil(sqrt(i)); j++){
			if(i%j==0){
				prime=0;break;
			}
		}
		if(prime) return i;
		i--;
	}
}
void Hashing::adjustHashing(){
  int oldTableSize=tableSize;
  int x,y,j;
	if(elementCount>(tableSize/2)){
    tableSize*=2;
    Prime=getPrime(tableSize);
		Node **NewTable=new Node*[tableSize];
		int * NewFlags=new int[tableSize];
		//----------------------------------------------------------------
		for(int i=0;i<oldTableSize;i++){ NewTable[i] =NULL;NewFlags[i] =0;}
    //----------------------------------------------------------
    int index;
		for(int i=0;i<oldTableSize;i++){
      if(Flags[i]!=0){
        x=hashOne(Table[i]->key);
	      y=hashTwo(Table[i]->key);
	      index=(x+0*y)%tableSize;
	      j=1;
        while(NewFlags[index]){
          index=(x+j*y)%tableSize;
          j++;
        }
        NewTable[index]=Table[i];
        NewFlags[index]=1;
        cout<<"succesfully re inserted ("<<Table[i]->key<<","<<Table[i]->value<<") at slot "<<index<<endl;
      }
		}
    
		//----------------------------------------------------------------
		int i=0;
		while(i<oldTableSize){
			Table[i]=NULL;
			i++;
		}
		delete[] Table;
		delete[] Flags;
		//----------------------------------------------------------------
		Table=NewTable;Flags=NewFlags;
		NewTable=NULL;NewFlags=NULL;
	}
}
int Hashing::hashOne(int key){
	return key%tableSize;
}
int Hashing::hashTwo(int key){
	return Prime-(key%Prime);
}
int Hashing::map_insert(int key){
	int x=hashOne(key);
	int y=hashTwo(key);
	int index=(x+0*y)%tableSize;
	int i=1;
	while(Flags[index]){
		index=(x+i*y)%tableSize;
		i++;
	}
	return index;
}
int Hashing::map_search(int key){
	int x=hashOne(key);
	int y=hashTwo(key);
  int i=0;
  int starting=1;
  int index=x%tableSize;
	while(Flags[index]){
		if(index==x%tableSize && starting==0) return -1;
		if(Table[index]->key==key) return index;
    starting=0;
    i++;
    index=(x+i*y)%tableSize;
	}
	return -1;
	
}
void Hashing::hashInsert(int key,int value){
  int index;
	if(map_search(key)!=-1){
    cout<<"key "<<key<<" already present ,So updating,As duplication not allowed"<<endl;
    index=map_search(key);
    Table[index]->value=value;
    return;
  }
  elementCount++;
	adjustHashing();
	index=map_insert(key);
	Node *temp=new Node; temp->key=key,temp->value=value;
	Flags[index]=1;
	Table[index]=temp;
  cout<<"succesfully inserted ("<<temp->key<<","<<temp->value<<")"<<endl;
}
Node* Hashing::hashSearch(int key){
	int index=map_search(key);
	if(index==-1) return NULL;
	else return Table[index];
}
void Hashing::hashDelete(int key){
	int index=map_search(key);
	if(index==-1) cout<<"Key not found"<<endl;
	else{
		cout<<"Deleting key "<<Table[index]->key<<" value "<<Table[index]->value<<endl;
		Flags[index]=0;delete Table[index];Table[index]=NULL;
		elementCount--;
	}
}
void Hashing::showHash(){
  for(int i=0;i<tableSize;i++){
    if(Table[i] && Flags[i]){
      cout<<"Slot["<<i<<"]"<<" key: "<<Table[i]->key<<" value: "<<Table[i]->value<<endl;
    }
  }
}
int main(){
	Hashing h;
	h.hashInsert(5,10);
	h.hashInsert(15,20);
	h.hashInsert(25,30);
  h.hashInsert(12,20);
  h.hashInsert(19,20);
  h.hashInsert(18,20);
  h.hashInsert(17,20);
  h.hashInsert(15,30);
  h.hashInsert(99,30);
  h.hashInsert(98,30);
  h.hashInsert(99,30);
  h.hashInsert(45,30);
  h.hashInsert(65,30);
  h.hashInsert(75,30);
  h.hashInsert(12,30);
  h.showHash();
	Node *n=NULL;
	n=h.hashSearch(5);
	if(n) cout<<"Key "<<n->key<<" Value "<<n->value<<endl;
	else cout<<"5 not found"<<endl;
	n=h.hashSearch(15);
	if(n) cout<<"Key "<<n->key<<" Value "<<n->value<<endl;
	else cout<<"15 not found"<<endl;
	n=h.hashSearch(25);
	if(n) cout<<"Key "<<n->key<<" Value "<<n->value<<endl;
	else cout<<"25 not found"<<endl;
  n=h.hashSearch(35);
	if(n) cout<<"Key "<<n->key<<" Value "<<n->value<<endl;
	else cout<<"35 not found"<<endl;
  h.hashDelete(5);
  n=h.hashSearch(5);
	if(n) cout<<"Key "<<n->key<<" Value "<<n->value<<endl;
	else cout<<"5 not found"<<endl;
  n=h.hashSearch(15);
	if(n) cout<<"Key "<<n->key<<" Value "<<n->value<<endl;
	else cout<<"15 not found"<<endl;
  h.showHash();
	return 0;
}