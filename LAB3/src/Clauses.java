import org.apache.commons.collections4.CollectionUtils;

import java.util.*;


public class Clauses {

    private ArrayList <String> pos;
    private ArrayList <String> neg;

    /* Default constructor */
    public Clauses()
    {
        pos = new ArrayList<String>();
        neg = new ArrayList<String>();

    }

    /* Construct Clause from String */
    public Clauses(String clause)
    {
         pos = new ArrayList<String>();
         neg = new ArrayList<String>();

        String[] splitString;

        splitString = clause.split(" ");

        for (String e : splitString)
        {
            if (e.startsWith("~"))
            {
                neg.add(e.replace("~", ""));
            }
            else if(!(e.equals("v")))
            {
                pos.add(e);
            }
        }
    }
    /* Copy constructor, making shallow copy */
    public Clauses(Clauses copy)
    {
        this.pos = (ArrayList<String>) copy.getPos().clone();
        this.neg = (ArrayList<String>) copy.getNeg().clone();
    }

    public ArrayList<String> getPos()
    {
        return pos;
    }

    public ArrayList<String> getNeg()
    {
        return neg;
    }

    public void setPos(ArrayList<String> in) { pos = in; }

    public void setNeg(ArrayList<String> in) { neg = in; }

    public boolean same(Clauses c)
    {
        if (c == null) return false;
        if (c.getClass() != this.getClass()) return false;

        if (((this.pos.isEmpty()) && (c.pos.isEmpty())) && (this.neg.equals(c.neg)))
        {
            return true;
        }
        if (((this.neg.isEmpty()) && (c.neg.isEmpty())) && (this.pos.equals(c.pos)))
        {
            return true;
        }
        if ((this.pos.equals(c.pos)) && (this.neg.equals(c.neg)))
        {
            return true;
        }

        return false;
    }

    @Override
    public String toString()
    {
        String returnString = "";
        for (int i = 0; i < pos.size(); i++)
        {
            returnString += pos.get(i);
            if (!(pos.size()-1 == i))
            {
                returnString += " v ";
            }
        }

        for (int i = 0; i < neg.size(); i++)
        {
            returnString += "~" + neg.get(i);
        }

        return returnString;
    }
}

