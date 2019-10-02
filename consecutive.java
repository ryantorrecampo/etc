
public class consecutive {
	
	public static boolean consecutive(String arr[], int size) {
		String [] vowels = {"A", "E", "I", "O", "U"};
		boolean flag = false;
		for (int i = 0; i < size; i++) {
			if(flag == true) {
				for (String item : vowels) {
					if(arr[i].equalsIgnoreCase(item)) {
						return true;
					}
				}
			}
			for (String item : vowels) {
				if(arr[i].equalsIgnoreCase(item)) {
					flag = true;
					break;
				} else {
					flag = false;
				}
			}
		}
		return false;
	}

	public static boolean repeat(String arr[], int size) {
		String [] vowels = {"A", "E", "I", "O", "U"};
		String [] res = new String[size];
		boolean allowed = true;
		for (int i = 0; i < size; i++) {
			for (String item : vowels) {
				if(arr[i].equalsIgnoreCase(item)) {
					allowed = false;
					break;
				}
			}
			if(allowed) {
				res[i] = arr[i];
			}
			allowed = true;
		}
		
		for(int i = 0; i < res.length; i++) {
			int count = 0;
			for (String item : res) {
				if(arr[i].equalsIgnoreCase(item)) {
					count++;
				}
				if(count > 1) {
					return true;
				}
			}
		}
		return false;
	}

	public static void main(String[] args)throws Exception { 
		String line = "JAIYEN";
		String arr[] = line.split("");
		if (consecutive(arr, arr.length) || repeat(arr, arr.length)) {
			System.out.println("INVALID");
		} else {
			System.out.println("ABRACADABRA");
		}
	} 
} 