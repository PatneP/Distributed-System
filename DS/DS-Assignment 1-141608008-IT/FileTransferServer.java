import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class FileTransferServer { 

        private static Socket socket;
		private static ServerSocket ssock;
		
    public static void main(String[] args) throws Exception {
			
		
        ssock = new ServerSocket(5000);
		System.out.println("*****************************Server is waiting for Clients to connect******************************");

			//Initialize Sockets
			socket = ssock.accept();
			
			//The InetAddress specification
			InetAddress IA = InetAddress.getByName("localhost"); 
			
			//Specify the file
			File file = new File("data.txt");
			FileInputStream fis = new FileInputStream(file);
			BufferedInputStream bis = new BufferedInputStream(fis); 
			//InputStreamReader isr = new InputStreamReader(socket.getInputStream);
			
			//Get socket's output stream
			OutputStream os = socket.getOutputStream();
					
			//Read File Contents into contents array 
			byte[] contents;
			long fileLength = file.length(); 
			long current = 0;
			 
			long start = System.nanoTime();
			while(current!=fileLength){ 
				int size = 10000;
				if(fileLength - current >= size)
					current += size;    
				else{ 
					size = (int)(fileLength - current); 
					current = fileLength;
				} 
				contents = new byte[size]; 
				bis.read(contents, 0, size); 
				os.write(contents);
				System.out.print("Sending file ... "+(current*100)/fileLength+"% complete!");
			}   
			
			os.flush(); 
			//File transfer done. Close the socket connection!
                socket.close();
				ssock.close();
			System.out.println("File sent succesfully!");
		
    }
}

