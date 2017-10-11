first = "Brandon";
last = "Hartford";
print(first.." "..last);

function Increment(a,b);
	return a+1,b+1;
end

a,b = Increment(12,30);

print(a,b);

while a > 2 do
	a = a - 1;
	if a == 5 then
		print("Fuck it all");
	else
		print(a);
	end;
end;

print("end of while loop");

for a = 10,15,2 do
	print(a);
end;

print("Size of string ", #first, "\n");

longString  = [[ I love
to eat 
poop]];

print(longString, "\n");
print(first);

isAbleToDrive = true;

print(type(isAbleToDribble));




