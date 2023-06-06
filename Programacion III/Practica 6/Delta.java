public class Delta<T>{



  //-------------------------------------------------------------------------------------------
  //Retorna el número máximo de islas distintas que se pueden recorrer en el grafo comprando un único boleto.
  
  
  public int maxIslasDistintas(Grafo<String> grafo) {
    int resultado=0, cant=0;
  
    if((grafo!=null)&&(!grafo.esVacio())){
      ListaGenerica<Vertice<String>> listaV=grafo.listaDeVertices();
      boolean visitado[]=new boolean[listaV.tamanio()];
      resultado=maxIslasDistintas(grafo, visitado, listaV.elemento(0),cant)-1;
    }
  
    return resultado;
  } 

  private int maxIslasDistintas(Grafo<String> grafo, boolean[] visitado, Vertice<String> act, int cant){
    int islaproximavisitada=0;
    visitado[act.posicion()]=true;
    ListaGenerica<Arista<String>> ady= grafo.listaDeAdyacentes(act);
    Arista<String> proxima;
    ady.comenzar();
    int mayor=0,may=0;
    while(!ady.fin() && ady!=null){
  
      proxima=ady.proximo();
      if(!visitado[proxima.verticeDestino().posicion()]){
        may=maxIslasDistintas(grafo, visitado, proxima.verticeDestino(),cant+1)+1;
        islaproximavisitada++;
        if(mayor<may)
          mayor=may;
      }
  }
  visitado[act.posicion()]=false;
  
  if(islaproximavisitada==0){
    return 1; // caso base devuelve 1. Suma la cantidad recursivamente
    }else{
      return mayor;
    }
  }
  



//  ----------------------------------------------------------------------------------------------
//Retorna un objeto de la clase RutaMinima, el cual contiene el camino más corto entre islaO
//e islaD y si se puede realizar con un único boleto o es necesario comprar un nuevo boleto
//para completar el recorrido.

  public RutaMinima caminoMasCorto(Grafo<String> grafo, String islaO, String islaD){
      RutaMinima posibleRuta=new RutaMinima();
      RutaMinima ruta=new RutaMinima();
      if(!grafo.esVacio()){
        boolean[] visitado= new boolean[grafo.listaDeVertices().tamanio()];
        Vertice<String> origen =devolverVerice(grafo, islaO);
      
        if(origen.dato().equals(islaD)){
          caminoMasCorto(grafo, ruta, origen, posibleRuta, islaD, visitado);
        }
      }
      return ruta;
    }
    
    //Lo hago que devuelva un int para poder alterar el minimo, y encontrar el mas corto. La lista al ser dinamica se devuelve sola.
    private void caminoMasCorto(Grafo<String> grafo, RutaMinima ruta ,Vertice<String> actual, RutaMinima posibleMin, String i2, boolean[] visitado){
      visitado[actual.posicion()]=true;
      posibleMin.getLista().agregarInicio(actual.dato());
      
      if(actual.posicion()==0)
        posibleMin.agregarBoletos(); //Por si pasa por el muelle agrego 1 boleto

      if(actual.dato().equals(i2)){ //Si llega al destino      
        if(ruta.getLista().tamanio()>posibleMin.getLista().tamanio()){ // Compara tamanio de lista
          ruta.setLista(posibleMin.getLista().copiar());;
          posibleMin.getLista().eliminar(actual.dato());
          ruta.setBoletos(posibleMin.getBoletos());
        }
      }else{ 
        ListaGenerica<Arista<String>> ady= grafo.listaDeAdyacentes(actual);
        ady.comenzar();  
      
        while(!ady.fin()){
          Arista<String> siguiente= ady.proximo();
          if(!visitado[siguiente.verticeDestino().posicion()]){
            caminoMasCorto(grafo ,ruta, siguiente.verticeDestino(), posibleMin, i2, visitado); //Devuelve el min asi lo puedo mantener actualizado
            posibleMin.getLista().eliminarEn(siguiente.verticeDestino().posicion());
            visitado[siguiente.verticeDestino().posicion()]=false; //Desmarco por si otro camino pasa por aca de vuelta
          }
          }  
          
          if(actual.posicion()==0)
          posibleMin.eliminarBoletos(); //Por si pasa por el muelle agrego 1 boleto
  
    }
  
  }

    
  private Vertice<String> devolverVerice(Grafo<String> grafo, String c1){
    
    Vertice<String> vertAct=null;

    int i=0;
    int numTot= grafo.listaDeVertices().tamanio()-1;
    
    vertAct= grafo.vertice(i);
    
    while((i<numTot)&&(!vertAct.dato().equals(c1))){
      i++;
      vertAct= grafo.vertice(i);
    }

    return vertAct;
  }


  }

