void mpu6050_init(void);
int Read_Quad(void);

extern float pitch, roll, yaw;
extern short gyro[3], accel[3], sensors;