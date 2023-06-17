from encoding import Encoder
from math import log2

class HuffmanTree:
    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right

    def children(self):
        return self.left, self.right

    def nodes(self):
        return self.left, self.right

    def __repr__(self):
        return '%s_%s' % (self.left, self.right)

def huffman_coding(node, left=True, digit=''):
    """
    1. En düsük frekansa sahip iki sembol bulunur (yaprak).
    2. Bunlardan birisine 0 birisine 1 atanir.
    3. Bu iki sembol birlestirilerek kök dügüm olusturulur.
    4. Bu dongu bu sekilde devam eder.
    """
    if type(node) is str:
        return {node: digit}

    (l, r) = node.children()
    huffman_code = {}
    huffman_code.update(huffman_coding(l, True, digit + '0'))
    huffman_code.update(huffman_coding(r, False, digit + '1'))

    return huffman_code

def code_statistics(frekans, uzunluk, kodUzunlugu):
    olasilik = [float("{:.3f}".format(frequency[1] / uzunluk))
                     for frequency in frekans]
    olasilik = sorted(olasilik, reverse=True)

    ortUzunluk = sum(
        [a * b for a, b in zip(kodUzunlugu, olasilik)])

    entropy = -1 * sum([a * log2(a) for a in olasilik])
    print("Ortalama Kod Kelime Uzunlugu: {:.3f}".format(ortUzunluk))

    try:
        print("Verimlilik: {:.3f}".format(entropy / ortUzunluk))
    except ZeroDivisionError:
        return


def main():
    # Kelime girisi ve uzunluhu hesaplanir.
    symbols = input("Lutfen Kelime Giriniz: ")
    uzunluk = len(symbols)
    # Hicbir sey girilmezse program durdurulur.
    if uzunluk == 0:
        print("Yanlis Veri Girisi. Lutfen Tekrar Deneyiniz!")
        return

    frekans = {}

    for symbol in symbols:
        if symbol in frekans:
            frekans[symbol] += 1
        else:
            frekans[symbol] = 1
    # Harflerin (sembollerin) frekansi yuksekten dusuge dogru siralanir.
    frekans = sorted(frekans.items(),
                         key=lambda x: x[1], reverse=True)

    nodes = frekans
    while len(nodes) > 1:
        (key1, val1) = nodes[-1]
        (key2, val2) = nodes[-2]
        nodes = nodes[:-2]
        node = HuffmanTree(key1, key2)
        nodes.append((node, val1 + val2))

        nodes = sorted(nodes, key=lambda x: x[1], reverse=True)

    code = huffman_coding(nodes[0][0])
    kodUzunlugu = []

    print(' Harf (Sembol) | Binary     ')
    print('-----------------------')
    for (char, frequency) in frekans:
        print(' %-4r          |%6s' % (char, code[char]))
        kodUzunlugu.append(len(code[char]))

    code_statistics(frekans, uzunluk, kodUzunlugu)

    encoder = Encoder()
    symbols = symbols.lower()
    encoded_message, encoding_table = encoder.encode_message(symbols)

    print("Sifrelenmis Mesaj: ", end=" ")
    print(encoded_message)

if __name__ == '__main__':
    main()