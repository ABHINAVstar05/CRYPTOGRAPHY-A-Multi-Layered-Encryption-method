# CRYPTOGRAPHY-A-Multi-Layered-Encryption-method

This is a cryptography based 3 layered encryption method to secure messages and data exchanged between sender and receiver over insecure communication channel with the help of a common key selected by the sender and receiver.

 In this method, the original message (or the plaintext) is converted into cipher text through a series of different encryption techniques to further secure the confidentiality of the shared message or data.
 
 **In the 1st layer**, the plaintext is converted into ciphertext1 by the use of Fibonacci number series and a key which is mutually agreed upon by both sender and receiver by using the mono-substitution encryption technique. What makes this step awesome is the way the ciphertext is created by taking help from the fibonacci number series each time a new key is decided by the two parties. The character set (for ciphertext) follows a round-robin method and the character which falls below the Fibonacci number is taken as the character in the cipher text. if the message is a long one and the value of fibonacci number is increased each time by adding the previous two numbers, the algorithm is such that the value of fibonacci number to be used to decide the ciphertext never goes out of index of the character set.  
 
 **In the 2nd layer**, the ciphertext1 is converted into ciphertext2. This is done by obtaining the ASCII values of each character of the ciphertext1 and its corresponding character in the plaintext and then adding both of them together. This process is repeated for every character in the ciphertext1 and in this way, we obtain a series of ASCII values corresponding to each character in the ciphertext1. By now, ciphertext2 is ready.
 
 **In the 3rd and final layer**, the ASCII value corresponding to each character in the ciphertext2 (or plaintext) is converted from decimal to hexa-decimal form and the ciphertext3 is obtained.
 
 ## Steps involved in Encryption
    1. Suppose a sender wants to send a Hello message to a recipient.
    2. The  original  message,  also  called  plaintext,  is  converted  to cipher  text  by  using  a  key  and  Fibonacci  numbers.  The  algorithm  being  used  can  produce  a different ciphertext each time a different key is selected.
    3. The ciphertext is then converted to ASCII values.
    4. These ASCII values are then converted to hexa-decimal values.
    5. Thus, the plaintext is converted into ciphertext. 
