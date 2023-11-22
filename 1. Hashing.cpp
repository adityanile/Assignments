#include<iostream>
#include<cstring>
using namespace std;
class Employee{
public:
    string sName;
    int iEmpID;
};
class HashTable{
private:
    Employee Records[10];

public:
    HashTable(){
        for(int i=0;i<10;i++){
            Records[i].sName ="";
            Records[i].iEmpID=-1;
        }
    }
    int hashValue(int number){
        return (number%10);
    }
    void insertRecord(string name, int id){
        int index = hashValue(id);
        if(Records[index].iEmpID==-1){
            Records[index].iEmpID = id;
            Records[index].sName = name;
        }
        else{
            int iNewIndex = (index+1)%10;
            while(iNewIndex != index){
                if(Records[iNewIndex].iEmpID == -1){
                    Records[iNewIndex].iEmpID = id;
                    Records[iNewIndex].sName = name;
                    break;
                }
                iNewIndex = (iNewIndex+1)%10;
            }
        }
    }

    void displayRecord(){
        for(int i=0;i<10;i++){
            cout<< Records[i].sName<<" and id is";
            cout<< Records[i].iEmpID<<endl;
        }
    }
};
int main(){
    HashTable ht;
    ht.insertRecord("Asmita",21);
    ht.insertRecord("Kavita",37);
    ht.insertRecord("Ashwini",31);
    ht.insertRecord("Kavita2",47);
    ht.insertRecord("Kavita3",57);
    ht.insertRecord("Kavita4",67);
    ht.insertRecord("Kavita5",77);
    ht.insertRecord("Kavita6",87);

    ht.displayRecord();
    return 0;
}
