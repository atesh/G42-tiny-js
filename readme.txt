Portable javascript interpreter 

This is a fork of 42tiny-js project maintained by Armin Diedering. 
(http://code.google.com/p/42tiny-js/) He dramatically improved
the initial version of Tiny-js by Gordon Williams. Tiny-js 
(http://code.google.com/p/tiny-js/) is a very promising project 
whose intention was providing a simple javascript interpreter in 
C++ language. It is very nice, because the implementation of
the interpreter is placed only in two files (C++ source and
header). Perfect example of demonstrating the possibilities of this
interpreter is a Mobile-Tiny-Js project 
(http://code.google.com/p/mobile-tiny-js/).

I was having problems porting the 43TinyJs project to my solution,
because it was heavily dependening on the std library. I was inspired
by the Mobily-Tiny-Js project which implemented its own std-like
classes to replace std and I decided to do the same on the larger 
43TinyJs project.

You may be asking - why the hell would be one doing such stupid thing?
The answer is that I am not used to the std library and I am familiar 
more with MFC from Microsoft instead. The other reason is porting
to the mobile platforms which often do not implement the std
library correctly. The 43TinyJs project also implements its own
memory management that supports multi threading and can be ported
to microcomputer devices without memory management.

