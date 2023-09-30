#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QProcess>
#include <stdio.h>
#include <QVector>
#include <QString>


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
    QProcess process;

    // Set the command you want to run as an argument to start
    QString command = "ls"; // Replace with your system command
    QStringList arguments;  // Any additional arguments for the command
    arguments << "-l";     // For example, to list files in long format

    // Start the process with the command and arguments
    process.start(command, arguments);

    // Wait for the process to finish (optional)
    process.waitForFinished();

    // Read the output of the process
    QString output = process.readAllStandardOutput();


    QMessageBox::information(this, "Button Clicked", output);
}


void MainWindow::on_pushButton_2_clicked()
{
    FILE *pin = popen("ps", "r");


      QVector<QString> lines; // Vector to store each line

      char buffer[1024];
      while (fgets(buffer, sizeof(buffer), pin) != NULL) {
          printf("%s", buffer);
          lines.push_back(buffer);
      }

      QString s = "";

      QVector<QString>::iterator ptr;
      for (ptr = lines.begin(); ptr < lines.end(); ptr++){
          s += *ptr;
      }

      QMessageBox msgBox;
      msgBox.setText(s);
      msgBox.exec();
      pclose(pin);

}

