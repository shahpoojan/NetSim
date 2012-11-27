// Definition of Simulator class
// ECE8893, Final Project, Fall 2012

#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

#include "CommonDefs.h"
#include "Handler.h"


class EventBase
{
public:
  EventBase(Time_t t) : time(t) {}
public:
  Time_t time;                    // Timestamp for the event
  virtual void CallHandler() = 0; // All subclasses must implement this
};

template<typename T, typename OBJ>
class Event0 : public EventBase
{ // Event class with no arguments
  // Type T is the object type for the event handler object
  // Type OBJ is the actual event handler object
public:
  Event0(double t, void (T::*f)(void), OBJ* obj0)
    : EventBase(t), handler(f), obj(obj0){}
  void (T::*handler)(void);
  OBJ*      obj;
public:
  void CallHandler();
};

template <typename T, typename OBJ>
void Event0<T, OBJ>::CallHandler()
{
  (obj->*handler)();
}

// Event with one parameter on the callback function
template<typename T, typename OBJ, typename U1, typename T1>
class Event1 : public EventBase
{
public:
  Event1(double t, void (T::*f)(U1), OBJ* obj0, T1 t1_0)
    : EventBase(t), handler(f), obj(obj0), t1(t1_0){}
  void (T::*handler)(U1);
  OBJ*      obj;
  T1        t1;
public:
  void CallHandler();
};

template <typename T, typename OBJ, typename U1, typename T1>
void Event1<T, OBJ, U1, T1>::CallHandler()
{
  (obj->*handler)(t1);
}

template<typename T, typename OBJ,
         typename U1, typename T1, 
         typename U2, typename T2>
class Event2 : public EventBase
{
public:
  Event2(double t, void (T::*f)(U1, U2), OBJ* obj0, T1 t1_0, T2 t2_0)
    : EventBase(t), handler(f), obj(obj0), t1(t1_0), t2(t2_0) {}
  void (T::*handler)(U1, U2);
  OBJ*      obj;
  T1        t1;
  T2        t2;
public:
  void CallHandler();
};

template <typename T, typename OBJ, 
          typename U1, typename T1,
          typename U2, typename T2>
void Event2<T, OBJ, U1, T1, U2, T2>::CallHandler()
{
  (obj->*handler)(t1, t2);
}

template <typename T,  typename OBJ,
          typename U1, typename T1,
          typename U2, typename T2,
          typename U3, typename T3>
class Event3 : public EventBase {
public:
   Event3(double t, void (T::*f)(U1, U2, U3), OBJ *obj0, T1 t1_0, T2 t2_0, T3 t3_0)  
     : EventBase(t), handler(f), obj(obj0), t1(t1_0), t2(t2_0), t3(t3_0) {}
   void (T::*handler)(U1, U2, U3);
   OBJ* obj;
   T1 t1;
   T2 t2;
   T3 t3;
   
public:
   void CallHandler();
};

template <typename T,  typename OBJ,
          typename U1, typename T1,
          typename U2, typename T2,
          typename U3, typename T3> 
void Event3<T,OBJ,U1,T1,U2,T2,U3,T3>::CallHandler() {
     (obj->*handler)(t1,t2,t3);
}

// Now define the sorted set of events and the event comparator
class event_less
{
public:
  event_less() { }
  inline bool operator()(EventBase* const & l, const EventBase* const & r) const {
    if(l->time < r->time) return true;
    return false;
  }
};

typedef std::multiset<EventBase*, event_less> EventSet_t;

class Simulator 
{
public:
  Simulator();
  static void Stop(); // Stop executing events and exit
  static void Run();  // Starting executing events
  static void StopAt(Time_t);
  //static void Schedule(Handler*, Event*, Time_t); // Schedule a new future event
  
  // Define the templated schedule functions
  
  // This one has zero arguments on the handler callback
  template <typename T, typename OBJ>
    static void Schedule(double t, void(T::*handler)(void), OBJ* obj)
  {
    EventBase* ev = new Event0<T, OBJ>(t + Simulator::Now(), handler, obj);
    events.insert(ev);
  }

  template <typename T, typename OBJ,
    typename U1, typename T1>
    static void Schedule(double t, void(T::*handler)(U1), OBJ* obj, T1 t1)
  {
    EventBase* ev = new Event1<T, OBJ, U1, T1>(t + Simulator::Now(), handler, obj, t1);
    events.insert(ev);
  }

  template <typename T, typename OBJ,
    typename U1, typename T1,
    typename U2, typename T2>
    static void Schedule(double t, void(T::*handler)(U1, U2), OBJ* obj, T1 t1, T2 t2)
  {
    EventBase* ev = new Event2<T, OBJ, U1, T1, U2, T2>(t + Simulator::Now(), handler, obj, t1, t2);
    events.insert(ev);
  }

  template <typename T, typename OBJ,
    typename U1, typename T1,
    typename U2, typename T2,
    typename U3, typename T3>
    static void Schedule(double t, void(T::*handler)(U1, U2, U3), OBJ* obj, T1 t1, T2 t2, T3 t3)
  {
    EventBase* ev = new Event3<T, OBJ, U1, T1, U2, T2, U3, T3>(t + Simulator::Now(), handler, obj, t1, t2, t3);
    events.insert(ev);
  }

  
  
  static void ComputeRoutes();                    // Compute routing tables at every node
  // Inherited from Handler
  virtual void Handle(Event*, Time_t);     // Handle the specified event
  static Simulator* instance
public:
  // Your member variables here
  static EventSet_t events;
  static bool stopped;
  static Time_t now;
};
#endif
