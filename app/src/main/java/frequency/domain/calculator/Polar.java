package frequency.domain.calculator;

public class Polar {
    private double a;   // amplitude
    private Angle p;   // phase

    public Polar(double a, Angle p) {
        this.a = a;
        this.p = p;
    }

    public double getA() {
        return a;
    }

    public Angle getP() {
        return p;
    }

    public Rectangular polarToRec() {
        double r = a * Math.cos(p.toRadians());
        double i = a * Math.sin(p.toRadians());
        return (new Rectangular(r, i));
    }
    
}
