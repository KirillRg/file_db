#include "delete.h"
#include "ui_delete.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>


using namespace std;

Delete::Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Delete::~Delete()
{
    delete ui;
}
int numOfElementsToDelete(string fileName) {

    ifstream reading(fileName);
    ofstream record(fileName, ios::app);
    string name;
    long int phoneNum;
    string city;
    int n;
    float mark;

    reading >> n;
    if(n!=1)n=1;
    else {
        for (int i = 0; i < n; ++i) {
            reading>>name;
            reading>>phoneNum;
            reading>>city;
            reading>>mark;
            reading>>n;
        }
        n++;
    }
    n--;
    reading.close();
    record.close();

    return n;
}

void createNameFileDelete(){

    ifstream reading("DB.txt");
    ofstream record("Names.txt", ios::out);

        if (reading)
        {
            if (record) {

                int count;
                string name;
                long int phoneNum;
                string city;
                float mark;

                int n = numOfElementsToDelete("DB.txt");

                for (int i = 0; i < n; i++)
                {
                    reading >> count;
                    reading >> name;


                    record << name << endl;

                    reading >> phoneNum;
                    reading >> city;
                    reading >> mark;
                }
            }
            else
            {
                cout << "Unable to open buffer." << endl;
            }
        }else{
            cout << "Unable to open file." << endl;
        }
        record.close();
        reading.close();
}
string searchNamesDelete(string nameToSearch)
{
    createNameFileDelete();
    ifstream reading("Names.txt");
    string fileInf;
    string numbersFound;
//Поиск
    for (int i = 1; i <= numOfElementsToDelete("DB.txt"); ++i) {
        reading >> fileInf;
        if(nameToSearch == fileInf){
            numbersFound = numbersFound + to_string(i)+" ";
        }
    }
//
    reading.close();
    return numbersFound;
}
void createNumberFileDelete(){

    ifstream reading("DB.txt");
    ofstream record("Numbers.txt", ios::out);

        if (reading)
        {
            if (record) {

                int count;
                string name;
                long int phoneNum;
                string city;
                float mark;

                int n = numOfElementsToDelete("DB.txt");

                for (int i = 0; i < n; i++)
                {
                    reading >> count;
                    reading >> name;

                    reading >> phoneNum;
                    record << phoneNum << endl;

                    reading >> city;
                    reading >> mark;
                }
            }
            else
            {
                cout << "Unable to open buffer." << endl;
            }
        }else{
            cout << "Unable to open file." << endl;
        }
        record.close();
        reading.close();
}
string searchNumbersDelete(long int numberToSearch)
{
    createNumberFileDelete();
    ifstream reading("Numbers.txt");
    long int fileInf;
    string numbersFound;
//Поиск
    for (int i = 1; i <= numOfElementsToDelete("DB.txt"); ++i) {
        reading >> fileInf;
        if(numberToSearch == fileInf){
            numbersFound = numbersFound + to_string(i)+" ";
        }
    }
//
    reading.close();
    return numbersFound;
}
void createCityFileDelete(){

    ifstream reading("DB.txt");
    ofstream record("Cities.txt", ios::out);

        if (reading)
        {
            if (record) {

                int count;
                string name;
                long int phoneNum;
                string city;
                float mark;

                int n = numOfElementsToDelete("DB.txt");

                for (int i = 0; i < n; i++)
                {
                    reading >> count;
                    reading >> name;
                    reading >> phoneNum;

                    reading >> city;
                    record << city << endl;

                    reading >> mark;
                }
            }
            else
            {
                cout << "Unable to open buffer." << endl;
            }
        }else{
            cout << "Unable to open file." << endl;
        }
        record.close();
        reading.close();
}
string searchCitiesDelete(string cityToSearch)
{
    createCityFileDelete();
    ifstream reading("Cities.txt");
    string fileInf;
    string numbersFound;
//Поиск
    for (int i = 1; i <= numOfElementsToDelete("DB.txt"); ++i) {
        reading >> fileInf;
        if(cityToSearch == fileInf){
            numbersFound = numbersFound + to_string(i)+" ";
        }
    }
//
    reading.close();
    return numbersFound;
}
void createMarkFileDelete(){

    ifstream reading("DB.txt");
    ofstream record("Marks.txt", ios::out);

        if (reading)
        {
            if (record) {
                int count;
                string name;
                long int phoneNum;
                string city;
                float mark;

                int n = numOfElementsToDelete("DB.txt");

                for (int i = 0; i < n; i++)
                {
                    reading >> count;
                    reading >> name;
                    reading >> phoneNum;
                    reading >> city;

                    reading >> mark;
                    record << mark << endl;
                }
            }
            else
            {
                cout << "Unable to open buffer." << endl;
            }
        }else{
            cout << "Unable to open file." << endl;
        }
        record.close();
        reading.close();
}
string searchMarksDelete(float markToSearch)
{
    createMarkFileDelete();
    ifstream reading("Marks.txt");
    float fileInf;
    string numbersFound;
    //Поиск
        for (int i = 1; i <= numOfElementsToDelete("DB.txt"); ++i) {
            reading >> fileInf;
            if(markToSearch == fileInf){
                numbersFound = numbersFound + to_string(i)+" ";
            }
        }
    //
     reading.close();
     return numbersFound;
}

string printDeleted(int index)
{
    ifstream reading("DB.txt");
    string result;
    if (reading) {
        int count;
        string name;
        int phoneNum;
        string city;
        float mark;
        int n = numOfElementsToDelete("DB.txt");
        for (int i = 0; i < n; i++)
        {
            reading>>count;
            reading>>name;
            reading>>phoneNum;
            reading>>city;
            reading>>mark;

            if(count == index){
            result = name+"|"+to_string(phoneNum)+"|"+city+"|"+to_string(mark)+"\n";
            }
        }
    }
    else
    {
        cout << "Unable to open file!" << endl;
    }
    reading.close();
    return result;
}
void Copy()
{
    ifstream reading("DB.txt");
    ofstream record("cDB.txt", ios::out);

        if (reading)
        {
            if (record) {

                int count;
                float mark;
                string name;
                int phoneNum;
                string city;

                int n = numOfElementsToDelete("DB.txt");

                for (int i = 0; i < n; i++)
                {
                    reading >> count;
                    record << count << endl;

                    reading >> name;
                    record << name << endl;

                    reading >> phoneNum;
                    record << phoneNum << endl;

                    reading >> city;
                    record << city << endl;

                    reading >> mark;
                    record << mark << endl;
                }
            }
            else
            {
                cout << "Unable to open buffer." << endl;
            }
        }else{
            cout << "Unable to open file." << endl;
        }
        record.close();
        reading.close();
    }
void deleteElement (int number)
{
    Copy();
    ifstream reading("cDB.txt");
    ofstream record("DB.txt", ios::out);

    int count;
    float mark;
    string name;
    int phoneNum;
    string city;

    int size = numOfElementsToDelete("cDB.txt");
    bool check = false;
    for (int i = 0; i < size; ++i) {
           reading >> count;
           if(count == number)
           {
               reading >> name;
               reading >> phoneNum;
               reading >> city;
               reading >> mark;
               check = true;
           }else
           {
               if(check==true)count--;
               record << count << endl;

               reading >> name;
               record << name << endl;

               reading >> phoneNum;
               record << phoneNum << endl;

               reading >> city;
               record << city << endl;

               reading >> mark;
               record << mark << endl;
           }
       }
    reading.close();
    record.close();
    remove("cDB.txt");
}

void Delete::on_pushButton_clicked()
{
    ui->label->setText("");
    string result;
    QString input = ui->lineEdit->text();
    string numbersFound = input.toStdString()+" ";
    if(stoi(numbersFound)<=0 || stoi(numbersFound)>numOfElementsToDelete("DB.txt"))
    {
        QMessageBox::critical(this,"Eror","Не удалось найти id!!!");
    }else
    {
        int left = 0;
        for (int i = 0; i < numbersFound.size(); ++i) {
               if(numbersFound[i] - '0' == -16)
               {
                   string numberToPrint;
                   for (int j = left; j < i; ++j) {
                       numberToPrint = numberToPrint + numbersFound[j];
                   }
               result = result+printDeleted(stoi(numberToPrint));
               deleteElement(stoi(numberToPrint));
               numberToPrint="";
               left = i+1;
               }
           }
        QString qstr = QString::fromStdString(result);
        ui->label->setText(qstr);
    }
}

void Delete::on_pushButton_2_clicked()
{
    ui->label->setText("");
    string result;
    QString input = ui->lineEdit_2->text();
    string nameToSearch = input.toStdString();
    string numbersFound = searchNamesDelete(nameToSearch);
    int left = 0;
    int number;
    int minus=0;
    bool flag = false;
        for (int i = 0; i < numbersFound.size(); ++i) {
               if(numbersFound[i] - '0' == -16)
               {
                   string numberToPrint;
                   for (int j = left; j < i; ++j) {
                       numberToPrint = numberToPrint + numbersFound[j];
                   }
               number = stoi(numberToPrint);
               if(flag == true)
               {
                   minus++;
                   number=number-minus;
               }
               result = result+printDeleted(number);
               deleteElement(number);
               numberToPrint="";
               left = i+1;
               flag=true;
               }
           }
        if(result == "")
        {
            QMessageBox::critical(this,"Eror","Не удалось найти атрибут!!!");
        }
        QString qstr = QString::fromStdString(result);
        ui->label->setText(qstr);
}

void Delete::on_pushButton_3_clicked()
{
    ui->label->setText("");
    string result;
    QString input = ui->lineEdit_3->text();
    long int numberToSearch = input.toLong();
    string numbersFound = searchNumbersDelete(numberToSearch);
    int left = 0;
    int number;
    int minus=0;
    bool flag = false;
        for (int i = 0; i < numbersFound.size(); ++i) {
               if(numbersFound[i] - '0' == -16)
               {
                   string numberToPrint;
                   for (int j = left; j < i; ++j) {
                       numberToPrint = numberToPrint + numbersFound[j];
                   }
               number = stoi(numberToPrint);
               if(flag == true)
               {
                   minus++;
                   number=number-minus;
               }
               result = result+printDeleted(number);
               deleteElement(number);
               numberToPrint="";
               left = i+1;
               flag=true;
               }
           }
        if(result == "")
        {
            QMessageBox::critical(this,"Eror","Не удалось найти атрибут!!!");
        }
        QString qstr = QString::fromStdString(result);
        ui->label->setText(qstr);
}

void Delete::on_pushButton_4_clicked()
{
    ui->label->setText("");
    string result;
    QString input = ui->lineEdit_4->text();
    string cityToSearch = input.toStdString();
    string numbersFound = searchCitiesDelete(cityToSearch);
    int left = 0;
    int number;
    int minus=0;
    bool flag = false;
        for (int i = 0; i < numbersFound.size(); ++i) {
               if(numbersFound[i] - '0' == -16)
               {
                   string numberToPrint;
                   for (int j = left; j < i; ++j) {
                       numberToPrint = numberToPrint + numbersFound[j];
                   }
               number = stoi(numberToPrint);
               if(flag == true)
               {
                   minus++;
                   number=number-minus;
               }
               result = result+printDeleted(number);
               deleteElement(number);
               numberToPrint="";
               left = i+1;
               flag=true;
               }
           }
        if(result == "")
        {
            QMessageBox::critical(this,"Eror","Не удалось найти атрибут!!!");
        }
        QString qstr = QString::fromStdString(result);
        ui->label->setText(qstr);
}

void Delete::on_pushButton_5_clicked()
{
    ui->label->setText("");
    string result;
    QString input = ui->lineEdit_5->text();
    float markToSearch = input.toFloat();
    string numbersFound = searchMarksDelete(markToSearch);
    int left = 0;
    int number;
    int minus=0;
    bool flag = false;
        for (int i = 0; i < numbersFound.size(); ++i) {
               if(numbersFound[i] - '0' == -16)
               {
                   string numberToPrint;
                   for (int j = left; j < i; ++j) {
                       numberToPrint = numberToPrint + numbersFound[j];
                   }
               number = stoi(numberToPrint);
               if(flag == true)
               {
                   minus++;
                   number=number-minus;
               }
               result = result+printDeleted(number);
               deleteElement(number);
               numberToPrint="";
               left = i+1;
               flag=true;
               }
           }
        if(result == "")
        {
            QMessageBox::critical(this,"Eror","Не удалось найти атрибут!!!");
        }
        QString qstr = QString::fromStdString(result);
        ui->label->setText(qstr);
}
