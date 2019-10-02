
public class example { 

	public static void main(String[] args)throws Exception { 
		String line =  "IAMNAFETS";
		String [] arr = line.split("");
		String vowel = "AEIOU";
		String first = "";
		String second = "";
		for(int i = 0; i < arr.length; i++) {
			if(vowel.indexOf(arr[i]) >= 0) {
				second+=arr[i];
			} else {
				first+=arr[i];
			}
		}

		System.out.println(first+second);
	} 
} 