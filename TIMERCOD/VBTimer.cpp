/*******************************************************************************
* FILE NAME: VBTimer.cpp                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Class implementation of the class:                                         *
*     VBTimer- A part that signals an event at regular intervals               *
* ---------------------------------------------------------------------------- *
* Warning: This file was generated by the VisualAge C++ Visual Builder.        *
* Modifications to this source file will be lost when the part is regenerated. *
*******************************************************************************/
#ifndef _ITIMER_
#include <itimer.hpp>
#endif

#ifndef _INOTIFEV_
#include <inotifev.hpp>
#endif

#ifndef _IOBSERVR_
#include <iobservr.hpp>
#endif

#ifndef _ISTDNTFY_
#include <istdntfy.hpp>
#endif

#ifndef _VBTIMER_
#include "VBTimer.hpp"
#endif

#ifndef _IVBDEFS_
#include <ivbdefs.h>
#endif

#ifndef _ITRACE_
#include <itrace.hpp>
#endif


#pragma export (VBTimer::readyId)
const INotificationId VBTimer::readyId = "VBTimer::readyId";
#pragma export (VBTimer::intervalId)
const INotificationId VBTimer::intervalId = "VBTimer::interval";
#pragma export (VBTimer::startedEvent)
const INotificationId VBTimer::startedEvent = "VBTimer::isStarted";
#pragma export (VBTimer::stoppedEvent)
const INotificationId VBTimer::stoppedEvent = "VBTimer::isStopped";
#pragma export (VBTimer::timerEventId)
const INotificationId VBTimer::timerEventId = "VBTimer::timerEvent";

//------------------------------------------------------------------------------
// VBTimer :: VBTimer
//------------------------------------------------------------------------------
#pragma export (VBTimer::VBTimer())
VBTimer::VBTimer() : iVBTimerFn(new VBTimerFn(this))
{
   iTimer = new ITimer();
}     //end constructor


//------------------------------------------------------------------------------
// VBTimer :: ~VBTimer
//------------------------------------------------------------------------------
#pragma export (VBTimer::~VBTimer())
VBTimer::~VBTimer()
{
   delete iTimer;
}

//------------------------------------------------------------------------------
// VBTimer :: initializePart
//------------------------------------------------------------------------------
#pragma export (VBTimer::initializePart())
VBTimer & VBTimer::initializePart()
{
   makeConnections();
   notifyObservers(INotificationEvent(readyId, *this));
   return *this;
}


//------------------------------------------------------------------------------
// VBTimer :: makeConnections
//------------------------------------------------------------------------------
#pragma export (VBTimer::makeConnections())
Boolean VBTimer::makeConnections()
{
   this->enableNotification();

   return true;
}

//------------------------------------------------------------------------------
// VBTimer :: interval
//------------------------------------------------------------------------------
#pragma export (VBTimer::interval())
unsigned long VBTimer::interval() const
{
  return iInterval;
}

//------------------------------------------------------------------------------
// VBTimer :: setInterval
//------------------------------------------------------------------------------
#pragma export (VBTimer::setInterval(unsigned long aInterval))
VBTimer& VBTimer::setInterval(unsigned long aInterval)
{
  if (!(iInterval == aInterval))
  {
    iInterval = aInterval;
    iTimer->setInterval(iInterval);
    notifyObservers(INotificationEvent(VBTimer::intervalId, *this));
  } // endif
  return *this;
}

//------------------------------------------------------------------------------
// VBTimer :: isStarted
//------------------------------------------------------------------------------
#pragma export (VBTimer::isStarted())
Boolean VBTimer::isStarted() const
{
  return iIsStarted;
}

//------------------------------------------------------------------------------
// VBTimer :: isStopped
//------------------------------------------------------------------------------
#pragma export (VBTimer::isStopped())
Boolean VBTimer::isStopped() const
{
  return iIsStopped;
}

//------------------------------------------------------------------------------
// VBTimer :: stop
//------------------------------------------------------------------------------
#pragma export (VBTimer::stop())
VBTimer& VBTimer::stop()
{
  iTimer->stop();
  notifyObservers(INotificationEvent(VBTimer::stoppedEvent, *this));
  return *this;
}

//------------------------------------------------------------------------------
// VBTimer :: start
//------------------------------------------------------------------------------
#pragma export (VBTimer::start())
VBTimer& VBTimer::start()
{
  iTimer->start(iVBTimerFn);
  notifyObservers(INotificationEvent(VBTimer::startedEvent, *this));
  return *this;
}

