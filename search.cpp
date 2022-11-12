#include "search.h"
#include "ui_search.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>


using namespace std;

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}
int numOfElementsForFiles(string fileName) {

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
string print(int index) {
    ifstream reading("DB.txt");
    string result;
    if (reading) {
        int count;
        string name;
        int phoneNum;
        string city;
        float mark;
        int n = numOfElementsForFiles("DB.txt");
        for (int i = 0; i < n; i++)
        {
            reading>>count;
            reading>>name;
            reading>>phoneNum;
            reading>>city;
            reading>>mark;

            if(count == index){
            result = to_string(count) +"|"+name+"|"+to_string(phoneNum)+"|"+city+"|"+to_string(mark)+"\n";
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


void createNameFile(){

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

                int n = numOfElementsForFiles("DB.txt");

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
void clearNameFile(){
    ofstream ofs;
    ofs.open("Names.txt", ofstream::out | ofstream::trunc);
    ofs.close();
}
string searchNames(string nameToSearch)
{
    ifstream reading("Names.txt");
    string fileInf;
    string numbersFound;
//Поиск
    for (int i = 1; i <= numOfElementsForFiles("DB.txt"); ++i) {
        reading >> fileInf;
        if(nameToSearch == fileInf){
            numbersFound = numbersFound + to_string(i)+" ";
        }
    }
//
    reading.close();
    return numbersFound;
}
void Search::on_pushButton_clicked()
{
    createNameFile();

    ui->label_5->setText("");
    string nameToSearch;
    QString input = ui->lineEdit->text();
    nameToSearch = input.toStdString();

    string numbersFound = searchNames(nameToSearch);
    int left = 0;
    string result;
    for (int i = 0; i < numbersFound.size(); ++i) {

           if(numbersFound[i] - '0' == -16)
           {
               string numberToPrint;
               for (int j = left; j < i; ++j) {
                   numberToPrint = numberToPrint + numbersFound[j];
               }
           result = result+print(stoi(numberToPrint));
           numberToPrint="";
           left = i+1;
           }
       }
    if(result == "")
    {
        QMessageBox::critical(this,"Eror","Не удалось найти атрибут!!!");
    }
    QString qstr = QString::fromStdString(result);
    ui->label_5->setText(qstr);
}

void createNumberFile(){

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

                int n = numOfElementsForFiles("DB.txt");

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
void clearNumberFile(){
    ofstream ofs;
    ofs.open("Numbers.txt", ofstream::out | ofstream::trunc);
    ofs.close();
}
string searchNumbers(long int numberToSearch)
{
    ifstream reading("Numbers.txt");
    long int fileInf;
    string numbersFound;
//Поиск
    for (int i = 1; i <= numOfElementsForFiles("DB.txt"); ++i) {
        reading >> fileInf;
        if(numberToSearch == fileInf){
            numbersFound = numbersFound + to_string(i)+" ";
        }
    }
//
    reading.close();
    return numbersFound;
}
void Search::on_pushButton_2_clicked()
{
    createNumberFile();

    ui->label_5->setText("");

    long int numberToSearch;
    QString input = ui->lineEdit_2->text();
    numberToSearch = input.toLong();

    string numbersFound = searchNumbers(numberToSearch);
    int left = 0;
    string result;
    for (int i = 0; i < numbersFound.size(); ++i) {

           if(numbersFound[i] - '0' == -16)
           {
               string numberToPrint;
               for (int j = left; j < i; ++j) {
                   numberToPrint = numberToPrint + numbersFound[j];
               }
           result = result + print(stoi(numberToPrint));
           numberToPrint="";
           left = i+1;
           }
       }
    if(result == "")
    {
        QMessageBox::critical(this,"Eror","Не удалось найти атрибут!!!");
    }
    QString qstr = QString::fromStdString(result);
    ui->label_5->setText(qstr);
}

void createCityFile(){

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

                int n = numOfElementsForFiles("DB.txt");

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
void clearCityFile(){
    ofstream ofs;
    ofs.open("Cities.txt", ofstream::out | ofstream::trunc);
    ofs.close();
}
string searchCities(string cityToSearch)
{
    ifstream reading("Cities.txt");
    string fileInf;
    string numbersFound;
//Поиск
    for (int i = 1; i <= numOfElementsForFiles("DB.txt"); ++i) {
        reading >> fileInf;
        if(cityToSearch == fileInf){
            numbersFound = numbersFound + to_string(i)+" ";
        }
    }
//
    reading.close();
    return numbersFound;
}
void Search::on_pushButton_3_clicked()
{
    createCityFile();

    ui->label_5->setText("");

    string cityToSearch;
    QString input = ui->lineEdit_3->text();
    cityToSearch = input.toStdString();
    string numbersFound = searchCities(cityToSearch);

    int left = 0;
    string result;
    for (int i = 0; i < numbersFound.size(); ++i) {

           if(numbersFound[i] - '0' == -16)
           {
               string numberToPrint;
               for (int j = left; j < i; ++j) {
                   numberToPrint = numberToPrint + numbersFound[j];
               }
           result= result + print(stoi(numberToPrint));
           numberToPrint="";
           left = i+1;
           }
       }
    if(result == "")
    {
        QMessageBox::critical(this,"Eror","Не удалось найти атрибут!!!");
    }
    QString qstr = QString::fromStdString(result);
    ui->label_5->setText(qstr);
}

void createMarkFile(){

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

                int n = numOfElementsForFiles("DB.txt");

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
void clearMarkFile(){
    ofstream ofs;
    ofs.open("Marks.txt", ofstream::out | ofstream::trunc);
    ofs.close();
}
string searchMarks(float markToSearch)
{
    ifstream reading("Marks.txt");
    float fileInf;
    string numbersFound;
    //Поиск
        for (int i = 1; i <= numOfElementsForFiles("DB.txt"); ++i) {
            reading >> fileInf;
            if(markToSearch == fileInf){
                numbersFound = numbersFound + to_string(i)+" ";
            }
        }
    //
     reading.close();
     return numbersFound;
}
void Search::on_pushButton_4_clicked()
{
    createMarkFile();

    ui->label_5->setText("");

    float markToSearch;
    QString input = ui->lineEdit_4->text();
    markToSearch = input.toFloat();

    string numbersFound = searchMarks(markToSearch);
    int left = 0;
    string result;
    for (int i = 0; i < numbersFound.size(); ++i) {

           if(numbersFound[i] - '0' == -16)
           {
               string numberToPrint;
               for (int j = left; j < i; ++j) {
                   numberToPrint = numberToPrint + numbersFound[j];
               }
           result = result + print(stoi(numberToPrint));
           numberToPrint="";
           left = i+1;
           }
       }
    if(result == "")
    {
        QMessageBox::critical(this,"Eror","Не удалось найти атрибут!!!");
    }
    QString qstr = QString::fromStdString(result);
    ui->label_5->setText(qstr);
}

