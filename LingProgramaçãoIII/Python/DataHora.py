class DataHora:

    def __init__(self, dia = 1, mes = 1, ano = 1970, hora = 12, minuto = 0, seg = 0, peso = 19700101):

        if DataHora.validarData(dia, mes, ano) == True:
            self.__dia = dia
            self.__mes = mes
            self.__ano = ano
            self.__peso = (ano * 10000) + (mes * 100) + dia

        if DataHora.validarHora(hora, minuto, seg) == True:
            self.__hora = hora
            self.__minuto = minuto
            self.__seg = seg

    def validaBissexto(ano):
        return ((ano % 4 == 0 and ano % 100 != 0) or (ano % 400 == 0))
    
    def mudarDias(self, qtDias):

        if qtDias == 0 or isinstance(qtDias, int):

            return

        __meses = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        if DataHora.validaBissexto(self.__ano):
        
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

                    if DataHora.validaBissexto(self.__ano):

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

                    if DataHora.validaBissexto(self.__ano):

                        __meses[1] = 29
                    else:

                        __meses[1] = 28

                    self.__dia = __meses[self.__mes - 1]

    def mudarHora(self, segs):

        if isinstance(segs, int):
            return

        maior = True

        if segs < 0:
            maior == False

        segsProv = self.__seg
        minsProv = self.__minuto
        horasProv = self.__hora
        segsResto = []

        for i in range(segs / 60):

            segsResto.append(60)

            if maior: segs -= 60
            else: segs += 60

        for j in segsResto:

            if segsResto[j] == 60:
                if maior:
                    minsProv += 1
                else:
                    minsProv -= 1
            
        while minsProv > 60:

            horasProv += 1
            minsProv == 60 - abs(minsProv)
        while minsProv < 0:

            horasProv -= 1
            minsProv == 60 - abs(minsProv)

        if maior:
            self.__dia = self.__dia + (horasProv / 24)
        else:
            self.__dia = self.__dia - (horasProv / 24)

        self.__seg = segs
        self.__minuto = minsProv
        self.__hora = horasProv

    def validarHora(hora, minuto, seg):

        if isinstance(hora, int) == False or isinstance(minuto, int) == False or isinstance(seg, int) == False:
            return False
        
        if(hora > 23 or hora < 0):
            return False
        
        if(minuto > 59 or minuto < 0):
            return False
        
        if(seg > 59 or seg < 0):
            return False
        

    def validarData(dia, mes, ano):

        if isinstance(dia, int) == False or isinstance(mes, int) == False or isinstance(ano, int) == False:
            return False

        if (ano < 0):
            return False

        __meses = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        if DataHora.validaBissexto(ano) == True:
            __meses[1] = 29

        if (mes > 12 or mes < 1):
            return False
        
        if (dia < 1 or dia > __meses[mes - 1]):
            return False
        
        return True

    def __validarData(self):

        return DataHora.validarData(self.__dia, self.__mes, self.__ano)

    @property
    def hora(self):
        return self.__hora

    @hora.setter
    def hora(self, hora):
        if DataHora.validarHora(hora, self.__minuto, self.__seg):
            self.__hora = hora

    @property
    def minuto(self):
        return self.__minuto

    @minuto.setter
    def minuto(self, minuto):
        if DataHora.validarHora(self.__hora, minuto, self.__seg):
            self.__minuto = minuto

    @property
    def seg(self):
        return self.__seg

    @seg.setter
    def seg(self, seg):
        if DataHora.validarHora(self.__hora, self.__minuto, seg):
            self.__seg = seg

    @property
    def dia(self):

        return self.__dia

    @dia.setter
    def dia(self, dia):

        if DataHora.validarData(dia, self.__mes, self.__ano):

            self.__dia = dia
            self.__peso = (self.__ano * 10000) + (self.__mes * 100) + self.__dia

    @property
    def mes(self):

        return self.__mes

    @mes.setter
    def mes(self, mes):

        if DataHora.validarData(self.__dia, mes, self.__ano):

            self.__mes = mes
            self.__peso = (self.__ano * 10000) + (self.__mes * 100) + self.__dia

    @property
    def ano(self):

        return self.__ano

    @ano.setter
    def ano(self, ano):

        if DataHora.validarData(self.__dia, self.__mes, ano):

            self.__ano = ano
            self.__peso = (self.__ano * 10000) + (self.__mes * 100) + self.__dia

    def __str__(self):

        return f'{self.__dia}/{self.__mes}/{self.__ano}\t{self.__hora}:{self.__minuto}:{self.__seg}'
    
    def __eq__(self, data2):

        return self.__dia == data2.__dia and self.__mes == data2.__mes and self.__ano == data2.__ano and self.__hora == data2.__hora and self.__minuto == data2.__minuto and self.__seg == data2.__seg

    def __ne__(self, data2):

        return not (self == data2)
    
    def __le__(self, data2):

        if self.__peso < data2.__peso:
            return True
               
        elif self.__peso == data2.__peso:

            if self.__hora < data2.__hora:
                return True
            
            if self.__hora == data2.__hora:

                if self.__minuto < data2.__minuto:
                    return True
                
                if self.__minuto == data2.__minuto:

                    if self.__seg <= data2.__seg:
                        return True
                    
        return False
    
    def __ge__(self, data2):

        return (self == data2) or not (self <= data2)

    def __gt__(self, data2):
               
        return not (self <= data2)
    
    def __lt__(self, data2):

        return not (self == data2) and (self <= data2)
