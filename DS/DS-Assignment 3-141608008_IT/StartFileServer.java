    import java.rmi.Naming;
     
    public class StartFileServer {
    	public static void main(String[] args) {
    		// TODO Auto-generated method stub
    		try{
    			
    			java.rmi.registry.LocateRegistry.createRegistry(1099);
    			
    			FileServer fs=new FileServer();
    			fs.setFile("itcrowd.avi");			
    			Naming.rebind("rmi://192.168.43.99/abc", fs);
    			System.out.println("File Server is Ready");
    			
    		}catch(Exception e){
    			e.printStackTrace();
    		}
    	}	
    }
     
