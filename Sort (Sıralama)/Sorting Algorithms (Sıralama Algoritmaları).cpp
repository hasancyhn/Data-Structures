void selectionSort(int * gelenDizi,int diziBoyut){
    int i, j, temp;

    for (i=0; i<diziBoyut-1; i++){
        for (j=i+1; j<diziBoyut; j++){
            if (gelenDizi[i] > gelenDizi[j]){
                temp = gelenDizi[j];
                gelenDizi[j] = gelenDizi[i];
                gelenDizi[i] = temp;
            }
        }
    }
//   return gelendizi;
}

void insertionSort(int * gelenDizi, int diziBoyut){
    int i, index, temp;
    
    for (i = 1 ; i < diziBoyut; i++){
        index = i;
        while ( index > 0 && gelenDizi[index] < gelenDizi[index-1]){
            temp = gelenDizi[index];
            gelenDizi[index]   = gelenDizi[index-1];
            gelenDizi[index-1] = temp;
            index--;
        }
    }
}

void bubbleSort(int * gelenDizi, int diziBoyut){
    int temp, i, j;
    
    for (i=1; i<diziBoyut; i++){
        for (j=0; j<diziBoyut-i; j++){
            if(gelenDizi[j] > gelenDizi[j+1]){
                temp = gelenDizi [j];
                gelenDizi [j]   = gelenDizi [j+1];
                gelenDizi [j+1] = temp;
            }
        }
    }
}


void quickSort(int gelenDizi[],int sol, int sag){
    int solIndex, sagIndex, orta, temp, i;

    solIndex = sol;
    sagIndex = sag;
    orta = gelenDizi[(sol+sag)/2];
    do{
    	//pivotun solunda, pivottan buyuk ilk elemana ulasilincaya kadar
        while (gelenDizi[solIndex]<orta && solIndex<sag)
            solIndex++;
        //pivotun saginda, pivottan kucuk ilk elemana ulasilincaya kadar
        while (orta < gelenDizi[sagIndex] && sagIndex > sol)
            sagIndex--;
        //pivotun sag ve solundaki elemanlari yer degistir
        if (solIndex <= sagIndex){
            temp = gelenDizi[solIndex];
            gelenDizi[solIndex] = gelenDizi[sagIndex];
            gelenDizi[sagIndex] = temp;
            solIndex++;
            sagIndex--;
            printf("\n");
            for (i=0;i<8;i++)
                printf("%d, ", gelenDizi[i]);
                printf("\n");
        }
    }
    while (solIndex <= sagIndex);

    if (sol < sagIndex) quickSort(gelenDizi, sol, sagIndex);
    if (solIndex < sag) quickSort(gelenDizi, solIndex, sag);
}




void MergeSort(int *array, int left, int right){
        int mid = (left + right) / 2;
        int * dizi;
        if(left < right){
            MergeSort(array, left, mid);
            MergeSort(array, mid+1, right);
            dizi = Merge(array, left, mid, right);
        }
}

void Merge(int *array, int left, int mid, int right){
        int tempArray[right-left+1];
        int pos=0, lpos = left,rpos = mid + 1;
        while(lpos <= mid && rpos <= right){
            if(array[lpos] < array[rpos]){
                tempArray[pos++] = array[lpos++];
            }
            else{
                tempArray[pos++] = array[rpos++];
            }
        }
        while(lpos <= mid)   tempArray[pos++] = array[lpos++];
        while(rpos <= right) tempArray[pos++] = array[rpos++];
        int iter;
        for(iter = 0; iter < pos; iter++){
            array[iter+left] = tempArray[iter];
        }
}

