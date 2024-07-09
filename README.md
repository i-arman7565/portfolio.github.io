<!-- ![header image](assets/logo.png) -->
<img src="assets/logo.png" alt="Getting In Touch with LinkedIn" height="400">

---

## 📘 Course Information

- **Course Name:** Algorithmic Problem Solving
- **Course Code:** 23ECSE309
- **Name:** Mohammad Arman Khan
- **USN:** 01FE21BCI037
- **University:** KLE Technological University, Hubballi-31

---

## 📑 Table of Contents

1. [Introduction](#introduction)
2. [Business Cases](#business-cases)
4. [References](#references)

---

## Introduction

LinkedIn is a professional networking platform designed to connect professionals worldwide, facilitating career development, networking opportunities, and knowledge exchange. It serves as a digital hub where individuals and businesses showcase their professional profiles, share industry insights, and collaborate on projects [[1]](https://en.wikipedia.org/wiki/LinkedIn). LinkedIn relies on Data Structures and Algorithms (DSA) to improve search results, recommend relevant connections and content, manage user interactions, ensure data security, and enhance overall platform performance. They play a crucial role in optimizing user experiences and facilitating effective professional networking and career development on the platform.[[2]](https://about.linkedin.com/)

<img src="assets/architecture.png" alt="Getting In Touch with LinkedIn" height="375">

### Market Analysis

LinkedIn has established itself as a dominant force in professional networking with significant market reach and impact. According to 99Firms, as of 2020, LinkedIn reported revenue of $8.05 billion and boasts over 830 million members globally. A substantial portion, approximately 31%, of LinkedIn's traffic originates from the United States.[[3]](https://thesocialshepherd.com/blog/linkedin-statistics) The platform has seen a notable surge in activity, particularly with a tripling of searches for remote work following the onset of the COVID-19 pandemic. Weekly job searches on LinkedIn reach up to 50 million, with 122 million individuals reportedly securing interviews through the platform. LinkedIn stands out in B2B lead generation, responsible for 80% of such leads from social media platforms. It's also recognized as the top-rated organic social media platform for B2B marketers, underscoring its pivotal role in professional networking and recruitment strategies worldwide. [[4]](https://99firms.com/blog/linkedin-statistics/#gref)

### Objectives

- Explore business use cases, challenges, and benefits.
- Identify and analyze different functionalities in LinkedIn that utilizes DSA.
- Identify Opportunities where DSA can be further optimized to enhance platform performance and user experience.
- Propose new algorithms or optimizations that could better handle LinkedIn's massive user base and diverse functionalities if any.

## Business Cases

---

## 1. Efficient Messaging System

The efficient messaging system is designed to facilitate real-time communication with features like instant message delivery and sequential message order. This system is crucial for applications such as chat platforms or collaborative tools.

### Use Case

The efficient messaging system aims to:
- Facilitate real-time communication.
- Ensure instant message delivery.
- Maintain sequential message order.

### Challenges
- **Low Latency:** Ensure timely message delivery.
- **Message Order:** Preserve message order across distributed systems.

### Market Benefits
- **Improved User Experience:** Enhanced responsiveness and reliability.
- **Higher Engagement:** Increased user satisfaction and platform retention rates.

### Algorithms

#### a. Queue
- **Time Complexity:** O(1) for enqueue and dequeue operations.
- **Use Case:** Message storage and retrieval.

#### b. HashMap
- **Time Complexity:** O(1) for session tracking.
- **Use Case:** Track user sessions and their message queues.

### Approach

1. **Message Storage and Retrieval:** Use a queue for efficient message storage and retrieval.
2. **Session Tracking:** Implement a HashMap to manage user sessions and their respective message queues.
3. **Distributed Messaging Architecture:** Design a scalable architecture to handle high message volumes.

### Design

- **Queue:** Manages message storage and ensures ordered retrieval.
- **HashMap:** Tracks user sessions and queues, providing constant-time access.
- **Distributed Architecture:** Ensures scalability and low latency in message delivery.

<img src="assets/messagin.png" alt="call 911" height="375">

### Implementation

The implementation involves setting up a distributed messaging architecture using queues for message handling and HashMaps for session management. This combination ensures efficient, real-time message delivery and scalability.

View implementation :  [Queue](https://github.com/Xenoids/C-Queue/blob/master/Queue%20Array.cpp) , 
 [Hash Map](https://gist.github.com/aozturk/2368896)<br>

---

## 2. Activity Feed Generation

The activity feed generation system is designed to provide personalized and real-time updates to users, enhancing their engagement and experience on the platform.


### Use Case

The activity feed generation system aims to:
- Generate personalized activity feeds for users.
- Ensure real-time updates.
- Handle a high volume of data efficiently.

### Challenges

- **Real-Time Updates:** Provide up-to-the-minute updates.
- **Data Volume:** Handle large amounts of activity data.
- **Personalization:** Ensure the feeds are relevant to each user.

### Market Benefits

- **Improved User Engagement:** Users stay engaged with fresh, relevant content.
- **Personalized Experience:** Enhanced user satisfaction through tailored feeds.

### Algorithms

#### a. Priority Queue

- **Time Complexity:** O(log n) for insert and remove operations.
- **Use Case:** Manage and rank activities based on relevance.

#### b. Heaps

- **Time Complexity:** O(log n) for insertion operations.
- **Use Case:** Efficient retrieval of top activities.

### Approach

1. **Activity Ranking:** Use a priority queue to manage and rank activities based on relevance.
2. **Efficient Retrieval:** Implement a min-heap or max-heap to efficiently retrieve the top activities.
3. **Real-Time Updates:** Design the system to update feeds in real-time as new activities occur.

### Design

- **Priority Queue:** Manages activity ranking and ensures efficient insertion and removal.
- **Heap:** Facilitates quick retrieval of top-ranked activities.

<img src="assets/feed.gif" alt="Getting In Touch with LinkedIn" height="375">

### Implementation

The implementation involves using a priority queue to rank activities and a heap structure to retrieve the most relevant activities efficiently. The system is designed to handle real-time updates, ensuring users receive fresh and personalized content.

View implementation : [Priority Queue](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/PriorityQueue.cpp)<br>

---

## 3. Profile Search and Indexing

The profile search and indexing system is designed to efficiently search and index user profiles, ensuring quick access and retrieval of information.

### Use Case

The profile search and indexing system aims to:
- Efficiently search and index user profiles.
- Handle large datasets.
- Ensure quick search results.

### Challenges
- **Handling Large Datasets:** Manage and index large volumes of user profile data.
- **Quick Search Results:** Ensure fast retrieval of relevant profile information.

### Market Benefits
- **Faster Profile Discovery:** Users can quickly find relevant profiles.
- **Improved Search Experience:** Enhances user satisfaction with efficient search capabilities.

### Algorithms

#### a. Trie
- **Time Complexity:** O(n) for insertion and search operations.
- **Use Case:** Index profile information for quick prefix-based searches.

<img src="assets/trie.webp" alt="call 911 image not loading" height="400"><br>

#### b. B-Tree
- **Time Complexity:** O(log n) for insertion and search operations.
- **Use Case:** Provide balanced indexing and efficient range queries.

![call 911 image not laoding](assets/bsearch.jpg)


### Approach

1. **Trie Data Structure:** Use a trie to index profile information, enabling efficient prefix-based searches.
2. **B-Trees:** Implement B-Trees to maintain balanced indexing and support efficient range queries.
3. **Dynamic Indexing:** Design the system to update dynamically as profiles are modified or added.

### Design

- **Trie:** Handles prefix-based searches efficiently.
- **B-Tree:** Provides balanced indexing for range queries.
- **Dynamic Indexing:** Ensures real-time updates to profile information.

### Implementation

The implementation involves integrating a trie for prefix-based searches and B-Trees for efficient range queries. The system is designed to handle large datasets and ensure quick access to profile information.

View implementation :  [Trie](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/Trie.cpp), 
 [B-plus tree](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/BPlusTrees.cpp)<br>

---

## 4. Load Balancing

The load balancing system distributes incoming traffic evenly across servers, ensuring high availability and optimal performance.

<img src="assets/loadbalancing.png" alt="Getting In Touch with LinkedIn" height="375">

### Use Case

The load balancing system aims to:
- Distribute incoming traffic evenly across servers.
- Ensure high availability during peak loads.
- Manage high traffic volumes efficiently.

### Challenges
- **Ensuring Availability:** Maintain server availability under varying traffic conditions.
- **Managing High Traffic Volumes:** Handle spikes in traffic without performance degradation.

### Market Benefits
- **Improved System Reliability:** Ensures continuous service availability.
- **Better Performance:** Optimizes resource utilization across servers.

### Algorithms

#### a. Round Robin
- **Time Complexity:** O(1) for distributing requests.
- **Use Case:** Distribute incoming requests evenly across server nodes.

#### b. Consistent Hashing
- **Time Complexity:** O(log n) for distributing requests.
- **Use Case:** Ensures minimal data movement when scaling server clusters.

### Approach

1. **Round Robin Algorithm:** Implement round-robin to evenly distribute requests across available servers.
2. **Consistent Hashing:** Use consistent hashing to maintain balanced loads and minimize data reassignment during scaling events.

### Design

- **Round Robin:** Distributes requests evenly.
- **Consistent Hashing:** Ensures balanced loads and minimal data movement.
- **Dynamic Adjustment:** Adjusts load balancing strategies based on real-time server conditions.

### Implementation

The implementation involves deploying a load balancing system that uses round-robin and consistent hashing algorithms to distribute traffic efficiently across server clusters. The system ensures high availability and optimal performance during varying traffic conditions.

Find Round Robin and other CPU scheduling algorithms [here](https://github.com/yousefkotp/CPU-Scheduling-Algorithms)<br>
Find Consistent hashing implementation [here](https://github.com/prakharrai1609/consistent-hashing)<br>

---

## 5. Job Recommendation System using Graph Methods on LinkedIn

LinkedIn aims to enhance its job recommendation system by leveraging graph methods to analyze the complex relationships between job seekers, job postings, skills, and career interests. By employing graph algorithms, LinkedIn can uncover nuanced connections and patterns that lead to more accurate and personalized job recommendations. 

### Use Case

LinkedIn seeks to provide job seekers with personalized recommendations that align closely with their skills, career interests, and professional aspirations.

### Challenges

- **Building a Comprehensive Job Graph:**
  - **Data Integration:** Integrating diverse data sources such as user profiles, job postings, skills, and endorsements into a unified job graph.
  - **Graph Construction:** Constructing a comprehensive graph that accurately reflects the relationships between job seekers, job postings, skills, and career interests.

- **Algorithm Selection and Optimization:**
  - **Graph Algorithms:** Choosing suitable graph algorithms (e.g., graph embedding, random walk-based recommendation) to extract meaningful insights and recommendations from the job graph.
  - **Scalability:** Ensuring that the system can handle LinkedIn's vast user base and the dynamic nature of job postings while maintaining low latency for recommendation queries.

- **Personalization and User Experience:**
  - **Personalized Recommendations:** Balancing between recommending jobs that match the user's current profile and suggesting opportunities that align with their long-term career aspirations.
  - **User Engagement:** Enhancing user engagement by providing timely and relevant job recommendations that cater to individual preferences and career interests.

### Algorithms

#### a. Graph Embedding (Node2Vec)
   - **Purpose:** Learn low-dimensional vector representations of nodes (users, job postings, skills) in the job graph, capturing their structural and semantic relationships.
   - **Application:** Construct a graph representing relationships between job seekers, job postings, and skills. Use Node2Vec to learn embeddings for each node, facilitating better understanding of their interconnections.
   - **Time Complexity:** O(d * V * E), where d is the dimensionality of embeddings, V is the number of nodes, and E is the number of edges.
   - **Space Complexity:** O(V + E), where V is the number of nodes and E is the number of edges.

#### b. Random Walk-based Recommendation
   - **Purpose:** Leverage graph embeddings to generate personalized job recommendations for users.
   - **Application:** Perform random walks starting from the user's profile to explore the job graph and identify relevant job postings that match the user's skills and career interests.
   - **Time Complexity:** O(k * V), where k is the number of random walks and V is the number of nodes.
   - **Space Complexity:** O(V + E), where V is the number of nodes and E is the number of edges.

### Approach

1. **Graph Construction:**
   - Build a comprehensive job graph that integrates user profiles, job postings, skills, and endorsements.
   - Define relationships between nodes (e.g., user-job, user-skill, job-skill) based on interactions and user activities on LinkedIn.

2. **Graph Algorithm Selection:**
   - Implement Node2Vec to learn embeddings for users, job postings, and skills, capturing their contextual relationships within the job graph.
   - Utilize random walk-based recommendation techniques to explore the job graph and generate personalized job recommendations for users.

3. **Personalization and Optimization:**
   - Enhance job recommendations by considering the user's current profile, past job interactions, skills, and career preferences.

### Design 

  - Design a scalable architecture that integrates graph algorithms with LinkedIn's existing job recommendation infrastructure.
  - Ensure data consistency and accuracy across the job graph to deliver reliable and relevant job recommendations.

![node2vect](assets/node.jpg)

### Implementation:
  - Implement graph algorithms (Node2Vec, random walk-based recommendation) after constructing the graph that integrates user profiles and job details.

[5][Learning Role-based Graph Embeddings](https://paperswithcode.com/paper/learning-role-based-graph-embeddings)<br>
[6][Find random walk implementation](https://www.slideshare.net/slideshow/write-a-c-program-which-generates-and-displays-a-random-walk-acrospdf/258947524)<br>

---

## 6. Connection Management

The connection management system efficiently manages user connections and networks to enhance social networking experiences.

### Use Case

The connection management system aims to:
- Manage user connections efficiently.
- Handle large graph data representing social networks.
- Ensure quick access to connection information.

### Challenges
- **Handling Large Graph Data:** Efficiently store and manage connections among users.
- **Quick Access:** Ensure rapid retrieval of connection information for networking features.

### Market Benefits
- **Enhanced Social Networking:** Improves user interactions and engagement.
- **Increased Connections:** Facilitates broader networking opportunities among users.

### Algorithms

#### a. Graph Data Structures
- **Adjacency List Time Complexity:** O(V + E) for space-efficient representation and operations.
- **Adjacency Matrix Time Complexity:** O(V^2) for dense graphs, suitable for connectivity checks.

#### b. BFS (Breadth-First Search)
- **Time Complexity:** O(V + E) for exploring connections and suggesting new connections.
- **Use Case:** Efficiently traverse the graph to recommend new connections.

### Approach

1. **Graph Representation:** Use adjacency lists to efficiently store user connections while conserving memory.
2. **BFS Algorithm:** Implement BFS to explore user connections and suggest new connections based on common interests or networks.
3. **Efficient Updates:** Design the system to handle dynamic updates to the connection graph as users connect or disconnect.

### Design

- **Graph Data Structures:** Adjacency lists for efficient space usage and quick access to connections.
- **BFS Algorithm:** Facilitates exploration of user networks and recommendation of new connections.
- **Dynamic Updates:** Supports real-time updates to reflect changes in user connections.

### Implementation

The implementation involves utilizing graph data structures and BFS algorithms to manage user connections effectively. The system is designed to enhance social networking experiences by facilitating efficient connection management and network exploration.

Find the implementation of BFS with adjacency list [link](https://gist.github.com/tamzidpeace/7c6ae5718a5615ac1c7af0a2712750dd)<br>

---

## 7. Data Compression in LinkedIn's Infrastructure

LinkedIn manages vast amounts of data including user profiles, connections, posts, and interactions across its platform. Efficient data storage and transmission are critical to ensuring a seamless user experience and optimizing operational costs. 

### Use Case

Implementing data compression enables LinkedIn to:
- **Reduce Data Size:** Compress frequently occurring data patterns to minimize storage space.
- **Enhance Data Transmission:** Transmit compressed data faster across networks, improving performance.
- **Optimize Storage:** Lower infrastructure costs by reducing the volume of stored data.

### Challenges

- **Data Analysis:** Identify and analyze frequent data patterns for efficient encoding.
- **Integration:** Ensure compatibility with existing data formats and infrastructure.
- **Efficiency:** Implement compression and decompression algorithms to minimize latency.

### Market Benefits

- **Cost Savings:** Reduced storage requirements lead to lower infrastructure costs.
- **Improved Performance:** Faster data transmission enhances user experience.
- **Network Optimization:** Minimized bandwidth usage optimizes network resources.

### Algorithms

#### Huffman Coding
- **Time Complexity:** O(n log n) for building the Huffman tree, where n is the number of symbols.
- **Space Complexity:** O(n) for storing the Huffman tree and encoded data.

![huffaman coading](assets/Huffman_huff_demo.gif)<br>

### Design

- **Data Analysis:** Identify frequent data patterns and their frequencies.
- **Huffman Tree Construction:** Build a Huffman tree based on data frequencies.
- **Encoding and Decoding:** Implement efficient algorithms for data compression and decompression.

### Implementation

Implement Huffman coding to compress data efficiently:
- Analyze data patterns and frequencies.
- Construct a Huffman tree to generate optimal encoding.
- Encode data using Huffman codes and decode as required.

View implementation : [Huffman Coding](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/HuffmanCoding.cpp)<br>

---

## 8 . Real Time Event Tracking
LinkedIn aims to enhance its real-time event detection capabilities by leveraging the A* algorithm. This heuristic-based approach can effectively analyze sudden spikes in events and bursts of activity related to specific keywords or hashtags within LinkedIn's network.

### Use Case
LinkedIn seeks to monitor and track real-time events occurring within its platform, such as trending topics, viral content, or significant user activities related to professional networking, job postings, or industry-specific discussions. 

### Challenges 
- **Analyzing Sudden Spikes:** Identifying and analyzing sudden increases in activity or events across LinkedIn's vast network in real-time.
- **Algorithmic Complexity:** Implementing the A* algorithm efficiently to ensure quick response times without compromising accuracy.

### Market Benefits
- **Real-Time Event Tracking:** Improve LinkedIn’s ability to track and respond to real-time events.
- **Timely Response:** Enable quick actions and decisions based on real-time data insights.

### Algorithm

#### A* Algorithm

- **Purpose:** Heuristic-based search algorithm used for pathfinding and analyzing event spikes based on keyword or hashtag occurrences.
- **Time Complexity:** Depends on the heuristic and graph structure, typically O(b^d), where b is the branching factor and d is the depth of the solution.
- **Space Complexity:** O(b^d) due to the storage requirements for nodes in the search tree.

<!-- ![Astar](assets/Astar.png) -->

<img src="assets/Astar.png" alt="Getting In Touch with LinkedIn" height="">

### Approach 
- **Event Identification:** Apply the A* algorithm to detect significant spikes or bursts in activity related to specific keywords or hashtags.
- **Analysis and Reporting:** Analyze detected events to provide actionable insights and real-time updates to LinkedIn users and administrators.

### Design 
  - Design a scalable architecture to integrate the A* algorithm with LinkedIn's existing data pipelines and event processing systems.
  - Ensure robust data consistency and accuracy to deliver reliable event detection and reporting.

### Implementation 
  - Implement the A* algorithm using efficient data structures and algorithms tailored for real-time event detection.
  - Integrate event detection capabilities into LinkedIn's backend infrastructure to support continuous monitoring and timely response to breaking events.

View implementation : [A star](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/AStar.cpp)<br>

---

## 9. Notification System

The notification system implements a real-time mechanism for delivering notifications, ensuring scalability, and personalization.

### Use Case

The notification system aims to:
- Implement real-time delivery of notifications.
- Ensure scalability to handle increasing user base and notification volume.
- Personalize notifications based on user preferences.

### Challenges
- **Scalability:** Handle a growing number of users and notifications without performance degradation.
- **Real-Time Delivery:** Ensure timely delivery of notifications.
- **Personalization:** Tailor notifications to individual user preferences and behaviors.

### Market Benefits
- **Increased User Engagement:** Promotes user interaction through timely updates.
- **Timely Updates:** Keeps users informed with relevant information.
- **Scalability:** Scales efficiently with increasing user base and notification traffic.

### Algorithms

#### a. Queue
- **Time Complexity:** O(1) for enqueue and dequeue operations.
- **Use Case:** Handles incoming notifications in a first-in, first-out manner.

![queue](assets/circular%20queue.gif)<br>

#### b. Observer Pattern
- **Time Complexity:** O(1) for notifying subscribers.
- **Use Case:** Allows users to subscribe and receive notifications based on their interests.

### Approach

1. **Queue Management:** Use a queue to manage incoming notifications and ensure they are delivered promptly.
2. **Observer Pattern:** Implement the observer pattern to allow users to subscribe to specific notification types or categories.
3. **Scalable Architecture:** Design the system to scale horizontally to accommodate increasing notification volumes and user base.

### Design

- **Queue:** Ensures FIFO delivery of notifications.
- **Observer Pattern:** Facilitates personalized notification delivery based on user preferences.

### Implementation

The implementation involves deploying a notification system that utilizes queues for efficient message delivery and the observer pattern for personalized notifications. The system ensures scalability and real-time delivery of notifications to enhance user engagement.

View implementation : [Queue](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/Deque.cpp)<br>

---


## 10. Real-Time Engagement Tracking on LinkedIn

LinkedIn emphasizes the importance of user engagement metrics to enhance user experience and provide valuable insights to content creators and advertisers. Implementing a real-time tracking system for engagement metrics such as likes, reactions, and comments can significantly improve user interaction analysis and platform responsiveness.

### Use Case:

LinkedIn aims to monitor user engagement metrics in real-time to understand trending topics, user preferences, and content performance across different demographics. Fenwick trees can efficiently track cumulative counts of engagement events over time intervals, enabling LinkedIn to provide up-to-date insights into user behavior and content effectiveness.

### Challenges

1. **High Volume of Updates**: Managing real-time updates from millions of users requires an efficient data structure like Fenwick trees to handle frequent updates and queries without compromising performance.
   
2. **Data Consistency**: Ensuring accurate and consistent engagement metrics across a distributed system is critical for generating reliable insights and maintaining user trust.
   

### Market Benefits

- **Enhanced User Engagement**: By tracking engagement metrics in real-time, LinkedIn can identify popular content and trends more effectively, encouraging user interaction and content creation.
  
- **Personalized Recommendations**: Real-time insights into user engagement enable LinkedIn to deliver personalized content recommendations and advertisements, improving user satisfaction and advertising effectiveness.
  
- **Data-Driven Decisions**: Analyzing real-time engagement metrics helps LinkedIn make data-driven decisions to optimize platform features, improve user retention, and attract advertisers.

### Algorithms

####  Fenwick Tree (Binary Indexed Tree)

- **Purpose**: Data structure for efficient range queries and updates of cumulative frequencies.
- **Time Complexity**: O(log n) for both updates and prefix sum queries.
- **Space Complexity**: O(n) for storing the Fenwick tree.

### Design 

Designing a scalable architecture that integrates Fenwick trees with LinkedIn’s existing data pipelines and analytics infrastructure.

### Implementation

Implementing Fenwick trees to track and update engagement metrics in real-time, ensuring data consistency and performance optimizations for high-volume updates.

Veiw implementation : [Fenwick Tree](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/FenwickTree.cpp)<br>

---

## 11. Data Caching

The data caching system caches frequently accessed data to improve performance and reduce database load.

### Use Case

The data caching system aims to:
- Cache frequently accessed data to reduce database queries and latency.
- Handle cache invalidation to maintain data consistency.
- Improve overall system performance by reducing response times for repeated queries.

### Challenges
- **Cache Invalidation:** Ensure cached data remains consistent with the database.
- **Consistency:** Maintain data integrity across cached and persistent storage.
- **Performance Optimization:** Reduce latency and improve response times for critical operations.

### Market Benefits
- **Improved Performance:** Enhances system responsiveness and user experience.
- **Reduced Latency:** Minimizes delays in data retrieval and processing.
- **Scalability:** Supports increased user traffic and data volume with optimized resource usage.

### Algorithms

#### a. LRU Cache (Least Recently Used)
- **Time Complexity:** O(1) for get and put operations.
- **Use Case:** Caches frequently accessed data and evicts the least recently used items when the cache reaches its capacity.

#### b. LFU Cache (Least Frequently Used)
- **Time Complexity:** O(log n) for get and put operations.
- **Use Case:** Caches data based on frequency of access and evicts the least frequently used items.

![Lru-Lfu](assets/lru.gif)

### Approach

1. **Cache Implementation:** Choose between LRU or LFU caching strategies based on access patterns and data characteristics.
2. **Data Structure:** Use a combination of HashMap and doubly linked list for efficient cache management and quick access.
3. **Invalidation Strategy:** Implement cache invalidation mechanisms to synchronize cached data with the database.

### Design

- **LRU or LFU Cache:** Implements either strategy to optimize data access and storage.
- **HashMap with Doubly Linked List:** Ensures efficient data retrieval and cache eviction.

### Implementation

The implementation includes integrating an LRU or LFU caching system to store frequently accessed data and reduce database load. The system is designed to handle cache invalidation and ensure consistent data access with minimal latency.

View implementation : [Page Replacement](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/pageReplacement.cpp)<br>

---

## 12. Rate Limiting

The rate limiting system controls and limits the number of requests a user or client can make to prevent abuse and maintain system stability.

### Use Case

The rate limiting system aims to:
- Prevent abuse and mitigate potential denial-of-service (DoS) attacks.
- Ensure fair usage of system resources among all users.
- Manage high throughput efficiently without compromising performance.

### Challenges

- **Fairness:** Enforce fair usage policies to allocate resources equitably.
- **High Throughput:** Handle a large volume of requests while maintaining responsiveness.
- **Dynamic Adjustment:** Adjust rate limits dynamically based on user behavior and system load.

### Market Benefits

- **Improved Security:** Mitigates the risk of DoS attacks and unauthorized access attempts.
- **Better Resource Management:** Optimizes resource allocation and usage across the system.
- **Enhanced User Experience:** Ensures consistent performance and availability for all users.

### Algorithms

#### a. Token Bucket
- **Time Complexity:** O(1) for checking and updating token availability.
- **Use Case:** Controls the rate of requests by allowing a fixed number of tokens to be consumed per time interval.

#### b. Leaky Bucket
- **Time Complexity:** O(1) for checking and updating water level.
- **Use Case:** Smooths out bursty traffic by leaking tokens at a constant rate.

### Approach

1. **Token Management:** Implement the token bucket algorithm to manage request rates and enforce rate limits.
2. **Leaky Bucket:** Use the leaky bucket algorithm to regulate incoming traffic and prevent sudden spikes in requests.
3. **Dynamic Adjustment:** Design the system to adjust rate limits dynamically based on user activity and system load.

### Design

- **Token and Leaky Bucket Algorithms:** Ensures controlled access to system resources and smooths out traffic spikes.
- **Dynamic Rate Adjustment:** Adapts rate limits in real-time to maintain system stability and performance.
- **Monitoring and Metrics:** Tracks and analyzes request patterns to optimize rate limiting strategies.

### Implementation

The implementation involves integrating token and leaky bucket algorithms to enforce rate limits effectively. The system is designed to enhance security, optimize resource usage, and provide a consistent user experience across varying traffic conditions.

View implementation : [rate limiting algorithm](https://github.com/hardikSinghBehl/rate-limiting-api-spring-boot)<br>

---

## 13. Session Management

The session management system efficiently manages user sessions to ensure seamless user experiences and enhanced security.

### Use Case

The session management system aims to:
- Efficiently handle user sessions across multiple devices and sessions.
- Ensure session persistence and security.
- Manage session timeouts and user authentication seamlessly.

### Challenges
- **Scalability:** Handle concurrent user sessions without performance degradation.
- **Session Persistence:** Maintain session state across multiple interactions and devices.
- **Security:** Ensure secure session handling and prevent unauthorized access.

### Market Benefits
- **Improved User Experience:** Provides seamless navigation and interaction across sessions.
- **Enhanced Security:** Protects user data and prevents unauthorized access.
- **Scalability:** Scales to support growing user bases and increasing session volumes.

![session](assets/session.svg)

### Algorithms

#### a. HashMap
- **Time Complexity:** O(1) for get and put operations.
- **Use Case:** Stores session data with quick access for authentication and state management.

#### b. Linked List
- **Time Complexity:** O(1) for insertion and deletion operations.
- **Use Case:** Tracks session timeouts and manages session lifecycle.

### Approach

1. **Session Storage:** Use a HashMap to store session data securely and efficiently.
2. **Session Lifecycle:** Implement a linked list to manage session timeouts and remove expired sessions.
3. **Concurrency Handling:** Design the system to handle high concurrency and ensure consistent session management across multiple devices.

### Design

- **HashMap:** Stores session data securely with fast access for authentication and state management.
- **Linked List:** Manages session timeouts and ensures timely removal of expired sessions.
- **Concurrency Control:** Supports concurrent session handling to maintain system responsiveness and user satisfaction.

### Implementation

The implementation involves deploying a session management system that uses HashMaps and linked lists to efficiently manage session states and ensure secure user interactions. 

View implementation : [LinkedList](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/linkedList.cpp)<br>

---

## 14. Follower/Following Management

The follower/following management system is designed to efficiently handle user connections and interactions within the platform.

![follower/following](assets/flll.jpg)

### Use Case

The system aims to:
- Manage follower and following lists efficiently.
- Ensure quick updates and insertions.
- Scale with the growing number of users and connections.

### Challenges
- **Handling Large Lists:** Efficiently manage large lists of followers and followings.
- **Quick Updates:** Ensure fast insertion and removal operations.
- **Scalability:** Design the system to handle increasing numbers of users and connections.

### Market Benefits
- **Enhanced User Experience:** Users can seamlessly manage their connections.
- **Increased Social Interactions:** Facilitates better engagement among users.

### Algorithms

#### a. HashSet
- **Time Complexity:** O(1) for add and remove operations.
- **Use Case:** Store follower and following lists for quick updates.

#### b. Linked List
- **Time Complexity:** O(1) for insertion operations.
- **Use Case:** Maintain order and handle insertions efficiently.

### Approach

1. **HashSet Implementation:** Use HashSet to store and manage follower/following relationships.
2. **Linked List Usage:** Implement a linked list to maintain order and efficiently handle insertions.
3. **Scalability Design:** Design the system to scale seamlessly with the increasing number of users and connections.

### Design

- **Data Structure Selection:** Utilize HashSet for fast access and management of follower/following relationships.
- **Order Maintenance:** Implement a linked list to maintain the order of connections, ensuring efficient insertion and deletion.
- **Scalability Considerations:** Design the system architecture to handle large volumes of user connections and interactions.

### Implementation

The implementation involves:
- **Data Structure Integration:** Integrate HashSet and linked list functionalities to manage follower/following lists efficiently.
- **Scalability Measures:** Implement strategies to scale the system as the user base grows, optimizing performance and responsiveness.
- **User Interface Integration:** Integrate with the user interface to provide seamless interaction and management of connections.

View implementation : [Hash Table](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/HashTables.java)<br>

---

## 15. Event Scheduling

The event scheduling system facilitates the management and scheduling of various events such as webinars and live sessions.

### Use Case

The system aims to:
- Schedule and manage events effectively.
- Handle conflicts and ensure timely notifications.
- Increase user engagement and event attendance.

### Challenges
- **Handling Conflicts:** Manage overlapping event schedules.
- **Timely Notifications:** Ensure users receive event updates promptly.
- **Scalability:** Scale the system to accommodate a growing number of events and users.

### Market Benefits
- **Increased User Engagement:** Users participate more actively in scheduled events.
- **Higher Event Attendance:** Ensure more users attend scheduled events.

### Algorithms

#### a. Interval Tree
- **Time Complexity:** O(log n) for insert and search operations.
- **Use Case:** Manage event time slots and avoid scheduling conflicts.

#### b. Priority Queue
- **Time Complexity:** O(log n) for insert and remove operations.
- **Use Case:** Handle event notifications based on scheduled times.

### Approach

1. **Interval Tree Implementation:** Use an interval tree to manage event time slots and avoid conflicts.
2. **Priority Queue Usage:** Implement a priority queue to manage event notifications based on scheduled times.
3. **Real-Time Updates:** Design the system to handle real-time updates and reminders for scheduled events.

### Design

- **Event Management:** Utilize interval trees to efficiently manage event schedules and avoid conflicts.
- **Notification Handling:** Implement a priority queue to ensure timely event notifications based on scheduled times.
- **Scalability Planning:** Design the system architecture to scale with increasing event volumes and user participation.

### Implementation

The implementation involves:
- **Algorithm Integration:** Integrate interval tree and priority queue algorithms for effective event scheduling and notification management.
- **Real-Time Updates:** Implement mechanisms for real-time updates and reminders to users about scheduled events.
- **Scalability Measures:** Design the system to accommodate growth in event numbers and user participation, ensuring optimal performance and user satisfaction.

View implementation : [Priority Queue](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/PriorityQueue.cpp)<br>

---

## 16. Sorting Job Listings on LinkedIn

LinkedIn needs to sort a vast amount of job listings that exceed the available memory capacity, ensuring efficient sorting while preserving order across the dataset.

### Use Case

Sorting job listings on LinkedIn based on relevance and applicant fit.

### Challenges
- **Large Dataset:** Handling a large number of job listings.
- **Sorting Criteria:** Sorting based on relevance, skills match, and experience.
- **Performance:** Ensuring efficient sorting without impacting user experience.

### Market Benefits
- **Improved Matching:** Increases the likelihood of finding suitable candidates.

### Algorithms

#### a. Mergesort
- **Time Complexity:** O(n log n).
- **Use Case:** Sorts job listings based on various criteria such as job title, location, and industry.

### Approach

1. **Data Collection:** Retrieve job listings from the database.
2. **Sorting:** Apply mergesort to sort job listings based on relevance and criteria.
3. **Display:** Present sorted job listings to users on LinkedIn's platform.

### Design and Implementaion

Collect data and then apply mergesort to sort the data based on job listing

View implementation: [Merge Sort](https://github.com/i-arman7565/portfolio.github.io/blob/main/codes/MergeSort.cpp)<br>

---

## 17. Payment Processing

In the realm of digital commerce, efficient and secure payment processing systems are fundamental to customer satisfaction and operational success.

### Use Case

LinkedIn implements a seamless payment processing system for its premium services like LinkedIn Premium and LinkedIn Learning. This system enables users to easily subscribe and manage payments using various methods, ensuring smooth transactions, timely service activation, and enhanced user satisfaction.

### Challenges

Implementing robust payment processing systems involves overcoming several challenges:

1. **Security**: Protecting sensitive financial information against cyber threats and fraud is paramount.
3. **Compliance**: Adhering to stringent regulatory requirements to ensure legality and trustworthiness.
5. **Integration**: Integrating with diverse payment gateways and financial institutions while maintaining compatibility and reliability.

### Algorithms

Several DSA algorithms are pivotal in payment processing systems:

#### a. Encryption Algorithms
 (e.g., AES, RSA) ensure data confidentiality and integrity. Time complexity varies based on key size and algorithm specifics.
   - AES: O(1) for encryption and decryption.
   - RSA: O(n^2) for key generation, O(n^3) for encryption and decryption.

   ![call 911 imaag not loading](assets/RSA-algorithm-in-C.jpg)<br>

#### b. Hashing Algorithms
   (e.g., SHA-256) verify data integrity and facilitate quick data retrieval.
   - SHA-256: O(n) for hashing.

#### c. Merkle Trees
   Validate the consistency of transaction data efficiently.
   - Construction: O(n log n)
   - Verification: O(log n)



#### d. Sorting Algorithms
   (e.g., Quicksort) used in transaction processing and reporting.
   - Quicksort: O(n log n)




### Approach:

The approach to building a robust payment processing system involves:

1. **Requirements Gathering**: Understanding business needs, compliance requirements, and user expectations.
2. **Architecture Design**: Designing a scalable and secure architecture that integrates with external payment gateways and internal systems.
3. **Technology Selection**: Choosing appropriate technologies and frameworks based on scalability, security, and compatibility.
4. **Implementation**: Developing core functionalities, integrating APIs, and implementing security measures.
5. **Testing and Validation**: Conducting rigorous testing to ensure functionality, security, and regulatory compliance.
6. **Deployment and Maintenance**: Rolling out the system in phases, monitoring performance, and providing ongoing support and updates.

### Design 

Key design considerations include:

1. **Security Layers**: Implementing encryption, tokenization, and SSL/TLS protocols to safeguard data in transit and at rest.
2. **Fault Tolerance**: Designing for redundancy and failover to ensure continuous operation.


### Implementation

Implementation involves collaborating with stakeholders, including developers, security experts, and compliance officers, to ensure a comprehensive and compliant solution.

View implementation for Merkel Tree: [Merkle-tree](https://github.com/sputnik1458/merkle-tree/tree/master/src)<br>
[7][A Review Paper on DES, AES, RSA Encryption Standards](https://ieeexplore.ieee.org/document/9336800)<br>

---



## References

[1] Wikipedia. "Topic: LinkedIn", Accessed July 3,2024. [Link](https://en.wikipedia.org/wiki/LinkedIn)<br>
[2] LinkedIn. "Topic : About LinkedIn", Accessed July 4,2024. [Link](https://about.linkedin.com/)<br>
[3] TheSocialShepherd. "Topic : Linked market Statistics", Accessed July 4,4024. [Link](https://thesocialshepherd.com/blog/linkedin-statistics)<br>
[4] 99Firms. “Topic: LinkedIn Market Stats.” Accessed July 5, 2024. [Link](https://99firms.com/blog/linkedin-statistics/#gref)<br>
[5] papersWithCode. "Topic : Learning Role-based Graph Embeddings", Acessesed July 5,2024. [Link](https://paperswithcode.com/paper/learning-role-based-graph-embeddings)<br>
[6] Slideshare. "Topic : Random walk algorithm", Accessesed July 5,2024. [Link](https://www.slideshare.net/slideshow/write-a-c-program-which-generates-and-displays-a-random-walk-acrospdf/258947524)<br>
[7] IEEE explore. "Topic : RSA and AES encryption", Accessesed July 6,2024. [link](https://ieeexplore.ieee.org/document/9336800)<br>