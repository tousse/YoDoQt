#include "dialog.h"
#include "ui_dialog.h"
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include <QApplication>
#include <QDesktopWidget>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
}


void Dialog::loading_Layers(QString params){
    if (params!="0"){
        QStringList args_test;
        args_test<< params;
        int param=params.toInt();
        ui->progressBar->setValue(param);
        down->setWorkingDirectory(QDir::currentPath() + "/scripts");
        down->start(QCoreApplication::applicationDirPath() + "/scripts/poky_script.sh", args_test);

        if(!down->waitForStarted()){
           QMessageBox::information(this,"Information about make", QDir::currentPath()+"erro");
        }
        connect(down,
            SIGNAL(readyReadStandardOutput()),
            this,
            SLOT(readdialog()));
        connect(down,
            SIGNAL(readyReadStandardError()),
            this,
            SLOT(readdialogerror()));
    }
}

void Dialog::readdialog(){
    QString output=down->readAllStandardOutput();

        if(output.contains("88")){
            ui->progressBar->setValue(8);
            changelogstate("88");
        }
        else if(output.contains("25")){
            ui->progressBar->setValue(25);
            changelogstate("25");
        }
        else if(output.contains("50")){
            ui->progressBar->setValue(50);
            changelogstate("50");
        }
        else if(output.contains("75")){
            ui->progressBar->setValue(75);
            changelogstate("75");
        }
        else if(output.contains("100") || status == 100){
            ui->progressBar->setValue(100);
            changelogstate("100");
            this->close();

        }
        else ui->label_3->setText(output);



}

void Dialog::changelogstate(QString state){
    QString line, s;
    QFile file("scripts/log.txt");
    QTextStream in(&file);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)){
        while (!in.atEnd()) {
            line = in.readLine();
            if(line.contains("Date=")){
                s = line;
            }
        }
        file.resize(0);
        s.append("\nStatus=" + state);
        in << s;
    }
    file.flush();
    file.close();
}


void Dialog::readdialogerror(){
    QString error = down->readAllStandardError();
    ui->label_3->clear();
    ui->label_3->setText(error);

}


Dialog::~Dialog()
{
    delete ui;
}

