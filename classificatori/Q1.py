dp = [[1, 0, 0]]                # dp[i][j]: persones que al dia i han transmès info durant j dies
while sum(dp[-1]) < 7776000000: # Si al final de l'ultim dia no ho sabien prou persones...
    dp.append([5*(dp[-1][0] + dp[-1][1]), dp[-1][0], dp[-1][1] + dp[-1][2]]) # ...actualitzem
print(len(dp) - 1)              # L'última dada de dp està en el primer dia en què tothom està informat