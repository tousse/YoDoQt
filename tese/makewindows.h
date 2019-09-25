#ifndef MAKEWINDOWS_H
#define MAKEWINDOWS_H


#include <QMainWindow>
#include <QDialog>
#include <QProcess>
#include <QProcess>
#include <QMessageBox>

namespace Ui {
class makewindows;
}

class makewindows : public QDialog
{
    Q_OBJECT

public:
    explicit makewindows(QWidget *parent = nullptr);
    void updatetextbox(QString);
    void updatetextboxerror(QString);
    ~makewindows();

private slots:
    void on_pushButton_clicked();
    //QProcess process;


private:
    Ui::makewindows *ui;
};

#endif // MAKEWINDOWS_H
