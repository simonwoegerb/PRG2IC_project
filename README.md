#Numerical Converter
## Initial project suggestion
While the initial idea for this project was: 
> A program with two modes: First to convert any floating point number in base 0-36 to any other base. (0-9+A-z =36 characters). Results are output to terminal as well as saved to a history file for future reference. Secondly a base_x to string decoder and encoder for any base up to base64. Mode is selectable upon startup and whenever a request is finished (running continuously in a loop). 

I have found the scope of the second mode to be badly defined. 
Furthermore mode 1 was already time-intensive enough with the character maths going on in C++, as well as with adding "proper" testing. As such, I focused on actually making the first mode (numerical conversion) functional and stable.

As it stands it gracefully handles wrong base inputs (asks again after an error message), supports negative inputs and gracefully handles non-sense input as well as input with too high a base (i.e. base 2 was selected but base 10 data given).
## Functionality 
This application contains a function for Numerical Conversion from Base2-35 to Decimal as well as Decimal to Base2-35. Both have also been combined in Base2-35 to Base2-35 for developer convenience. All can be found in `src/conversion.cpp`

The entire application runs in an infinte loop, always asking for the next set of input (Base to convert from, Base to convert to, Number to be converted). It can be quit by `Ctrl+C` or by inputting `q` or `Q` as any of the bases.  
Be aware of integer overflow.
## Building
The application has an attached make file (runs on OpenSuse Tumbleweed). If built with `make debug`/`make debug_run`, the tests are automatically run on startup Otherwise they must be uncommented in the main file.
## Running
The program can be run with `make run`. 
## Testing
All tests are contained in `src/testing/Tests.cpp`. At the time of this commit, all succeed.