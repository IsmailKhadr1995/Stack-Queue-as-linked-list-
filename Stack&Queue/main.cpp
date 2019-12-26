#include <iostream>

using namespace std;
class Employee
{
    public:
   string  name;
    float salary;
    float oTime;
    int code;

    Employee *pNext;
    Employee *pPervious;
    Employee()
    {
        code = 0;
        name="no name";
        salary = oTime = 0;
        pNext=NULL;
        pPervious =NULL;
    }
    Employee(int c, char *n, float s, float o)
    {
        code = c;
        name= n ;
        salary =s ;
        oTime =o;
        pNext=NULL;
        pPervious =NULL;
    }
    // setters and getters.
    void printEmployee()
    {
        cout << code <<"  "<<name <<"  "<<endl;
    }
};

class LinkedList
{
     protected :
      Employee * pStart;
      Employee * pEnd;
     public :
      LinkedList() {pStart=pEnd=NULL;}

// Setters and getters for pStart and pEnd;
    void addList(Employee *pItem);

    Employee* searchList(int Code);
    int DeleteList(int Code);
    void freeList();
    void InsertList(Employee *pItem);
    void displayAll();
    //~LinkedList() { freeList();}
};
class Stack:private LinkedList
{
 public :
     void push (Employee *e)
     { // also add to the end of the stack and the list
        addList(e); // or LinkedList :: addList(e);

     }
     Employee * pop()
     {

         Employee * temp;
         temp=pEnd;
         if(pEnd)
         {
             cout<<1<<endl;
             if(pStart==pEnd)
             {

             cout<<2<<endl;
                 pEnd=pStart=NULL;
             }
             else
             {
                 cout<<"-------"<<endl;
                 pEnd=pEnd->pPervious;
                 pEnd->pNext=NULL;
                 temp->pPervious=NULL;

             }



         }
         return temp;

     }
     Employee* searchStack(int Code)
     {
      return searchList(Code);
     }

   int deleteStack(int Code)
   {
      return DeleteList(Code);
   }
   void freeStack()
   {
      freeList();
   }
   void display()
   {
    displayAll();
   }


};
class Queue:private LinkedList
{

public:
    void enque(Employee *pItem)
    {
        addList(pItem);
    }
    Employee * Deque()
    {
       Employee * temp=pStart;
       if(pStart)
       {
           if(pStart==pEnd)
              pStart=pEnd=NULL;
           else
           {


               pStart=pStart->pNext;
               pStart->pPervious=NULL;
               temp->pNext=NULL;
           }


       }
       return temp;

    }
    Employee* searchQueue(int Code)
     {
      return searchList(Code);
     }

   int deleteQUEUE(int Code)
   {
      return DeleteList(Code);
   }
   void freeQueue()
   {
      freeList();
   }
   void display()
   {
    displayAll();
   }



};





void LinkedList::addList(Employee *pItem)
{
    if(pStart==NULL)
    {

        pItem->pNext=NULL;
        pItem->pPervious=NULL;
        pStart=pEnd=pItem;
    }
    else
    {
        pEnd->pNext = pItem;
        pItem->pNext=NULL;
        pItem->pPervious=pEnd;
        pEnd=pItem;
    }
}
void LinkedList::displayAll()
{
   Employee * PItem;
   PItem =pStart;
   while(PItem)
   {
       PItem->printEmployee();
       PItem = PItem->pNext;
   }
}
Employee* LinkedList::searchList(int Code)
{

    Employee*p=NULL;
    p=pStart;
   while (p&&p->code!=Code)
   {
       p=p->pNext;
   }
   //cout<<p->code<<endl;
   return p;

}
void LinkedList::freeList()
{
   Employee *p;
   while(pStart)
   {
       p=pStart;
       pStart=pStart->pNext;
       delete p;
   }
   pEnd=NULL;

}
int LinkedList::DeleteList(int Code)
{
  Employee *p;
  int flag=0;
  p= searchList(Code);
  if(!p)
  {
      flag=1;
  }
  else
  {
   if(pStart==pEnd)
   {
       pStart=pEnd=NULL;
   }
   else if (p==pStart)
   {
       pStart=pStart->pNext;
       pStart->pPervious=NULL;
   }
   else if(p==pEnd)
   {
       pEnd=pEnd->pPervious;
       pEnd->pNext=NULL;


   }
   else
   {
       p->pPervious->pNext=p->pNext;
       p->pNext->pPervious=p->pPervious;

   }

     delete p;

  }
  return flag;


}
void LinkedList::InsertList(Employee *pItem)
{
    Employee *Temp;
    if(pStart==NULL)
        addList(pItem);
    else
    {
      Temp=pStart;
      while (Temp&&Temp->code<pItem->code)
            Temp=Temp->pNext;
      if(!Temp)
        addList(pItem);
      else if(pStart==pEnd)
      {
         pItem->pNext=pStart;
         pItem->pPervious=NULL;
         pStart->pPervious=pItem;

         pStart=pItem;


      }
      else
      {

            pItem->pNext=Temp;
            pItem->pPervious=Temp->pPervious;
             Temp->pPervious->pNext=pItem;
             Temp->pPervious=pItem;



      }




    }
}


int main()
{
    Employee e(1,"ahmed",2000,20);
    Employee e2(2,"ismail",2000,20);


    /*LinkedList d;
    d.addList(&e);
    Employee e2(2,"ismail",2000,20);
     d.addList(&e2);
     Employee e3(3,"yasser",2000,20);
     d.addList(&e3);
       Employee e5(5,"yasser",2000,20);
       d.InsertList(&e5);
     //d.DeleteList(2);
    //d.displayAll();

     //d.addList(e);
//    Employee *e4;
    //e4=d.searchList(1);
    //cout<<e4->name;


    //cout << "Hello world!" << endl;*/
    Stack s;
    s.push(&e);
    s.push(&e2);
    s.display();
    s.pop();
    s.display();

    /*Queue q;
    q.enque(&e);
    q.enque(&e2);
    q.display();
    q.Deque();
    q.display();*/





    return 0;
}
