// mainwindow.h
#include <QMainWindow>
#include "myqueue.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE



class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_btnGenerate_clicked();
    void on_btnPush_clicked();
    void on_btnPop_clicked();
    void on_btnHead_clicked();
    void on_btnTail_clicked();
    void on_btnSize_clicked();
    void on_btnEmpty_clicked();
    void on_btnClear_clicked();
    void on_btnRemoveNeg_clicked();

private:
    MyQueue queue;
    Ui::MainWindow *ui;
    void refreshOperations();
    void refreshQueue();
};
