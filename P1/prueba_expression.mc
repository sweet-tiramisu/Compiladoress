prueba() {
    const int a = 0;
    var int b,c,x;

    c=1+1;          //probamos la suma
    print(c,"\n"); //imprimimos el resultado

    c=2*2;//probamos la multiplicación
    print(c,"\n");//imprimimos el resultado

    c=4/2;//probamos la división
    print(c,"\n");//imprimimos el resultado

    c=1+1*4+1;//probamos la prioridad de multiplicación y suma
    print(c,"\n");//imprimimos el resultado

    c=(1+1)*4+1;//probamos la prioridad de multiplicación y suma con parentesis.
    print(c,"\n");//imprimimos el resultado

    c=1+4/2+1;//probamos la prioridad de división y suma
    print(c,"\n");//imprimimos el resultado

    c=(2+4)/2+1;//probamos la prioridad de división y suma con parentesis
    print(c,"\n");//imprimimos el resultado




    c=1==1;//probamos el == con ambos iguales
    print(c,"\n");//imprimimos el resultado

    c=1==2;//probamos el == con el de la izquierda siendo menor.
    print(c,"\n");//imprimimos el resultado

    c=2==1;//probamos el == con el de la derecha siendo menor.
    print(c,"\n");//imprimimos el resultado


    c= 1!=1;//probamos el != con ambos iguales
    print(c,"\n");//imprimimos el resultado

    c=1!=2;//probamos el != con el de la izquierda siendo menor.
    print(c,"\n");//imprimimos el resultado

    c=2!=1;//probamos el != con el de la derecha siendo menor.
    print(c,"\n");//imprimimos el resultado



    c= 1<1;//probamos el < con ambos iguales
    print(c,"\n");//imprimimos el resultado

    c=1<2;//probamos el < con el de la izquierda siendo menor.
    print(c,"\n");//imprimimos el resultado

    c=2<1;//probamos el < con el de la derecha siendo menor.
    print(c,"\n");//imprimimos el resultado


    c= 1>1;//probamos el > con ambos iguales
    print(c,"\n");//imprimimos el resultado

    c=1>2;//probamos el > con el de la izquierda siendo menor.
    print(c,"\n");//imprimimos el resultado

    c=2>1;//probamos el > con el de la derecha siendo menor.
    print(c,"\n");//imprimimos el resultado


    c= 1<=1;//probamos el <= con ambos iguales
    print(c,"\n");//imprimimos el resultado

    c=1<=2;//probamos el <= con el de la izquierda siendo menor.
    print(c,"\n");//imprimimos el resultado

    c=2<=1;//probamos el <= con el de la derecha siendo menor.
    print(c,"\n");//imprimimos el resultado


    c= 1>=1;//probamos el >= con ambos iguales
    print(c,"\n");//imprimimos el resultado

    c=1>=2;//probamos el >= con el de la izquierda siendo menor.
    print(c,"\n");//imprimimos el resultado

    c=2>=1;//probamos el >= con el de la derecha siendo menor.
    print(c,"\n");//imprimimos el resultado

    c=0;    //para que se ejecute el 2+2
    c= (c ? 1+1 : 2+2);
    print(c,"\n");//imprimimos el resultado

    c=1;    //para que se ejecute el 1+1
    c= (c ? 1+1 : 2+2);
    print(c,"\n");//imprimimos el resultado


    c=0;    //para que se ejecute el 2+2
    c= 1+(c ? 1+1 : 2+2)+1; //ahora probamos sumandole 1 por la derecha y por la izquierda, para ver si se suma bien
    print(c,"\n");//imprimimos el resultado

    c=1;    //para que se ejecute el 1+1
    c= 1+(c ? 1+1 : 2+2)+1; //ahora probamos sumandole 1 por la derecha y por la izquierda, para ver si se suma bien
    print(c,"\n");//imprimimos el resultado
}