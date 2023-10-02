// accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
uint8_t mpuStatus = 0;
int attempts = 0;
void setupMPU6050(void)
{

    while (!Serial)
        delay(10); // will pause Zero, Leonardo, etc until serial console opens

    Serial.println("Adafruit MPU6050 test!");

    // Try to initialize!

    while (attempts < 10)
    {
        if (mpu.begin())
        {
            mpuStatus = 1; // MPU initialized successfully
            Serial.println("MPU6050 Found!");
            break; // Exit the loop
        }
        else
        {
            if (attempts == 9) // On the last attempt, print the error message
            {
                Serial.println("Failed to find MPU6050 chip. Check Connections.");
                mpuStatus = 0; // MPU failed to initialize
            }
            delay(10); // Wait for 10ms before the next attempt
        }
        attempts++;
    }

    mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
    Serial.print("Accelerometer range set to: ");
    switch (mpu.getAccelerometerRange())
    {
    case MPU6050_RANGE_2_G:
        Serial.println("+-2G");
        break;
    case MPU6050_RANGE_4_G:
        Serial.println("+-4G");
        break;
    case MPU6050_RANGE_8_G:
        Serial.println("+-8G");
        break;
    case MPU6050_RANGE_16_G:
        Serial.println("+-16G");
        break;
    }
    mpu.setGyroRange(MPU6050_RANGE_2000_DEG);
    Serial.print("Gyro range set to: ");
    switch (mpu.getGyroRange())
    {
    case MPU6050_RANGE_250_DEG:
        Serial.println("+- 250 deg/s");
        break;
    case MPU6050_RANGE_500_DEG:
        Serial.println("+- 500 deg/s");
        break;
    case MPU6050_RANGE_1000_DEG:
        Serial.println("+- 1000 deg/s");
        break;
    case MPU6050_RANGE_2000_DEG:
        Serial.println("+- 2000 deg/s");
        break;
    }

    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    Serial.print("Filter bandwidth set to: ");
    switch (mpu.getFilterBandwidth())
    {
    case MPU6050_BAND_260_HZ:
        Serial.println("260 Hz");
        break;
    case MPU6050_BAND_184_HZ:
        Serial.println("184 Hz");
        break;
    case MPU6050_BAND_94_HZ:
        Serial.println("94 Hz");
        break;
    case MPU6050_BAND_44_HZ:
        Serial.println("44 Hz");
        break;
    case MPU6050_BAND_21_HZ:
        Serial.println("21 Hz");
        break;
    case MPU6050_BAND_10_HZ:
        Serial.println("10 Hz");
        break;
    case MPU6050_BAND_5_HZ:
        Serial.println("5 Hz");
        break;
    }

    Serial.println("");
    delay(100);
}

int roundint(double r)
{
    return (int)((r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5));
}

float sqrtV(float v)
{
    return v * v;
}
float diff(float b, float a)
{
    return b - a;
}
String getMPU6050Data()
{

    /* Get new sensor events with the readings */

    String dataV = "";

    if (mpuStatus)
    {
        /* Print out the values */
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
        dataV = String(a.acceleration.x) + String(",") + String(a.acceleration.y) + String(",") + String(a.acceleration.z) + String(",") + String(g.gyro.x) + String(",") + String(g.gyro.y) + String(",") + String(g.gyro.z);
    }
    else
    {
        dataV = String("0") + String(",") + String("0") + String(",") + String("0") + String(",") + String("0") + String(",") + String("0") + String(",") + String("0");
    }

    return dataV;
}