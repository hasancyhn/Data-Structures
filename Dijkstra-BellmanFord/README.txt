This code aims to find the shortest path by using the Bellman-Ford and Dijkstra algorithms to open the files named "bellmanFordInput.txt" and "dijkstraInput.txt".

In summary, the code performs the following operations:

1- The struct node is used to represent an edge between two nodes.
2- Necessary variables and matrices are defined.
3- The bellmanFord function implements the Bellman-Ford algorithm. It determines the starting node, calculates the shortest path, and returns the result.
4- The extract_min function selects the node with the minimum distance.
5- The dijkstra function applies the Dijkstra algorithm. It determines the starting node, calculates the shortest path, and prints the result to the screen.
6- The main function presents a menu to the user within a loop. Depending on the selection of the Bellman-Ford or Dijkstra algorithm, it reads the corresponding file, performs the necessary calculations, and prints the result to the screen.
The code can be extended to include additional operations for step-by-step printing of the results, depending on the chosen algorithm and input file. However, it is stated that this feature is not fully implemented in the given code.
------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------
Bu kod, Bellman-Ford ve Dijkstra algoritmalarını kullanarak "bellmanFordInput.txt" ve "dijkstraInput.txt" adlı dosyaları açarak en kısa yolu bulmayı amaçlamaktadır.

Özetle, kod aşağıdaki işlemleri gerçekleştirir:

1- struct node yapısı, iki düğüm arasındaki kenarı temsil etmek için kullanılır.
2- Gerekli değişkenler ve matrisler tanımlanır.
3- bellmanFord fonksiyonu, Bellman-Ford algoritmasını uygular. Başlangıç düğümünü belirler, en kısa yolu hesaplar ve sonucu döndürür.
4- extract_min fonksiyonu, mesafesi en küçük olan düğümü seçer.
5- dijkstra fonksiyonu, Dijkstra algoritmasını uygular. Başlangıç düğümünü belirler, en kısa yolu hesaplar ve sonucu ekrana yazdırır.
6- main fonksiyonu, bir döngü içerisinde menüyü kullanıcıya sunar. Bellman-Ford veya Dijkstra algoritması seçimine göre ilgili dosyayı okur, gerekli hesaplamaları yapar ve sonucu ekrana yazdırır.
Kod, seçilen algoritma ve giriş dosyasına bağlı olarak en kısa yolu hesaplar ve sonuçları adım adım yazdırmak için ek işlemler yapılabilir. Ancak, bu özelliğin tam olarak uygulanmadığı belirtilmektedir.