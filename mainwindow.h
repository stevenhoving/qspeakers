#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPrinter>

#include "speakerdialog.h"
#include "searchdialog.h"
#include "listdialog.h"
#include "bandpassdialog.h"
#include "speaker.h"
#include "sealedbox.h"
#include "portedbox.h"
#include "bandpassbox.h"
#include "plot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void currentSpeakerChanged(Speaker spk);
    void currentSealedBoxChanged(SealedBox box);
    void currentPortedBoxChanged(PortedBox box);
    void currentBandPassBoxChanged(BandPassBox box);

public slots:
    void onProjectSave();
    void onProjectExport();
    void onProjectImport();
    void onProjectQuit();
    void onSpeakerNew();
    void onSpeakerRemove();
    void onSpeakerModify();
    void onSpeakerInserted(Speaker spk);
    void onSpeakerCancelled();
    void onEditOptimize();
    void onSpeakerSearch();
    void onProjectPrint();
    void onAboutAbout();

    void onSearchRequested(const QString& param, double min, double max);
    void onSearchCancelled();
    void onSpeakerItemSelected(QString title, const Speaker &speaker);
    void onSpeakerItemCancelled();

    void onCurrentTabChanged(int tab);

    void onNumberSpinChanged(int number);
    void onVendorChanged(QString vendor);
    void onModelChanged(QString model);

    void onCurrentSpeakerChanged(const Speaker& spk);

    void onCurrentSealedBoxChanged(const SealedBox& box);
    void onCurrentPortedBoxChanged(const PortedBox& box);
    void onCurrentBandPassBoxChanged(const BandPassBox& box);

    void onSealedVolumeDoubleSpinChanged(double val);

    void onPortedVolumeDoubleSpinChanged(double val);
    void onPortedResonanceDoubleSpinChanged(double val);
    void onPortedPortsNumberSpinChanged(int val);
    void onPortedPortDiameterDoubleSpinChanged(double val);
    void onPortedSlotWidthDoubleSpinChanged(double val);
    void onPortedSlotPortActivated();

    void onBandPassSealedVolumeDoubleSpinChanged(double val);
    void onBandPassPortedVolumeDoubleSpinChanged(double val);
    void onBandPassPortedResonanceDoubleSpinChanged(double val);
    void onBandPassPortNumSpinChanged(int val);
    void onBandPassPortDiameterDoubleSpinChanged(double val);

    void onAlignModerate_Inf();
    void onAlignLegendre();
    void onAlignBessel();
    void onAlignBullock();
    void onAlignKeele_Hoge();

    void onBandpassAlignment();
    void onBandpassOptimizeRequested(double s, double pa);
    void onBandpassOptimizeCancelled();

protected:
    void linkMenus();
    void linkTabs();
    void linkInternals();
    void unlinkMenus();
    void unlinkTabs();
    void unlinkInternals();
    bool print(QPrinter* printer);
    void syncUiFromCurrentSpeaker(const Speaker &spk);
    void syncUiFromCurrentSealedBox(const SealedBox& box);
    void syncUiFromCurrentPortedBox(const PortedBox& box);
    void syncUiFromCurrentBandPassBox(const BandPassBox& box);
    void setActivateActions(QList<QAction *> actions, bool enable);
    void setCurrentSpeaker(const Speaker& spk);   

private:
    static QString getHome();

    Ui::MainWindow *ui;
    bool projectSaved;
    bool isModifying;
    SpeakerDialog *spkDialog;
    QFileDialog *fileDialog;
    SearchDialog *searchDialog;
    ListDialog *listDialog;
    BandpassDialog *bandpassDialog;

    Speaker currentSpeaker;
    int currentSpeakerNumber;
    SealedBox currentSealedBox;
    PortedBox currentPortedBox;
    BandPassBox currentBandPassBox;

    int currentTabIndex;

    Plot *sealedPlot;
    Plot *portedPlot;
    Plot *bandpassPlot;

    const Speaker *notInDbSpeaker;
};

#endif // MAINWINDOW_H
