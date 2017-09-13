/* @file: realbox.h
 * Definition of class RealBox
 * @C - Galaxy Express Softworks 
 * 
 * Version 16.1.0
 
 */

#ifndef REALBOX_H
#define REALBOX_H

#include <iostream>


/* _________________
  /                 \
  |  RealBox  Class  |
  \_________________/
   
    Purpose: Implements an Real Number Box, as required by the Emperor Lrrr

    A Real-Box is a class that encapsulates an array of Real Numbers
    The size of the array is specified at declaration.

*/

// ---------------  Class RealBox Declarations
class RealBox
{ 
public:  
  float* m_reals;                     // Array of Real Numbers
  int m_boxsize;                      // number of Real Numbers in this box       


public:
  // Purpose: Constructs an Real-Box
	// Preconditions:
	//     's' is greater than 0;
  // Postconditions: 
  //     m_reals points to a dynamically allocated array of size 's'
  //     all elements of m_reals[] are initiallized to 'a'.
  RealBox(int s, float a);


  /* 
   * --------- Big 3 Member Functions -----------
   */

  // Purpose: Destructor
  // Postconditions: m_reals[] deallocated
  ~RealBox();

  // Purpose: Operator=, performs a deep copy of 'rhs' into 'this' RealBox
  // Parameters: rhs, RealBox to be copied
  // Returns: *this
  // Postconditions: *this == rhs
  const RealBox& operator=(const RealBox& rhs);

  // Purpose: Copy Constructor
  // Parameters: rhs - RealBox to be copied
  // Postconditions:  *this == rhs
  RealBox(const RealBox& rhs);


  /* 
   * ----- Simple Accessor Operations ----- 
   */

  // Purpose: Sets a value in the RealBox
  // Parameters: 'i' location to set
  //             'x' value to store
  // PreConditions: 'i' is between the boundaries of the RealBox 
  // Postconditions:  element 'i' in the RealBox is set to 'x'
	void set( int i, float x );


  /* 
   * ----- Complex Accessor Operations ----- 
   */
  
  // Purpose: prints the RealBox
  friend std::ostream& operator<< (std::ostream& out, const RealBox& box);
}; // RealBox


#endif
