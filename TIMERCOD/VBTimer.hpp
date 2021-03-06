/*******************************************************************************
* FILE NAME: VBTimer.hpp                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class:                                                  *
*     VBTimer- A part that signals an event at regular intervals               *
* ---------------------------------------------------------------------------- *
* Warning: This file was generated by the VisualAge C++ Visual Builder.        *
* Modifications to this source file will be lost when the part is regenerated. *
*******************************************************************************/
#ifndef _VBTIMER_
#define _VBTIMER_

class VBTimer;

#ifndef _VBTIMERFN_
#include "VBTmerFn.hpp"
#endif

#ifndef _ISTDNTFY_
#include <istdntfy.hpp>
#endif

class ITimer;
class VBTimerFn;
#include "VBTimer.h"


/*----------------------------------------------------------------------------*/
/* Align classes on four byte boundary.                                       */
/*----------------------------------------------------------------------------*/
#pragma pack(4)

//*****************************************************************************
// Class definition for VBTimer
//*****************************************************************************
class VBTimer : public IStandardNotifier {
public:
   //---------------------------------------------------------------------------
   // Constructors / destructors
   //---------------------------------------------------------------------------
   VBTimer();

   virtual  ~VBTimer();

   //---------------------------------------------------------------------------
   // public member functions
   //---------------------------------------------------------------------------
   virtual VBTimer & initializePart();
   virtual unsigned long interval() const;
   virtual VBTimer& setInterval(unsigned long aInterval);
   virtual Boolean isStarted() const;
   virtual Boolean isStopped() const;
   virtual VBTimer& stop();
   virtual VBTimer& start();

   //---------------------------------------------------------------------------
   // public member data
   //---------------------------------------------------------------------------
   static const INotificationId readyId;
   static const INotificationId intervalId;
   static const INotificationId startedEvent;
   static const INotificationId stoppedEvent;
   static const INotificationId timerEventId;

protected:
   //---------------------------------------------------------------------------
   // protected member functions
   //---------------------------------------------------------------------------
   virtual Boolean makeConnections();

private:
   //---------------------------------------------------------------------------
   // private member data
   //---------------------------------------------------------------------------
   ITimer * iTimer;
   const IReference<ITimerFn> iVBTimerFn;
   unsigned long iInterval;
   Boolean iIsStarted;
   Boolean iIsStopped;
};   //VBTimer


/*----------------------------------------------------------------------------*/
/* Resume compiler default packing.                                           */
/*----------------------------------------------------------------------------*/
#pragma pack()

#endif
