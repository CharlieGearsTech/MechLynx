#include "conclusionsWidget.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>


ConclusionsWidget::ConclusionsWidget(QWidget *parent) : QWidget(parent)
{
    QLabel* title=new QLabel("Conclusion was found",this);
    items=new QListWidget(this);

    QVBoxLayout* mainLayout=new QVBoxLayout;
    mainLayout->addWidget(title);
    mainLayout->addWidget(items);

    setLayout(mainLayout);

    connect(items,SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this,SLOT(onItemDoubleClick(QListWidgetItem*)));
}

void ConclusionsWidget::onInsertConclusion(QString conclusion){
    QListWidgetItem* item=new QListWidgetItem(
                QIcon(":/SEResources/logo.png"),conclusion);
    items->addItem(item);
}

void ConclusionsWidget::onItemDoubleClick(QListWidgetItem *item){
    QString explanation=item->text().replace(" ","_");

    emit conclusionClicked(explanation);
}

void ConclusionsWidget::clearItems(){
    items->clear();
}

void ConclusionsWidget::setItems(QStringList stringList){
    foreach(QString symbol,stringList){
        QListWidgetItem* item=new QListWidgetItem(
                    QIcon(":/SEResources/logo.png"),symbol);
        items->addItem(item);
    }
}


