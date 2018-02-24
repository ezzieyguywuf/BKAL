GTAL is a Geometric Topology Abstraction Layer. Its intent is to provide an abstraction
layer between a given Geometric Topology engine (i.e. OpenCascade's TopoDS package) and
the client using this engine. GTAL does *not* provide any abstraction for actual Geometric
functions, i.e. creating solids, filleting objects, boolean operations etc. GTAL is
strictly interested in providing access to Topological information, which while dependant
upon the underlying geometry, should not strictly need access to this geometry for must
tasks.
