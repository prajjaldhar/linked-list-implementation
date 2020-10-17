//implementation of linked list using stuctures
#include<iostream>
using namespace std;
struct node{
	int data;//data storage
	struct node *link;//self referential pointer
};
node *root=NULL;//initially

int length(){
	int count=0;
	node *temp=root;
	while(temp!=NULL)
	{
		count+=1;
		temp=temp->link;
	}
	return count;
} //length of linked list
void nodeatbeg(){
	node *temp;//creating node
	temp=new node;//dynamically
	cout<<"Enter Node Data\n";
	cin>>temp->data;
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp; //putting value of temp to root
	}
	else{
		temp->link=root;//as temp->link is null& it is replaced with root value
		root=temp;//placing new element at beg
	}
  cout<<"ADDING OF ELEMENT IS SUCCESSFULLY DONE\n\n\n";
  cout<<"\n\n\n";
}
void nodeatend()
{
	node *temp,*rear;
	temp=new node;
	rear=root;//providing root address to rear
	cout<<"Enter Node Data\n";
	cin>>temp->data;
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp; //putting value of temp to root
	}
	else{
		while(rear->link!=NULL)//unless pointing to last index
		    rear=rear->link;//1.incrementing rear or moving it fwd 
		rear->link=temp;//2.placing new node at end
	}
  cout<<"ADDITION OF ELEMENT IS SUCCESSFULLY DONE\n\n\n";
  cout<<"\n\n\n";
}
void display()
{
	node *temp=root;
	if(root==NULL)
	{
		cout<<"NO ELEMENTS PRESENT\n\n\n";
	}
	else{
		cout<<"\nRoot";
	    while(temp!=NULL)//unless temp is pointing the last element
		{
	     cout<<"->"<<temp->data;//printing data
	     temp=temp->link;//moving fwd the pointer
      	}
    cout<<"\n\n\n";
}
}
void addafter()
{   
    int loc,len,i=1;
	node *temp,*front;
	cout<<"ENTER THE LOCATION WHERE YOU WANT TO INSERT NEW ELEMENT\n";
	cin>>loc;
	len=length();//calling the length function
	if(loc>len)
	{
		cout<<"INVALID LOCATION,LOCATION OUT OF INDEX\n";
		cout<<"CURRENTLY LIST IS HAVING"<<len<<"NUMBER OF NODES\n\n\n";
	}
	else{
	front=root;//providing root value to front
    temp=new node;
	cout<<"Enter Node Data\n";
	cin>>temp->data;
	temp->link=NULL;
		while(i<loc)//loop will continue till it reaches the given loc
		{
			front=front->link;
			i++;//moving fwd the front till the exact loc
		}
		 temp->link=front->link;//the new node is provided with the next node add
		 front->link=temp;//front will now point temp
	 cout<<"ADDING ELEMENT IN[" <<loc<<"]LOCATION IS SUCCESFULLY DONE\n\n\n";
	}
	
}
void deletionatbeg()
{   
    node *temp;//taking one temporary variable
	if(root==NULL)
	cout<<"LINKED LIST IS EMPTY\n\n\n";
	else
	{  
	  temp=root;//assigning root value to temp
	  root=temp->link;//temp is pointing 1st index so assigning temp value to root
	  delete temp;//alas deleting temp which has previous root value
	}
  cout<<"\nDELETION SUCCESSFULLY DONE\n";
  cout<<"\n\n\n";
}
void deletingfromend()
{ 
    if(root==NULL)
    cout<<"NO ELEMENTS PRESENT DELETING NULL\n\n\n";
   else if(root->link==NULL)
     { 
        root=NULL;
        delete root;
        cout<<"ROOT DELETED SUCCESSFULY DONE\n\n\n";     
	 }
    else{
	node *secondlast;
	secondlast=root;
	while(secondlast->link->link!=NULL)
	{
		secondlast=secondlast->link;
	}
     node *temp= secondlast->link;
     secondlast->link=NULL;
     delete temp;
     cout<<"\nDELETION SUCCESSFULY DONE\n\n\n";
     cout<<"\n\n\n";
}
}
void reverselistelements(){
	int i,j,len,k,temp;
	len=length();
	i=0;j=len-1;
	node *p,*q;
	p=q=root;
	while(i<j)
	{
		k=0;//this is done to make j pointing to the last index
		while(k<j)//unless pointing to last location
		{
			q=q->link;//q will always starts from root and we are reaching the ending index through q
			k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		i++;
		j--;//this will effect in while loop to run (len-1) times
		p=p->link;//p will move forward
		q=root;//as there is no opt for reverse traversing
	}
	cout<<"REVERSE OF LIST ELEMENTS IS SUCCESSFULLY DONE\n\n\n";
}
int addallelements()
{
	int sum=0;
	node *p=root;
	while(p)
	{
		sum=sum+p->data;
		p=p->link;
	}
	return sum;
}
int maximum()
{
	node *p=root;
	int m=-32768;
	if(root==NULL){
	cout<<"LIST IS EMPTY\n";
	return NULL;
    }
	else{
	 while(p)
	 {
		if(p->data>m)
			m=p->data;
	   p=p->link;
	 }
 }return m;
}
int minimum()
{
	node *p=root;
	int m=32768;
	if(root==NULL){
	cout<<"LIST IS EMPTY\n\n";
	return NULL;
    }
	else{
	 while(p)
	 {
		if(p->data<m)
			m=p->data;
	   p=p->link;
	 }
 }return m;
}
void search(int key)
{  
    int flag=0;
	node *p=root;
	if(root==NULL)
	cout<<"LIST IS EMPTY\n\n";
	else{
	 while(p)
	 {
		if(key==p->data){
		 flag+=1;
		 break;}
	  p=p->link;
     }   
}
if(flag==1)
cout<<"FOUND!!!\n\n\n";
else
cout<<"NOT FOUND!!!\n\n\n";
}
void reverselinks(){//uisng sliding operations
	node *p=root;//p pointing to 1st node
	node *q=NULL;
	node *r=NULL;
	while(p!=NULL)
	{
		r=q;//where q previously was
		q=p;// where r previously was
		p=p->link;//moving ahead the p
		q->link=r;//as q is middle pointer so changing links is done through q
	}
	root=q;//alas root is now the last node ie.pointed by q as p becomes null
    cout<<"\nLINKS ARE NOW REVERSED SUCUSSESFULLY\n\n\n";
}
int checksort()
{
	int x=-32768,flag=0;//min integer value
	node *p=root;
	while(p)
	{
		if(p->data<x)
		     flag=0;//sorted
	    x=p->data;
	    p=p->link;
	    flag=flag+1;//not sorted
	}
	return flag;
}
void sortlist()
{ 
	int n=length();
	for(int i=0;i<n-1;i++)
	{ 
	    node *prev=NULL; //we will use it later
		node *current=root;//assigning root value to current pointer
		node *temp;
		//this will be our head pointer
		while(current!=NULL && current->link!=NULL)//checking cond whether current is not pointing null or current itslef is null
		{
			if(current->data > current->link->data)//checking whether value of current is greater than next node 
			{
				if(prev==NULL)//at that time is prev is null ie.the 1st iterations
				{
					temp=current->link;//placing temp next to current or making it head pointer
					current->link=temp->link;//making jump cuurent value to next to the next of head pointer
					temp->link=current;//placing current value to temp->link such that it will come fwd as it is less than cuurent value
					root=prev=temp;// moving prev and fixing root
				}
				else//this will work when if fails ie prev is not null
				{ 
				  	temp=current->link;//moving temp fwd to current 
				  	prev->link=temp;//as prev has some value so prev will point the lesser linked
					current->link=temp->link;//current which has higher value will be shifted rhs
					temp->link=current;//lesser value will link will now point higher value ie.link is sorted
					prev=temp;//prev link will be what temp was before ie the lesser value node
				}
			}
			else{ //if it was sorted 
					temp=current->link;//just move temp ahead
					prev=current;//change prev to what current was before
					current=temp;//change current was temp was before
			}
			}
		}
	cout<<"SORTING IS SUCCESSFULY DONE\n\n\n";
}
void duplicates()
{
		node *p=root;
		node *q=p->link;//head pointer
		int ch,flag;
		char d;
		cout<<"PLEASE MAKE SURE THAT LINKED LIST IS SORTED!!!\n";
		cout<<"PRESS [Y] TO CONTINUE OTHERWISE ANY OTHER KEY TO EXIT:-"<<"\t";
		cin>>d;
		if(d=='Y' || d=='y')
		flag=checksort();
		else
		   exit(1);
		if(flag==1)
	   {
	    	cout<<"LIST IS NOT SORTED!!! PRESS KEY=[14] TO SORT THE LIST\n";
			cin>>ch;
			if(ch==14)
				sortlist();
		  while(p->link!=NULL && q!=NULL)
			{
				if(p->data != q->data)
				{
					p=q;//moving ahead p using q;
					q=q->link;//moving q value
				}
				else{
					p->link=q->link;//step jump in p
					delete q;//deleting the duplicate where q points
					q=p->link;//aheading q agian(head pointer)
				}
			}
		cout<<"DELETING THE DUPLICATE IS SUCCESSFULLY DONE\n\n\n";
		}
	    else
	  {
		while(p->link!=NULL && q!=NULL)
		{
			if(p->data != q->data)
			{
				p=q;//moving ahead p using q;
				q=q->link;//moving q value
			}
			else{
				p->link=q->link;//step jump in p
				delete q;//deleting the duplicate where q points
				q=p->link;//aheading q agian(head pointer)
			}
		}
	 cout<<"DELETING THE DUPLICATE IS SUCCESSFULLY DONE\n\n\n";
	 }
}
int middle()
{ 
    int len,i=0;
	node *p,*q;
	p=root;
	q=root;
	len=length();
	if(len%2!=0)//odd number of length
	{
	while(q->link!=NULL && q!=NULL)
	{
		p=p->link;
		q=q->link->link;
	}
	return p->data;
	}
	else
	{   len=length()/2;
		while(i<len)//for even length
		{
			p=p->link;
			i++;
		}
		return p->data;
	}
}
void nodeswap()
{
	int loc,len,i=1;
	node *q,*r;
	node *front=root;
	cout<<"ENTER THE LOCATION WHERE YOU WANT TO SWAP THE ADJACENTS\n";
	cin>>loc;
	len=length();//calling the length function
	if(loc>=len || loc< 0 || loc==len-1)
	{
		cout<<"INVALID LOCATION,LOCATION OUT OF INDEXING\n";
		cout<<"CURRENTLY LIST IS HAVING"<<len<<"NUMBER OF NODES\n\n\n";
	}
	else{
		while(i<loc)//loop will continue till it reaches the given loc
		{
			front=front->link;
			i++;//moving fwd the front till the exact loc
		}
	q=front->link;//where front is now pointing making it head pointer
	r=q->link;//making it next to head
	q->link=r->link;//
	r->link=q;
	front->link=r;//swap prgm
    cout<<"ADJACENT NODE SWAPPING IS DONE\n\n\n";
}
}
int main()
{   int d,len,sum,max,min,data,flag,m;
	while(1){
		cout<<"******************SINGLE LINKED LIST OPERATIONS PERFORMING*****************\n";
		cout<<"1.ADD AT BEG\n";
		cout<<"2.LENGTH\n";
		cout<<"3.DISPLAY\n";
		cout<<"4.ADD AT END\n";
		cout<<"5.ADDING AT PARTICULAR LOCATION\n";
		cout<<"6.DELETION FROM BEG\n";
		cout<<"7.DELETION FROM END\n";
		cout<<"8.REVERSE THE ELEMENT ORDER OF LINKED LIST\n";
		cout<<"9.ADD ALL ELEMENTS\n";
	    cout<<"10.FIND MAXIMUM ELEMENT\n";
		cout<<"11.FIND MINIMUM ELEMENT\n";
		cout<<"12.SEARCH ELEMENT\n";
		cout<<"13.REVERSE THE LINK OF LINKED LIST\n";
		cout<<"14.CHECK WHETHER THE LINKED LIST IS SORTED\n";
		cout<<"15.SORT THE LINKED LIST\n";
		cout<<"16.REMOVE THE DUPLICATES\n";
		cout<<"17.FIND THE MIDDLE ELEMENT OF LINKED LIST\n";
        cout<<"18.SWAP ADJACENT NODES\n";	
		cout<<"19.TO STOP\n";
		cout<<"PLEASE ENTER YOUR CHOICE TO PROCEED FURTHER\n";
		cin>>d;
		switch(d){
			case 1:nodeatbeg();
			       break;
			case 2:len=length();
			       cout<<"THE LENTH OF LINKED LIST IS:["<<len<<"]\n\n\n";
			       break;
			case 3:display();
			       break;
			case 4:nodeatend();
			       break;
			case 5:addafter();
			       break;
			case 6:deletionatbeg();
			       break;
			case 7:deletingfromend();
			       break;
		    case 8:reverselistelements();
			       break;
			case 9:sum=addallelements();
			       cout<<"SUM OF ALL ELEMENTS IS:["<<sum<<"]\n\n\n"; 
				   break; 
			case 10:max=maximum();
			        cout<<"MAXIMUM ELEMENT PRESENT IN LINKED LIST IS:["<<max<<"]\n\n\n";
			        break;
			case 11:min=minimum();
			        cout<<"MINIMUM ELEMENT PRESENT IN LINKED LIST IS:["<<min<<"]\n\n\n";
			        break;
			case 12:cout<<"ENTER ELEMENT TO BE SEARCHED\n";
			        cin>>data;
			        search(data);
			        break;
		    case 13:reverselinks();
		            break;
		    case 14:flag=checksort();
		            	if(flag==1)
							 cout<<"LIST IS NOT SORTED\n\n\n";
						else
							cout<<"LIST IS SORTED\n\n\n";
		            break;
		    case 15:sortlist();
		            break;
		    case 16:duplicates();
		            break;
		    case 17:m=middle();
                    cout<<"MIDDLE ELEMENT OF LINKED LIST IS["<<m<<"]\n\n\n";
		            break;
		    case 18:nodeswap();
		            break;
		    case 19:exit(1);	
			default:cout<<"INVALID OPTION THANKS FOR OPTING US\n\n";}
		
	}
}

