fun member (e, nil) = false
|  member (e, x::xs) = 
    if (e=x) then true
    else member(e, xs);

fun split (pivot, nil) = (nil, nil)
| split (pivot, x::xs) =
      let  
         val (smaller, bigger) = split (pivot, xs) 
      in
          if x < pivot then (x::smaller, bigger) 
                 else (smaller, x::bigger)
      end;
