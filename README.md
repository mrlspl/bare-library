![Bare-Library](https://github.com/mrlspl/bare-library/blob/master/bare-lib.png)
# bare-library
An empty skeleton of a library that may have many interfaces. e.g.: for
different robots or simulators or prototyping languages like matlab.

This structure is meant to be used for the modules of MRL-SPL which are to be
developed. It is actually a number of conventions which I like to mention here
all of which are planned to result in a portable code so that one can easily
write new interfaces to the classes they need and use it for a new purpose.
Let's first check why we did it:

The initial idea was to ease the pain of diverged code of prototypes (e.g.: in
Octave, R, or Matlab) and the deploy code (for us, usually in c++). So, it
would be nice if one could prevent duplication between those versions. Why not
to make use of all codes easy in the prototyping languge? When a module is
stable enough to be used in the actual product, it's prototype code should be
`replaced' by an actual version. What we have prepared here is a skeleton for
enabling the actual code to be used instead of the old prototype and eventually
stop diverging the brances.

Since we are working on a platform that is not that easy and cheap to make a
real test, we would rather test our codes on simulators, but who guarantees the
simulated code is the same thing? Why one cannot write an `if' for a part of
their code that would someday make difference between simulated version of the
code and the actual one?

Last but not least, what if we needed the same workes to be done on another
platform, or what if someone working on another platform liked to use our code?
Do we need to make it easy for us and them? Of course, we should!

The point is to separate implementations and interfaces neatly. There is a
directory hirerarchy to categorize and organize files for different purposes.

	- /include:
		This folder is the most sensative part. The files in it define
		classes in which the actual jobs are done and the definitions
		should stay compatible to many things. A change in this part is
		the most expensive change because it imposes modifications on
		all interfaces and maybe also modification in other
		implementations and class definitions that has probably used
		this definition. Therefore, it is wise not to implement
		absolutely anything here! using proxy classes can be useful if
		gets too hard not to implement things in the header files.
		(e.g.: template classes)
	- /src:
		The actual implementation of everything goes here. Here is a
		relatively safe place to make changes. Implementation of a
		class can be changed as far as it does the same thing as viewd
		from outside!
	- /unit-test:
		Considering a code without automated tests?! Wrong choice! Here
		is where you can place the unit tests for all the clases.
		Obviously, a file in /includes means existence of another file
		with the same name in this folder to test things made available
		for others in /includes. Test Driven Development is our
		favorite! It's one of the beloved ways of being clear and
		deliberative.
	- /interface:
		As mentioned above, this structure is meant to ease the pain of
		reusing code for different purposes and we need a bunch of
		interfaces for many of our classes. They are categorized here
		each purpose in a different sub-directory here. For example
		/interfaces/matlab is a favorable one! or /interfaces/nao.

