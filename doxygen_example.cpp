Source of doxygen_example.cpp
Structures and functions
  1: /** @file doxygen_example.cpp
  2: @author Lastname:Firstname:A00123456:cscxxxxx
  3: @version Revision 1.1
  4: @brief Illustrates doxygen-style comments for documenting a C++
  5: program file and the functions in that file.
  6: @details If you want to add any further detailed description of
  7: what is in the file, then place it here (after the first statement)
  8: and it will appear in the detailed description section of the HTML
  9: output description for the file.
 10: @date Monday, September 19, 2011
 11: */

 13: /**
 14: @mainpage
 15: This short program contains some sample code illustrating
 16: how the doxygen comments must appear
 17: - for documenting a file, and in particular
 18: - for documenting functions
 19: .
 20: when we intend to use the doxygen tool for preparing HTML
 21: documentation of our code. Note that this file is intended
 22: <em>only</em> to illustrate a particular set of <b>commenting
 23: conventions</b> and how they show up when implemented with
 24: doxygen. Your actual requirements may not be the same as
 25: shown here. Im particular you may need less (or more) than
 26: is shown here.

 28: Pay careful attention, in the source code,\n to the distinction
 29: between the special doxygen comments,<br>which produce output
 30: here, and regular C++ comments which are ignored by doxygen,
 31: and look at the source code to see how line breaks in this
 32: paragraph are produced.
 33: */

 35: /*
 36: Author self-assessment statement:
 37: This program is complete and working according to spcecifications,
 38: according to the best of my knowledge.
 39: Or ...
 40: This program is incomplete in the following ways
 41: 1. ...
 42: 2. ...
 43: And/or ...
 44: This program still contains the following bugs:
 45: 1. ...
 46: 2. ...
 47: And by the way, note that this is a C++ but non-doxygen comment,
 48: so it will not appear in the HTML displays produced by doxygen.
 49: */


 52: //Include section
 53: #include <iostream>
 54: #include <string>
 55: using namespace std;


 58: //Prototype section
 59: void DoSomething
 60: (
 61:     int numberOfPositions,   //in
 62:     char& firstInitial,      //inout
 63:     string& stringOfInitials //out
 64: );
 65: /**<
 66: A single statement goes here to give a high-level description of
 67: the function, which is ended by the first period. Any further
 68: description of the function, such as this statement that comes
 69: after the first statement, will appear as part of the "detailed
 70: description" for this function. The brief description may also
 71: be repeated here immediately prior to the detailed description,
 72: but the configuration file for this example is currently set to
 73: disable that feature.
 74: @return void
 75: @param numberOfPositions The number of positions firstInitial is to
 76: be  moved forward.
 77: @param firstInitial A character representing the first letter in a
 78: person's first name (for example).
 79: @param stringOfInitials A string in which all characters are the
 80: same.
 81: @pre
 82: -# numberOfPositions contains a positive integer.
 83: -# firstInitial contains a printable character at least numberOfPositions
 84: positions from the end of the printable character set.
 85: @post
 86: -# firstInitial contains the character numberOfPositions to the right of
 87: its original value.
 88: -# stringOfInitials contains a string of length numberOfPositions
 89: in which each character is the original value of firstInitial.
 90: */


 93: int numberOfDigits
 94: (
 95:     int n //in
 96: );
 97: /**<
 98: Compute and return the number of digits in a positive integer.
 99: The style used for the pre/post coditions of this function is
100: purposely different from that for the void function given above,
101: just so you can see the differnce in the HTML output.
102: @return The number of digits in n.
103: @param n An integer, the number of whose digits is desired.
104: @pre n contains a positive integer.
105: This is some other precondition, and note that it does not
106: start on a new line.
107: @post
108: The number of digits in n has been returned.
109: \n This is some other post condition, and note that it does start
110: on a new line.
111: */


114: int main()
115: {
116:     int count = 6;
117:     char myInitial = 'P';
118:     string allOneLetter;

120:     DoSomething(count, myInitial, allOneLetter);
121:     cout << endl;
122:     cout << count << " " << myInitial << " " << allOneLetter << endl;

124:     cout << "\nNumber of digits in 0 ...... " << numberOfDigits(0);
125:     cout << "\nNumber of digits in 7 ...... " << numberOfDigits(7);
126:     cout << "\nNumber of digits in 123 .... " << numberOfDigits(123);
127:     cout << "\nNumber of digits in 12345 .. " << numberOfDigits(12345);
128:     cout << endl << endl;

130:     cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');
131: }


134: //Function definition section
135: //Definitions must be in the same order as the prototypes.
136: void DoSomething
137: (
138:     int numberOfPositions,   //in
139:     char& firstInitial,      //inout
140:     string& stringOfInitials //out
141: )
142: {
143:     stringOfInitials = string(numberOfPositions, firstInitial);
144:     firstInitial = (char)(((int)firstInitial)+numberOfPositions);
145: }


148: int numberOfDigits
149: (
150:     int n //in
151: )
152: {
153:     int count = 0;
154:     do
155:     {
156:         n /= 10;
157:         ++count;
158:     }
159:     while (n != 0);
160:     return count;
161: }
