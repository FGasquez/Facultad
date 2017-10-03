/** 5. Se tienen 50 empleados de una empresa petrolera que se reúnen para ir en grupos
de a 5 a verificar 1 de los 10 pozos de petróleo existentes, cuando los empleados llegan
se les asigna un numero de grupo, luego deberán esperar a sus compañeros de grupo para ir
 a la verificación. **/


Monitor Group{
  condition queue;
  groupNumber = 1;
  count = 0;

  Procedure in(var p){
    if(count < 4){
      count ++;
      p = groupNumber;
      wait(queue);
    }else{
      count = 0;
      p = groupNumber;
      groupNumber ++;
      singnalAll(queue);
    }
  }
}


Process employees[1..50]{
  int p;
  Group.in(p);
  //checking
}
