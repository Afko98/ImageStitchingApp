#include "imageprocessing.h"
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QFileSystemWatcher>
#include <QImage>
#include <QMap>

ImageProcessing::ImageProcessing(QString LP, QString SP, int pFL, int w, QObject *parent)
    : QObject{parent}, LoadPath(LP), SavePath(SP), pixFromLeft(pFL), pixWidth(w)
{

}

void ImageProcessing::processImage()
{
    QDir directory(LoadPath);

    QStringList images = directory.entryList(QStringList() <<"*.tiff"<<"*.TIFF"<< "*.jpg" << "*.JPG" <<"*.png"<<"*.PNG",QDir::Files);

    std::sort(images.begin(),images.end(),[](QString a,QString b){a=a.split(QLatin1Char('.')).at(0);b=b.split(QLatin1Char('.')).at(0); return a.toInt()<b.toInt();});

    int imagHeight = (QImage(LoadPath+"/"+images.at(0), "QImage::Format_RGB32")).height();
    finalImage = QImage(640,imagHeight, QImage::Format_RGB32);
    int k=0;

    foreach(QString filename, images) {
        QString filename1=LoadPath+"/"+filename;
        qDebug()<<"FileName: "<<filename;
        currentImage = new QImage(filename1, "QImage::Format_RGB32");
        for (int j=pixFromLeft; j<pixWidth+pixFromLeft; j++){
            for (int i=0; i<imagHeight; i++){
                finalImage.setPixel(j+k*pixWidth,i,currentImage->pixelColor(j,i).rgb());
            }
        }
        k++;
        delete currentImage;
        currentImage=nullptr;
    }
    finalImage.save(SavePath+"/image.png");
    qDebug()<<"Done!";

}

ImageProcessing::~ImageProcessing()
{
    delete currentImage;
}

