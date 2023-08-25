package frequency.domain.calculator;

public class Angle {
    private final double radians;

    public Angle() {
        this.radians = 0;
    }

    private Angle(double radians) {
        this.radians = radians;
    }

    public static Angle fromRadians(double radians) {
        return new Angle(radians);
    }

    public static Angle fromDegrees(double degrees) {
        return new Angle(Math.toRadians(degrees));
    }

    public double toRadians() {
        return radians;
    }

    public double toDegrees() {
        return Math.toDegrees(radians);
    }

    public Angle add(Angle other) {
        return new Angle(this.toRadians() + other.toRadians());
    }

    public Angle subtract(Angle other) {
        return new Angle(this.toRadians() - other.toRadians());
    }

    public String getRadiansString() {
        return String.format("%.2lf", toRadians());
    }

    public String getDegreesString() {
        return String.format("%.2lf°", toDegrees());
    }
}
