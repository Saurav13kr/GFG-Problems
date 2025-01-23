//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class Node {
    int data;
    Node next;
    Node random;

    Node(int x) {
        data = x;
        next = null;
        random = null;
    }
}

public class Main {
    public static void print(Node root) {
        Map<Node, Integer> link = new HashMap<>();
        Node temp = root;
        int index = 0;

        // Store node addresses and their index
        while (temp != null) {
            link.put(temp, index++);
            temp = temp.next;
        }

        temp = root;
        System.out.print("[");
        while (temp != null && temp.next != null) {
            if (temp.random == null) {
                System.out.print("[" + temp.data + ", NULL], ");
            } else {
                System.out.print("[" + temp.data + ", " + (link.get(temp.random) + 1) +
                                 "], ");
            }
            temp = temp.next;
        }
        if (temp != null) {
            if (temp.random == null) {
                System.out.print("[" + temp.data + ", NULL]]\n");
            } else {
                System.out.print("[" + temp.data + ", " + (link.get(temp.random) + 1) +
                                 "]]\n");
            }
        }
    }

    public static Node buildLinkedList(List<int[]> v, Map<Node, Integer> orgAddress) {
        List<Node> address = new ArrayList<>(v.size());
        Node head = new Node(v.get(0)[0]);
        address.add(head);
        orgAddress.put(head, 0);
        Node temp = head;

        for (int i = 1; i < v.size(); i++) {
            Node newNode = new Node(v.get(i)[0]);
            orgAddress.put(newNode, i);
            address.add(newNode);
            temp.next = newNode;
            temp = temp.next;
        }

        temp = head;
        for (int i = 0; i < v.size(); i++) {
            int randomIndex = v.get(i)[1];
            if (randomIndex != -1) {
                temp.random = address.get(randomIndex - 1);
            }
            temp = temp.next;
        }

        return head;
    }

    public static boolean validateInput(Map<Node, Integer> orgAddress, Node head,
                                        List<int[]> v) {
        List<Node> address = new ArrayList<>(v.size());
        Node temp = head;

        for (int i = 0; i < v.size(); i++) {
            if (!orgAddress.containsKey(temp) || orgAddress.get(temp) != i) {
                return false;
            }
            address.add(temp);
            temp = temp.next;
        }

        if (temp != null) {
            return false;
        }

        temp = head;
        for (int i = 0; i < v.size(); i++) {
            int value = v.get(i)[0];
            int randomIndex = v.get(i)[1];

            if (randomIndex == -1) {
                if (temp.random != null) {
                    return false;
                }
            } else {
                Node tempNode = address.get(randomIndex - 1);
                if (temp.random != tempNode) {
                    return false;
                }
            }
            temp = temp.next;
        }
        return true;
    }

    public static boolean validation(Node res, Map<Node, Integer> orgAddress) {
        Node temp = res;
        while (temp != null) {
            if (orgAddress.containsKey(temp)) {
                return false;
            }
            if (orgAddress.containsKey(temp.random)) {
                return false;
            }
            temp = temp.next;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            List<int[]> v = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                String y = sc.next();
                int randomIndex = y.equals("NULL") || y.equals("N") ||
                                          y.equals("null") || y.equals("n") ||
                                          y.equals("Null")
                                      ? -1
                                      : Integer.parseInt(y);
                v.add(new int[] {x, randomIndex});
            }
            Map<Node, Integer> orgAddress = new HashMap<>();
            Node head = buildLinkedList(v, orgAddress);

            Solution solution = new Solution();
            Node res = solution.cloneLinkedList(head);

            // Validate if input is modified
            if (validateInput(orgAddress, head, v)) {
                if (validation(res, orgAddress)) {
                    print(res);
                } else {
                    System.out.println("Pointing to the original list");
                }
            } else {
                System.out.println("Input list modified");
            }
            System.out.println("~");
        }
        sc.close();
    }
}
// } Driver Code Ends


/*linked list node
class Node {
    int data;
    Node next;
    Node random;

    Node(int x) {
        data = x;
        next = null;
        random = null;
    }
}
*/

class Solution {
    public Node cloneLinkedList(Node head) {
        if (head == null) return null;

        // Step 1: Create new nodes and insert them in the original list
        Node current = head;
        while (current != null) {
            Node newNode = new Node(current.data); // Use current.data instead of current.val
            newNode.next = current.next;
            current.next = newNode;
            current = newNode.next; // Move to the next original node
        }

        // Step 2: Copy the random pointers
        current = head;
        while (current != null) {
            if (current.random != null) {
                current.next.random = current.random.next; // Copy the random pointer
            }
            current = current.next.next; // Move to the next original node
        }

        // Step 3: Separate the new list from the original list
        Node newHead = head.next;
        current = head;
        Node copy = newHead;
        while (current != null) {
            current.next = current.next.next; // Restore the original list
            if (copy.next != null) {
                copy.next = copy.next.next; // Link the copied list
            }
            current = current.next;
            copy = copy.next;
        }

        return newHead;
    }
}

