package aula74;

import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;

@SuppressWarnings("serial")
public class LabelFrame extends JFrame {
	
	private JLabel label1;
	
	public LabelFrame() {
		super("Testing JLabel");
		setLayout(new FlowLayout());
		
		label1 = new JLabel("Label with text");
		label1.setToolTipText("This is label1");
		
		add(label1);
	}
}
