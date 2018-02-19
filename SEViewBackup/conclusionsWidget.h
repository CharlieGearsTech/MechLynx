#ifndef CONCLUSIONSWIDGET_H
#define CONCLUSIONSWIDGET_H

#include <QWidget>

class QListWidget;
class QListWidgetItem;

class ConclusionsWidget : public QWidget
{
    Q_OBJECT
private:
    QListWidget* items;
public:
    explicit ConclusionsWidget(QWidget *parent = 0);
    void clearItems();
    void setItems(QStringList stringList);
signals:
    void conclusionClicked(QString conclusionString);
public slots:
    void onInsertConclusion(QString conclusion);
    void onItemDoubleClick(QListWidgetItem* item);
};

#endif // CONCLUSIONSWIDGET_H
