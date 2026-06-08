#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
struct node{
	string name;
	bool isfile;
	vector<node*>children;
};
void searching(node *root);
node *search(node *root,string name){
	if(root==NULL){
		return nullptr;
	}
	if(root->name==name){
		return root;
	}
	for(node *ls:root->children){
		node *result=search(ls,name);
		if(result->name==name){
			return result;
		}
	}
  return nullptr;
}
void searching(node *root){
	int choice=0;
	do{
		string name="";
		cout<<"1.file to search"<<endl;
		cout<<"2.folder to search"<<endl;
		cout<<"3.exit"<<endl;
		cin>>choice;
		if(choice==1){
                         cout<<"enter the filename to search"<<endl;
			 cin.ignore();
			 getline(cin,name);
			 node *result=search(root,name);
		/*	 for(auto it=root->children.begin();it!=root->children.end();it++){
				 if((*it)->name==name){
					 cout<<"file name is "<<":"<<(*it)->name<<endl;
					 break;
			 }
		}*/
			 cout<<"your file name is "<<endl;
			 cout<<result->name<<endl;
}
else if(choice==2){
	cout<<"enter the foldername to search"<<endl;
	cin.ignore();
	getline(cin,name);
	node *result=search(root,name);
/*	for(auto it=root->children.begin();it!=root->children.end();it++){
		if((*it)->name==name){
			cout<<"folder name is "<<":"<<(*it)->name<<endl;
			break;
		}
	}*/
	cout<<"your foldername is "<<endl;
	cout<<result->name<<endl;
}
}while(choice!=3);
}
void display(node *root);
void (*func)();
struct node *root=new node();
void (*funcptr)(node *);
void addfile();
void addfolder();
void deletefunc(node *root){
int choice=0;
string name="";
do{
	cout<<"1.delete the file"<<endl;
	cout<<"2.delete the folder"<<endl;
	cout<<"3.display"<<endl;
	cout<<"4.exit"<<endl;
	cout<<"enter the choice"<<endl;
	cin>>choice;
	if(choice==1){
		cout<<"enter the file name to delete"<<endl;
		cin.ignore();
		getline(cin,name);
                        for(node *ls:root->children){
		for(auto it=root->children.begin();it!=root->children.end();it++){
			if((*it)->name==name){
				cout<<"the file name "<<(*it)->name<<endl;
				root->children.erase(it);
				break;
		}
	}
	}
	}
	else if(choice==2){
	cout<<"enter the folder name to delete"<<endl;
	cin.ignore();
	getline(cin,name);
		for(node *ls:root->children){
	for(auto it=root->children.begin();it!=root->children.end();it++){
		if((*it)->name==name){
			cout<<"the folder name"<<(*it)->name<<endl;
			root->children.erase(it);
			break;
	}
	}
	}
	}
	else if(choice==3){
		cout<<"displaying"<<endl;
		funcptr=display;
		funcptr(root);
	}
}while(choice!=4);
}
void display(node *root){
	if(root->isfile==true){
		cout<<"|__"<<root->name<<endl;
	}
	else{
	cout<<root->name<<endl;
	}
	for(node *ls :root->children){
		display(ls);
	}
}
node *file(string name){
	struct node *newnode=new node();
	newnode->name=name;
	newnode->isfile=true;
	return newnode;
}
node *folder(string name){
	struct node*newnode=new node();
	newnode->name=name;
	newnode->isfile=false;
	return newnode;
}
void addfile(){
	int choice;
	string name;
	do{
	cout<<"1.create file in root"<<endl;
	cout<<"2.create file in folder"<<endl;
	cout<<"3.exit"<<endl;
	cin>>choice;
        if(choice==1){
	  	cout<<"enter the file name"<<endl;
		cin.ignore();
		getline(cin,name);
		node *files=file(name);
		files->isfile=true;
			root->children.push_back(files);
	}
	else if(choice==2){
		cout<<"enter the folder name to find"<<endl;
		cin>>name;
		for(node *child: root->children){
			if(name==child->name){
				cout<<"here is your folder name"<<endl;
				cout<<child->name<<endl;
				cout<<"enter the file name"<<endl;
				string filename;
				cin.ignore();
				getline(cin,filename);
				node *newnfile=file(filename);
				newnfile->isfile=true;
				child->children.push_back(newnfile);
				break;
			}
		}
}
}while(choice!=3);
}
void addfolder(){
	int choice;
	string name;
	do{
		cout<<"1.create folder in root"<<endl;
		cout<<"2.create folder in another folder"<<endl;
		cout<<"3.exit"<<endl;
		cin>>choice;
		if(choice==1){
			cout<<"enter the folder name"<<endl;
			cin.ignore();
			getline(cin,name);
			node *folders=folder(name);
			folders->isfile=false;
			root->children.push_back(folders);
		}
		else if(choice==2){
			cout<<"enter the folder name"<<endl;
			cin>>name;
			for(node *child:root->children){
				if(name==child->name){
					cout<<"here is your foldername"<<endl;
					cout<<child->name<<endl;
					string foldername;
					cout<<"enter the folder name"<<endl;
					cin.ignore();
					getline(cin,foldername);
					node *folderss=folder(foldername);
					folderss->isfile=false;
                                    child->children.push_back(folderss);
				    break;
			}
		}

	}
	}while(choice!=3);
}
int main(){
	root->name="root";
	root->isfile=false;
	int choice;
	do{
		cout<<"1.create folder"<<endl;
		cout<<"2.create file"<<endl;
		cout<<"3.display"<<endl;
		cout<<"4.delete file or folder"<<endl;
		cout<<"5.search the file or folder"<<endl;
		cout<<"6.exit"<<endl;
		cin>>choice;
		if(choice==1){
			func=addfolder;
			func();
		}
		else if(choice==2){
			func=addfile;
			func();
		}
		else if(choice==3){
		funcptr=display;
		funcptr(root);
	}
		else if(choice==4){
			funcptr=deletefunc;
			funcptr(root);
		}
		else if(choice==5){
			funcptr=searching;
			funcptr(root);
		}
		}while(choice!=6);
	return 0;
}
	/*
	struct node *root=new node();
	root->name="root";
	root->isfile=false;
	struct node *games=new node();
	games->name="games";
	games->isfile=false;
	root->children.push_back(games);
	//so 
	struct node *photos=new node();
	photos->name="photos";
	photos->isfile=false;
	root->children.push_back(photos);
	struct node *gta=new node();
	gta->name="gta.exe";
	gta->isfile=true;
	games->children.push_back(gta);
cout<<root->nam
	for(node *child :root->children){
		cout<<child->name<<endl;
	}
	*/


