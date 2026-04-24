class Data:

    def __init__(self, dia = 1, mes = 1, ano = 1970, peso = 19700101):

        if Data.validarData(dia, mes, ano) == True:
            self.__dia = dia
            self.__mes = mes
            self.__ano = ano
            self.__peso = (ano * 10000) + (mes * 100) + dia

    def validaBissexto(ano):
        return ((ano % 4 == 0 and ano % 100 != 0) or (ano % 400 == 0))
    
    def mudarDias(self, qtDias):

        if qtDias == 0:

            return

        __meses = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        if Data.validaBissexto(self.__ano):
        
            __meses[1] = 29

        while qtDias != 0:

            if qtDias > 0:

                if (self.__dia + qtDias <= __meses[self.__mes - 1]):

                    self.__dia += qtDias
                    qtDias = 0
                else:

                    qtDias -= (__meses[self.__mes - 1] - self.__dia + 1)
                    self.__dia = 1
                    self.__mes += 1

                    if (self.__mes > 12):

                        self.__mes = 1
                        self.__ano += 1

                    if Data.validaBissexto(self.__ano):

                        __meses[1] = 29
                    else:

                        __meses[1] = 28
            else:

                if (self.__dia + qtDias > 0):

                    self.__dia += qtDias
                    qtDias = 0
                else:

                    qtDias += self.__dia
                    self.__mes -= 1

                    if (self.__mes < 1):

                        self.__mes = 12
                        self.__ano -= 1

                    if Data.validaBissexto(self.__ano):

                        __meses[1] = 29
                    else:

                        __meses[1] = 28

                    self.__dia = __meses[self.__mes - 1]    
                    

    def validarData(dia, mes, ano):

        if isinstance(dia, int) == False or isinstance(mes, int) == False or isinstance(ano, int) == False:
            return False

        if (ano < 0):
            return False

        __meses = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        if Data.validaBissexto(ano) == True:
            __meses[1] = 29

        if (mes > 12 or mes < 1):
            return False
        
        if (dia < 1 or dia > __meses[mes - 1]):
            return False
        
        return True

    def __validarData(self):

        return Data.validarData(self.__dia, self.__mes, self.__ano)

    @property
    def dia(self):

        return self.__dia

    @dia.setter
    def dia(self, dia):

        if Data.validarData(dia, self.__mes, self.__ano):

            self.__dia = dia
            self.__peso = (self.__ano * 10000) + (self.__mes * 100) + self.__dia

    @property
    def mes(self):

        return self.__mes

    @mes.setter
    def mes(self, mes):

        if Data.validarData(self.__dia, mes, self.__ano):

            self.__mes = mes
            self.__peso = (self.__ano * 10000) + (self.__mes * 100) + self.__dia

    @property
    def ano(self):

        return self.__ano

    @ano.setter
    def ano(self, ano):

        if Data.validarData(self.__dia, self.__mes, ano):

            self.__ano = ano
            self.__peso = (self.__ano * 10000) + (self.__mes * 100) + self.__dia

    def __str__(self):

        return f'{self.__dia}/{self.__mes}/{self.__ano}'
    
    def __eq__(self, data2):

        return self.__dia == data2.__dia and self.__mes == data2.__mes and self.__ano == data2.__ano

    def __ne__(self, data2):

        return self.__dia != data2.__dia or self.__mes != data2.__mes or self.__ano != data2.__ano
    
    def __lt__(self, data2):
               
        return self.__peso < data2.__peso
    
    def __le__(self, data2):

        return (self == data2) or (self < data2)

    def __gt__(self, data2):
               
        return self.__peso > data2.__peso
    
    def __ge__(self, data2):

        return (self == data2) or (self > data2)
