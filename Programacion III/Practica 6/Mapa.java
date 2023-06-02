public class Mapa {

  //Construccion basica
  public Grafo<String> mapaCiudades;

  public Mapa(Grafo<String> ciudades){
    this.mapaCiudades=ciudades;
  }

  public Mapa(){
  
  }

  public void setmapaCiudades(Grafo<String> ciudades){
    this.mapaCiudades=ciudades;
  }

  public Grafo<String> getmapaCiudades(){
    return mapaCiudades;
  }

  //Metodos


//1
  public ListaGenerica<String> devoolverCamino(String ciudad1, String ciudad2){
    ListaGenerica<String> listaCaminos = new ListaGenericaEnlazada<String>();
    
    if(!mapaCiudades.esVacio()){
      boolean[] visitado= new boolean[mapaCiudades.listaDeVertices().tamanio()];
      Vertice<String> origen= devolverVerice(ciudad1);
    
      if (origen.dato().equals(ciudad1)){

        //Doy por hecho que es un unico grafo conexo, porque si no se conectan chau.
        
        devolverCamino(listaCaminos, visitado, origen, ciudad2);
      
      }
      
    }
  return listaCaminos;
}


  private void devolverCamino (ListaGenerica<String> listaCamino, boolean[] visitado, Vertice<String> vActual, String destino){
    visitado[vActual.posicion()]=true;  
    
    if(vActual.dato().equals(destino)){  
      listaCamino.agregarInicio(vActual.dato());
  
    }else{
      ListaGenerica<Arista<String>> ady= mapaCiudades.listaDeAdyacentes(vActual);
      ady.comenzar();
      Arista<String> siguiente=null;

      while(!ady.fin()&&(listaCamino.esVacia())){
        siguiente= ady.proximo();
        //si el siguiente Vertice ya fue visitado, pregunto por otro
        if(!visitado[siguiente.verticeDestino().posicion()])
          devolverCamino(listaCamino, visitado, siguiente.verticeDestino(), destino);
  
      }  
      //Una vez que sale(porque puede ser que la lista ya no este vacia) pregunta si agrega si ciudad, y vuelve de la recursion
      if(!listaCamino.esVacia())
        listaCamino.agregarInicio(vActual.dato());
    }
    }
  
  private Vertice<String> devolverVerice(String c1){
    
    Vertice<String> vertAct=null;

    int i=0;
    int numTot= mapaCiudades.listaDeVertices().tamanio()-1;
    
    vertAct= mapaCiudades.vertice(i);
    
    while((i<numTot)&&(!vertAct.dato().equals(c1))){
      i++;
      vertAct= mapaCiudades.vertice(i);
    }

    return vertAct;
  }


  //2
  public ListaGenerica<String> devolverCaminoExceptuando (String ciudad1, String ciudad2, ListaGenerica<String> ciudades){
    ListaGenerica<String> listaCaminos = new ListaGenericaEnlazada<String>();
    
    if(!mapaCiudades.esVacio()){
      boolean[] visitado= new boolean[mapaCiudades.listaDeVertices().tamanio()];
      Vertice<String> origen= devolverVerice(ciudad1);
    
      if (origen.dato().equals(ciudad1)){

        //Doy por hecho que es un unico grafo conexo, porque si no se conectan chau.
        
        devolverCaminoExceptuando(listaCaminos, ciudades, visitado, origen, ciudad2);
      
      }
      
    }

    return listaCaminos;
  }

  private void devolverCaminoExceptuando(ListaGenerica<String> listaCamino, ListaGenerica<String> ciudades,boolean[] visitado, Vertice<String> vActual, String destino){
    
    visitado[vActual.posicion()]=true;  
    
    if(vActual.dato().equals(destino) && !pertenece(vActual.dato(),ciudades)){  
      listaCamino.agregarInicio(vActual.dato());
  
    }else{
      ListaGenerica<Arista<String>> ady= mapaCiudades.listaDeAdyacentes(vActual);
      ady.comenzar();
      
      while(!ady.fin()&&(listaCamino.esVacia())){
        Arista<String> siguiente= ady.proximo();
        //si el siguiente Vertice ya fue visitado, pregunto por otro
        if(!visitado[siguiente.verticeDestino().posicion()])
          devolverCaminoExceptuando(listaCamino, ciudades, visitado, siguiente.verticeDestino(), destino);
  
      }  
      //Una vez que sale(porque puede ser que la lista ya no este vacia) pregunta si agrega si ciudad, y vuelve de la recursion
      if(!listaCamino.esVacia())
        listaCamino.agregarInicio(vActual.dato());
    }
    }

  private boolean pertenece(String actual, ListaGenerica<String> ciudades){
    if(!ciudades.esVacia()){
      ciudades.comenzar();
      String aux;
      while(!ciudades.fin()){
        aux= ciudades.proximo();
        if(actual.equals(aux))
          return true;
      }    
  }
  return false;
}
}
