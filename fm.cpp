#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
struct node{
	string name;
	bool isfile;
	vector<node*>children;
};
struct node *root=new node();
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
		cin>>name;
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
				cin>>filename;
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
			cin>>name;
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
					cin>>foldername;
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
		cout<<"4.exit"<<endl;
		cin>>choice;
		if(choice==1){
			addfolder();
		}
		else if(choice==2){
			addfile();
		}
		else if(choice==3){
		display(root);
	}
		}while(choice!=4);
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
cout<<root->name;
	for(node *child :root->children){
		cout<<child->name<<endl;
	}
	*/

 

