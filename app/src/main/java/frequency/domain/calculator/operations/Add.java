package frequency.domain.calculator.operations;

import frequency.domain.calculator.Rectangular;
import frequency.domain.calculator.Value;

public class Add implements OperationNode {
    Value a;
    Value b;

    public Add(Value a, Value b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public Value evaluate() {
        double resX = a.getX() + b.getX();
        double resY = a.getY() + b.getY();
        return Value.fromRect(new Rectangular(resX, resY));
    }
    
}
