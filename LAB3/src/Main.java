/*
1. The resolution of two clauses in CNF. That is, given two clauses the program calculates
their resolvent by applying one resolution step.

2. The resolution mechanism applied to a given set S of clauses. Given S, the program selects
two arbitrary clauses from S, or any previously calculated resolvent, and calculates the
new resolvents. The program applies the resolution step until no new resolvent can be
derived. See the Solver for Clauses in CNF on p.4.
 */

import java.util.*;

public class Main {
    public static void main(String[] args) {
         Clauses A = new Clauses("a v b v ~c");
         // (p = a,b n = c)
        //  B = new Clauses; B
        //  C = new Clauses; New resulting Clause
        // Run


        //Vector<String> name = new Vector<String>();
    }
}
