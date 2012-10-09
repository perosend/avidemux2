/***************************************************************************
  FAC_toggle.cpp
  Handle dialog factory element : Toggle
  (C) 2006 Mean Fixounet@free.fr 
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QSpinBox>



#include "ADM_default.h"
#include "DIA_factory.h"
#include "ADM_dialogFactoryQt4.h"

extern const char *shortkey(const char *);

namespace ADM_Qt4Factory
{
/**
 *      \class diaElemTimeStamp
 *      \brief Qt4 version of diaElemTimeStamp
 */
class diaElemTimeStamp : public diaElem
{
  protected :
        uint32_t valueMin;
        uint32_t valueMax;
public:
  
  diaElemTimeStamp(uint32_t *v,const char *toggleTitle,const uint32_t vmin, const uint32_t vmax);
  virtual ~diaElemTimeStamp() ;
  void setMe(void *dialog, void *opaque,uint32_t line);
  void getMe(void);
  int getRequiredLayout(void);
};

/**
 * \fn diaElemTimeStamp
 * @param percent
 * @param toggleTitle
 */
diaElemTimeStamp::diaElemTimeStamp(uint32_t *v,const char *toggleTitle,const uint32_t vmin, const uint32_t vmax)
  : diaElem(ELEM_TIMESTAMP)
{
  param=v;
  valueMin=vmin;
  valueMax=vmax;
  paramTitle=shortkey(toggleTitle);
 }
/**
 * \fn diaElemTimeStamp
 * \brief dtor
 */
diaElemTimeStamp::~diaElemTimeStamp()
{
  if(paramTitle)
    delete paramTitle;
}
/**
 * \fn          setMe
 * \brief       construct UI to display editable timestamp
 * @param dialog
 * @param opaque
 * @param line
 */
void diaElemTimeStamp::setMe(void *dialog, void *opaque,uint32_t line)
{
QSpinBox *box=new QSpinBox((QWidget *)dialog);
  QGridLayout *layout=(QGridLayout*) opaque;
  QHBoxLayout *hboxLayout = new QHBoxLayout();
 myWidget=(void *)box; 
   
 box->setValue(*(uint32_t *)param);
 
 QLabel *text=new QLabel( QString::fromUtf8(this->paramTitle),(QWidget *)dialog);
 text->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
 text->setBuddy(box);

 QSpacerItem *spacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

 hboxLayout->addWidget(box);
 hboxLayout->addItem(spacer);

 layout->addWidget(text,line,0);
 layout->addLayout(hboxLayout,line,1);
 
}
/**
 * \fn getMe
 * \brief retrieve value from UI
 */
void diaElemTimeStamp::getMe(void)
{
        uint32_t val;
        QSpinBox *box=(QSpinBox *)myWidget;
        val=box->value();
        if(val<valueMin) val=valueMin;
        if(val>valueMax) val=valueMax;
        *(uint32_t *)param=val;
 
}

int diaElemTimeStamp::getRequiredLayout(void) { return FAC_QT_GRIDLAYOUT; }
} // nameapsce
/**
 * \fn qt4CreateTimeStamp
 * @param v
 * @param toggleTitle
 * @param vmin
 * @param vmax
 * @return 
 */
diaElem  *qt4CreateTimeStamp(uint32_t *v,const char *toggleTitle,const uint32_t vmin, const uint32_t vmax)
{
	return new  ADM_Qt4Factory::diaElemTimeStamp(v,toggleTitle,vmin,vmax);
}
void qt4DestroyTimeStamp(diaElem *e)
{
	ADM_Qt4Factory::diaElemTimeStamp *a=(ADM_Qt4Factory::diaElemTimeStamp *)e;
	delete a;
}
//
//EOF