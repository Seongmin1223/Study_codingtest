package week1;

import java.util.*;

class 택배박스 {
    public int solution(int[] order) {
        int idx = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < order.length; i++){
            stack.push(i+1);
            while(!stack.isEmpty()){
                if (stack.peek() == order[idx]){
                    stack.pop();
                    idx++;
                }
                else
                    break;
            }
        }
        return idx;
    }
}