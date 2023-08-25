package frequency.domain.calculator;

public class Value {
    private final Polar polar;
    private final Rectangular rect;

    private Value (Polar polar, Rectangular rect) {
        this.polar = polar;
        this.rect = rect;
    }

    public static Value fromPolar(Polar polar) {
        return new Value(polar, polar.polarToRec());
    }

    public static Value fromRect(Rectangular rect) {
        return new Value(rect.recToPolar(), rect);
    }

    public Polar getPolar() {
        return polar;
    }

    public Rectangular getRectangular() {
        return rect;
    }
}
