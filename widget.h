#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qdom.h"
#include <QMainWindow>
#include <QMenuBar>

class QStandardItemModel;
namespace Ui {
class Widget;
}

//类的定义
class Widget : public QMainWindow// 4)类名冒号后面的是用来定义类的继承
{
    Q_OBJECT//必须在类的私有声明中声明这个宏，这样就可以使用Qt的信号槽机制等Qt特有的功能，否则无法使用。
    
public:
    explicit Widget(QWidget *parent = 0);//构造函数，其中parent参数，可指定父窗口
    ~Widget();
    enum DateTimeType{Time,Date,DateTime};
    QString getDateTime(DateTimeType type);
    QMenu *manageMenu;
    QMenu *passwordMenu;
    QMenu *mainMenu;
    QMenu *realstaMenu;
    QMenu *basesettingMenu;
    QMenu *advsettingMenu;
    QMenu *parsettingMenu;
    QMenu *videoMenu;
    QMenu *voiceMenu;
    QMenu *SpecMenu;
    QMenu *lookMenu;
    QMenu *aboutMenu;
    QMenu *exitMenu;
    QAction *manageAction;
    QAction *chartAction;
    QAction *quitAction;
    
private slots:
    void on_sellBrandComboBox_currentIndexChanged(const QString &arg1);

    void on_sellNumSpinBox_valueChanged(int arg1);

    void on_sellCancelBtn_clicked();

    void on_sellOkBtn_clicked();

    void on_updateBtn_clicked();

    //void on_manageBtn_clicked();

    //void on_chartBtn_clicked();

    void on_manageMenu_clicked();

    void on_chartMenu_clicked();

    void on_quitMenu_clicked();

    void on_sellFactoryComboBox_currentIndexChanged(const QString &arg1);

    void on_factoryComboBox_currentIndexChanged(const QString &arg1);

private:
    //3)表示引用成员函数及变量，作用域成员运算符 例：System::Math::Sqrt() 相当于System.Math.Sqrt()
    Ui::Widget *ui;//ui界面对象指针，凡是需要ui界面中的控件对象指针，都可以通过这个指针来进行调用访问。
    QDomDocument doc;
    bool docRead();
    bool docWrite();
    void writeXml();
    void createNodes(QDomElement &date);
    void showDailyList();
    QStandardItemModel *chartModel;
    void createChartModelView();
    void showChart();
    void createMenuBar();
};

#endif // WIDGET_H
