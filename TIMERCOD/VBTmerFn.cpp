/*******************************************************************************
* FILE NAME: VBTmerFn.cpp                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Class implementation of the class:                                         *
*     VBTimerFn- Timer function class for VBTimer                              *
* ---------------------------------------------------------------------------- *
* Warning: This file was generated by the VisualAge C++ Visual Builder.        *
* Modifications to this source file will be lost when the part is regenerated. *
*******************************************************************************/
#ifndef _INOTIFEV_
#include <inotifev.hpp>
#endif

#ifndef _IOBSERVR_
#include <iobservr.hpp>
#endif

#ifndef _ISTDNTFY_
#include <istdntfy.hpp>
#endif

#ifndef _VBTIMERFN_
#include "VBTmerFn.hpp"
#endif

#ifndef _IVBDEFS_
#include <ivbdefs.h>
#endif

#ifndef _ITRACE_
#include <itrace.hpp>
#endif


#pragma export (VBTimerFn::readyId)
const INotificationId VBTimerFn::readyId = "VBTimerFn::readyId";
//------------------------------------------------------------------------------
// VBTimerFn :: VBTimerFn
//------------------------------------------------------------------------------
#pragma export (VBTimerFn::VBTimerFn(VBTimer*))
VBTimerFn::VBTimerFn(VBTimer* timer)
{
   setTimer(timer);
}     //end constructor


//------------------------------------------------------------------------------
// VBTimerFn :: ~VBTimerFn
//------------------------------------------------------------------------------
#pragma export (VBTimerFn::~VBTimerFn())
VBTimerFn::~VBTimerFn()
{

}

//------------------------------------------------------------------------------
// VBTimerFn :: initializePart
//------------------------------------------------------------------------------
#pragma export (VBTimerFn::initializePart())
VBTimerFn & VBTimerFn::initializePart()
{
   makeConnections();
   return *this;
}


//------------------------------------------------------------------------------
// VBTimerFn :: makeConnections
//------------------------------------------------------------------------------
#pragma export (VBTimerFn::makeConnections())
Boolean VBTimerFn::makeConnections()
{
   return true;
}

//------------------------------------------------------------------------------
// VBTimerFn :: timer
//------------------------------------------------------------------------------
VBTimer* VBTimerFn::timer() const
{
  return iTimer;
}

//------------------------------------------------------------------------------
// VBTimerFn :: setTimer
//------------------------------------------------------------------------------
VBTimerFn& VBTimerFn::setTimer(VBTimer* aTimer)
{
  if (!(iTimer == aTimer))
  {
    iTimer = aTimer;
  } // endif
  return *this;
}

//------------------------------------------------------------------------------
// VBTimerFn :: timerExpired
//------------------------------------------------------------------------------
void VBTimerFn::timerExpired(unsigned long timerId)
{
   timer()->notifyObservers(INotificationEvent(VBTimer::timerEventId, *timer()));
}
