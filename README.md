
# Project Description:
# Title: Cricket Player and Match Statistics Management System

The Cricket Player and Match Statistics Management System is a sophisticated software solution that leverages the power of AVL (Adelson-Velsky and Landis) trees to efficiently manage and update player rankings within the context of cricket player and match statistics. This project focuses on the intricacies of implementing AVL trees to handle large datasets and maintain balanced and consistently updated player rankings.

## the time complexities :  Every function from crud , sort , search , max , min in logarithmic time 

| **Operation**        | **Time Complexity** | **Reason**                                               |
|----------------------|----------------------|----------------------------------------------------------|
| **Player Search**    | O(1)                 | Unordered map search is O(1) on average.                |
| **Player Creation**  | O(1)                 | The constructor of the player is O(1).                  |
| **Player Update**    | O(log k)             | Inserting into priority queues is O(log k).             |
| **Match Search**     | O(1)                 | Unordered map search is O(1) on average.                |
| **Match Creation**   | O(1)                 | The constructor of the match is O(1).                   |
| **Match Update**     | O(log p)             | Inserting into a set is O(log p).                        |
| **Rankings Update**  | O(1)                 | The check function is O(1).                             |
| **AVL Tree Search**  | O(log n)             | AVL tree search is O(log n).                            |
| **AVL Tree Insert**  | O(log n)             | AVL tree insertion is O(log n).                         |
| **AVL Tree Delete**  | O(log n)             | AVL tree deletion is O(log n).                          |
| **AVL Tree Reinsert**| O(log n)             | Deletion and reinsertion combined is O(log n).          |

*Overall Time Complexity for input_1 is dominated by the AVL tree operations, making it O(log n), where n is the number of players in the AVL tree.*

## the space complexities :  

| Operation          | Space Complexity | Reason                                                                |
|--------------------|------------------|-----------------------------------------------------------------------|
| **Player Search**  | O(1)             | Searching in an unordered map requires no additional space.           |
| **Player Creation**| O(1)             | Creating a player object requires a constant amount of space.         |
| **Player Update**  | O(1)             | Updating a player in a priority queue does not require extra space.   |
| **Match Search**   | O(1)             | Searching in an unordered map for matches requires no additional space.|
| **Match Creation** | O(1)             | Creating a match object requires a constant amount of space.          |
| **Match Update**   | O(1)             | Updating a match in a set requires no additional space.               |
| **Rankings Update**| O(1)             | Updating rankings requires a constant amount of space.                |
| **AVL Tree Operations** | O(log n)    | Space complexity for the height of the tree affecting recursion stack.|


AVL Tree Implementation:
Balanced Rankings:

The heart of the system lies in the AVL tree structure, ensuring that player rankings remain balanced at all times.
AVL trees maintain balance by performing rotations during insertions and deletions, preventing the tree from becoming skewed and optimizing search and update operations.
Efficient Searching and Updating:

The AVL tree structure facilitates efficient searching for specific players and updating their rankings based on individual match performances.
The logarithmic time complexity of AVL trees ensures quick retrieval of player information and rankings, enhancing the overall performance of the system.
Automatic Ranking Adjustments:

As new match data is inputted, the AVL tree dynamically adjusts player rankings, taking into account the total runs scored for batsmen and total wickets taken for bowlers.
The self-balancing property of AVL trees ensures that the rankings are consistently updated without manual intervention.
Node Structure:

Each node in the AVL tree represents a player, storing relevant information such as player ID, total runs scored, total wickets taken, and other relevant details.
The balancing factor associated with each node ensures that the tree remains balanced, providing optimal search and update efficiency.
Insertion and Deletion Operations:

When a new player is added or an existing player's information is modified, the AVL tree undergoes rotations to maintain balance, ensuring that the tree remains height-balanced.
Similarly, when a player is removed from the system, the AVL tree adjusts to maintain its balanced structure.
Rankings Display:

The system provides a seamless interface to display top batsmen and bowlers based on their rankings, which are dynamically maintained by the underlying AVL tree structure.
Benefits of AVL Tree Integration:
Optimized Performance:

AVL trees ensure optimal search and update operations, even with a large dataset, providing users with a responsive and efficient experience.
Consistent Balance:

The automatic balancing feature of AVL trees guarantees that the rankings remain balanced, preventing performance degradation over time.
Scalability:

The AVL tree implementation makes the system highly scalable, capable of handling an increasing volume of player and match data without compromising performance.
In summary, the Cricket Player and Match Statistics Management System's core strength lies in its AVL tree implementation, providing a robust and efficient foundation for managing and updating player rankings within the dynamic context of cricket statistics.




