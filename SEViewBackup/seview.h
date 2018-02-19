#ifndef SEVIEW_H
#define SEVIEW_H

#include <QWidget>
#include <QSet>
#include <QList>

#define APPWIDTH 375
#define APPHEIGHT 600
#define BUTTONSIZE 100

class QStackedWidget;
class QPushButton;
class CoverWidget;
class SubjectWidget;
class InferenceKernel;
class ConclusionsWidget;

namespace Ui {
class SEView;
}

class SEView : public QWidget
{
    Q_OBJECT

protected slots:
    void onAtomDisplayed(int atomEntry);
    void onBackClicked();
    void onAskClicked();
    void onNextClicked();
    void onConclusionDisplayed(QList<int> conclusions);
    void onKnowledgeBaseExhausted();
    void onToggledConclusions(QSet<int> subjectConclusions,bool checked);
    void onConclusionClicked(QString conclusionString);

private:
    bool isKnowledgeExhausted;
    InferenceKernel* inferenceKernel;
    QSet<int> topicConclusion;
    Ui::SEView* ui;
    ConclusionsWidget* conclusionsPage;
    CoverWidget* coverPage;
    SubjectWidget* subjectPage;
    QStackedWidget* pages;
    QPushButton* backButton;
    QPushButton* nextButton;
    QPushButton* askButton;

public:
    explicit SEView(InferenceKernel* ik,QWidget *parent = 0);
    QSet<int> getConclusionsByRule(QSet<int> rules);
    ~SEView();

protected:
    void paintEvent(QPaintEvent*);
};

#endif // SEVIEW_H
