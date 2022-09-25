#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QFileSystemWatcher>
#include <QImage>
#include <QList>

class ImageProcessing : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessing(QString, QString, int, int, QObject *parent = nullptr);
    void processImage();
    ~ImageProcessing();
signals:

private:
    QImage finalImage;
    QImage *currentImage = nullptr;
    QString LoadPath;
    QString SavePath;
    int pixFromLeft;
    int pixWidth;
};

#endif // IMAGEPROCESSING_H
