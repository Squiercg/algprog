package aula72;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class ButtonFrame extends JFrame {
	private JButton plainJButton;
	private JButton fancyJButton;
	
	public ButtonFrame() {
		super("Testing Buttons");
		setLayout(new FlowLayout());
		
		plainJButton = new JButton("Plain Button");
		add(plainJButton);
		
		Icon bug1 = new ImageIcon(getClass().getResource("bug1.png"));
		Icon bug2 = new ImageIcon(getClass().getResource("bug2.png"));
		fancyJButton = new JButton("Fancy Button", bug1);
		fancyJButton.setRolloverIcon(bug2);
		add(fancyJButton);
		
		ButtonHandler handler = new ButtonHandler();
		plainJButton.addActionListener(handler);
		fancyJButton.addActionListener(handler);
		
	}
	
	private class ButtonHandler implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			JOptionPane.showMessageDialog(ButtonFrame.this, e.getActionCommand());
			
		}
	}
}
