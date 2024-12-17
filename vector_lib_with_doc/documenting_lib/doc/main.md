@mainpage
@author Khevaiya Ghode

\ref kvector are sequence container representing arrays that can change in size.

Just like arrays, \ref kvector use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

Internally,\ref kvector use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size wheni new elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, and thus,\ref kvector do not reallocate each time an element is added to the container.

Instead, \ref kvector containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size). Libraries can implement different strategies for growth to balance between memory usage and reallocations, but in any case, reallocations should only happen at logarithmically growing intervals of size so that the insertion of individual elements at the end of the \ref kvector can be provided with amortized constant time complexity.

Therefore, compared to arrays,\ref kvector consume more memory in exchange for the ability to manage storage and grow dynamically in an efficient way.
<hr/>
<h1>How to compile application while using  kvector Library </h1>
Place  the  Header  File(kvector)  and  Library  File(kvector.lib)   in  the  folder of your choice. 
<h4>Command To Compile On Windows Operating System </h4>
<pre>g++   your_source_code.cpp  -o  executable_file_name.exe  -I  path_to_heade_file_folder  -L   path_to_library_file_folder   -l   kvector</pre>






















