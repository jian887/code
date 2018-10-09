import Java.util.Random;

public class ACMorAI {
	public void static main (String [] args)
	{
		String Program = new String[]{"matlab","python"};
		//Scanner scanner = new Scanner(System.in);
		Random random = new Random();
		int i = random.nextInt();
		System.out.println(Program[i]);
	}
}
		