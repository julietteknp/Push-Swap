1. indexer tous les nombres de 0 à n - 1

2. calculer chunk_size = sqrt(n)

3. chunk 1 : index 0 à chunk_size - 1
   chunk 2 : index chunk_size à 2*chunk_size - 1
   etc.

4. pour chaque chunk :
      parcourir A jusqu’à avoir poussé tous les index du chunk dans B

5. une fois tout dans B :
      récupérer le max de B
      le mettre en haut avec rb/rrb
      pa

get_index

int ft_get_chunk_size(int n)

