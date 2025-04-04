////this'll be for the animation so get it working later
//
//import javax.swing.*;
//import java.awt.event.*;
//
//public class stash extends face implements ActionListener {
//    private boolean swap = true;
//
//    private Timer timer;
//
//    public stash(){
//        timer = new Timer(30, this);
//        timer.start();
//    }
//
//    public void pixels(int time){
//        int counter = 0;
//        while(counter < time){
//            if(swap){
//                //main
//                this.screen.getCanvas().fillRect(25, 45, 80, 7);
//                //bottom bits
//                this.screen.getCanvas().fillRect(30, 50, 20, 7);
//                this.screen.getCanvas().fillRect(80, 50, 20,7);
//                //side bits
//                this.screen.getCanvas().fillRect(20, 40,7,10);
//                this.screen.getCanvas().fillRect(102, 40, 7, 10);
//                //tops
//                this.screen.getCanvas().fillRect(47, 40, 12,7);
//                this.screen.getCanvas().fillRect(72, 40, 12, 7);
//                swap = false;
//            } else {
//                //main moustachio
//                this.screen.getCanvas().fillRect(25, 40, 80, 7);
//                //bottoms
//                this.screen.getCanvas().fillRect(30, 45, 20, 7);
//                this.screen.getCanvas().fillRect(80, 45, 20, 7);
//                //side bits
//                this.screen.getCanvas().fillRect(20, 35, 7, 10);
//                this.screen.getCanvas().fillRect(102, 35, 7, 10);
//                //tops
//                this.screen.getCanvas().fillRect(47, 35, 12, 7);
//                this.screen.getCanvas().fillRect(72, 35, 12, 7);
//                swap = true;
//            }
//            counter++;
//        }
//
//    }
//
//    @Override
//    public void actionPerformed(ActionEvent e) {
//
//    }
//}
