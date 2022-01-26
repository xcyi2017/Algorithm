int majorityElement(int* nums, int numsSize){
   int candidate = -1;
   int count = 0;

   for (int i = 0; i < numsSize; i++) {
       if (count == 0) {
           candidate = nums[i];
       }
       if (candidate == nums[i]) {
           count++;
       }
       else {
           count--;
       }
   } 
   count = 0;
   for (int i = 0; i < numsSize; i++) {
       if (nums[i] == candidate) count++;
   }

   return  (count > numsSize / 2 ? candidate : -1);
}