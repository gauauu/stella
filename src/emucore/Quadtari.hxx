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

#ifndef JOYSTICK_HXX
#define JOYSTICK_HXX

#include "bspf.hxx"
#include "Control.hxx"
#include "Event.hxx"

/**
  Quadtari -- the 4-player atari joystick adapter.
  This controller works by using both joystick ports.
  Port 0 is used for reading all 4 joystick states.
  Port 1 is used in write mode to select a joystick to read.

  @author  Nathan Tolbert (gauauu)
*/
class Quadtari : public Controller
{
  public:
    /**
      Create a new quadtari adapter plugged into the specified jack

      @param jack   The jack the controller is plugged into
      @param event  The event object to use for events
      @param system The system using this controller
    */
    Quadtari(Jack jack, const Event& event, const System& system);
    virtual ~Quadtari() = default;

  public:

    /**
      Update the entire digital and analog pin state according to the
      events currently set.
    */
    void update() override;



  private:
    // Following constructors and assignment operators not supported
    Quadtari() = delete;
    Quadtari(const Quadtari&) = delete;
    Quadtari(Quadtari&&) = delete;
    Quadtari& operator=(const Quadtari&) = delete;
    Quadtari& operator=(Quadtari&&) = delete;
};

#endif
