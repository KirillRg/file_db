#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color:purple");
}

MainWindow::~MainWindow()
{
    delete ui;
}
int numOfElements(string fileName) {

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
string Print() {
    ifstream reading("DB.txt");
    string result;
    if (reading) {
        int count;
        string name;
        int phoneNum;
        string city;
        float mark;
        int n = numOfElements("DB.txt");

        for (int i = 0; i < n; i++)
        {
            reading >> count;
            reading >> name;
            reading >> phoneNum;
            reading >> city;
            reading >> mark;
            result = result + to_string(count) +"|"+name+"|"+to_string(phoneNum)+"|"+city+"|"+to_string(mark)+"\n";

        }
    }
    else
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    reading.close();
    return result;
}

void MainWindow::on_pushButton_clicked()
{
    window = new Dialog (this);
    window->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    ofstream ofs;
    ofs.open("DB.txt", ofstream::out | ofstream::trunc);
    ofs.close();
}

void MainWindow::on_pushButton_3_clicked()
{
    searchWindow = new Search(this);
    searchWindow->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    ifstream reading("DB.txt");
    ofstream record("Backup.txt", ios::out);

        if (reading)
        {
            if (record) {

                int count;
                float mark;
                string name;
                int phoneNum;
                string city;

                int n = numOfElements("DB.txt");

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
                cout << "Unable to open DB." << endl;
            }
        }else{
            cout << "Unable to open file." << endl;
        }
        record.close();
        reading.close();
    }

void MainWindow::on_pushButton_5_clicked()
{
    string result = Print();
    QString qstr = QString::fromStdString(result);
    ui->label->setText(qstr);
}

void MainWindow::on_pushButton_6_clicked()
{
    deleteWindow = new Delete(this);
    deleteWindow->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    changeWindow = new change(this);
    changeWindow->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    ifstream reading("DB.txt");
    ofstream record("formatDB.csv", ios::out);

    if (reading)
    {
        if (record) {

            int count;
            string name;
            long int phoneNum;
            string city;
            float mark;
            int n = numOfElements("DB.txt");

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
            QMessageBox::information(this,"Information","Данные были успешно сохранены в файл стороннего формата (formatDB.csv).");
        }
        else
        {
            cout << "Unable to open DB." << endl;
        }
    }else{
        cout << "Unable to open file." << endl;
    }
    record.close();
    reading.close();
}

