#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_makewindows.h"
#include "qstring.h"
#include <QMessageBox>
#include <QStorageInfo>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include <iostream>
#include <QDir>
#include <QThread>
#include <QFileDialog>
#include <QDateTime>
#include <QInputDialog>
#include <QDesktopWidget>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Dialog stat;

    Update_DateHour();

    if(CheckStatus()==0)
        while(CheckStatus()==0)
            password_request();
    else if(CheckStatus()!=100 && CheckStatus()!=0){
        //QMessageBox::information(this,"Information about make","AQUIIII");
        loading(CheckStatus());
    }
     Update_image();
    if(CheckStatus()==100){
        ui->setupUi(this);
        ui->Machine_combobox->addItem("raspberrypi");ui->Machine_combobox->addItem("raspberrypi0");ui->Machine_combobox->addItem("raspberrypi0-wifi");ui->Machine_combobox->addItem("raspberrypi2");ui->Machine_combobox->addItem("raspberrypi3");ui->Machine_combobox->addItem("raspberrypi3-64");ui->Machine_combobox->addItem("raspberrypi-cm");ui->Machine_combobox->addItem("raspberrypi-cm3");
        ui->Output_combobox->addItem("tar.gz");ui->Output_combobox->addItem("rpi-sdimg");
        ui->Pack_Format_ComboBox->addItem("package_ipk");ui->Pack_Format_ComboBox->addItem("package_deb");ui->Pack_Format_ComboBox->addItem("package_rpm");ui->Pack_Format_ComboBox->addItem("package_tar");
        ui->GPU_Spinbox->setMaximum(128);ui->GPU_Spinbox->setMinimum(16);ui->GPU_Spinbox->setSingleStep(16);ui->GPU_Spinbox->setValue(16);
        ui->lineEdit->setText("root");

    }
    //on_pushButton_4_clicked();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QCoreApplication::quit();

}

void MainWindow::Update_image(){
    QString std;
    QFile file("scripts/poky/meta/recipes-core/images/core-image-base.bb");
    QTextStream in(&file);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        if(!std.contains("IMAGE_INSTALL"))
        std.append("LICENSE = \"MIT\"\n\ninherit core-image\n");
        std.append("\nIMAGE_INSTALL += \" \\\n         kernel-modules \\\n         \"");
        std.append("\nCOMPATIBLE_MACHINE = \"^rpi$\"");
       // std.append("\nIMAGE_INSTALL_append = \" packagegroup-rpi-test\"");
        std.append("\nSPLASH = \"psplash-raspberrypi\"");
      //  std.append("\n\nDEV_SDK_INSTALL = \" \\ \n\npython3-modules \\  \n\n\"");
       // std.append("\n\nIMAGE_INSTALL += \" \\ \n${DEV_SDK_INSTALL} \\ \n\"");
        std.append("\n#by Rafael Araujo");
        file.resize(0);
        in << std;
    }
    file.flush();
    file.close();


}

void MainWindow::Update_DateHour(){
    QDateTime t = QDateTime::currentDateTime();
    QString s = "Date=",
                line,status;
    s.append(t.toString());
    QFile file("scripts/log.txt");
    QTextStream in(&file);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)){
        while (!in.atEnd()) {
            line = in.readLine();
            if(line.contains("Status=")){
                status = line;
            }
        }
        file.resize(0);
        s.append("\n" + status);
        in << s;
    }
    file.flush();
    file.close();

}

void MainWindow::loading(int var){
    //Fazer check se as layers estão sacadas
    QString S_var = QString::number(var);
    load.loading_Layers(S_var);
    load.setModal(true);
    load.exec();
}

int MainWindow::CheckStatus(){
    int status=0;
    QString line,s;
    QFile file("scripts/log.txt");
    QTextStream in(&file);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!in.atEnd()) {
            line = in.readLine();
            if(line.contains("Status=")){
                s = line;
            }
        }
    }
    s=s.mid(7,3);
    status=s.toInt();
    if(QDir("scripts/poky").exists())
        status=s.toInt();
    else {
        status=88;
    }
    return status;
}

int MainWindow::password_request(){
    if(sec_pass==true){
        QProcess *pass_process = new QProcess;
        sec_pass=false;
        QString user_password="", pass="pass";
        QInputDialog *inp = new QInputDialog(this);
        inp->setLabelText(tr("User Password:"));
        inp->setWindowTitle(tr("User Password"));
        inp->setTextEchoMode(QLineEdit::Password);
        inp->adjustSize();
        inp->move(QApplication::desktop()->screen()->rect().center() - inp->rect().center());
        if(inp->exec() == QDialog::Accepted)
            user_password = inp->textValue();

        /*user_password = QInputDialog::getText(this,tr("User Password"),
                                         tr("User Password:"), QLineEdit::Password,
                                         "Password");*/

        QStringList args_test;
        args_test<< pass << user_password;
        pass_process->setWorkingDirectory(QDir::currentPath() + "/scripts");
        pass_process->start(QCoreApplication::applicationDirPath() + "/scripts/poky_script.sh", args_test);

        if(!pass_process->waitForStarted()){
           QMessageBox::information(this,"Information about make","erro");
        }
        pass_process->waitForFinished(-1);

        QString output= pass_process->readAllStandardOutput();
        QString error= pass_process->readAllStandardError();


        if(output!=""){
            readdialog(output);
        }
        if(error!=""){
            readdialogerror(error);
        }
        pass_process->close();pass_process->kill();
        return 0;
    }

}

void MainWindow::readdialog(QString output){
    QString line,s;
    if(output.contains("Reading package")){
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
            s.append("\nStatus=88");
            in << s;
        }
        file.flush();
        file.close();
        loading(88);
    }

}

void MainWindow::readdialogerror(QString Error){
    if(Error.contains("sudo: 1 incorrect password attempt\n")){
        //QMessageBox::information(this,"Information about make","Pass errada");
        sec_pass=true;
        password_request();

    }
}

void MainWindow::on_pushButton_3_clicked()
{
        pathdest=QFileDialog::getExistingDirectory(
                    this,
                    tr("Choose path"),
                    QDir::homePath()
                    );
        ui->pushButton_2->setEnabled(1);
}

int MainWindow::on_pushButton_2_clicked()
{
        QString Commanf,
                output,
                StdOut;
        QStringList arg;
        QString first, second;

        refresh_param();
        update_bblayers();
        first="bitbake";
        second=QDir::currentPath()+"/scripts/poky/build";
        arg<<first << second;
        processmake->setWorkingDirectory(QDir::currentPath() + "/scripts");
        processmake->start(QCoreApplication::applicationDirPath() + "/scripts/poky_script.sh", arg);
        if(!processmake->waitForStarted()){
            //QMessageBox::information(this,"Information about make",proc_ovpn->readAllStandardOutput());
        }
        connect(processmake,
                SIGNAL(readyReadStandardOutput()),
                this,
                SLOT(readyReadStandardOutput()));
        connect(processmake,
                SIGNAL(readyReadStandardError()),
                this,
                SLOT(readyReadStandardError()));
        makew.setModal(true);
        makew.exec();
        return 0;
}

int MainWindow::int_size_string(QString str, QString beginning, QString End){
    int size;
    int extra_index=str.indexOf(beginning);
    int temp_size=beginning.length();
    //beginning=beginning+str.length();
    int end_index=str.indexOf(End,temp_size+extra_index);
    size=end_index-extra_index+1;
    return size;
}

void MainWindow::refresh_param(){
    QThread thread;
    QString features = "";
    QString std="DISTRO = \"poky\"\nDISTRO_FEATURES_remove = \" x11 \"\nIMAGE_INSTALL_append = \" ${CORE_IMAGE_BASE_INSTALL}\"\nUSER_CLASSES ?= \"image-mklibs image-prelink\"\nSDKMACHINE = \"x86_64\"\nPACKAGECONFIG_append_pn-qemu-native = \" sdl\"\nPACKAGECONFIG_append_pn-nativesdk-qemu = \" sdl\"\nPATCHRESOLVE = \"noop\"\nCONF_VERSION = \"1\"\nCORE_IMAGE_EXTRA_INSTALL+=\"python3 python3-pip python-pyserial\"\n";

    //Atualiza Change password
    if(ui->ChangePass_checkbox->checkState()){
        //std.replace("INHERIT += \"chageusers\"\n","");
        update_geral_conf("INHERIT += \"chageusers\"\nCHAGE_USERS_PARAMS = \"", &std,"chage -d0 root;");
    }
    if(!ui->No_password_checkbox->checkState())
        update_Password(&std);

    if (ui->SSH_CheckBox->checkState()){
        features.append("ssh-server-openssh ssh-server-dropbear ");
    }
    if(ui->RPI_Logo_CheckBox-CheckStatus())
        features.append("splash ");
    if (ui->No_password_checkbox->checkState())features.append("debug-tweaks ");
    update_geral_conf("EXT"
                      ""
                      "RA_IMAGE_FEATURES ?= \"", &std, features);
    //Atualiza maquina
    update_geral_conf("MACHINE=\"", &std, ui->Machine_combobox->currentText());
    //Package format
    update_geral_conf("PACKAGE_CLASSES = \"", &std, ui->Pack_Format_ComboBox->currentText());
    //output format
    update_geral_conf("IMAGE_FSTYPES += \"", &std, ui->Output_combobox->currentText());
    //thread number
    int N_Core=QThread::idealThreadCount()+1;
    update_geral_conf("BB_NUMBER_THREADS = \"", &std, QString::number(N_Core));
    update_geral_conf("PARALLEL_MAKE = \"", &std, "-j "+QString::number(N_Core));
    update_geral_conf("GPU_MEM = \"", &std, QString::number(ui->GPU_Spinbox->value()));
    //Atualiza U_boot
    if(ui->u_boot_checkbox->checkState())
        update_geral_conf("RPI_USE_U_BOOT = \"", &std,"1");
    //SPI
    if(ui->SPI_Checkbox->checkState())
        update_geral_conf("ENABLE_SPI_BUS = \"", &std,"1");
    //I2C
    if(ui->i2c_checkbox->checkState())
        update_geral_conf("ENABLE_I2C = \"", &std,"1");
    //UART
    if(ui->UART_CheckBox->checkState())
        update_geral_conf("ENABLE_UART = \"", &std,"1");
    //WIFI
    if(!ui->Wifi_checkbox->checkState())
        update_geral_conf("DISABLE_OVERSCAN = \"", &std,"1");
    //USB
    if(ui->UART_CheckBox->checkState())
        update_geral_conf("ENABLE_DWC2_PERIPHERAL = \"", &std,"1");
    //RPI_Logo
    if(!ui->RPI_Logo_CheckBox-CheckStatus())
        update_geral_conf("DISABLE_RPI_BOOT_LOGO = \"", &std,"1");
    std.append("#By Rafael Araujo");
    QFile file("scripts/poky/build/conf/local.conf");
    QTextStream in(&file);
    \


    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))return;
    in.flush();
    in << std;
    file.close();

}

void MainWindow::update_bblayers(){
    QFile file("scripts/poky/build/conf/bblayers.conf");
    QTextStream in(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))return;
    in.flush();
    in << "POKY_BBLAYERS_CONF_VERSION = \"2\"\n\n" << "BBPATH = \"${TOPDIR}\"\n" << "BBFILES ?= \"\"\n\n" << "BBLAYERS ?= \" \\\n  " <<
        QDir::currentPath() <<"/scripts/poky/meta \\\n  "<<
        QDir::currentPath() <<"/scripts/poky/meta-poky \\\n  "  <<
        QDir::currentPath() <<"/scripts/poky/meta-yocto-bsp \\\n  "<<
        QDir::currentPath() <<"/scripts/poky/meta-raspberrypi \\\n  "<<
        QDir::currentPath() <<"/scripts/poky/meta-openembedded/meta-oe \\\n  "<<
        QDir::currentPath() <<"/scripts/poky/meta-openembedded/meta-multimedia \\\n  "<<
        QDir::currentPath() <<"/scripts/poky/meta-openembedded/meta-networking \\\n  "<<
        QDir::currentPath() <<"/scripts/poky/meta-openembedded/meta-python \\\n  "<<
        QDir::currentPath() <<"/scripts/poky/meta-qt5 \\\n  \"";

    file.close();

}

void MainWindow::copyfile(){
    QString path ="scripts/poky/build/tmp/deploy/images/";              //raspberrypi-cm3/core-image-minimal-raspberrypi-cm3.rpi-sdimg of=/dev/sdc bs=1M";
    path.append(ui->Machine_combobox->currentText()+"/core-image-base-"+ui->Machine_combobox->currentText()+"."+ui->Output_combobox->currentText());

    //QMessageBox::information(this,"Information about make",path + "\n" + pathdest);
    QProcess mv;
                    mv.setProcessChannelMode(QProcess::MergedChannels);
                    mv.start("cp",  QStringList() << path << pathdest) ;
                    mv.waitForFinished();
    return;
}

void MainWindow::readyReadStandardOutput(){

    QString output=processmake->readAllStandardOutput(),
            sucess="all succeeded.";
    if(output.contains(sucess)){
        copyfile();
    }
    if(output.contains("You can now run 'bitbake"))
        refresh_param();
        update_bblayers();
    makew.updatetextbox(output);
}

void MainWindow::readyReadStandardError(){
    QString error=processmake->readAllStandardError();
    //makew.updatetextbox(error);
}

void MainWindow::on_No_password_checkbox_clicked(bool checked)
{
    if(!checked){
        ui->lineEdit->setEnabled(1);
        password = QInputDialog::getText(this,tr("Password"),
                                         tr("Boot Password:"), QLineEdit::Password,
                                         "root");

    }
    if(checked){

    }


}

void MainWindow::update_Password(QString *temp_file){
    QString addpass,new_pass;
    QString username;
    if(ui->lineEdit->text().isEmpty())
        username="root";
    else {
        username=ui->lineEdit->text();
    }
    if(password.isEmpty())
        password="root";
    temp_file->replace("debug-tweaks","");
    int index=temp_file->indexOf("EXTRA_USERS_PARAMS = \"usermod -P");
    if(index>=0){
        int end_index=temp_file->indexOf("\n",index);
        int size=end_index-index+0;
        new_pass.append("EXTRA_USERS_PARAMS = \"usermod -P "+password+ " " +username + "\"\n");
        temp_file->replace(index,size,new_pass);}
        else {
            addpass.append("INHERIT += \"extrausers\"\nEXTRA_USERS_PARAMS = \"usermod -P "+password+ " " +username + "\"\n");
            temp_file->append(addpass);
        }

    }

void MainWindow::update_IP_interface(){
    int LastIpSize;
    QFile file("scripts/poky/meta/recipes-core/init-ifupdown/init-ifupdown-1.0/interfaces");
    QString Ip_static="", temp_file="";
    QTextStream in(&file);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)){
        temp_file=file.readAll();
        if(temp_file.contains("auto eth0"))
                temp_file.replace("auto eth0\n","");
        Ip_static.append("iface eth0 inet static\naddress "+ip_interface +"\nbroadcast 192.168.0.255\nnetmask 255.255.255.0\n");   
        if(temp_file.contains("iface eth0 inet dhcp")){
            temp_file.replace(QString("iface eth0 inet dhcp"),Ip_static);
        }
        else if(temp_file.contains("iface eth0 inet static")){
            QString begin_Ip="iface eth0 inet static\naddress ";
            int index=temp_file.lastIndexOf(begin_Ip);
            index=index+begin_Ip.length();
            int last_index=temp_file.indexOf("broadcast")-1;
            LastIpSize=last_index-index;
            temp_file.replace(index,LastIpSize,ip_interface);
        }
        else {
            temp_file.append(Ip_static);
        }
        QMessageBox::information(this,"Information about make",temp_file);
       // file.seek(0);
        file.resize(0);
        //file.write(temp_file.toUtf8());
        in.flush();
        in << temp_file;
        file.flush();
        file.close();


    }
}

void MainWindow::on_SSH_CheckBox_clicked(bool checked)
{
    if(checked){
        ip_interface=QInputDialog::getText(this,tr("Ip"),
                                           tr("Ip for ssh:"), QLineEdit::Normal,
                                           "192.168.0.2");
        ip_interface.replace(QString(" "),QString(""));
        update_IP_interface();
    }

}

void MainWindow::update_geral_conf(QString feature, QString* file, QString check){
    QString file_temp;
    file_temp.sprintf("%s",file->toStdString().c_str());
    int index=file->indexOf(feature);
    feature.append(check+"\"\n");
    if(index>0){
        int temp_size=feature.length();
        int size=int_size_string(file_temp, feature, "\"");
        file->replace(index,size+temp_size,feature);
    }
    if(index<=0){
        file->append(feature);}
}
