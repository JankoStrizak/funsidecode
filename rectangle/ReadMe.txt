How Inputs work
    - the format is a command, followed by a space, then all of the arguments in order seperated only by a semi-colon.
    - list of commands
        > create
            - adds a new object of the Rectangle class
            - arguments (3 possibilities)
                   1) it is a square at the origin, so only the id and side length are needed (2)
                            ~create_rect id; side length of the square
                            ex. create_rect 1;34.54
                   2) the id, the bottom, left corner is at the origin, so only the rectangle's initial size are needed (3)
                           ~ create_rect id; length of the rectangle (along the x-axis); height of the rectangle (along the y-axis)
                           ex. create_rect 1;3.4;5.22
                   3) it is a square so only the id, the bottom, left corner, the height, and the length are given (4)
                           ~ create_rect id; bottom left corner's x-coordinate, the bottom left corner's y-coordinate, side length of the square
                           ex. create_rect 3;-3.2;4.7;8.8
                   4) the id, the bottom, left corner of the rectangle, the height, and the length (5)
                           ~ create_rect id; the bottom left corner's x-coordinate, the bottom left corner's y-coordinate, length of the rectangle (along the x-axis), height of the rectangle (along the y-axis)
                   *Each id must be a unique natural number*
                   *all rectangle side lengths/heights are positive decimal numbers*
                   *coordinate points are any positive/negative decimal number*
        > create_copy
            - adds a new object of rectangle class
            - this object is a COPY of an already existing rectangle
            -arguments
                ~ id of new rectangle, id of rectangle to copy
                ~ create_copy 44;3
        >set_equal
            - mutator
            - sets an existing rectangle's values, except for it's id, equal to another rectangle's values
            - arguments
                ~ id of rectangle to mutate, id of rectangle to copy
                ~ set_equal id;id -> set_equal 342;1

        > contained
            - checks if a point is inside a rectangle
            - arguments
                ~ id of rectangle, x-coordinate of the point, y-coordinate of the point
                ~ example: contained id;x;y -> contained 34;1.9;-5.6

        > intersect
            - checks if two rectangles intersect
            - arguments
                ~ id, id
                ~ ex. intersect id;id -> intersect 23;5
