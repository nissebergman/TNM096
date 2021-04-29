import javax.lang.model.type.ArrayType;
import javax.swing.plaf.basic.BasicInternalFrameTitlePane;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;


import org.apache.commons.collections4.CollectionUtils; //For using cool set functions

public class Solver
{
    public static ArrayList<Clauses> removeDuplicates(ArrayList<Clauses> KB)
    {
        ArrayList<Clauses> tempClauses = new ArrayList<Clauses>(KB);
        for(int i = 0; i < KB.size()-1; i++)
        {
            if((KB.get(i).same(KB.get(i+1))))
            {
                tempClauses.remove(KB.get(i));
            }
        }
        return tempClauses;
    }
    public static Clauses resolution(Clauses A, Clauses B)
    {
        Clauses C = new Clauses();
        if(Collections.disjoint(A.getPos(),B.getNeg()) && Collections.disjoint(A.getNeg(),B.getPos()))
            return null;
        if(!(Collections.disjoint(A.getPos(),B.getNeg())))
        {
            //Collections.shuffle(B.getNeg()); // Haxxy randomizer
            ArrayList<String> interSecB = (ArrayList<String>) CollectionUtils.intersection(A.getPos(),B.getNeg());
            String a = interSecB.get(0);
            A.getPos().remove(a);
            B.getNeg().remove(a);
        }
        else
        {
            //Collections.shuffle(A.getNeg()); // Haxxy randomizer
            ArrayList<String> interSecA = (ArrayList<String>) CollectionUtils.intersection(A.getNeg(),B.getPos());
            String a = interSecA.get(0);
            A.getNeg().remove(a);
            B.getPos().remove(a);
        }

        C.setPos((ArrayList<String>) CollectionUtils.union(A.getPos(), B.getPos()));
        C.setNeg((ArrayList<String>) CollectionUtils.union(A.getNeg(), B.getNeg()));

        if (!(Collections.disjoint(C.getPos(), C.getNeg())))
            return null;

        return C;
    }


    public static ArrayList<Clauses> SolverFunction(ArrayList<Clauses> KB)
    {
        ArrayList<Clauses> KBPrim = new ArrayList<>();
        ArrayList<Clauses> returnKB = new ArrayList<>();
        ArrayList<Clauses> S;
        Clauses C;
        Clauses A;
        Clauses B;
        while (!KBPrim.equals(KB))
        {
            KBPrim = new ArrayList<Clauses>(KB);
            S = new ArrayList<Clauses>();
            C = new Clauses();
            for (int i = 0; i < KB.size() - 1; i++)
            {
                for (int j = i+1; j < KB.size(); j++)
                {
                    A = new Clauses(KB.get(i));
                    B = new Clauses(KB.get(j));
                    C = resolution(A, B);
                    if (C != null)
                    {
                        if (!S.contains(C))
                        {
                            S.add(C);
                        }
                    }
                }
            }
            if (S.isEmpty())
            {
                returnKB = removeDuplicates(KB);
                return returnKB;
            }
            KB = Incorporate(S, KB);
        }

        return KB;
    }

    public static ArrayList<Clauses> Incorporate(ArrayList<Clauses> S, ArrayList<Clauses> KB)
    {
        ArrayList<Clauses> KBTemp = new ArrayList<Clauses>(KB);
        for (Clauses A : S)
        {
            KBTemp = Incorporate_clauses(A, KBTemp);
        }
        return KBTemp;
    }

    public static ArrayList<Clauses> Incorporate_clauses(Clauses A, ArrayList<Clauses> KB)
    {
        int KBSize = KB.size();
        for (int i = 0; i < KBSize; i++)
        {
            if (isSubSet(A,KB))
                return KB;

            if (isStrictSubset(A,KB.get(i)))
            {
                KB.remove(KB.get(i));
                KBSize = KB.size();
            }
        }

        if(!KB.contains(A))
        {
            KB.add(A);
        }
        return KB;
    }
    public static boolean isSubSet(Clauses A, ArrayList<Clauses> KB)
    {
        for (Clauses B : KB)
        {
            if (!(CollectionUtils.isSubCollection(B.getPos(),A.getPos())))
                return false;
            else if (!(CollectionUtils.isSubCollection(B.getNeg(), A.getNeg())))
                return false;
            else
                return true;
        }
        return true;
    }
    public static boolean isStrictSubset(Clauses A, Clauses B)
    {
        for (String S :  A.getPos())
        {
            if (!(B.getPos().contains(S)))
                return false;
        }
        for (String S : A.getNeg())
        {
            if(!(B.getNeg().contains(S)))
                return false;
        }

        if ((B.getPos().size() + B.getNeg().size()) < (A.getNeg().size() + A.getNeg().size()))
                return false;

        return true;
    }
}
