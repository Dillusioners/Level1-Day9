import java.io.*;
class Hotel
{
	static BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
	static Hotel obj = new Hotel();
	static int TOTAL = 0;
	//Display function to show menu
	void display()
	{
		System.out.println("###################");
		System.out.println("       MENU ");
		System.out.println("###################");
		System.out.println("1.North Indian Thali\n"
						  +"2.Bengali Thali\n"
						  +"3.South Indian Thali\n"
						  +"4.General Thali\n"
						  +"5.Exit\n"
						  +"(-)Enter your option => ");

	}

	//NorthIndian Thali simulation
	void NorthIndian()
	{
		int cost[] = {10,20,45};

		System.out.println("(-)Welcome to the North Indian Thali !!");
		while(true){
			System.out.println("Here you have :\n"
							   +"1.Nan\n"
							   +"2.Butter Chicken\n"
							   +"3.Rabri\n"
							   +"Anything else to exit\n"
							   +"(-)Enter your choice =>" );
			try{
				int ch = Integer.parseInt(rd.readLine());
				if(ch >= 1 && ch <= 3)
					TOTAL += cost[ch-1];
				else
				{
					System.out.println("(-)Thank you for eating here !");
					break;
				}
			}catch(Exception e)
			{
				System.err.println("(-)Something went wrong : (");
			}
			
		}
	}
	//Bengali Thali simulation
	void Bengali()
	{
		int cost[] = {30,20,65};

		System.out.println("(-)Welcome to the Bengali Thali !!");
		while(true){
			System.out.println("(-)Here you have :\n"
							   +"1.Mach Bhat\n"
							   +"2.Khasir Manksho\n"
							   +"3.Dudh Cha\n"
							   +"Anything else to exit\n"
							   +"(-)Enter your choice =>" );
			try{
				int ch = Integer.parseInt(rd.readLine());
				if(ch >= 1 && ch <= 3)
					TOTAL += cost[ch-1];
				else
				{
					System.out.println("(-)Thank you for eating here !");
					break;
				}
			}catch(Exception e)
			{
				System.err.println("(-)Something went wrong : (");
			}
			
		}
	}
	//South Indian Thali simulation
	void SouthIndian()
	{
		int cost[] = {40,30,45};

		System.out.println("(-)Welcome to the North Indian Thali !!");
		while(true){
			System.out.println("(-)Here you have :\n"
							   +"1.Masala Dosa\n"
							   +"2.Plain Dosa\n"
							   +"3.Coconut Milk\n"
							   +"Anything else to exit\n"
							   +"(-)Enter your choice =>" );
			try{
				int ch = Integer.parseInt(rd.readLine());
				if(ch >= 1 && ch <= 3)
					TOTAL += cost[ch-1];
				else
				{
					System.out.println("(-)Thank you for eating here !");
					break;
				}
			}catch(Exception e)
			{
				System.err.println("(-)Something went wrong : (");
			}
			
		}
	}

	//general stuff
	void General()
	{
		int cost[] = {100,205,69};

		System.out.println("(-)Welcome to the General Thali !!");
		while(true)
		{
			System.out.println("(-)Here you have :\n"
							   +"1.Chicken Biriyani\n"
							   +"2.Chicken Chap\n"
							   +"3.Mutton Shawarma\n"
							   +"Anything else to exit\n"
							   +"(-)Enter your choice =>" );
			try{
				int ch = Integer.parseInt(rd.readLine());
				if(ch >= 1 && ch <= 3)
					TOTAL += cost[ch-1];
				else
				{
					System.out.println("(-)Thank you for eating here !");
					break;
				}
			}
			catch(Exception e)
			{
				System.err.println("(-)Something went wrong : (");
			}
			
		}	
	}


	public static void main(String[] args) {
			while(true){
				obj.display();
				try{
						//Asking for users choice
						int choice = Integer.parseInt(rd.readLine());
						if(choice > 5 || choice < 1)
							System.err.println("(-)Invalid Input!!");
						else if(choice == 5){
							System.out.println("(-)Have a good day Sir!");
							break;
						}
						else if(choice == 1)
							obj.NorthIndian();
						else if(choice == 2)
							obj.Bengali();
						else if(choice == 3)
							obj.SouthIndian();
						else
							obj.General();
	
					}catch(Exception e)
					{
						System.out.println("(-)Wrong input sir !");
				}
		}
		//Program ends
			System.out.println("(-)Your Total bill is = " + TOTAL + ".Rs");
	}
}