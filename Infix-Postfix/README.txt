This project is a program that converts an infix expression entered by the user into a postfix expression. The code utilizes a stack data structure to perform the conversion from infix to postfix. Operator priorities are taken into consideration during the process and are temporarily stored on the stack. Parentheses are also used to determine the order of operations.

The general workflow of the code is as follows:

1- Prompt the user to enter an infix expression.
2- Create a stack and a temporary array to construct the postfix expression.
3- Iterate through each character of the infix expression.
4- If the character is an opening parenthesis, push it onto the stack.
5- If the character is a closing parenthesis, pop all operators from the stack and append them to the postfix expression until an opening parenthesis is encountered.
6- If the character is an operand, directly append it to the postfix expression.
7- If the character is an operator, compare its priority with the operator at the top of the stack. If the top operator has higher or equal priority, pop it from the stack and append it to the postfix expression. Repeat this process until a lower priority operator is encountered or the stack is empty. Then push the current operator onto the stack.
8- Once all characters have been processed, append any remaining operators from the stack to the postfix expression.
9- Finally, display the postfix expression.
By converting the infix expression to postfix, this project provides convenience in evaluating mathematical expressions.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Bu proje, kullanıcıdan alınan infix ifadesini postfix ifadeye dönüştüren bir programdır.
Kod, bir stack (yığın) veri yapısı kullanarak infix ifadeyi postfix ifadeye dönüştürmektedir. İşleme sırasında operatörlerin öncelikleri dikkate alınır ve stack üzerinde geçici olarak tutulurlar. Parantezlerin işlem sırasını belirlemek için de kullanılırlar.

Kodun genel işleyişi şu şekildedir:

1- Kullanıcıdan infix ifade alınır.
2- Stack ve geçici bir dizi kullanılarak postfix ifade oluşturulur.
3- Infix ifadenin karakterleri tek tek kontrol edilir.
4- Eğer karakter bir açma parantezi ise, stack'e eklenir.
5- Eğer karakter bir kapama parantezi ise, stack'teki tüm operatörler açma parantezine kadar postfix ifadeye eklenir.
6- Eğer karakter bir operand ise, doğrudan postfix ifadeye eklenir.
7- Eğer karakter bir operatör ise, önceliği stack'teki en üstteki operatöre göre kontrol edilir. Daha düşük önceliğe sahip veya aynı önceliğe sahip operatörler postfix ifadeye eklenir.
8- İşlem tamamlandığında, stack'teki tüm operatörler postfix ifadeye eklenir.
9- Son olarak, postfix ifade ekrana yazdırılır.
Bu şekilde, infix ifade postfix ifadeye dönüştürülerek matematiksel ifadelerin değerlendirilmesinde kolaylık sağlanır.