import org.graphstream.graph.*;
import org.graphstream.graph.implementations.*;
import java.util.Scanner;

public class VisuHex {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		String line;
		Graph graph = new SingleGraph("Tutorial 1");
		Node start = null;
		Node end = null;

		String styleSheet =
        "node {" +
        "	fill-color: black;" +
        "}" +
        "node.marked {" +
        "	fill-color: red;" +
		"}" + 
		"edge {" +
        "	fill-color: black;" +
        "}" +
        "edge.marked {" +
        "	fill-color: red;" +
        "}";
		
		graph.addAttribute("ui.stylesheet", styleSheet);
		
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

				/* if (line.matches("#.*")) {
				continue;
			} */

			if (line.matches(".+\\s\\d+\\s\\d+")) {
				graph.addNode(line.split("\\s")[0]);
				continue;
			}

			if (line.split("-").length == 2) {
				graph.addEdge(line.split("-")[0] + line.split("-")[1],
				line.split("-")[0], line.split("-")[1]);
				continue;
			}

			if (line.matches("##path")) {
				line = scanner.nextLine();
				//System.out.println(line);
				String[] room = line.split("->");
				for (int i = 0; i < room.length - 1; i++) {
					graph.getNode(room[i]).setAttribute("ui.class", "marked");
					Edge edge = graph.getEdge(room[i] + room[i + 1]);
					if (edge == null)
						edge = graph.getEdge(room[i + 1] + room[i]);
					//System.out.println(edge);
					edge.setAttribute("ui.class", "marked");
				}
				graph.getNode(room[room.length - 1]).setAttribute("ui.class", "marked");
				continue;
			}
		}
		start.addAttribute("ui.label", "start");
		start.setAttribute("ui.class", "marked");
		end.addAttribute("ui.label", "end");
		end.setAttribute("ui.class", "marked");
		scanner.close();
		graph.display();
	}
}
