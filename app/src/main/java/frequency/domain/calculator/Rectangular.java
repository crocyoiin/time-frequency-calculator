package frequency.domain.calculator;

public class Rectangular {
    private double x;   // real
    private double y;   // imaginary

    public Rectangular(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public Polar recToPolar() {
        double a = Math.sqrt((x * x) + (y * y));
        double p = (x == 0) ? -90 : Math.atan(y / x);
        Angle pAngle = Angle.fromRadians(p);
        return new Polar(a, pAngle);
    }
    
}
