#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "makewindows.h"
#include "dialog.h"
#include <simplecrypt.h>
#include <QtGlobal>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    makewindows makew;
    //flashwindow flashw;
    Dialog load;


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int CheckStatus();

private slots:

    void on_pushButton_clicked();

    void update_bblayers();

    void refresh_param();

    void update_IP_interface();

    void update_Password(QString *);

    void on_pushButton_3_clicked();

    int on_pushButton_2_clicked();

    void readyReadStandardOutput();

    void readyReadStandardError();

    int int_size_string(QString, QString, QString);

    void Update_image();

    void Update_DateHour();

    void loading(int);

    void copyfile();

    void readdialogerror(QString);

    void readdialog(QString);

    int password_request();

    void update_geral_conf(QString, QString*, QString);

    void on_No_password_checkbox_clicked(bool checked);

    void on_SSH_CheckBox_clicked(bool checked);

private:
    bool sec_pass=true;
    Ui::MainWindow *ui;
    QProcess *processmake = new QProcess(this);
    QProcess processflash;
    QString pathdest;
    QString ip_interface, password;

};

#endif // MAINWINDOW_H
