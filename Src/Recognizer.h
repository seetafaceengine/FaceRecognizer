#ifndef CRECOGNIZER_H_KL_2019_10_21_
#define CRECOGNIZER_H_KL_2019_10_21_

#pragma once
#include <QObject>
#include <QImage>

#include "facerecognizer_export.h"
#include "ParameterRecognizer.h"

class FACERECOGNIZER_EXPORT CRecognizer : public QObject
{
    Q_OBJECT
public:
    CRecognizer(QObject* parent = nullptr);
    virtual ~CRecognizer();
    
    virtual int SetParameter(CParameterRecognizer *pPara);
    
    /**
     * @brief Register face and save register image
     * @param image: face image
     * @param points: feature points
     * @return register index. other return -1.
     */
    virtual qint64 Register(const QImage &image,
                            const QVector<QPointF> &points) = 0;
    virtual int Delete(const qint64 &index) = 0;
    
    /**
     * @brief Query register face
     * @param image: query face image
     * @param points: feature points
     * @return find index. other return -1
     */
    virtual qint64 Query(/*[in]*/ const QImage &image,
                        /*[in]*/ const QVector<QPointF> &points) = 0;
    /**
     * @brief Save feature to file
     * @param szFile: feature file name
     * @return 
     */
    virtual int Save(const QString &szFile = QString()) = 0;
    /**
     * @brief Load feature from file
     * @param szFile: feature file name
     * @return 
     */
    virtual int Load(const QString &szFile = QString()) = 0;
    
    /**
     * @brief GetRegisterImage
     * @param index: search register image index.
     *        when is -1, get register image path
     * @return register image file or path
     */
    virtual QString GetRegisterImage(qint64 index = -1);
   
public Q_SLOTS:
    void slotParameterUpdate();
    void slotParameterDelete();

protected:
    virtual void UpdateParameter() = 0;

    CParameterRecognizer* m_pParameter;
};

#endif // CRECOGNIZER_H_KL_2019_10_21_
