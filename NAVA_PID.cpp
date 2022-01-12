#include <NAVA_PID.H>

NAVA_PID::NAVA_PID(double* desired_degree, double* measured_degree, double* throttle, double Kp, double Ki, double Kd)
{
    my_desired_degree = desired_degree;
    my_measured_degree = measured_degree;
    my_throttle = throttle;
    my_kp = Kp;
    my_ki = Ki;
    my_kd = Kd;
}

void NAVA_PID::compute()
{
  current_time = millis();
  elapsed_time = (current_time - prev_time) / 1000;

  error = my_measured_degree - my_desired_degree;
  
  pid_p = my_kp * error;

  if(-3 < error <3)
  {
    pid_i = pid_i + (my_ki * error);  
  }

  pid_d = my_kd * ((error - prev_error) / elapsed_time);

  pid = pid_p + pid_i + pid_d;

  if(pid < -1000)
     pid = -1000;
  if(pid >  1000)
     pid =  1000;

  pwm_right = throttle - pid;
  pwm_left = throttle + pid;

  if(pwm_right < 1000)
     pwm_right = 1000;
  if(pwm_right > 2000)
     pwm_right = 2000;

  if(pwm_left < 1000)
     pwm_left = 1000;
  if(pwm_left > 2000)
     pwm_left

  prev_error = error;

  prev_time = current_time;
}

double NAVA_PID::get_pwm_right() {return pwm_right;}

double NAVA_PID::get_pwm_left() {return pwm_left;}
