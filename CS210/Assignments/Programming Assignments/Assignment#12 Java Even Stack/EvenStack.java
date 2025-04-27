/*********************************************
 * Id: plum0598
 *
 * This program implements an evenstack in java
 *********************************************/

public class EvenStack{
   private static final int DEFAULT_CAPACITY = 10;
   private int even_size = 0;
   private int even_stack_array[];
   
   public EvenStack(){
      even_stack_array = new int[DEFAULT_CAPACITY + 1]; // fix the offset, there shouldn't be an offset, maxsize is broken, 
   }                                                    // probably a -1 or +1 issue in the push odd integer

   public void push(int e){
      System.out.println("Pushing: " + e);
      if(even_size == DEFAULT_CAPACITY){
         System.out.println("Error: EvenStack is full");
      } else {
         if(e % 2 == 1){ // If odd integer, shuffle even integers towards the top of stack
            even_size++;
            int i = even_size - 1;
            for(i = even_size - 1; (i >= 0) && (even_stack_array[i] % 2 == 0); i--){
               even_stack_array[i + 1] = even_stack_array[i];
            }
            even_stack_array[++i] = e;
         } else {
            even_stack_array[even_size++] = e; // if even add to top of stack
         }
      }
   }

   public int pop(){
      if(even_size == 0){
         System.out.println("Error: EvenStack is empty");
         return 0; // Return a default value
      } else {
         int popped = even_stack_array[even_size - 1];
         //even_stack_array[even_size] = 0; // Reset the popped element to 0
         even_size--;
         return popped;
      }
   }

   @Override
   public String toString(){
      StringBuilder string_build = new StringBuilder();
      string_build.append("[");
      for(int i = 0; i < even_size; i++){
         string_build.append(even_stack_array[i]);
         if(i < even_size - 1){
            string_build.append(",");
         }
      }
      string_build.append("]");
      return string_build.toString();
   }
}
