    import java.rmi.Naming;
    import java.util.Scanner;
     
     
    public class StartFileClient {
     
    	public static void main(String[] args) {
    		try{
    			FileClient c=new FileClient("imed");			
    			FileServerInt server=(FileServerInt)Naming.lookup("rmi://192.168.43.99/abc");
    			server.login(c);
    			System.out.println("Listening.....");			
    			Scanner s=new Scanner(System.in);			
    			while(true){
    				String line=s.nextLine();
    			}
    		}catch(Exception e){
    			e.printStackTrace();
    		}
    	}	
     
    }
