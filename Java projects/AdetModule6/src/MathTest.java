import org.testng.Assert;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;
public final class MathTest {

        private Math math;

        @BeforeMethod
        public void setUp()
        {math = new Math(); }



        @Test
        public void add_TwoPlusTwo_ReturnsFour()
        {//Arrange
            final int expected = 4;
            //Act
            final int actual = math.add(2, 2);
            //Assert
            Assert.assertEquals(actual, expected); }




        @Test
        public void divide_TenDividedByFive_ReturnsTwo()
        {   final double expected = 2.0;
            final double actual = math.divide(10, 5);
            Assert.assertEquals(actual, expected); }




        @AfterMethod
        public void tearDown()
        {math = null; }


}