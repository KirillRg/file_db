#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

int numberOfElements(string fileName) {

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
    cout << n << endl;
    reading.close();
    record.close();

    return n;
}
void Dialog::on_pushButton_clicked()
{
    ifstream reading("DB.txt");
    ofstream record("DB.txt", ios::app);
    string skipLine;
    string name;
    long int phoneNum;
    string city;
    int count;
    float mark;

    reading >> count;
    if(count!=1)count=1;
    else {
        for (int i = 0; i < count; ++i) {
            reading>>skipLine;
            reading>>skipLine;
            reading>>skipLine;
            reading>>skipLine;
            reading>>count;
        }
        count++;
    }
    record << count << endl;
       if (record) {
               QString a = ui->lineEdit->text();
               name = a.toStdString();

               QString b = ui->lineEdit_2->text();
               phoneNum = b.toLong();

               QString c = ui->lineEdit_3->text();
               city = c.toStdString();

               QString d = ui->lineEdit_5->text();
               mark = d.toFloat();

               record << name << endl;
               record << phoneNum << endl;
               record << city << endl;
               record << mark << endl;

           }else
       {
           cout << "File did not open!" << endl;

       }
       reading.close();
       record.close();
}

void Dialog::on_pushButton_3_clicked()
{
    string fileName;
    QString a = ui->lineEdit_4->text();
    fileName = a.toStdString();

    ifstream reading(fileName);
    ofstream record("DB.txt", ios::out);

    if (reading) {
        if (record) {
            string name;
            long int phoneNum;
            string city;
            int n,count;
            float mark;
            n = numberOfElements(fileName);

            for (int i = 0; i < n; i++)
            {
                reading >> count;
                reading >> name;
                reading >> phoneNum;
                reading >> city;
                reading >> mark;

                record << count << endl;
                record << name << endl;
                record << phoneNum << endl;
                record << city << endl;
                record << mark << endl;
            }
        }
        else
        {
            cout << "Unable to open DATABASE!" << endl;
        }
    }
    else
    {
        cout << "Unable to open File!" << endl;
    }

    reading.close();
    record.close();
}
