//import org.firmata4j.IODevice;
//import org.firmata4j.Pin;
//import org.firmata4j.firmata.FirmataDevice;
//import java.io.IOException;
//
//public class components{
//
//    IODevice board;
//
//    private String state = "OFF";
//
//    /**
//     * initializes the board
//     *
//     * @param board = the board
//     * @throws InterruptedException = in case the thread fails
//     */
//    public components(IODevice board) throws InterruptedException {
//        this.board = new FirmataDevice("COM8");
//    }
//
//    /**
//     * turns the led on and off
//     *
//     * @param board = board
//     * @throws IOException = there is an issue with the input
//     * @throws InterruptedException = a thread issue
//     */
//    public void ledOn(IODevice board) throws IOException, InterruptedException {
//        //sets the led to pin 4 and sets to an output
//        Pin led = board.getPin(4);
//        led.setMode(Pin.Mode.OUTPUT);
//        //turns it on
//        led.setValue(1);
//        //pauses for a second (and catches if it fails)
//        try{
//            Thread.sleep(1000);
//        } catch (Exception ex) {
//            System.out.println("struggling to pause");
//        }
//        //turns it off
//        led.setValue(0);
//    }
//
//    /**
//     * checks if the button is pressed
//     * if so, return a fortune
//     *
//     * @return ans = the future
//     * @throws IOException = if there is an issue with the input
//     * @throws InterruptedException = threads issue
//     */
//    public String ask() throws IOException, InterruptedException {
//        //creates a random number to determine future
//        int randomNum = (int) (Math.random()*7);
//        String ans = "future not certain";
//        //set up the button as pin 6 and to be an input
//        Pin button = board.getPin(6);
//        button.setMode(Pin.Mode.INPUT);
//
//        //checks for a button PRESS not hold
//        if((int) button.getValue() == 1){
//            Thread.sleep(100);
//            if((int) button.getValue() == 0){
//                //assigns a fortune to be returned
//                ans = switch (randomNum) {
//                    case 0 -> "lol no";
//                    case 1 -> "do it before i smite you";
//                    case 2 -> "if 2 + 2 = 4...";
//                    case 3 -> "womp womp";
//                    case 4 -> "trust your gut";
//                    case 5 -> "maybe not :<";
//                    case 6 -> "id say so";
//                    default -> ans;
//                };
//            }
//        }
//        return ans;
//    }
//
//    public boolean pets(){
//        Pin touch = board.getPin(2);
//        int sound = 0;
//        for (int i = 0; i < 32; i++){
//            sound += analogRead(touch); //change to work
//        }
//        sound >>= 5; //bit shift to fill empty cells
//        if(sound > 700){
//            System.out.println("oo that tickles"); //should print to the board
//            return true;
//        }
//        return false;
//    }
//}