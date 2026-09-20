    HashMap<Integer, List<Integer>> rowMap = new HashMap<>();




     for(int[] row : reservedSeats)
    {
        if(row[1] == 1 || row[1] == 10)
            continue;

        rowMap.computeIfAbsent(row[0], k-> new ArrayList<>()).add(row[1]);
    }


    int groups = 0;

    for(int i : rowMap.keySet())
    {
        boolean first = true;
        boolean second = true;
        boolean third = true;

        if(rowMap.containsKey(i))
        {
            for(int seat : rowMap.get(i))
            {
                if(seat == 4 || seat == 5)
                {
                     first = false;
                     second = false;
                }
                else if(seat == 6 || seat == 7)
                {
                    second = false;
                    third = false;
                }
                else if(seat < 4)
                    first = false;
                else if(seat > 7 )
                {
                    third = false;
                }

                if(!first && !second && !third)
                    break;
            }
        }

        if(first && third)
            groups += 2;
        else if(first || second || third)
            groups++;

    }

    int allFree = n - rowMap.size();

    groups += (2 * allFree);
    return groups;

}