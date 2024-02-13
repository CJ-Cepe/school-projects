import com.opencsv.CSVWriter;       //output 2d Array To Excel

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.awt.image.ConvolveOp;
import java.awt.image.Kernel;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

    /*
        Reference used: Filthy Rich Clients (2007)
            Developing Animated and Graphical Effects for Desktop Java™ Applications

        A sharpen effect is an image filter that recovers finer details from a picture,
                enhancing the edges in the scene to make a crisper, sharper view
     */

public class sharpen {

    /*
        >sharpening filter, may also need the color of the surrounding pixels.
        >Java 2D's image-processing model revolves around the java.awt.image.BufferedImage class and the java.awt.image.BufferedImageOp interface.
        >A BufferedImageOp implementation takes a BufferedImage as input, called the source, and outputs another BufferedImage, called the destination,
            which is altered according to specific rules.
        >If you need a sharpening or blurring filter, for example, you must know how to provide parameters to a ConvolveOp filter.
    */
    public static void main(String[] args) throws IOException {
        sharpen sharpy = new sharpen();

        //================================================================================
        String sourceFilePath = "C:\\Users\\ATHENA\\Desktop\\image\\oldDoge.jpg";           //image to read
        String destinationFilePath = "C:\\Users\\ATHENA\\Desktop\\image\\newDoge.jpg";      //new image
        String formatName="jpg";                                                            //format

                                                                                            //CSV comma-separated values
        String oldRedPath ="C:\\Users\\ATHENA\\Desktop\\image\\csv\\redOLD.csv";            //CSV for red
        String oldGreenPath ="C:\\Users\\ATHENA\\Desktop\\image\\csv\\greenOLD.csv";        //CSV for green
        String oldBluePath ="C:\\Users\\ATHENA\\Desktop\\image\\csv\\blueOLD.csv";          //CSV for blue

        String newRedPath ="C:\\Users\\ATHENA\\Desktop\\image\\csv\\redNEW.csv";            //CSV for new Red
        String newGreenPath ="C:\\Users\\ATHENA\\Desktop\\image\\csv\\greenNEW.csv";        //CSV for new green
        String newBluePath ="C:\\Users\\ATHENA\\Desktop\\image\\csv\\blueNEW.csv";          //CSV for new blue

        /*
        The larger the matrix, the more local information is lost

        There are no particular restrictions about the size and contents of the kernels you can use with Java 2D
        Important characteristics of kernels.
        1. The values of a kernel should add up to 1.0 in the typical case
                If these values do not add up to 1.0, the luminosity of the picture will not be preserved
        2. The size of a kernel defines the strength of a filter.
        3. The dimensions of the kernel are equally important. Kernels are usually odd sided (for centering)
        4. Your kernels do not have to be square shaped
        5. Avoid using large kernels (because of large operation)

        In Java 2D, a kernel is an array of floats and two dimensions

            we use a 3 × 3 sharpening kernel to create an array of nine floats and tell the Kernel
                    class that we want this array to be treated as a 3 × 3 matrix.
        */

        float[] filter = new float[]{
              0f, -1f, 0f,
              -1f, 5f, -1f,
              0f, -1f, 0f
        };
        //===============================================================================
                                                                                    //Java BufferedImage class is a subclass of Image class. It is used to handle and manipulate the image data.
        BufferedImage sourceImage = sharpy.setSourceImage(sourceFilePath);          //store source image
        Kernel kernel = sharpy.makeKernel(filter);                                  //make create
        BufferedImage resultImage = sharpy.getResultImage(kernel,sourceImage);      //convolution
        sharpy.createNewImage(destinationFilePath,formatName,resultImage);          //create image as file

        double[][][] sourceRGB = sharpy.getRGB(sourceImage);                        //RGB
        double[][][] resultRGB = sharpy.getRGB(resultImage);
        export(sourceRGB,resultImage,oldRedPath,oldGreenPath,oldBluePath);          //exporting to excel
        export(resultRGB,resultImage,newRedPath,newGreenPath,newBluePath);
    }//main



    public void createNewImage(String filePath,String formatName, BufferedImage resultImage) throws IOException {
        File outputFile = new File(filePath);
        ImageIO.write(resultImage, formatName, outputFile);
    }

    /*
        Calling the filter() method on a BufferedImageOp triggers the processing of
            the source image and the generation of the destination image. The second
            parameter, set to null here, is actually the destination image, which, when set to
            null, tells the filter() method to create a new image of the appropriate size.
        A ConvolveOp is used to perform a convolution from the source image to the
            destination.
            >computes the destination pixel by multiplying the source pixel and its neighbors by a convolution kernel
    */
    public BufferedImage getResultImage(Kernel kernel, BufferedImage sourceImage){
        ConvolveOp op = new ConvolveOp(kernel);
        BufferedImage resultImage = op.filter(sourceImage,null);
        return resultImage;
    }

    public BufferedImage setSourceImage(String filePath) throws IOException {         // get source image
        BufferedImage sourceImage = ImageIO.read(new File(filePath));
        return sourceImage;
    }

    /*
        The kernel defined here represents a 3 × 3 matrix of floating-point numbers.
                When you perform a convolution operation, this matrix is used as a sliding mask over the pixels of the source image.
        To compute the value of the destination pixel at (x, y),
            Java 2D multiplies the kernel values with their corresponding color values in the source image.
            Each color value is multiplied by the corresponding value of the kernel.
        What this kernel does: It replaces each pixel by the average color of its surroundings.

         In Java 2D, a kernel is an array of floats and two dimensions
            we use a 3 × 3 sharpening kernel to create an array of nine floats and tell the Kernel
                    class that we want this array to be treated as a 3 × 3 matrix.
    */
    public Kernel makeKernel(float[] sharpeningFilter){                 //make kernel
        Kernel kernel = new Kernel(3, 3, sharpeningFilter);
        return kernel;
    }

    public  double[][][] getRGB(BufferedImage rgbImage){
        int width = rgbImage.getWidth();                                //get lang natin dimensions nung image
        int height = rgbImage.getHeight();                              // sabog na ko

        double[][][] rgbMatrix = new double[3][height][width];          // 3 since 3dimension RGB diba, pinaghihiwalay ko dito

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                Color color = new Color(rgbImage.getRGB(j, i));
                rgbMatrix[0][i][j] = color.getRed();                        // para ma-imitate yung tulad sa matlab
                rgbMatrix[1][i][j] = color.getGreen();                      // yung 3 dimensions
                rgbMatrix[2][i][j] = color.getBlue();                       //sa 1st [0] nakalagay yung sa red, then green [1], last blue [2]
            }//for j
        }//for i
        return rgbMatrix;
    }//getRGB

    public static void export(double[][][] rgbImage,BufferedImage tempImage, String redPath, String greenPath, String bluePath) throws IOException {
        int width = tempImage.getWidth();
        int height = tempImage.getHeight();

        double[][] red = new double[height][width];
        double[][] green = new double[height][width];
        double[][] blue = new double[height][width];
        System.out.println(width);
        System.out.println(height);

        for (int h=0; h < 3; h++) {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if(h==0) {
                        red[i][j] = rgbImage[h][i][j];
                    }
                    else if(h==1){
                        green[i][j] = rgbImage[h][i][j];
                    }
                    else if(h==2){
                        blue[i][j] = rgbImage[h][i][j];
                    }
                }// for j
            }//for i
        }//for h

        exportDataToExcel(redPath, red);
        exportDataToExcel(greenPath, green);
        exportDataToExcel(bluePath, blue);
    }//export

    public static void exportDataToExcel(String fileName, double[][] data) throws FileNotFoundException, IOException
    {
        File file = new File(fileName);
        if (!file.isFile())
            file.createNewFile();

        CSVWriter csvWriter = new CSVWriter(new FileWriter(file));

        int rowCount = data.length;

        for (int i = 0; i < rowCount; i++)
        {
            int columnCount = data[i].length;
            String[] values = new String[columnCount];
            for (int j = 0; j < columnCount; j++)
            {
                values[j] = data[i][j] + "";
            }
            csvWriter.writeNext(values);
        }
        csvWriter.flush();
        csvWriter.close();
    }
}//sharpen class


/*
Black edge:
    Take a close look at the generated result: You should see a black border surrounding the picture

        During the convolve operation, Java 2D always matches the center of the kernel with one pixel of the source image.
             This works well for every pixel except the ones on the edges of the picture

             Java 2D replaces the pixels it cannot compute with black pixels
                which results in darkened edges because of the extra black introduced into the convolve operations for these edge pixels

        To get rid of any problem on the edges
            simply increase the size of the original picture
 */