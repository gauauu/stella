//============================================================================
//
//   SSSS    tt          lll  lll
//  SS  SS   tt           ll   ll
//  SS     tttttt  eeee   ll   ll   aaaa
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2017 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//============================================================================

#include "Event.hxx"
#include "Quadtari.hxx"
#include "System.hxx"
#include "M6532.hxx"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Quadtari::Quadtari(Jack jack, const Event& event, const System& system)
  : Controller(jack, event, system, Controller::Quadtari)
{

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Quadtari::update()
{
  /*
   
   The right Quadtari port shouldn't really ever be read,
  it is just used as a data selector for the left jack.
  
  Unfortunately, the two controller objects don't know about
  each other in Stella (as best I can tell), so instead of
  trying to communicate that state betwene left and right
  (which the real hardware does), we'll do mostly-nothing
  with the right jack in Stella, and let the left-jack
  artificially peek at the RIOT's pin state.

  */
  

  //For reading the right jack, set dummy values to the read pins
  if (myJack == Right) {
    myDigitalPinState[Three] = 0;
    myDigitalPinState[Four] = 0;
    myDigitalPinState[Six] = 0;
    return;
  }

  //Otherwise, we're on the left jack.

  //First read the writable pins of the right jack,
  //to see which controller we're reading
  uInt8 swcha = mySystem.m6532().peek(0x280);
  swcha = swcha % 4;

  //then read the correct joystick
  switch (swcha) {

    case 0:
    default:
      myDigitalPinState[One]   = (myEvent.get(Event::JoystickZeroUp) == 0);
      myDigitalPinState[Two]   = (myEvent.get(Event::JoystickZeroDown) == 0);
      myDigitalPinState[Three] = (myEvent.get(Event::JoystickZeroLeft) == 0);
      myDigitalPinState[Four]  = (myEvent.get(Event::JoystickZeroRight) == 0);
      myDigitalPinState[Six]   = (myEvent.get(Event::JoystickZeroFire) == 0);
      break;

    case 1:
      myDigitalPinState[One]   = (myEvent.get(Event::JoystickOneUp) == 0);
      myDigitalPinState[Two]   = (myEvent.get(Event::JoystickOneDown) == 0);
      myDigitalPinState[Three] = (myEvent.get(Event::JoystickOneLeft) == 0);
      myDigitalPinState[Four]  = (myEvent.get(Event::JoystickOneRight) == 0);
      myDigitalPinState[Six]   = (myEvent.get(Event::JoystickOneFire) == 0);
      break;
    case 2:
      myDigitalPinState[One]   = (myEvent.get(Event::QuadtariTwoUp) == 0);
      myDigitalPinState[Two]   = (myEvent.get(Event::QuadtariTwoDown) == 0);
      myDigitalPinState[Three] = (myEvent.get(Event::QuadtariTwoLeft) == 0);
      myDigitalPinState[Four]  = (myEvent.get(Event::QuadtariTwoRight) == 0);
      myDigitalPinState[Six]   = (myEvent.get(Event::QuadtariTwoFire) == 0);
      break;
    case 3:
      myDigitalPinState[One]   = (myEvent.get(Event::QuadtariThreeUp) == 0);
      myDigitalPinState[Two]   = (myEvent.get(Event::QuadtariThreeDown) == 0);
      myDigitalPinState[Three] = (myEvent.get(Event::QuadtariThreeLeft) == 0);
      myDigitalPinState[Four]  = (myEvent.get(Event::QuadtariThreeRight) == 0);
      myDigitalPinState[Six]   = (myEvent.get(Event::QuadtariThreeFire) == 0);
      break;

  }
}

