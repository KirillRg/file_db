#include "change.h"
#include "ui_change.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

change::change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);
}

change::~change()
{
    delete ui;
}
int numOfElementsForChanging(string fileName) {

    ifstream reading(fileName);
    ofstream record(fileName, ios::app);
    string skipLine;
    int n;

    reading >> n;
    if(n!=1)n=1;
    else {
        for (int i = 0; i < n; ++i) {
            reading>>skipLine;
            reading>>skipLine;
            reading>>skipLine;
            reading>>skipLine;
            reading>>n;
        }
        n++;
    }
    n--;
    reading.close();
    record.close();

    return n;
}

void copyToChange()
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

                int n = numOfElementsForChanging("DB.txt");

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

string printChanged(int index)
{
    ifstream reading("DB.txt");
    string result;
    if (reading) {
        int count;
        string name;
        int phoneNum;
        string city;
        float mark;
        int n = numOfElementsForChanging("DB.txt");
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

void change::on_pushButton_clicked()
{
    ui->label_7->setText("");
    string result;
    QString input0 = ui->lineEdit->text();
    string numbersFound = input0.toStdString()+" ";
    if(stoi(numbersFound)<=0 || stoi(numbersFound)>numOfElementsForChanging("DB.txt"))
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
               result = result+printChanged(stoi(numberToPrint));
//Изменение
               copyToChange();
               ifstream reading("cDB.txt");
               ofstream record("DB.txt", ios::out);

               int count;
               float mark;
               string name;
               int phoneNum;
               string city;

               int size = numOfElementsForChanging("cDB.txt");
               for (int k = 0; k < size; ++k)  {
                      reading >> count;
                      if(count == stoi(numberToPrint))
                      {
                          record << count << endl;

                          reading >> name;
                          reading >> phoneNum;
                          reading >> city;
                          reading >> mark;

                          QString input = ui->lineEdit_2->text();
                          string nameToChange = input.toStdString();
                          name = nameToChange;
                          record << name << endl;

                          QString input2 = ui->lineEdit_3->text();
                          long int numToChange = input2.toLong();
                          phoneNum = numToChange;
                          record << phoneNum<< endl;

                          QString input3 = ui->lineEdit_4->text();
                          string cityToChange = input3.toStdString();
                          city = cityToChange;
                          record << city << endl;

                          QString input4 = ui->lineEdit_5->text();
                          float markToChange = input4.toFloat();
                          mark = markToChange;
                          record << mark << endl;

                      }else
                      {
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
//
               reading.close();
               record.close();
               remove("cDB.txt");
               numberToPrint="";
               left = i+1;
               }
           }
        QString qstr = QString::fromStdString(result);
        ui->label_7->setText(qstr);
    }
}
