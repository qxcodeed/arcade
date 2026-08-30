const input = () => ""; // MODO_TESTE
export {};

function get_men(vet: number[]): number[] {
    // @DROP
    let output: number[] = [];
    for (let elem of vet)
        if (elem > 0)
            output.push(elem);
    return output;
    // @UNC
    // return [];
}

function get_calm_women(vet: number[]): number[] {
    // @DROP
    return vet.filter(x => x < 0 && Math.abs(x) < 10);
    // @UNC
    // return [];
}

function sort(vet: number[]): number[] {
    // @DROP
    let aux = vet.slice(); //faz uma copia
    aux.sort((a, b) => a - b);
    return aux;
    // @UNC
    // return [];
}

function sort_stress(vet: number[]): number[] {
    // @DROP
    vet.sort((a, b) => Math.abs(a) - Math.abs(b));
    return vet;
    // @UNC
    // return [];
}

function reverse(vet: number[]): number[] {
    // @DROP
    let output: number[] = [];
    for (let elem of vet)
        output.unshift(elem);
    return output;
    // @UNC
    // return [];
}

function unique(vet: number[]): number[] {
    // @DROP
    let unique_list: number[] = [];
    for (let elem of vet)
        if (!unique_list.includes(elem))
            unique_list.push(elem);
    return unique_list;
    // @UNC
    // return [];
}

function repeated(vet: number[]): number[] {
    // @DROP
    let unique_list: number[] = [];
    let repeated: number[] = [];
    for (let elem of vet) {
        if (!unique_list.includes(elem))
            unique_list.push(elem);
        else
            repeated.push(elem);
    }
    return repeated;
    // @UNC
    // return [];
}

// @KEEP

function main() {
    let vet = new Array<string>();

    while (true) {
        let line = input();
        console.log("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")             { break;                                             }
        else if (args[0] === "get_men")         { console.log(fmt(get_men(       to_vet(args[1])))); }
        else if (args[0] === "get_calm_women")  { console.log(fmt(get_calm_women(to_vet(args[1])))); }
        else if (args[0] === "sort")            { console.log(fmt(sort(          to_vet(args[1])))); }
        else if (args[0] === "sort_stress")     { console.log(fmt(sort_stress(   to_vet(args[1])))); }
        else if (args[0] === "reverse")         {
            let vet = to_vet(args[1]);
            let reversed = reverse(vet);
            console.log(fmt(vet));
            console.log(fmt(reversed));
        }
        else if (args[0] === "unique")          { console.log(fmt(unique(        to_vet(args[1])))); }
        else if (args[0] === "repeated")        { console.log(fmt(repeated(      to_vet(args[1])))); }
        else                                    { console.log("fail: comando invalido");             }
    }
}

// Função auxiliar para converter de string para vetor
// "[1,2,3,4]" para [1, 2, 3, 4]
function to_vet(token: string): number[] {
    let size = token.length;
    let inside = token.substring(1, size - 1);
    return inside === "" ? [] : inside.split(",").map(x => +x)
}

//Converte de vetor para string sem inserir os espaços
//[1, 2, 3, 4] => "[1,2,3,4]"
function fmt(vet: number[]): string {
    if (vet == null) {
        return "[]";
    }
    return "[" + vet.join(", ") + "]";
}

main()
