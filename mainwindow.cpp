#include "mainwindow.h"
#include "myqueue.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    refreshQueue();  
    this->setStyleSheet(
        "background-color: #181818;"
        "color: white;");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::refreshQueue() {
    ui->listWidget_2->clear();
    for (int val : queue.toVector()) {
        ui->listWidget_2->addItem(QString::number(val));
    }
}

void MainWindow::on_btnGenerate_clicked() {
    if (queue.isEmpty()) {
        queue.generateRandom(10, -50, 50);
        ui->listWidgetOperations->addItem("Generated 10 random numbers between -50 and 50");
        ui->listWidgetOperations->scrollToBottom();
        refreshQueue();
    }
    else {
            queue.clear();
            queue.generateRandom(10, -50, 50);
            ui->listWidgetOperations->addItem("Generated 10 random numbers between -50 and 50");
            ui->listWidgetOperations->scrollToBottom();
            refreshQueue();
        }
}

void MainWindow::on_btnPush_clicked() {
    bool ok;
    int val = QInputDialog::getInt(this, tr("Push back"), tr("Value:"), 0, -10000, 10000, 1, &ok);
    if (ok) {
        queue.PushBack(val);
        ui->listWidgetOperations->addItem("Pushed back: " + QString::number(val));
        ui->listWidgetOperations->scrollToBottom();
        refreshQueue();
    }
}

void MainWindow::on_btnPop_clicked() {
    try {
        int val = queue.PopFront();
        ui->listWidgetOperations->addItem("Popped front: " + QString::number(val));
        refreshQueue();
    } catch (const std::exception &e) {
        ui->listWidgetOperations->addItem("Attempted to pop front: " + QString(e.what()));
        QMessageBox::warning(this, tr("Pop front"), e.what());
    }
    ui->listWidgetOperations->scrollToBottom();
}

void MainWindow::on_btnHead_clicked() {
    try {
        int val = queue.Head();
        ui->listWidgetOperations->addItem("Queried Head: " + QString::number(val));
    } catch (const std::exception &e) {
        ui->listWidgetOperations->addItem("Attempted to query Head: " + QString(e.what()));
        QMessageBox::warning(this, tr("Head"), e.what());
    }
    ui->listWidgetOperations->scrollToBottom();
}

void MainWindow::on_btnTail_clicked() {
    auto vec = queue.toVector();
    if (vec.isEmpty()) {
        ui->listWidgetOperations->addItem("Queried Tail: Queue is empty");
    } else {
        int val = vec.back();
        ui->listWidgetOperations->addItem("Queried Tail: " + QString::number(val));
    }
    ui->listWidgetOperations->scrollToBottom();
}

void MainWindow::on_btnSize_clicked() {
    int sz = queue.size();
    ui->listWidgetOperations->addItem("Queried Size: " + QString::number(sz));
    ui->listWidgetOperations->scrollToBottom();
}

void MainWindow::on_btnEmpty_clicked() {
    bool emp = queue.isEmpty();
    ui->listWidgetOperations->addItem("Queried Empty: " + (emp ? QString("Yes") : QString("No")));
    ui->listWidgetOperations->scrollToBottom();
}

void MainWindow::on_btnClear_clicked() {
    queue.clear();
    ui->listWidgetOperations->addItem("Cleared the queue");
    ui->listWidgetOperations->scrollToBottom();
    refreshQueue();
}

void MainWindow::on_btnRemoveNeg_clicked() {
    if (queue.isEmpty())
        ui->listWidgetOperations->addItem("Queue is empty");
    else {
        queue.removeNegatives();
        ui->listWidgetOperations->addItem("Removed all negative numbers");
        ui->listWidgetOperations->scrollToBottom();
        refreshQueue();
    }
}

