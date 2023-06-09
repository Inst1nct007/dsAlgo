import java.util.Scanner;

class linked_list
{
    node head = new node();
    linked_list(int[] array) {
        head.data = 0;
        node prevNode = new node();
        prevNode = head;
        for(int i = 0; i < array.length; i++) {
            node newNode = new node();
            prevNode.next = newNode;
            newNode.data = array[i];
            prevNode = newNode;
        }
        prevNode.next = null;
    }
    
    public void push(int data) {
        node currentNode = head;
        while(currentNode.next != null) {
            currentNode = currentNode.next;
        }
        
        node newNode = new node();
        newNode.data = data;
        newNode.next = null;
        currentNode.next = newNode;
    }
    
    public void pop() {
        node currentNode = head;
        node prevNode = new node();
        prevNode = currentNode;
        while(currentNode.next != null) {
            prevNode = currentNode;
            currentNode = currentNode.next;
        }
        currentNode = null;
        prevNode.next = null;
    }
    
    public void print() {
        System.out.print("The Linked List is : \n");
        try {
         node currentNode = head.next;
         while(currentNode != null) {
            System.out.print(currentNode.data + " -> ");
            currentNode = currentNode.next;
        }
        }catch(Exception e) {
            System.out.println("The List is already Empty\n");
        }
    }
}


class node {
    int data;
    node next;
}


public class main {
    public static void main() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of numbers to input: \n");
        int number_of_inputs = sc.nextInt();
        int[] nums = new int[number_of_inputs];
        System.out.println("Enter the numbers: ");
        for(int i = 0; i < number_of_inputs; i++) {
            nums[i] = sc.nextInt();
        }
        linked_list l1 = new linked_list(nums);
        l1.print();
    }
}