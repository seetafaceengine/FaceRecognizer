#ifndef CFACESEETA_H_KL_2019_10_21
#define CFACESEETA_H_KL_2019_10_21

#pragma once

#include "Face.h"
#include "DetectorSeeta.h"
#include "LandmarkerSeeta.h"
#include "RecognizerSeeta.h"
#include <QSharedPointer>

class CFaceSeeta : public CFace
{
    Q_OBJECT
public:
    CFaceSeeta(QObject* parent = nullptr);
    virtual ~CFaceSeeta();
    
    virtual CDetector* GetDector();
    virtual CLandmarker* GetLandmarker();
    virtual CRecognizer* GetRecognizer();
    
private:
    CDetectorSeeta* m_pDetector;
    CLandmarkerSeeta* m_pLandmark;
    CRecognizerSeeta* m_pRecognizer;
};

#endif // CFACESEETA_H_KL_2019_10_21
