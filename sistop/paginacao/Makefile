all: paginacao_por_demanda_fifo

paginacao_por_demanda_fifo: paginacao_por_demanda_fifo.o
	g++ paginacao_por_demanda_fifo.o -o paginacao_por_demanda_fifo

paginacao_por_demanda_fifo.o: paginacao_por_demanda_fifo.cc
	g++ -c paginacao_por_demanda_fifo.cc

#PHONY
clean:
	rm paginacao_por_demanda_fifo.o paginacao_por_demanda_fifo