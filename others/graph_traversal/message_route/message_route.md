
# Message Route

There is a network of  `n`  computers, each computer is numbered  `1`  to  `n`.

The computer network is given as an array of  `edges`  where  `edges[i] = [ui, vi]`  is a bidirectional edge that connects computer  `ui`  and computer  `vi`  .

Your task is to find if Alice can send a message to Bob, if it is possible, return minimum number of computers on such a route and if it is not possible than return  `-1`.

Alice's Computer is  `1`  and Bob's computer is `n`.

**Constraints:**

-   `2≤ n ≤10^5`
    
-   `1<= edges.length <= 2*10^5`
    
-   `1<= ui, vi <=n`
    

**Example:**

1.  Input: n=  5, edges=  [[1,2],[1,3],[1,4],[2,3],[5,4]]  

3.  Output:  3
