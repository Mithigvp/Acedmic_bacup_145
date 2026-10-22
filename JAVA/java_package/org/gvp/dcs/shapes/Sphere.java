
package org.gvp.dcs.shapes;

public class Sphere {
    private double radius;

    
    public Sphere(double radius) {
        if (radius <= 0) {
            throw new IllegalArgumentException(
                "Radius must be positive."
            );
        }
        this.radius = radius;
    }

  
    public double volume() {
        return (4.0 / 3.0) * Math.PI
                * radius * radius * radius;
    }

    public double surfaceArea() {
        return 4 * Math.PI * radius * radius;
    }
}
