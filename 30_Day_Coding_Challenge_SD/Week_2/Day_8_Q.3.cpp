vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
    map<int, int> mapArr;
    vector<int> res;

    /* I taken map her but not used hashing, I taken map only for storing "ranked" array elements in sorted order(accessending order) and for not including repeated
       elements.
       We can take any container instead of map, but the only thing to take care is while storing elements in that container just make sure that it should be stored in 
       sorted order(accessending order) and no repeataion should be included of any element. 
       For example: ranked = [100, 100, 50, 40, 40, 20, 10]
       so new container would be, map = [10, 20, 40, 50, 100]
    */
   
    for (int i = 0; i < ranked.size(); i++) 
    {
        mapArr[ranked[i]]++;
    }

    int j = 0;
    int rank = mapArr.size();
    map<int, int>::iterator i;
    for (i = mapArr.begin(); i != mapArr.end();)
    {

        if (j < player.size())
        {

            if (player[j] < (i->first) && j < player.size())
            {
                res.push_back(rank + 1);
                j++;
            }
            else if (player[j] == (i->first) && j < player.size())
            {
                res.push_back(rank);
                j++;
            }
            else if (player[j] >= (i->first) && rank == 1 && j < player.size())
            {
                res.push_back(1);
                j++;
            }
            else
            {
                rank--;
                i++;
                continue;
            }
        }

        else
        {
            break;
        }
    }

    return res;
}

// Time Complexity: O(N)
// Space Complexity: O(N)