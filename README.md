<!-- ![header image](assets/logo.png) -->
<img src="assets/logo.png" alt="Getting In Touch with LinkedIn" height="400">

## 📘 Course Information

- **Course Name:** Algorithmic Problem Solving
- **Course Code:** 23ECSE309
- **Name:** Mohammad Arman Khan
- **USN:** 01FE21BCI037
- **University:** KLE Technological University, Hubballi-31

## 📑 Table of Contents

1. [Introduction](#introduction)
2. [Business Cases](#business-cases)
   - [Existing Functionalities](#existing-functionalities)
   - [Proposed Functionalities](#proposed-functionalities)
   - [Detailed Business Use Cases](#detailed-business-use-cases)
3. [Performance Analysis](#performance-analysis)
4. [References](#references)

## Introduction

LinkedIn is a professional networking platform designed to connect professionals worldwide, facilitating career development, networking opportunities, and knowledge exchange. It serves as a digital hub where individuals and businesses showcase their professional profiles, share industry insights, and collaborate on projects. LinkedIn relies on Data Structures and Algorithms (DSA) to improve search results, recommend relevant connections and content, manage user interactions, ensure data security, and enhance overall platform performance. They play a crucial role in optimizing user experiences and facilitating effective professional networking and career development on the platform.

<img src="assets/architecture.png" alt="Getting In Touch with LinkedIn" height="350">

### Market Analysis

LinkedIn has established itself as a dominant force in professional networking with significant market reach and impact. According to 99Firms, as of 2020, LinkedIn reported revenue of $8.05 billion and boasts over 830 million members globally. A substantial portion, approximately 31%, of LinkedIn's traffic originates from the United States. The platform has seen a notable surge in activity, particularly with a tripling of searches for remote work following the onset of the COVID-19 pandemic. Weekly job searches on LinkedIn reach up to 50 million, with 122 million individuals reportedly securing interviews through the platform. LinkedIn stands out in B2B lead generation, responsible for 80% of such leads from social media platforms. It's also recognized as the top-rated organic social media platform for B2B marketers, underscoring its pivotal role in professional networking and recruitment strategies worldwide. [[1]](https://99firms.com/blog/linkedin-statistics/#gref)

### Objectives

- Explore business use cases, challenges, and benefits.
- Identify and analyze different functionalities in LinkedIn that utilizes DSA.
- Identify Opportunities where DSA can be further optimized to enhance platform performance and user experience.
- Propose new algorithms or optimizations that could better handle LinkedIn's massive user base and diverse functionalities if any.

## Business Cases

## 1. Efficient Messaging System

The efficient messaging system is designed to facilitate real-time communication with features like instant message delivery and sequential message order. This system is crucial for applications such as chat platforms or collaborative tools.

### Use Case

The efficient messaging system aims to:
- Facilitate real-time communication.
- Ensure instant message delivery.
- Maintain sequential message order.

### Challenges
- **Scalability:** Handle increasing message volume.
- **Low Latency:** Ensure timely message delivery.
- **Message Order:** Preserve message order across distributed systems.

### Market Benefits
- **Improved User Experience:** Enhanced responsiveness and reliability.
- **Higher Engagement:** Increased user satisfaction and platform retention rates.

### Algorithms

### a. Queue
- **Time Complexity:** O(1) for enqueue and dequeue operations.
- **Use Case:** Message storage and retrieval.

### b. HashMap
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

### Implementation

The implementation involves setting up a distributed messaging architecture using queues for message handling and HashMaps for session management. This combination ensures efficient, real-time message delivery and scalability.

## References

[1] 99Firms. “Topic: LinkedIn Market Stats.” Accessed July 8, 2024. [Link](https://99firms.com/blog/linkedin-statistics/#gref)
