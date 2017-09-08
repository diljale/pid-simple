#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;
  prev_cte_ = 0;
  cte_total_ = 0;
}

void PID::UpdateError(double cte) {
  cte_total_ += cte;
  p_error = Kp_ * cte;
  d_error = Kd_ * (cte - prev_cte_);
  i_error = Ki_ * cte_total_;
  
  prev_cte_ = cte;
}

double PID::TotalError() {
  return p_error+d_error+i_error;
}

