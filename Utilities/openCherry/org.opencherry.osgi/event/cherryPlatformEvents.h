/*=========================================================================
 
Program:   openCherry Platform
Language:  C++
Date:      $Date$
Version:   $Revision$
 
Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.
 
This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.
 
=========================================================================*/

#ifndef CHERRYPLATFORMEVENTS_H_
#define CHERRYPLATFORMEVENTS_H_

#include "../cherryDll.h"

#include "../cherryMessage.h"

#include "cherryPlatformEvent.h"

namespace cherry {

struct CHERRY_API PlatformEvents
{
  Message1<const PlatformEvent&> platformStarted;
  Message1<const PlatformEvent&> platformError;
  Message1<const PlatformEvent&> platformWarning;
  
  Message1<const PlatformEvent&> logged;
};

}

#endif /*CHERRYPLATFORMEVENTS_H_*/
