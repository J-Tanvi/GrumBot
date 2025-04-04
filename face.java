import org.firmata4j.ssd1306.MonochromeCanvas;
import org.firmata4j.ssd1306.SSD1306;

public class face {

    SSD1306 screen;

    MonochromeCanvas.Color c = MonochromeCanvas.Color.BRIGHT;

    //allows for states to be tracked
    int swap = 0;


    /**
     * setting up the OLED to show a face and expressions (constructor)
     *
     * @param screen
     */
    public face(SSD1306 screen){
        this.screen = screen;
    }

    /**
     * will print off normal eyes on the face
     */
    public void eyes(){
        c = MonochromeCanvas.Color.BRIGHT;
        //create the eyes using 4 rectangles
        fillR(30, 17, 47, 24);
        fillR(35, 12, 42, 29);
        fillR(83, 17, 100, 24);
        fillR(88, 12, 95, 29);

        this.screen.display();
    }

    /**
     * will print off angry eyes on the face
     */
    public void angryEyes(){
        c = MonochromeCanvas.Color.BRIGHT;
        this.screen.getCanvas().drawLine(33, 7, 53,10, c);
        this.screen.getCanvas().drawLine(98, 7, 78,10, c);
        eyes();

        this.screen.display();
    }

    /**
     * creates a mustache on the OLED screen that moves up and down
     *
     * @param time
     */
    public void mustache(int time){
        c = MonochromeCanvas.Color.BRIGHT;


        this.screen.display();

        int counter = 0;
        while(counter < time){
            if(swap == 0){
                //main stash
                fillR(25, 45, 105, 52);
                //bottoms
                fillR(30, 50, 50, 57);
                fillR(80, 50, 100, 57);
                //side bits
                fillR(20, 40, 27, 50);
                fillR(102, 40, 109, 50);
                //tops
                fillR(47, 40, 59, 47);
                fillR(72, 40, 84, 47);
                swap = 1;
            } else {
                //main moustachio
                this.screen.getCanvas().fillRect(25, 40, 80, 7);
                //bottoms
                this.screen.getCanvas().fillRect(30, 45, 20, 7);
                this.screen.getCanvas().fillRect(80, 45, 20, 7);
                //side bits
                this.screen.getCanvas().fillRect(20, 35, 7, 10);
                this.screen.getCanvas().fillRect(102, 35, 7, 10);
                //tops
                this.screen.getCanvas().fillRect(47, 35, 12, 7);
                this.screen.getCanvas().fillRect(72, 35, 12, 7);
                swap = 0;
            }
            counter++;
        }
    }

    /**
     * shows a minor blinking animation
     * uses Threads to pause between the frames
     * @throws InterruptedException
     */
    public void blink() throws InterruptedException {
        MonochromeCanvas.Color c = MonochromeCanvas.Color.BRIGHT;

        this.screen.display();
        //repeate motion 3 times
        for(int i = 0; i < 4; i++){
            //remove previous image
            clearScreen();
            //change state/frame
            if(swap == 0){
                this.screen.getCanvas().drawLine(15, 25, 45, 25, c);
                this.screen.getCanvas().drawLine(80, 25, 110, 25, c);
                swap = 1;
            } else {
                this.screen.getCanvas().drawLine(15, 30, 30, 20, c);
                this.screen.getCanvas().drawLine(30, 20, 45, 30, c);
                this.screen.getCanvas().drawLine(80, 30, 95, 20, c);
                this.screen.getCanvas().drawLine(95, 20, 110, 30, c);
                swap = 0;
            }
            //show the new image
            this.screen.display();
            //wait 1 second
            Thread.sleep(1000);
        }
    }

    /**
     * creates a rectangle that starts at (x1, y1) and fills until
     * it reaches (x2, y2), either white or black
     *
     * @param x1 = starting x position
     * @param y1 = starting y position
     * @param x2 = ending x spot
     * @param y2 = ending y spot
     */
    public void fillR(int x1, int y1, int x2, int y2){
        MonochromeCanvas.Color c = MonochromeCanvas.Color.BRIGHT;
//        if(x1 > x2){
            for(int x = x1; x <= x2; x++){
                for(int y = y1; y <= y2; y++){
                    this.screen.getCanvas().setPixel(x, y, c);
                }
            }
//        }
        this.screen.display();
    }


    /**
     * Clears the display fully
     */
    public void clearScreen(){
        c = MonochromeCanvas.Color.DARK;

        for (int i = 0; i < this.screen.getCanvas().getWidth(); i++) {
            for (int j = 0; j < this.screen.getCanvas().getHeight(); j++) {
                this.screen.getCanvas().setPixel(i,j,c);
            }
        }

        this.screen.display();
    }
}
