public class Delta<String>{



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
  public RutaMinima caminoMasCorto(Grafo<String> grafo, String islaO, String islaD){


    
  }


}
