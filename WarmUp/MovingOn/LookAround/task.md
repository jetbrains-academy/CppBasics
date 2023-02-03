When solving the previous task, you might have wondered how just a few lines 
of C++ code turn into an entire application that opens up a new window, 
draws the planet on the scene, and does other stuff.

Well, we actually cheated a bit and hid a large part of the code 
responsible for all of that. But now let's put all the cards on the table. 
You can now see the hidden part of the code in
the file [main.cpp](course://WarmUp/MovingOn/LookAround/src/main.cpp).

Take a look at that file. Do not worry if currently you cannot understand some code there.
In the future lessons we will gradually explain all the missing parts.

For now, you can just try to find how the function `move`
(the one you implemented in the previous step) is used 
in [main.cpp](course://WarmUp/MovingOn/LookAround/src/main.cpp).

<div class="hint">

`move` is called from the `update` function, which 
is responsible for the periodical update of the scene.

</div>

