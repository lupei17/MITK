#ifndef MITKDOPPLERTOSTRAINRATEFILTER_H_HEADER_INCLUDED_C1F48A22
#define MITKDOPPLERTOSTRAINRATEFILTER_H_HEADER_INCLUDED_C1F48A22

#include "mitkCommon.h"
#include "mitkImageToImageFilter.h"
#include <vecmath.h>


#define M_PI       3.14159265358979323846
//#endif

namespace mitk {
//##Documentation
//## @brief 
//## @ingroup Process

class DopplerToStrainRateFilter : public ImageToImageFilter
{
public:
  mitkClassMacro(DopplerToStrainRateFilter, ImageToImageFilter);

	itkNewMacro(Self);

  itkSetMacro(Distance, float);
	itkGetMacro(Distance, float);

  itkSetMacro(NoStrainInterval, int);
	itkGetMacro(NoStrainInterval, int);

	float GetLimit();

protected:

  //##Description 
  //## @brief Time when Header was last initialized
  itk::TimeStamp m_TimeOfHeaderInitialization;
 
 
protected:
  virtual void GenerateData();

	virtual void GenerateOutputInformation();

	virtual void GenerateInputRequestedRegion();

  
	DopplerToStrainRateFilter();

    ~DopplerToStrainRateFilter();


private:

  float m_Distance;
  int m_NoStrainInterval;
  Point3<int> m_Origin;  
    
};

} // namespace mitk

#endif /* MITKDOPPLERTOSTRAINRATE_H_HEADER_INCLUDED_C1F48A22 */

