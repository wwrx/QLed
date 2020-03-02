#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_setup_clicked()
{
    QList<QColor> colors;
    colors.append(QColor("red"));
    colors.append(QColor("orange"));
    colors.append(QColor("yellow"));
    colors.append(QColor("green"));
    colors.append(QColor("blue"));
    colors.append(QColor("indigo"));
    colors.append(QColor("violet"));

    // Iterate over all widgets
    QGridLayout *layout = qobject_cast<QGridLayout*>(this->centralWidget()->layout());
    for(int row=1; row<layout->rowCount(); row++){
        for(int col=0; col<layout->columnCount(); col++){
            QLed *item = qobject_cast<QLed*>((layout->itemAtPosition(row, col)->widget()));
            item->setShape(QLed::ledShape(row-1));
            item->setColor(colors.at(col));
            //item->setOnColor(colors.at(col));
            //item->setOffColor(QColor("grey"));
            item->setValue(false);
        }
    }
}

void MainWindow::on_pushButton_toggle_clicked()
{
    QGridLayout *layout = qobject_cast<QGridLayout*>(this->centralWidget()->layout());
    for(int row=1; row<layout->rowCount(); row++){
        for(int col=0; col<layout->columnCount(); col++){
            QLed *item = qobject_cast<QLed*>((layout->itemAtPosition(row, col)->widget()));
            item->toggleValue();
        }
    }
}


