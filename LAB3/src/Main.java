/*
1. The resolution of two clauses in CNF. That is, given two clauses the program calculates
their resolvent by applying one resolution step.

2. The resolution mechanism applied to a given set S of clauses. Given S, the program selects
two arbitrary clauses from S, or any previously calculated resolvent, and calculates the
new resolvents. The program applies the resolution step until no new resolvent can be
derived. See the Solver for Clauses in CNF on p.4.
 */

import java.util.*;
import org.apache.commons.collections4.*;



public class Main {
    public static void main(String[] args) {
        /* TASK 1
         Clauses A = new Clauses("~b v c v t");
         Clauses B = new Clauses("~c v z v b");

         Clauses C = new Clauses();

         C = C.resolution(A,B);
        if (C != null) {
            System.out.println(C);
        } else {
            System.out.println("FASLE");
        }
        */

        /* ------- TASK A ----------
        ArrayList<Clauses> KB = new ArrayList<Clauses>()
        {
            {
                add(new Clauses("~sun v ~money v ice"));
                add(new Clauses("~money v ice v movie"));
                add(new Clauses("~movie v money"));
                add(new Clauses("~movie v ~ice"));
                add(new Clauses("movie"));
            }
        };

        ArrayList<Clauses> Bob = new ArrayList<Clauses>();

        Bob = Solver.SolverFunction(KB);

        System.out.println("Bob: " + Bob);*/

        /* ------- TASK B ---------- */
        ArrayList<Clauses> knightProblem = new ArrayList<Clauses>()
        {
            {
                /*
                add(new Clauses("~Knc v ~Sc"));
                add(new Clauses("~Ka v Knc"));
                add(new Clauses("~Ka v Bs"));
                add(new Clauses("~Sc v ~Knc"));
                */

                //Alex tells truth
                add(new Clauses("Ka v ~Sa v ~Kna"));
                add(new Clauses("~Kb v Sb v ~Kna"));
                add(new Clauses("~Kc v ~Sc v Knc"));
                //Alex lies
                add(new Clauses("~Ka v ~Sa v Kna"));
                add(new Clauses("~Kb v ~Sb v Knb"));
                add(new Clauses("Kc v Sc v ~Knc"));

                //Ben tells truth
                add(new Clauses("Ka v ~Sa v ~Kna"));
                add(new Clauses("Kb v Sb v ~Knb"));
                add(new Clauses("Kc v Sc v ~Knc"));


            }
        };

        ArrayList<Clauses> knightSolution = new ArrayList<Clauses>();

        knightSolution = Solver.SolverFunction(knightProblem);

        System.out.println(knightSolution);
         // (p = a,b n = c)
        //  B = new Clauses; B
        //  C = new Clauses; New resulting Clause
        // Run

        //Vector<String> name = new Vector<String>();
    }
}
