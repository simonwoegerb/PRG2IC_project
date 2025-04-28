# Numerical Converter
While the initial idea for this project was: 
> A program with two modes: First to convert any floating point number in base 0-36 to any other base. (0-9+A-z =36 characters). Results are output to terminal as well as saved to a history file for future reference. Secondly a base_x to string decoder and encoder for any base up to base64. Mode is selectable upon startup and whenever a request is finished (running continuously in a loop). 

I have found the scope of the second mode to be badly defined. 
Furthermore mode 1 was already time-intensive enough with the shenanigans going on in C++, as well as adding "proper" testing. 

As it stands, this application contains a Numerical Conversion from Base2-35 to Decimal as well as Decimal to Base2-35. Both have also been combined in Base2-35 to Base2-35 for convenience. 

The entire application runs in an infinte loop, always asking for the next set of input. If the first input of a conversion is `q`, the application is closed.  
Be aware of integer overflow.

The application has an attached make file (runs on OpenSuse Tumbleweed). If built with `make debug`/'make debug_run', the tests are automatically run on startup Otherwise they must be uncommented in the main file.