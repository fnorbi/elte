Program fadontes;

const MAXN = 1000;

Type fa = Record
    tav, mag: integer;
	end;

Var
	n: integer;
	adatok: array[0..MAXN-1] of fa;
	db, lastmaxindex, maxi, maxe, loki, lokdb, tav, i: integer;

Begin

    Readln(n);

    for i := 0 to n-1 do
	Begin
		Readln(adatok[i].tav, adatok[i].mag);
	End;

    db := 1; //kidöntendő fák száma, elsőt mindenképp ki kell
    lastmaxindex := 0; //legtovább elérő kidöntött fa indexe
    maxi := 0; maxe := 0; //a legtöbbet kidöntő fa indexe és maximum értéke
    loki := 0; lokdb := 0; //a jelenleg vizsgált fa hányat dönt ki: addig növeljük míg dönti ki a fákat

	for i := 1 to n-1 do
	Begin
		tav := adatok[i].tav - adatok[lastmaxindex].tav;
		//ha nem dől ki
        if(adatok[lastmaxindex].mag <= tav) then
		Begin
			inc(db);
			if(lokdb > maxe) then
			Begin
				maxe := lokdb;
				maxi := loki;
			End;
			loki := i;
			lokdb := 0;
			
		End
        else
        Begin
			inc(lokdb);
		End;
        
        //ha a mostani tovább elér
        if(adatok[i].mag > adatok[lastmaxindex].mag - tav) then
        Begin
            lastmaxindex := i;
        End;
	End;

    //utolsó fa is döntheti ki a legtöbbet
    if(lokdb > maxe) then
    Begin
        maxe := lokdb;
        maxi := loki;
    End;

	Writeln(db);
	Writeln(maxi + 1);

End.