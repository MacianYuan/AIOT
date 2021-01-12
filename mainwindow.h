#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWizard>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;

    QWizardPage *createPage1();        // 新添加
    QWizardPage *createPage2();        // 新添加
    QWizardPage *createPage3();        // 新添加

private slots:

    void updateCurrentTime();
    void about();
    void wizard();
    void welcome();
    void snap();
};
#endif // MAINWINDOW_H
