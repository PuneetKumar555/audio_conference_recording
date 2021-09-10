#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTest>
#include <pjsua-lib/pjsua.h>
#include <pjmedia.h>
#include <pjlib-util.h>	/* pj_getopt */
#include <pjlib.h>
#include <pjmedia/rtcp_fb.h>

#define SIP_DOMAIN	"example.com"
#define SIP_USER	"alice"
#define SIP_PASSWD	"secret"
#define THIS_FILE	"APP"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    pjsua_acc_id acc_id;
    pj_status_t status;
    void custom_init();

    void updateText();

private slots:


    void on_pb_hungup_clicked();

    void on_pb_call_clicked();



    void on_pb_call_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
