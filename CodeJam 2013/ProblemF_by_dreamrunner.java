import java.util.Scanner;

public class Main {
	static int size, last, current;
	static boolean[] arr;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		arr = new boolean[40];
		while (test -- > 0) {
			size = sc.nextInt();
			last = 1;
			current = 0;
			for (int i = 0; i < 2*size; i++) {
				arr[i] = false;
			}
			for (int i = 0; i < size; i++) {
				int temp = sc.nextInt();
				int diff = temp - last;
				last = temp;
				current += diff + 1;
				arr[current] = true;
			}
			int theNum = 0;
			for (int i = 1; i < 2*size; i++) {
				if (arr[i]) {
					theNum++;
					int count = 0, w = 1;
					for (int j = i-1 ; j >= 0; j --) {
						if (!arr[j]) {
							if (count == 0) {
								break;
							} else {
								count --;
								w++;
							}
						} else {
							count ++;
						}
					}
					System.out.print(w);
					if (theNum < size) {
						System.out.print(' ');
					}
				}
			}
			System.out.println();
		}
		sc.close();
	}
}