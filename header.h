//header for STRING

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class STRING
{
	char *ptr;
	public:

 void getdata()
 {
	 //cout<<"\ngetdata call"<<endl;
	 cout<<ptr<<endl;
 }
	//default constructor
	STRING(){
	//	cout<<"\n default const. call"<<endl;
		ptr=NULL;
	}

	//destructor
	~STRING(){
	//	cout<<"\n dest. call"<<endl;
		if(ptr!=0)
			delete[]ptr;
	}

	//parameterised  constructor
	STRING(const char*s){
	 //	cout<<"\nparameterised const. call"<<endl;
		ptr=new char[strlen(s)+1];
		strcpy(ptr,s);
	}
	
	//copy constructor
	STRING(STRING &temp){
	 //	cout<<"\ncopy const. call"<<endl;
		ptr=new char[strlen(temp.ptr)+1];
		strcpy(ptr,temp.ptr);
	}

	//assignment operator overloading
	STRING operator=(const STRING &temp)
	{
		if(ptr!=NULL)
			delete []ptr;
	//	cout<<"\nassignment op call"<<endl;
		ptr=new char[strlen(temp.ptr)+1];
		strcpy(ptr,temp.ptr);
		return *this;
	}

	//+operator overloading
	STRING operator+(const STRING &temp)
	{
	//	cout<<"+ operator overloading"<<endl;
		STRING ret;
		ret.ptr=new char[strlen(ptr)+strlen(temp.ptr)+1];
		strcpy(ret.ptr,ptr);
		strcpy(ret.ptr+strlen(ptr),temp.ptr);
		return ret;
	}

	//> operator overloading
	bool operator>(const STRING &temp)
	{
		if(strcmp(ptr,temp.ptr)>=1)
			return true;
		else
			return false;
	}
	// < operator overloading
	bool operator<(const STRING &temp)
	{
		if(strcmp(ptr,temp.ptr)<0)
			return true;
		else
			return false;
	}
	// == operator overloading
	bool operator==(const STRING &temp)
	{
		if(strcmp(ptr,temp.ptr)==0)
			return true;
		else
			return false;
	}
	// != operator overloading
	bool operator!=(const STRING &temp)
	{
		if(strcmp(ptr,temp.ptr))
			return true;
		else
			return false;
	}
	// <= operator overloading
	bool operator<=(const STRING &temp)
	{
		if(strcmp(ptr,temp.ptr)<=0)
			return true;
		else
			return false;
	}
	// >= operator overloading
	bool operator>=(const STRING &temp)
	{
		if(strcmp(ptr,temp.ptr)>=0)
			return true;
		else
			return false;
	}
	//[] operator overloading
	char operator[](const int &i)
	{
		return ptr[i];
	}


	friend ostream & operator<<(ostream &,const STRING &);
	friend istream & operator>>(istream &,STRING &);
	friend STRING MYSTRCPY(STRING &,const STRING &);
	friend int MYSTRCMP(const STRING &,const STRING &);
	friend STRING MYSTRCAT(STRING &,const STRING &);
	friend char* MYSTRCHR(const STRING &,char);
	friend char* MYSTRRCHR(const STRING &,char);
	friend int MYSTRLEN(const STRING &);
	friend char* MYSTRSTR(const STRING &,const  STRING &);
	friend STRING MYSTRREV(STRING &);
	friend STRING MYSTRUPR(STRING &);
	friend STRING MYSTRLWR(STRING &);
};

	//extraction << operator
	ostream & operator<<(ostream &out,const STRING &temp)
	{
		//out<<"<< overloading"<<endl;
		out<<temp.ptr;
		return out;
	}

	//insertion operator
	istream & operator>>(istream &in,STRING &temp)
	{
		//cout<<">> overloading"<<endl;
		char c[512];
		in>>c;
		temp.ptr=new char[strlen(c)+1];
		strcpy(temp.ptr,c);
		return in;
	}
	
//strcpy
STRING MYSTRCPY(STRING &dest,const STRING &src)
{
	cout<<"strcpy call"<<endl;
	strcpy(dest.ptr,src.ptr);
	return dest;
}

//strcmp
int MYSTRCMP(const STRING &dest,const STRING &src)
{
	if(strcmp(dest.ptr,src.ptr)==1)
		return 1;
	else if(strcmp(dest.ptr,src.ptr)==0)
		return 0;
	else return -1;
}
//concatenation
STRING MYSTRCAT(STRING &dest,const STRING &src)
{
	strcat(dest.ptr,src.ptr);
	return dest;
}
//strchr
char* MYSTRCHR(const STRING &src,char c)
{
	char *p;
	p=strchr(src.ptr,c);
	return p;
}
//strrchr

char* MYSTRRCHR(const STRING &src,char c)
{
	char *p;
	p=strrchr(src.ptr,c);
	return p;
}
//strlen
int MYSTRLEN(const STRING &src)
{
	return strlen(src.ptr);
}
//strstr
char* MYSTRSTR(const STRING &src,const  STRING &ss)
{
	char *p;
	p=strstr(src.ptr,ss.ptr);
	return p;
}
//strrev
STRING MYSTRREV(STRING &src)
{
	char *p,*q,ch;
	q=src.ptr;
	
	p=src.ptr+strlen(src.ptr)-1;
	while(q<p)
	{
		ch=*q;
		*q=*p;
		*p=ch;
		p--;
		q++;
	}
	return src;
}
//upper
STRING MYSTRUPR(STRING &src)
{
	char *p;
	p=src.ptr;
	while(*p)
	{
		*p=*p&~' ';
		p++;
	}
	return src;
}

STRING MYSTRLWR(STRING &src)
{
	char *p;
	p=src.ptr;
	while(*p)
	{
		*p=*p|' ';
		p++;
	}
	return src;
}
