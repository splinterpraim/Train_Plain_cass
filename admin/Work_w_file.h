#ifndef WORK_W_FILE_H_INCLUDED
#define WORK_W_FILE_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include "Element.h"


using namespace std;

class Work_w_file{

private:
    int _size;
    Element *_list;


public:
	Work_w_file();
	Work_w_file(const Work_w_file& w);
	~Work_w_file();


    void Add();
    void Del();
    void Redact();
    void Show();
    void SaveBackup(string f);
    void Recovery(string f);

    void Put_in_file(string f);
    void Get_from_file(string f);

    void Sort();




};
#endif // WORK_W_FILE_H_INCLUDED
