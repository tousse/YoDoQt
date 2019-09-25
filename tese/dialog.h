#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    int status;

    void loading_Layers(QString);

    ~Dialog();

    void changelogstate(QString);
private:
    Ui::Dialog *ui;

    QProcess *down = new QProcess;


    bool sudo_check=false;



private slots:

    void readdialogerror();

    void readdialog();

};

#endif // DIALOG_H
