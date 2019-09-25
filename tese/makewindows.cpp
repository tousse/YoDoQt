#include "makewindows.h"
#include "ui_makewindows.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QTextStream>
#include <iostream>
#include <cstdio>
#include <QDir>

makewindows::makewindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::makewindows)
{
    ui->setupUi(this);
    ui->textBrowser_2->clear();

}

makewindows::~makewindows()
{
    delete ui;
}

void makewindows::on_pushButton_clicked(){
    QProcess *proc_ovpn = new QProcess(this);
    QStringList arg;
    QString first, second;
    first="kill";
    second="bitbake";
    arg<< first << second;
    proc_ovpn->setWorkingDirectory(QDir::currentPath() + "/scripts");
    proc_ovpn->start(QCoreApplication::applicationDirPath() + "/scripts/poky_script.sh", arg);
    if(!proc_ovpn->waitForStarted()){
         QMessageBox::information(this,"Information about make","erro");
    }
    proc_ovpn->waitForFinished(-1);
     //QMessageBox::information(this,"Information about make",proc_ovpn->readAllStandardOutput());
     //QMessageBox::information(this,"Information about make",proc_ovpn->readAllStandardError());
    proc_ovpn->close();proc_ovpn->kill();
    ui->textBrowser_2->clear();
    this->close();

}

void makewindows::updatetextbox(QString info)
{

    ui->textBrowser_2->append(info);
}

void makewindows::updatetextboxerror(QString info)
{
    ui->textBrowser_2->append(info);
}


