class Cliente:

    def __init__(self, nome = "", cpf = "000.000.000-00", dependentes = []):
        
        if Cliente.validarCliente(nome, cpf, dependentes):
            
            self.__nome = nome
            self.__cpf = cpf
            self.__dependentes = dependentes
        
        
    def validarCliente(nome, cpf, dependentes):

        cpf = Cliente.ajustaCPF(cpf)

        if not isinstance(nome, str) or not all(isinstance(x, str) for x in dependentes):
            return False
        
        return True

    @property
    def nome(self):
        return self.__nome
    
    @nome.setter
    def nome(self, nome):
        if Cliente.validarCliente(nome, self.__cpf, self.__dependentes):
            self.__nome = nome

    @property
    def cpf(self):
        return self.__cpf
    
    @cpf.setter
    def cpf(self, cpf):
        if Cliente.validarCliente(self.__nome, cpf, self.__dependentes):
            self.__cpf = cpf

    @property
    def dependentes(self):
        return self.__dependentes
    
    @dependentes.setter
    def dependentes(self, dependentes):
        if Cliente.validarCliente(self.__nome, self.__cpf, dependentes):
            self.__dependentes = dependentes

    def addDependente(self, nome):

        if isinstance(nome, str):
            self.__dependentes.append(nome)

    def trocaNome(self, nome):

        if isinstance(nome, str):
            self.__nome = nome

    def ajustaCPF(cpf):

        if not isinstance(cpf, str) and not isinstance(cpf, int):
            return "000.000.000-00"

        if isinstance(cpf, int):
            cpf = f'{cpf}'

        if isinstance(cpf, str):

            while len(cpf) < 11:
                cpf = 0 + cpf
            
            if len(cpf) > 11:
                return "000.000.000-00"
            else:
                
                cpf = cpf[:3] + '.' + cpf[3:]
                cpf = cpf[:7] + '.' + cpf[7:]
                cpf = cpf[:11] + '-' + cpf[11:]

        return cpf;

    def trocaCPF(self, cpf):

        self.__cpf = Cliente.ajustaCPF(cpf)
