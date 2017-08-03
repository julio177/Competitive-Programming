
 
Edit
Selection
Find
Goto
Settings
 Make Private
Login or Register
Go Pro!


150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
    line = '+'.join(['-'*(width*3)]*3)
    # Para cada row, inserta pipes como separadores
    for r in rows:
        print(''.join(values[r+c].center(width)+('|' if c in '36' else '')
                      for c in cols))
        # Imprime la linea
        if r in 'CF': print(line)
    print('') # Imprime un salto de linea
# Resuelve el grid de sudoku, manda llamar la funcion search que recibe como argumeto el sudoku parseado
def solve(grid): return search(parse_grid(grid))
# Funcion para buscar valores para las casillas
def search(values):
    "Using depth-first search and propagation, try all possible values."
    # Si los valores estan en falso
    if values is False:
        # No es posible solucionar
        return False ## Failed earlier
    # Si a cada casilla del sudoku le corresponde un valor
    if all(len(values[s]) == 1 for s in squares): 
        # Retornar que se encontro la solucion
        return values ## Solved!
    ## Chose the unfilled square s with the fewest possibilities
    # Se busca resolver las reglas que cuentan con menos valores posibles a asignar
    n,s = min((len(values[s]), s) for s in squares if len(values[s]) > 1)
    # Se retorna una llamada recursiva que busca asignar un nuevo valor 
    return some(search(assign(values.copy(), s, d)) for d in values[s])
    
# Retorna un elemento que este en la lista que recibe
def some(seq):
    "Return some element of seq that is true."
    for e in seq:
        if e: return e
    return False
display(solve(grid))
