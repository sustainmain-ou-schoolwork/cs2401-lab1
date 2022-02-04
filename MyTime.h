#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

using namespace std;
    
class MyTime
{   
  public:
    /**
     * @brief Construct a new MyTime object.
     * The default value for h is 0, and the default for m is 0.
     * 
     * @param h the hour
     * @param m the minute
     */
    MyTime(int h = 0, int m = 0);   

    /**
     * @brief Give the object a new time from arguments.
     * 
     * @param h the hour
     * @param m the minute
     */
    void Reset(int h, int m);

    /**
     * @brief Give the object a new time from an istream.
     * 
     * @param ins the istream to read the new time from
     */
    void input(std::istream& ins);            

    /**
     * @brief Sends the time to the ostream in H:MM format.
     * 
     * @param outs the ostream
     */
    void output(std::ostream& outs) const;

    /**
     * @brief Returns the value of hours in the MyTime object.
     * 
     * @return hours
     */
    int get_hours() const{return hours;}

    /**
     * @brief Returns the value of minutes in the MyTime object.
     * 
     * @return minutes
     */
    int get_minutes() const{return minutes;}

    /**
     * @brief Adds a time to the initial time given.
     * 
     * @param t the time to add
     * @return the sum of both times
     */
    MyTime operator + (const MyTime& t) const;
 
    /**
     * @brief Subtracts a time from the initial time given.
     * 
     * @param t the time to subtract
     * @return the difference of both times
     */
    MyTime operator - (const MyTime& t) const;

    /**
     * @brief Multiplies a time by a number.
     * 
     * @param num the number to multiply the time by
     * @return the product of the time and the number
     */
    MyTime operator * (int num) const;

    /**
     * @brief Divides a time by a number.
     * 
     * @param num the number to divide the time by
     * @return the time divided by the number
     */
    MyTime operator / (int num) const;

    /**
     * @brief Checks if the initial time given is the same as another time t.
     * 
     * @param t the time to compare to
     * @return true if the times are the same
     */
    bool operator == (const MyTime& t) const;

    /**
     * @brief Checks if the initial time given is less than another time t.
     * 
     * @param t the time to compare to
     * @return true if the initial time is less than t
     */
    bool operator < (const MyTime& t) const;

    /**
     * @brief Checks if the initial time given is less than or equal to another time t.
     * 
     * @param t the time to compare to
     * @return true if the initial time is less than or equal to t
     */
    bool operator <= (const MyTime& t) const;
   
  private:
      void simplify();  // wraps values of minutes over 59
      int hours;        // hours can be > 24
      int minutes;      // 0 <= minutes <= 59
 };

/**
 * @brief Sets the time based on input from an istream.
 * 
 * @param fin the istream to read the new time from
 * @param t the MyTime object whose time will be set
 */
std::istream& operator >>(std::istream& fin, MyTime& t);

/**
 * @brief Outputs the time to an ostream.
 * 
 * @param fin the ostream
 * @param t the MyTime object whose time will be output in H:MM format.
 */
std::ostream& operator <<(std::ostream& fout, const MyTime& t);

 #endif