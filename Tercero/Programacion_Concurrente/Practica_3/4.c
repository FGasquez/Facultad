
/** 4. Suponga que N personas llegan a la cola de un banco. Una vez que la persona se agrega en la cola no espera más de 15 minutos para su atención, si pasado ese tiempo no fue atendida se retira. Para atender a las personas existen 2 empleados que van atendiendo de a una y por orden de llegada a las personas **/

    bool attended[1..N] = ([N], false);

    Monitor MTimer{
      condition queue[1..N];
      int aux[1..N] = ([N], 0);

      procedure p(id){
        if (aux[id] == 0){
          aux[id]++;
          wait(queue[id]);
        }else{
          aux[id] --;
        }
      }

      procedure v(id){
        if(aux[id] == 0){
          aux[id] ++;
        }else{
          signal(queue[id]);
          aux[id] --;
        }
      }
    }

    Monitor Checkout{
      condition queue;
      int sleep = 0;
      int count = 0;

      procedure in(){
        if(count == 2){
          sleep ++;
          wait(queue);
        }else{
          count ++;
        }
      }

      procedure out(){
        if(sleep > 0){
          sleep --;
          signal(queue);
        }else{
          cant --;
        }
      }
    }

    process customers[id:1..N]{
      MTimer.v(id);
      Checkout.in();
      if(!attended[id]){
        attended[id] = true;
        //in Checkout
        Checkout.out();
      }
    }

    Process timer[id:1..N]{
      MTimer.p(id);
      delay(15*60) //15 minutes
      if(not attended[id]){
        attended[id] = true;
        Checkout.out(id);
      }
    }
