BKAL is a BREP Kernal Abstraction Layer. It's purpose is to provide a simple, intuitive
means of communicating with a BREP Kernel. BKAL should effectively allow you to de-couple
your code base from a given BREP kernel, thus making unit-testing easier as well as
providing a single point of entry of large third-party libraries.

At the time of this writing, the most prominent, easily available open-source BREP Kernel
is he OpenCascade Library (OCC for short). As such, BKAL is written with OCC in mind.

Please note that BKAL does nothing on its own. Indeed, many of the classes defined herein
are "Pure Virtual", i.e. they can not be instantiated. Rather, a library must be written
which implements he BKAL interfaces.
