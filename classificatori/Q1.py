dp = [[1, 0, 0]]                # dp[i][j]: persones que al dia i ha transmés info durant j dies
while sum(dp[-1]) < 7776000000: # Si a l'ultim dia no ho sabien prous persones...
    dp.append([5*(dp[-1][0] + dp[-1][1]), dp[-1][0], dp[-1][1] + dp[-1][2]]) # ...actualitzem
print(len(dp) - 1)              # L'última dada de dp és la que està en el dia quan tothom està informat