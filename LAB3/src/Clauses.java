import java.util.Vector;
import java.util.*;

public class Clauses {
    Vector<String> posVector = new Vector<String>();
    Vector<String> negVector = new Vector<String>();

    public Clauses(String clause)
    {
        ArrayList <String> neg = new ArrayList<String>();
        ArrayList <String> pos = new ArrayList<String>();

        String result = clause;

        for ( String in : result.split("~")) {
            neg.add(in);
        }
        pos.add(neg.get(0).replaceAll("v",""));
        neg.remove(0);

        //pos.removeIf(n->(n.charAt(0) == '~'));
        System.out.println("NEGATIVES");
        for (int i = 0; i < neg.size(); i++) {
            System.out.println(neg.get(i));
        }
        System.out.println("POSITIVES");
        for (int i = 0; i < pos.size(); i++) {
            System.out.println(pos.get(i));
        }
    }
}
