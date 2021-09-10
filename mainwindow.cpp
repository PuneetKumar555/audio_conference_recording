#include "mainwindow.h"
#include "util.h"
#include "ui_mainwindow.h"
#include <QDebug>
#define RECORDER 1
MainWindow *pMainWnd;
const char * record_file= "recording.wav";
pjsua_call_info CI;
pjsua_recorder_id rec_id;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    custom_init();
    pMainWnd = this;
}

MainWindow::~MainWindow()
{
    delete ui;
}

static void on_incoming_call(pjsua_acc_id acc_id, pjsua_call_id call_id,
                             pjsip_rx_data *rdata)
{
    pjsua_call_info ci;

    PJ_UNUSED_ARG(acc_id);
    PJ_UNUSED_ARG(rdata);


    pjsua_call_get_info(call_id, &ci);

    PJ_LOG(3,(THIS_FILE, "Incoming call from %.*s!!",
              (int)ci.remote_info.slen,
              ci.remote_info.ptr));

    /* Automatically answer incoming calls with 200/OK */
    pMainWnd->updateText();

    pjsua_call_answer(call_id, 200, NULL, NULL);
    PJ_LOG(3,(THIS_FILE, "slot kya hai  %d!!",ci.conf_slot));

}


/* Callback called by the library when call's state has changed */
static void on_call_state(pjsua_call_id call_id, pjsip_event *e)
{
    pjsua_call_info ci;

    PJ_UNUSED_ARG(e);

    pjsua_call_get_info(call_id, &ci);

    PJ_LOG(3,(THIS_FILE, "Call %d state=%.*s", call_id,
              (int)ci.state_text.slen,
              ci.state_text.ptr));

}


/***********************************************************************/
static void on_call_media_event(pjsua_call_id call_id,
                                unsigned med_idx,
                                pjmedia_event *event)
{
    qDebug()<<"this function is being called";
    qDebug()<< event->type;
    if (event->type == PJMEDIA_EVENT_RX_RTCP_FB) {
        /* Incoming RTCP-FB event */
        pjmedia_event_rx_rtcp_fb_data *fb_data = (pjmedia_event_rx_rtcp_fb_data*)event->data.ptr;
        if (fb_data->cap.type == PJMEDIA_RTCP_FB_NACK && fb_data->cap.param.slen == 0)
        {
            /* Generic NACK */
            /* NACK message can be accessed via 'fb_data->msg.nack' */
            qDebug()<< "***************************************************";
        }
    }
}
/***********************************************************************/

/* Callback called by the library when call's media state has changed */

static void on_call_media_state(pjsua_call_id call_id)
{
    pjsua_call_info ci;

    pjsua_call_get_info(call_id, &ci);


    if (ci.media_status == PJSUA_CALL_MEDIA_ACTIVE) {
        // When media is active, connect call to sound device.
        pjsua_conf_connect(ci.conf_slot, 0);
        pjsua_conf_connect(0, ci.conf_slot);
        CI= ci;
        PJ_LOG(3,(THIS_FILE, "slot kya hai  %d!!",ci.conf_slot));

    }

    if(ci.conf_slot>=3)     // 4 people
    {

        int max_slot= ci.conf_slot;
        pjsua_conf_connect(max_slot, max_slot-1);
        pjsua_conf_connect(max_slot-1, max_slot);

        pjsua_conf_connect(max_slot, max_slot-2);
        pjsua_conf_connect(max_slot-2, max_slot);
        /**********************************/

    }
    else if(ci.conf_slot>=2)     // 3 people
    {
        qDebug()<< "conf call start ho  >=4(total 3 candidate)";
        int max_slot= ci.conf_slot;
        pjsua_conf_connect(max_slot, max_slot-1);
        pjsua_conf_connect(max_slot-1, max_slot);
    }



}


static void error_exit(const char *title, pj_status_t status)
{
    qDebug()<< "\n*****************************************************************error occured\n";
    pjsua_perror(THIS_FILE, title, status);
    pjsua_destroy();
    exit(1);
}



void MainWindow::on_pb_call_clicked()
{

    QString temp8 =  "sip:100@10.0.0.227:5060";
    QString temp= ui->le_user->text();
    qDebug()<< "\n********\n"<<temp;
    qDebug()<<"\n**************************************************Hello world\n";
    QByteArray ba7= temp.toLocal8Bit();
    char * c7 = ba7.data();
    pj_str_t uri = pj_str(c7);

    status = pjsua_call_make_call(acc_id, &uri, 0, NULL, NULL, NULL);
    if (status != PJ_SUCCESS) error_exit("Error making call", status);

}


void MainWindow::custom_init()
{

    int argc =2;

    qDebug()<< "*************************************custom init";

    /* Create pjsua first! */
    status = pjsua_create();
    if (status != PJ_SUCCESS) error_exit("Error in pjsua_create()", status);



    /* Init pjsua */
    {
        pjsua_config cfg;
        pjsua_logging_config log_cfg;

        pjsua_config_default(&cfg);
        cfg.cb.on_incoming_call = &on_incoming_call;
        cfg.cb.on_call_media_state = &on_call_media_state;
        cfg.cb.on_call_state = &on_call_state;
        cfg.cb.on_call_media_event= &on_call_media_event; // adding line for checking for rtcp-fb

        pjsua_logging_config_default(&log_cfg);
        log_cfg.console_level = 4;

        status = pjsua_init(&cfg, &log_cfg, NULL);
        if (status != PJ_SUCCESS) error_exit("Error in pjsua_init()", status);
    }

    /* Add UDP transport. */
    {
        pjsua_transport_config cfg;

        pjsua_transport_config_default(&cfg);
        cfg.port = 5060;
        status = pjsua_transport_create(PJSIP_TRANSPORT_UDP, &cfg, NULL);
        if (status != PJ_SUCCESS) error_exit("Error creating transport", status);
    }

    /* Initialization is done, now start pjsua */
    status = pjsua_start();
    if (status != PJ_SUCCESS) error_exit("Error starting pjsua", status);

    /* Register to SIP server by creating SIP account. */
    {
        pjsua_acc_config cfg;
        qDebug()<< "avpf value true/false before ::" << cfg.rtcp_fb_cfg.dont_use_avpf;
        cfg.rtcp_fb_cfg.dont_use_avpf= PJ_FALSE;
        qDebug()<< "avpf value true/false after::" << cfg.rtcp_fb_cfg.dont_use_avpf;

        pjsua_acc_config_default(&cfg);


        pjmedia_rtcp_fb_setting_default(&cfg.rtcp_fb_cfg);
        qDebug()<< "avpf value true/false after calling api itself::" << cfg.rtcp_fb_cfg.dont_use_avpf;

        QString temp1 = "sip:" SIP_USER "@" SIP_DOMAIN;
        QByteArray ba1= temp1.toLocal8Bit();
        char * c1 = ba1.data();
        cfg.id = pj_str(c1);

        QString temp2 = "sip:" SIP_DOMAIN;
        QByteArray ba2= temp2.toLocal8Bit();
        char * c2 = ba2.data();
        cfg.reg_uri = pj_str(c2);


        cfg.cred_count = 1;

        QString temp3 =  SIP_DOMAIN;
        QByteArray ba3= temp3.toLocal8Bit();
        char * c3 = ba3.data();
        cfg.cred_info[0].realm = pj_str(c3);

        QString temp4 =  "digest";
        QByteArray ba4= temp4.toLocal8Bit();
        char * c4 = ba4.data();
        cfg.cred_info[0].scheme = pj_str(c4);


        QString temp5 =  SIP_USER;
        QByteArray ba5= temp5.toLocal8Bit();
        char * c5 = ba5.data();
        cfg.cred_info[0].username = pj_str(c5);





        cfg.cred_info[0].data_type = PJSIP_CRED_DATA_PLAIN_PASSWD;




        QString temp6 =  SIP_PASSWD;
        QByteArray ba6= temp6.toLocal8Bit();
        char * c6 = ba6.data();
        cfg.cred_info[0].data = pj_str(c6);

        status = pjsua_acc_add(&cfg, PJ_TRUE, &acc_id);
        if (status != PJ_SUCCESS) error_exit("Error adding account", status);
    }

}

void MainWindow::updateText()
{
    ui->le_incomingcallinfo->setText("Lo, mai aa gya .. hahahaha");
}

void MainWindow::on_pb_hungup_clicked()
{
    qDebug()<<"hang up call";
    pjsua_call_hangup_all();
    pj_thread_sleep(100);
    pjsua_destroy();
    qDebug()<< "end";

}

void MainWindow::on_pb_call_2_clicked()
{

    pj_str_t rec_file = pj_str(const_cast<char*>(record_file));
    pj_status_t status = PJ_ENOTFOUND;
    pjsua_recorder_id recID;


    // Create recorder for call
    status = pjsua_recorder_create(&rec_file, 0, NULL, 0, 0, &recID);
    if (status != PJ_SUCCESS) error_exit("Error recording answer", status);

    // connect active call to call recorder
    pjsua_conf_port_id rec_port = pjsua_recorder_get_conf_port(recID);
    //pjsua_conf_connect(CI.conf_slot, rec_port);
    qDebug()<< "rec_port " << rec_port;
    pjsua_conf_connect(0, rec_port); // connect self user to recording port
    pjsua_conf_connect(1, rec_port);  // connect 2nd user to recording port
    pjsua_conf_connect(2, rec_port); // connect 3rd user to recording port

    /* above code is only just for testing , this can also be done using simple for loop*/
}
