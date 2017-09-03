rm(list=ls())


valores<-c(15,10,9,5)
pesos<-c(1,5,3,4)
n<-length(valores)
capacidade<-8
matriz_solucao<-matrix(-1,ncol=capacidade+1,nrow=n+1)

##Preenchendo a primeira linha, sem nenhum item na mochila
matriz_solucao[1,]<-0

rownames(matriz_solucao)<-c("Nenum Item",paste("Item",1:n))
colnames(matriz_solucao)<-c("Peso=0",paste("Peso=",1:capacidade,sep=""))

##Preenchendo a matriz
for(i in 2:(n+1)){
    for(j in 1:(capacidade+1))        
        if(pesos[i-1]>j){
            matriz_solucao[i,j]<-matriz_solucao[i-1,j]
            ##Se o item item não cabe, continua a solução anterior            
        }else{
            matriz_solucao[i,j]<-max(matriz_solucao[i-1,j], matriz_solucao[i-1, j-pesos[i-1]] + valores[i-1])
            ##Senão pegamos o melhor entre a solução anterior e adicionar o item mais a melhor solução sem esse item
            ##(tiramos j-pesos[i-1] que é voltar o peso na matriz para pegar a solução que cabe com esse item) 
        }
}
##O melhor ganha esta na ultima linha, na ultima coluna
matriz_solucao

##Para saber qual a solução, olhamos na matriz
mochila<-rep(-1,n)
j<-ncol(matriz_solucao)
for(i in nrow(matriz_solucao):2){
    if(matriz_solucao[i,j]==matriz_solucao[i-1,j]){
        ##Se o ganho da linha superior, para uma coluna, é o mesmo, esse item não foi escolhido
        mochila[i-1]<-0
    }else{
        ##Se a linha de cima é menor, logo esse item esta na mochila
        ##Então ele entra, e continuamos comparando a matriz para traz do peso doitem, por isso
        ##Decrementamos j
        mochila[i-1]<-1
        j<-j-pesos[i-1]
    }
}

mochila


#####################################
## Solução gulosa
#####################################
valores<-c(15,10,9,5)
pesos<-c(1,5,3,4)
n<-length(valores)
capacidade<-8

ordem<-order(valores/pesos,decreasing = T)

mochila<-rep(0,n)

i<-1
while(i<=n){
    if(sum(pesos[which(mochila==1)])+pesos[ordem[i]]<=capacidade){    
        mochila[ordem[i]]<-1
    }
    i<-i+1
}


#####################################
## Funções
#####################################

##Programação dinamica
mochila_dinamico<-function(valores,pesos,capacidade){
    n<-length(valores)
    matriz_solucao<-matrix(-1,ncol=capacidade+1,nrow=n+1)
    matriz_solucao[1,]<-0

    for(i in 2:(n+1)){
        for(j in 1:(capacidade+1))        
            if(pesos[i-1]>j){
                matriz_solucao[i,j]<-matriz_solucao[i-1,j]
            }else{
                matriz_solucao[i,j]<-max(matriz_solucao[i-1,j], matriz_solucao[i-1, j-pesos[i-1]] + valores[i-1])
            }
    }
    mochila<-rep(-1,n)
    j<-ncol(matriz_solucao)
    for(i in nrow(matriz_solucao):2){
        if(matriz_solucao[i,j]==matriz_solucao[i-1,j]){
            mochila[i-1]<-0
        }else{
            mochila[i-1]<-1
            j<-j-pesos[i-1]
        }
    }
    saida<-list(ganho=matriz_solucao[nrow(matriz_solucao),ncol(matriz_solucao)],solucao=mochila)
    return(saida)
}

##Programação Gulosa
mochila_guloso<-function(valores,pesos,capacidade){
    n<-length(valores)
    ordem<-order(valores/pesos,decreasing = T)
    mochila<-rep(0,n)
    i<-1
    while(i<=n){
        if(sum(pesos[which(mochila==1)])+pesos[ordem[i]]<=capacidade){    
            mochila[ordem[i]]<-1
        }
        i<-i+1
    }
    sum(valores[which(mochila==1)])
    saida<-list(ganho=sum(valores[which(mochila==1)]),solucao=mochila)
    return(saida)
}

##Gerador de Exemplos
mochila_exemplo<-function(n=10,peso_max=100,valores_max=100,capacidade_max=1000){
    itens<-sample(1:n,1)
    pesos<-sample(1:peso_max,itens,replace=TRUE)
    valores<-sample(1:valores_max,itens,replace=TRUE)
    capacidade<-sample(1:capacidade_max,1)
    return(list(pesos=pesos,valores=valores,capacidade=capacidade))
}


###Exemplos
mochila_dinamico(valores,pesos,capacidade)
mochila_guloso(valores,pesos,capacidade)

###Testando
dados<-data.frame(itens=vector(),
                  capacidade=vector(),
                  tempo_guloso=vector(),
                  ganho_guloso=vector(),
                  tempo_dinamico=vector(),
                  ganho_dinamico=vector())

set.seed(123)
for(i in 1:1000){
    print(paste("Iteração",i))
    exemplo<-mochila_exemplo(n=10000,peso_max=1000,valores_max = 1000,capacidade_max = 2000)
    ##write.table(rbind(c(length(exemplo$valores),exemplo$capacidade),cbind(exemplo$pesos,exemplo$valores)),file=paste("exemplo_",i,".txt",sep=""),row.names = F,col.names=F, sep=" ")    
    ##tempo_guloso<-system.time(guloso<-mochila_guloso(exemplo$valores,exemplo$pesos,exemplo$capacidade))
    ##tempo_dinamico<-system.time(dinamico<-mochila_dinamico(exemplo$valores,exemplo$pesos,exemplo$capacidade))
    ##dados[i,]<-c(length(exemplo$valores),exemplo$capacidade,tempo_guloso[1],guloso$ganho,tempo_dinamico[1],dinamico$ganho)
    dados[i,1:2]<-c(length(exemplo$valores),exemplo$capacidade)
}

dados

dados[,c(3,4)]<-read.table("guloso.txt")[,c(2,1)]
dados[,c(5,6)]<-read.table("prog_dinamica.txt")[,c(2,1)]

head(dados)

png("figura1.png",width = 2*480,height = 2*480, pointsize = 2*12)
plot(tempo_dinamico~itens,data=dados,pch=19,col="gray",cex=(dados$capacidade+0.2)/(max(dados$capacidade)-min(dados$capacidade)),
     xlab="Quantidade de Itens",ylab="Tempo Utilizado",frame=F)
predicao<-predict(loess(tempo_dinamico~itens,data=dados),data.frame(itens = 1:max(dados$itens)))
points(1:max(dados$itens),predicao,type="l",lwd=3,lty=3,col="black")

points(tempo_guloso~itens,data=dados,pch=19,col="lightblue",cex=(dados$capacidade+0.2)/(max(dados$capacidade)-min(dados$capacidade)))
predicao<-predict(loess(tempo_guloso~itens,data=dados),data.frame(itens = 1:max(dados$itens)))
points(1:max(dados$itens),predicao,type="l",lwd=3,lty=3,col="blue")
legend("topleft",legend=c("Tempo Dinâmico","Tempo Guloso"),pch=19,col=c("gray","lightblue"),title="Casos",bty="n")
legend("left",legend=c("Alg. Dinâmico","Alg. Guloso"),lwd=3,lty=3,col=c("black","blue"),title="Média esperada",bty="n")
dev.off()

png("figura2.png",,width = 2*480,height = 2*480, pointsize = 2*12)
hist(dados$ganho_dinamico-dados$ganho_guloso,breaks=seq(0,600,10),xlab="Diferença de ganho entre dinâmico e guloso",ylab="Número de casos",col="gray",main="")
dev.off()

table(dados$ganho_guloso==dados$ganho_dinamico)

dados[dados$ganho_guloso==dados$ganho_dinamico,]

summary(dados$ganho_guloso)
summary(dados$ganho_dinamico)
    




cbind(dados$ganho_guloso/dados$ganho_dinamico,dados$ganho_dinamico/dados$ganho_guloso)
   
