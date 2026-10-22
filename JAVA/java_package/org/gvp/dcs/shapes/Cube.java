package org.gvp.dcs.shapes;

public class Cube {
    private double side;

    public Cube(double side) {
        if (side <= 0) {
            throw new IllegalArgumentException(
                "Side must be positive."
            );
        }
        this.side = side;
    }


    public double volume() {
        return side * side * side;
    }

    public double surfaceArea() {
        return 6 * side * side;
    }
}
