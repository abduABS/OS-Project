#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QProcess>
#include <stdio.h>
#include <QVector>
#include <string>
#include <QString>
//hello

QString priority = 0;
QString PID = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_pushButton_2_clicked()
{
    QString command = "kill -9 "  + PID;
    FILE *pin = popen(command.toStdString().c_str(), "r");


      QVector<QString> lines; // Vector to store each line

      char buffer[1024];
      while (fgets(buffer, sizeof(buffer), pin) != NULL) {
          printf("%s", buffer);
          lines.push_back(buffer);
      }

//      QMessageBox msgBox;
//      msgBox.setText();
//      msgBox.exec();
      pclose(pin);

}


void MainWindow::on_radioButton_clicked()
{
    priority = "-15";
}


void MainWindow::on_radioButton_2_clicked()
{
    priority = "0";
}


void MainWindow::on_radioButton_3_clicked()
{
    priority = "10";
}


void MainWindow::on_textEdit_textChanged()
{
    PID = ui->textEdit->toPlainText();
}


void MainWindow::on_textEdit_cursorPositionChanged()
{

}


void MainWindow::on_pushButton_3_clicked()
{
    QString command = "renice "  + priority + " -p " + PID;
    FILE *pin = popen(command.toStdString().c_str(), "r");


      char buffer[1024];
      while (fgets(buffer, sizeof(buffer), pin) != NULL) {
          printf("%s", buffer);

          QMessageBox msgBox;
          msgBox.setText(buffer);
          printf("%s",buffer);
          msgBox.exec();
      }

      QMessageBox msgBox;
      msgBox.setText(buffer);
      msgBox.exec();
      pclose(pin);
}

