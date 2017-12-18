
# CarND Unscented Kalman Filter Project

[//]: # (Image References)
[image1]: ./Output_images/NIS_L.png
[image2]: ./Output_images/NIS_R.png
[image3]: ./Output_images/UKF_L_DS1.png
[image4]: ./Output_images/UKF_L_DS2.png
[image5]: ./Output_images/UKF_R_DS1.png
[image6]: ./Output_images/UKF_R_DS2.png
[image7]: ./Output_images/UKF_LR_DS1.png
[image8]: ./Output_images/UKF_LR_DS2.png
[image9]: ./Output_images/EKF_UKF.png

---
This project is an implementation of a sensor fusion algorithm based on Unscented Kalman filter for object tracking combining Lidar and Radar sensors measurements.

---
### Project Goals
This project aims to solve the non-linearity problem in moving object by using the constant turn rate and velocity magnitude motion model(CTRV) in order to allocate the the position of object moving not in straight line and with different internal force(velocity) more precise than by using Extended Klaman Filter with linear motion and the steps as following:

1. Initialize the Kalman Parameter and initial state.
2. Predict the next state and covariance.
3. Update the state based on sensor type.

### Dependencies
* cmake >= v3.5
* make >= v4.1
* gcc/g++ >= v5.4

### Build instructions
1. Clone this repo.
2. Make a build directory: mkdir build && cd build
3. Compile: cmake .. && make
4. Run it: ./UnscentedKF

---


## Results

The Algorithm is tested with single sensor and fused Lidar and radar sensors. the images below shows the tracking performance in each test as the vertical axis in the y axis and the horizontal axes in the x axis. The performance is achieved by tuning the acceleration noise `std_a` and turn rate noise `std_yawd` and best value choosed based on  Normalized Innovation squared (NIS) value for each prediction step for Laser and radar as following.
![alt text][image1]
![alt text][image2]
The residual error is calculated by root mean square error.  the system shows higher RMSE in test 1 and 2 in using either radar or Lidar and the accuracy in Lidar is higher than the radar in estimating the position but Radar is better for estimating the velocity. In combining both sensors the accuracy increased and RMSE decreased to below the required level. By focusing on the curve moving, we find UKF has better result in position the object when moving in circular motion and I applied the approach in the Car Runaway Catch Bonus task in the following github linke: https://github.com/Eng-Mo/CarND--Catch-Runaway-Car
![alt text][image9]


RMSe|UKF-Laser|UKF-Radar|UKF-Fused|EKF-Fused
--------------|---------|---------|---------
X   |.1745    |.2234    |.0702    |.1840 
Y   |.1540    |.3108    |.0864    |.1534  
vX  |.6666    |.5017    |.3616    |.6056  
vY  |.3831    |.3948    |.2661    |.0486 


![alt text][image3]
![alt text][image4]
![alt text][image5]
![alt text][image6]
![alt text][image7]
![alt text][image8]


