#ifndef NAVA_PID
#define NAVA_PID
#define LIBRARY_VERSION	1.1

class NAVA_PID
{
  public:
  NAVA_PID(double*, double*, double*,double, double, double);

  void compute();
	
  double get_pwm_right();
  double get_pwm_left();

  private:
  double pid, pwm_right, pwm_left, error, prev_error;

  double pid_p = 0;
  double pid_i = 0;
  double pid_d = 0;
	
  double my_kp;                  // * (P)roportional Tuning Parameter
  double my_ki;                  // * (I)ntegral Tuning Parameter
  double my_kd;                  // * (D)erivative Tuning Parameter

  double *my_desired_degree;
  double *my_measured_degree;
  double *my_throttle;
	
  unsigned long elapsed_time;	  
  unsigned long current_time;
  unsigned long prev_time = 0;
};
#endif

