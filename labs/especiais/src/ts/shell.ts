//retorna um vetor de pares
function occurr(vet: number[]): number[][] {
    // @DROP
    let m = new Map<number, number>();
    for (let elem of vet) {
        let value = Math.abs(elem);
        if (m.has(value)) {
            m.set(value, m.get(value)! + 1);
        } else {
            m.set(value, 1);
        }
    }
    return Array.from(m.entries()).sort();
    // @UNC
    //return [];
}

//retorna um vetor de pares
function teams(vet: number[]): number[][] {
    // @DROP
    let size = vet.length;
    if (size == 0)
        return []; 
    let output: number[][] = [];

    output.push([vet[0], 1]);
    for (let elem of vet.slice(1)) {
        let [key, value] = output.pop()!;
        
        if (key == elem) {
            output.push([key, value + 1]);
        } else {
            output.push([key, value]);
            output.push([elem, 1]);
        }
    }
    return output;
    // @UNC
    //return [];
}

function mnext(vet: number[]): number[] {
    // @DROP
    let size = vet.length;
    let has_woman = (index: number) => index >= 0 && index < size && vet[index] < 0;
    let output: number[] = [];
    for (let i = 0; i < size; i++) {
        if (vet[i] > 0 && (has_woman(i - 1) || has_woman(i + 1))) {
            output.push(1);
        } else {
            output.push(0);
        }
    }
    return output;
    // @UNC
    //return [];
}

function alone(vet: number[]): number[] {
    // @DROP
    let size = vet.length;
    let has_woman = (index) => index >= 0 && index < size && vet[index] < 0;
    let output: number[] = [];
    for (let i = 0; i < size; i++) {
        if (vet[i] > 0 && (!has_woman(i - 1) && !has_woman(i + 1))) {
            output.push(1);
        } else {
            output.push(0);
        }
    }
    return output;
    // @UNC
    //return [];
}

function couple(vet: number[]): number {
    // @DROP
    let qtd = 0;
    let size = vet.length;
    for (let i = 0; i < size; i++) {
        for (let j = i + 1; j < size; j++) {
            if (vet[i] != 0 && vet[j] != 0 && vet[j] && vet[i] == -vet[j]) {
                vet[i] = 0;
                vet[j] = 0;
                qtd++;
            }
        }
    }
    return qtd;
    // @UNC
    //return 0;
}

function has_subseq(vet: number[], seq: number[], pos: number): boolean {
    // @DROP
    for (let i = 0; i < seq.length; i++)
        if (pos + i >= vet.length || vet[pos + i] != seq[i])
            return false;
    return true;
    // @UNC
    //return true;
}

function subseq(vet: number[], seq: number[]) {
    // @DROP
    let vet_size = vet.length;
    for (let i = 0; i < vet_size; i++)
        if (has_subseq(vet, seq, i))
            return i;
    return -1;
    // @UNC
    //return 0;
}

function erase(vet: number[], pos_list: number[]): number[] {
    // @DROP
    let output: number[] = [];
    for (let i = 0; i < vet.length; i++)
        if (pos_list.indexOf(i) == -1)
            output.push(vet[i]);
    return output;
    // @UNC
    //return [];
}

function clear(vet: number[], value: number): number[] {
    // @DROP
    let output: number[] = [];
    for (let elem of vet)
        if (elem != value)
            output.push(elem);
    return output;
    // @UNC
    //return [];
}

// @KEEP

const input = () => ""; 
export {};

function main() {
    while (true) {
        let line = input();
        console.log("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   {
            break; 
        }
        else if (args[0] === "occurr") {
            console.log(fmtpair(occurr(to_vet(args[1]))));
        }
        else if (args[0] === "teams") {
            console.log(fmtpair(teams(to_vet(args[1]))));
        }
        else if (args[0] === "mnext") {
            console.log(fmt(mnext(to_vet(args[1]))));
        }
        else if (args[0] === "alone") {
            console.log(fmt(alone(to_vet(args[1]))));
        }
        else if (args[0] === "couple") {
            console.log(couple(to_vet(args[1])));
        }
        else if (args[0] === "subseq") {
            console.log(subseq(to_vet(args[1]), to_vet(args[2])));
        }
        else if (args[0] === "erase") {
            console.log(fmt(erase(to_vet(args[1]), to_vet(args[2]))));
        }
        else if (args[0] === "clear") {
            console.log(fmt(clear(to_vet(args[1]), +args[2])));
        }
        else {
            console.log("Comando invalido");
        }
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
function fmt(vet: any[]): string {
    return "[" + vet?.join(", ") + "]";
}

function fmtpair(vet: number[][]): string {
    return fmt(vet?.map((x: number[]) => {
        let [key, value] = x;
        return "(" + key + ", " + value + ")";
    }));
}


main()
