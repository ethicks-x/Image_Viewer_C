Image Viewer App (Built using SDL2 Library)
===========================================
*SDL2 must be installed in the system earlier*

Commands
--------

Latest Way: (meson implemented)
^^^^^^^^^^

.. bash::
   sudo apt install libsdl2-2.0-0 libsdl2-dev
   meson setup builddir
   meson compile -C builddir

   # App testing
   cat images/image2.ppm | ./buildir/pom_i

Alternate Way: (make)
^^^^^^^^^^^^^^^^^^^^^

.. bash::
   sudo apt install libsdl2-2.0-0 libsdl2-dev
   make

   # App testing 
   cat images/image2.ppm | ./pom_i

*note: the make file is going to be removed in the next versions, so watch out.*

**Coming Soon, too tired to write this**

**N.B:** Too many can be implemented , I know but shut up and go away!
