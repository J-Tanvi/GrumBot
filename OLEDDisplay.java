import org.firmata4j.I2CDevice;
import org.firmata4j.IODevice;
import org.firmata4j.firmata.FirmataDevice;
import org.firmata4j.ssd1306.MonochromeCanvas;
import org.firmata4j.ssd1306.SSD1306;

import java.io.IOException;

public class OLEDDisplay {

    private final String myPort = "COM8"; // modify for your own computer & setup.
    private IODevice myGroveBoard;
    private SSD1306 theOledObject;

    /**
     * Constructor.
     */
    public OLEDDisplay() {
        this.myGroveBoard = new FirmataDevice(this.myPort);

        try {
            this.myGroveBoard.start(); // start communication with board;
            this.myGroveBoard.ensureInitializationIsDone();
            System.out.println("Board started."); //hopefully we make it here.

            // Initialize the OLED (SSD1306) object
            I2CDevice i2cObject = this.myGroveBoard.getI2CDevice((byte) 0x3C); // Use 0x3C for the Grove OLED
            this.theOledObject = new SSD1306(i2cObject, SSD1306.Size.SSD1306_128_64); // 128x64 OLED SSD1515
            this.theOledObject.init();
        } catch (Exception ex) { // if not, detail the error.
            System.out.println("couldn't connect to board.");
        }

    }

    /**
     * Stop the Board and clear the display
     * @throws IOException
     */
    public void stopDisplay() throws IOException {
        this.theOledObject.turnOff();
        this.myGroveBoard.stop();
    }

    /**
     * Example code to show you how to write to the OLED
     */
    private void testDisplay(boolean on) {

        //This line shows you how to use a ternary operator!
        MonochromeCanvas.Color c = on ? MonochromeCanvas.Color.BRIGHT : MonochromeCanvas.Color.DARK;

        //turn every pixel ON
        for (int i = 0; i < this.theOledObject.getCanvas().getWidth(); i++) {
            for (int j = 0; j < this.theOledObject.getCanvas().getHeight(); j++) {
                this.theOledObject.getCanvas().setPixel(i,j,c);
            }
            if (i > 0 && i%10 == 0) this.theOledObject.display();
        }

        //display any remaining lines
        this.theOledObject.display();

    }

    public void drawFace(String feat) throws InterruptedException {
        MonochromeCanvas.Color c = MonochromeCanvas.Color.BRIGHT;
        face grum = new face(this.theOledObject);

        grum.clearScreen();
        if(feat.equals("eyes")) {
            grum.eyes();
        } else if (feat.equals("blink")) {
            grum.blink();
        } else if(feat.equals("mumbo")){
            grum.mustache(1);
        }
        this.theOledObject.display();
    }

    /**
     * Main method
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException, InterruptedException {
        OLEDDisplay d = new OLEDDisplay();
        //starting animation
//        d.drawFace("blink");
//        Thread.sleep(2000);

        d.drawFace("eyes");
        d.drawFace("mumbo");
        Thread.sleep(3000);

//        d.testDisplay(true);
//        Thread.sleep(2000);
//
//        //pause for a moment
//        try {
//            System.out.println("Pausing.");
//            Thread.sleep(3000);
//        } catch (InterruptedException e) {
//            throw new RuntimeException(e);
//        }
//
//        d.testDisplay(false);
//
//        //pause for a moment
//        try {
//            System.out.println("Pausing.");
//            Thread.sleep(3000);
//        } catch (InterruptedException e) {
//            throw new RuntimeException(e);
//        }
//
        d.stopDisplay();
    }
}
