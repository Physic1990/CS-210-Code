fun sq n = n * n;

fun sqsum nil = 0
 |sqsum(first::rest)=sq(first)+sqsum(rest);

fun cycle (nil,_) = nil
 |cycle(L,0) = L
 |cycle(first::rest,x)=cycle(rest@[first],x-1);

fun semrev (nil,_) = nil
 |semrev(L,0) = L
 |semrev(first::rest,x)=semrev(rest,x-1)@[first];
