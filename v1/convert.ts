

interface polar {
    a: number;  // amplitude
    p: number;   // phase
};

interface rect {
    r: number;   // real
    i: number;   // imaginary
};

interface value {
    polarForm: polar;   // polar form
    rectForm:  rect;   // rectangle form
};

///////////////////////////////////////////////////////////////////////////////

function main () {
    let cmd;
    let a;
    let b;
    switch(cmd) {
        case '+': add(a,b); break;
        case '-': sub(a, b); break;
        case '*': mult(a, b); break;
        case '/': div(a, b); break;
        default: console.log("DIE (not a command)\n");

    }
}

///////////////////////////////////////////////////////////////////////////////

function polarToRect(v: polar): rect {
    let result: rect = {
        r: v.a * Math.cos(v.p * Math.PI / 180),
        i: v.a * Math.sin(v.p * Math.PI / 180),
    }
    return result;
}

function rectToPolar(v: rect): polar {
    let result: polar = {
        a: Math.sqrt((v.r * v.r) + (v.i * v.i)),
        p: (v.r === 0)
            ? -90 
            : Math.atan(v.i / v.r) / Math.PI * 180,
    }
    return result;
}

function add(a: rect, b: rect): rect {
    let result: rect = {
        r: a.r + b.r,
        i: a.i + b.i,
    };
    return result;
}

function sub(a: rect, b: rect): rect {
    let result: rect = {
        r: a.r + b.r,
        i: a.i + b.i,
    };
    return result;
}

function mult(a: polar, b: polar): polar {
    let result: polar = {
        a: a.a * b.a,
        p: a.p + b.p,
    };
    return result;
}

function div(a: polar, b: polar): polar {
    let result: polar = {
        a: a.a / b.a,
        p: a.p - b.p,
    };
    return result;
}

function printResult(result: value): void {
    console.log("\n ==================== \n");
    console.log(result.polarForm);
    console.log(result.rectForm);
    console.log("\n ==================== \n");
}