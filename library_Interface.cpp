#include <iostream>
#include <cassert>
#include <string>
#include <stdexcept>

#include "Lib.h"
using namespace std;

static library* p_lib = nullptr;
typedef int ret_t;

struct temp_book{
    std::string p_book_name;
    std::string author_name;
    std::string subject;
    int book_id;
}temp_book_obj;

void Add_book()
{
    if(p_lib == nullptr){
        cout<<"First create the library:" <<endl;
        return ;
    }
    cout<<"please do not give spaces between name else use underscore "<<endl;
    cout<<"Please Enter book Name :" <<endl;
    cin>>temp_book_obj.p_book_name;
    cout<<"Please Enter author name :" <<endl;
    cin>>temp_book_obj.author_name;
    cout<<"Please Enter Subject Name :" <<endl;
    cin>>temp_book_obj.subject;
    cout<<"Please Enter book id :" <<endl;
    cin>>temp_book_obj.book_id;
    
    /*Add book*/
    ret_t ret = p_lib->insert_end(temp_book_obj.p_book_name, temp_book_obj.author_name, temp_book_obj.subject , temp_book_obj.book_id);
    if(ret == SUCCESS) 
    {    
        cout<<"Book Added Successfully..." <<endl;
    }
    else{
        cout<<"Book not addedd Sucessfully.." <<endl; 
    }

}

void Add_book_to_last()
{
    if(p_lib == nullptr){
        cout<<"First create the library:" <<endl;
        return ;
        }
    cout<<"please do not give spaces between name else use underscore "<<endl;
    cout<<"Please Enter book Name :" <<endl;
    cin>>temp_book_obj.p_book_name;
    cout<<"Please Enter author name :" <<endl;
    cin>>temp_book_obj.author_name;
    cout<<"Please Enter Subject Name :" <<endl;
    cin>>temp_book_obj.subject;
    cout<<"Please Enter book id :" <<endl;
    cin>>temp_book_obj.book_id;
    
    /*Add book*/
    ret_t ret = p_lib->insert_end(temp_book_obj.p_book_name, temp_book_obj.author_name, temp_book_obj.subject , temp_book_obj.book_id);
    if(ret == SUCCESS) 
    {    
        cout<<"Book Added Successfully..." <<endl;
    }
    else{
        cout<<"Book not addedd Sucessfully.." <<endl; 
    }
}
void Add_book_to_First()
{
    if(p_lib == nullptr){
        cout<<"First create the library:" <<endl;
        return ;
        }
    cout<<"please do not give spaces between name else use underscore "<<endl;
    cout<<"Please Enter book Name :" <<endl;
    cin>>temp_book_obj.p_book_name;
    cout<<"Please Enter author name :" <<endl;
    cin>>temp_book_obj.author_name;
    cout<<"Please Enter Subject Name :" <<endl;
    cin>>temp_book_obj.subject;
    cout<<"Please Enter book id :" <<endl;
    cin>>temp_book_obj.book_id;
    
    /*Add book*/
    ret_t ret = p_lib->insert_first(temp_book_obj.p_book_name, temp_book_obj.author_name, temp_book_obj.subject , temp_book_obj.book_id);
    if(ret == SUCCESS) 
    {    
        cout<<"Book Added Successfully..." <<endl;
    }
    else{
        cout<<"Book not addedd Sucessfully.." <<endl; 
    }
}

void add_book_before()
{
    data_t p_e_data;
    if(p_lib == nullptr){
        cout<<"First create the library:" <<endl;
        return ;
        }
    cout<<"Enter the book name to add before that book" <<endl;
    cin>>p_e_data;
    
    book* e_book = p_lib->search_book(p_e_data);

    if(e_book == nullptr)
    {
        cout<<"Book is not available.." <<endl;
        return ;
    }
    
    cout<<"please do not give spaces between name else use underscore "<<endl;
    cout<<"Please Enter book Name :" <<endl;
    cin>>temp_book_obj.p_book_name;
    cout<<"Please Enter author name :" <<endl;
    cin>>temp_book_obj.author_name;
    cout<<"Please Enter Subject Name :" <<endl;
    cin>>temp_book_obj.subject;
    cout<<"Please Enter book id :" <<endl;
    cin>>temp_book_obj.book_id;

    /*Add book*/
    try{
    ret_t ret = p_lib->insert_before(p_e_data ,temp_book_obj.p_book_name, temp_book_obj.author_name, temp_book_obj.subject , temp_book_obj.book_id);
    }catch(const data_not_found& e){
        cout<< e.what() <<endl;
        return;
    }
    cout<<"Book Added Successfully..." <<endl;
}

void Add_book_after()
{
    data_t p_e_data;
    if(p_lib == nullptr){
        cout<<"First create the library:" <<endl;
        return ;
        }
    cout<<"Enter the book name to add after that book" <<endl;
    cin>>p_e_data;
    
    book* e_book = p_lib->search_book(p_e_data);

    if(e_book == nullptr)
    {
        cout<<"Book is not available.." <<endl;
        return ;
    }
    cout<<"please do not give spaces between name neither use underscore "<<endl;
    cout<<"Please Enter book Name :" <<endl;
    cin>>temp_book_obj.p_book_name;
    cout<<"Please Enter author name :" <<endl;
    cin>>temp_book_obj.author_name;
    cout<<"Please Enter Subject Name :" <<endl;
    cin>>temp_book_obj.subject;
    cout<<"Please Enter book id :" <<endl;
    cin>>temp_book_obj.book_id;

    /*Add book*/
    try{
        ret_t ret = p_lib->insert_after(p_e_data ,temp_book_obj.p_book_name, temp_book_obj.author_name, temp_book_obj.subject , temp_book_obj.book_id);
    }catch(const data_not_found& e){
        cout<< e.what() <<endl;
        return;
    }
    cout<<"Book Added Successfully..." <<endl;
}

void View_Book_details()
{
    cout<<"Enter book name for view details" <<endl;
    cin>>temp_book_obj.p_book_name;
    bool ret;
    ret = p_lib->find_list_data(temp_book_obj.p_book_name, &temp_book_obj.author_name, &temp_book_obj.subject , &temp_book_obj.book_id);
    if(ret == false)
    {
        cout<<"book not found..." <<endl;
        return;
    }
    cout<<"---------------------" <<endl;
    std::cout<<"->Book Name :"<< temp_book_obj.p_book_name <<endl
                <<"->Author Name: " <<temp_book_obj.author_name <<endl 
                <<"->Subject:" <<temp_book_obj.subject <<endl
                <<"->book id:" <<temp_book_obj.book_id <<endl;
    
}

void view_library()
{
    if(p_lib == nullptr)
    {
        cout<<"libray is empty..."<<endl;
        return;
    }
    cout<<*p_lib <<endl;
    int selection;
    cout<<"Press any key and enter for main menu :" <<endl;
    cin>>selection;
    if(selection)
        return;    
}

void Remove_book()
{
    data_t p_e_data;
    cout<<"Enter book name :" <<endl;
    cin>>p_e_data;
    try{
        ret_t ret = p_lib->remove_data(p_e_data);
    }catch(data_not_found& e){
        cout<< e.what() <<endl;
        return;
    }
    cout<<"book Removed sucessfully.."<<endl;
}

void Delete_Library()
{
    if(p_lib == nullptr){
        printf("library does not exist\n");
        return ;
    }
    delete(p_lib);
    p_lib = nullptr;
    cout<<"library deleted successfully..." <<endl;
                
}

void get_length()
{
    if(p_lib == nullptr){
        printf("library does not exist\n");
        return ;
    }
    bool ret;
    ret = p_lib->is_empty();
    cout<<ret <<endl;
    if(ret == false){
        cout<<"Hello" ;
        len_t len = p_lib->get_len();
        cout<<"Total number of books available in library is : " <<len <<endl; 
        return ;
    }
    cout<<"Library was empty..." <<endl;
}

int main(){

     int select = 0;
     while(1)
     {
        cout<<"-------------Index-----------" <<endl;
        cout<<"please make a selection" <<endl;
        cout<<"[1]create library :" <<endl;
        cout<<"[2]Add book to first:" <<endl;
        cout<<"[3]Add book before :" <<endl;
        cout<<"[4]Add book after :" <<endl;
        cout<<"[5]View Book details :" <<endl;
        cout<<"[6]view library :" <<endl;
        cout<<"[7]Remove book :" <<endl;
        cout<<"[8]Delete Library :" <<endl;
        cout<<"[9]count of book available" <<endl;
        cout<<"[10]Exit :" <<endl;
        cout<<"-----------------------------" <<endl;
        cin>>select;
        if(select > 10 && select < 1)
        {      
                cout<<"please select valid index" <<endl;
                continue;
        }
        
        switch(select)
        {
            case 1:
                if(p_lib != nullptr)
                    printf("library already created\n");

                p_lib = new library;
                assert(p_lib->is_empty() == true);
                assert(p_lib->get_len() == 0);
                cout<<"library created sucessfuly " <<endl;
                continue;
            case 2:
                Add_book();
                continue;
            case 3:
                add_book_before(); 
                continue;
            case 4:
                Add_book_after();
                continue;
            case 5:
                View_Book_details();
                continue;
            case 6:
                view_library();
                continue;
            case 7:
                Remove_book();
                continue;
            case 8:
                Delete_Library();
                continue;
            case 9:
                get_length();
                continue;
            case 10:
                if(p_lib != nullptr){
                    delete(p_lib);
                    p_lib = nullptr;
                }
                return 0;
        }
     }
    return 0;
}
