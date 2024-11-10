## [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)

O problema se resume em encontrar o custo mínimo para percorrer um caminho entre a origem (_src_) até o destino (_dst_), respeitando o limite máximo de paradas (_k_). Caso não aja esse caminho, o retorno é -1.

A entrada consiste em:

- _n_: número total de vôos;
- _flights_: uma lista de voos, onde cada voo é representado por uma lista _[from, to, price]_, indicando que existe um voo direto entre cidade origem (_from_) e cidade destino (_to_) com determinado custo (_price_).
- _src_: cidade de origem que se inicia a viagem
- _dst_: cidade destino que se quer alcançar
- _k_: número máximo de paradas permitidas
