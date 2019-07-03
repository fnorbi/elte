//import java.util.Scanner;
import mester.IO;

public class feladat{
    public static final int MAXN = 1000;

    public static class Fa{
        public int tav, mag;
        public Fa(int tav, int mag){
            this.tav = tav;
            this.mag = mag;
        }
    }

    public static void main(String[] args) throws Exception{
        //Scanner reader = new Scanner(System.in);
        IO io = new IO();

        //int n = reader.nextInt();
        int n = io.nextInt();

        Fa[] adatok = new Fa[MAXN];

        for(int i = 0; i < n; i++){
            //int tav = reader.nextInt();
            //int mag = reader.nextInt();
            int tav = io.nextInt();
            int mag = io.nextInt();
            adatok[i] = new Fa(tav, mag);
        }

        //reader.close();

        int db = 1; //kidöntendő fák száma, elsőt mindenképp ki kell
        int lastmaxindex = 0; //legtovább elérő kidöntött fa indexe
        int maxi = 0, maxe = 0; //a legtöbbet kidöntő fa indexe és maximum értéke
        int loki = 0, lokdb = 0; //a jelenleg vizsgált fa hányat dönt ki: addig növeljük míg dönti ki a fákat

        for (int i = 1; i < n; i++){
            int tav = adatok[i].tav - adatok[lastmaxindex].tav;
            //ha nem dől ki
            if(adatok[lastmaxindex].mag <= tav){
                db++;
                if(lokdb > maxe){
                    maxe = lokdb;
                    maxi = loki;
                }
                loki = i;
                lokdb = 0;
            }else{
                lokdb++;
            }
            
            //ha a mostani tovább elér
            if(adatok[i].mag > adatok[lastmaxindex].mag - tav){
                lastmaxindex = i;
            }
        }
        //utolsó fa is döntheti ki a legtöbbet
        if(lokdb > maxe){
            maxe = lokdb;
            maxi = loki;
        }

        //System.out.println(db);
        //System.out.println(maxi + 1);

        io.writeLn(db);
        io.writeLn(maxi + 1);
        io.close();

    }
}
