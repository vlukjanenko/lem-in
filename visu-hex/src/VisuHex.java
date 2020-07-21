import org.graphstream.graph.*;
import org.graphstream.graph.implementations.*;
import java.util.Scanner;

public class VisuHex {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		String line;
		Graph graph = new SingleGraph("Tutorial 1");
		Node start;
		Node end;

		while (scanner.hasNextLine()) {
			line = scanner.nextLine();
			
			if (line.matches("##start")) {
				line = scanner.nextLine();	
				start = graph.addNode(line.split("\\s")[0]);
				continue;
			}
			
			if (line.matches("##end")) {
				line = scanner.nextLine();	
				end = graph.addNode(line.split("\\s")[0]);
				continue;
			}
			
			if (line.matches("#.*")) {
				continue;
			}

			if (line.split("\\s").length == 3) {
				graph.addNode(line.split("\\s")[0]);
				continue;
			}

			if (line.split("-").length == 2) {
				graph.addEdge(line.split("-")[0] + line.split("-")[1],
				line.split("-")[0], line.split("-")[1]);
				continue;
			}
		}
		graph.display();
	}
}
