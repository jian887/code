    package com.layout.jpanel;
    import java.awt.*;
    import java.awt.event.*;
    import javax.swing.*;
    
    public class JPanel1
    {
    public JPanel1()
    {
    JFrame f = new JFrame("JPanelDemo");
    Container contentPane = f.getContentPane();
    contentPane.setLayout(new GridLayout(2,1));
    JLabel[] label = new JLabel[5];
    
    for(int i=0; i< label.length ; i++)
        {
            label[i] = new JLabel("Label "+(i+1),JLabel.CENTER);
            label[i].setBackground(Color.lightGray);
            label[i].setBorder(BorderFactory.createEtchedBorder());
            label[i].setOpaque(true);//setOpaqueIture)方法的目的是让组件变成不透明，这样我们在JLabel上所设置的颜色
                                     // 才能显示出来。
        
        }
        
        JPanel panel1 = new JPanel(new GridLayout(1,1));
        panel1.add(label[0]);
        
        JPanel panel2 = new JPanel(new GridLayout(1,2));
        
        JPanel panel3 = new JPanel(new GridLayout(1,2));
        panel3.add(label[1]);
        panel3.add(label[2]);
        
        JPanel panel4 = new JPanel(new GridLayout(2,1));
        panel4.add(label[3]);
        panel4.add(label[4]);
        
        panel2.add(panel3);
        panel2.add(panel4);
        
        contentPane.add(panel1);
        contentPane.add(panel2);

        f.pack();
        f.show();
        f.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                    System.exit(0);
            }
        });
    }
    
    public static void main(String[] arg)
    {
        new JPanel1();
    }
}
