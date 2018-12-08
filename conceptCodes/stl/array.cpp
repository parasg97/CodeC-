

/*Array classes knows its own size, whereas C-style arrays lack this property.
 So when passing to functions, we don’t need to pass size of Array as a separate parameter.
With C-style array there is more risk of array being decayed into a pointer.
 Array classes don’t decay into pointers
Array classes are generally more efficient, light-weight and reliable than C-style arrays.*/

