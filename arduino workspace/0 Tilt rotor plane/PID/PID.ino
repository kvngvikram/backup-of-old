 void setup(){
   
 }
 volatile float e_old[4]={0,0,0,0} ; 
 volatile double E[4]={0,0,0,0}; 
 float pid(float set_point , float current , float kp , float ki , float kd ,int i){
  float e , e_dot , outpid ; 
  e = set_point - current ;
  e_dot = e - e_old[i] ; 
  E[i]=E[i]+e ;
  if(E[i]>1000)E[i]=0; 
  outpid = kp*e + kd*e_dot + ki*E[i] ;
  e_old[i] = e ;
  return outpid ;
 } 
 void loop(){
 }
  
  
  
