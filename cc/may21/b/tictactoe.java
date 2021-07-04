import java.util.*;
import java.io.*;

class TCTCTOE{
    //SOLUTION BEGIN
    int[] pow3, state;
    void pre() throws Exception{
        pow3 = new int[10];
        pow3[0] = 1;
        for(int i = 1; i< pow3.length; i++)pow3[i] = pow3[i-1]*3;

        state = new int[pow3[9]];
        Arrays.fill(state, 3);
        //1 -> reachable and ended
        //2 -> reachable and going on
        //3 -> not reachable
        char[][] start = new char[][]{
            {'_', '_', '_'},
            {'_', '_', '_'},
            {'_', '_', '_'}
        };
        dfs(start, 'X');
    }
    void dfs(char[][] g, char turn){
        int id = encode(g);
        if(state[id] != 3)return;//This state is already processed
        if(ended(g)){
            state[id] = 1;
            return;
        }
        state[id] = 2;
        for(int i = 0; i< g.length; i++){
            for(int j = 0; j< g[i].length; j++){
                if(g[i][j] == '_'){
                    g[i][j] = turn;
                    dfs(g, (char)('X' + 'O'-turn));
                    g[i][j] = '_';
                }
            }
        }
    }
    void solve(int TC) throws Exception{
        char[][] grid = new char[3][];
        for(int i = 0; i< grid.length; i++)grid[i] = n().toCharArray();
        pn(state[encode(grid)]);
    }
    //Checks if the game is finished or not.
    boolean ended(char[][] g){
        boolean win = false;
        for(int i = 0; i< 3; i++){
            win |= g[i][0] != '_' && g[i][0] == g[i][1] && g[i][1] == g[i][2];
            win |= g[0][i] != '_' && g[0][i] == g[1][i] && g[1][i] == g[2][i];
        }
        win |= g[0][0] != '_' && g[0][0] == g[1][1] && g[1][1] == g[2][2];
        win |= g[0][2] != '_' && g[0][2] == g[1][1] && g[1][1] == g[2][0];

        boolean filled = true;
        for(char[] row:g)
            for(char cell:row)
                filled &= cell != '_';
        return win || filled;
    }
    int encode(char[][] g){
        int id = 0;
        for(int i = 0; i< g.length; i++)
            for(int j = 0; j< g[i].length; j++)
                id += pow3[i*3+j]*get(g[i][j]);
        return id;
    }
    int get(char ch){
        switch(ch){
            case '_':return 0;
            case 'X':return 1;
            case 'O':return 2;
            default: return -1;
        }
    }
    //SOLUTION END
    void hold(boolean b)throws Exception{if(!b)throw new Exception("Hold right there, Sparky!");}
    static boolean multipleTC = true;
    FastReader in;PrintWriter out;
    void run() throws Exception{
        in = new FastReader();
        out = new PrintWriter(System.out);
        //Solution Credits: Taranpreet Singh
        int T = (multipleTC)?ni():1;
        pre();for(int t = 1; t<= T; t++)solve(t);
        out.flush();
        out.close();
    }
    public static void main(String[] args) throws Exception{
        new TCTCTOE().run();
    }
    int bit(long n){return (n==0)?0:(1+bit(n&(n-1)));}
    void p(Object o){out.print(o);}
    void pn(Object o){out.println(o);}
    void pni(Object o){out.println(o);out.flush();}
    String n()throws Exception{return in.next();}
    String nln()throws Exception{return in.nextLine();}
    int ni()throws Exception{return Integer.parseInt(in.next());}
    long nl()throws Exception{return Long.parseLong(in.next());}
    double nd()throws Exception{return Double.parseDouble(in.next());}

    class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws Exception{
            br = new BufferedReader(new FileReader(s));
        }

        String next() throws Exception{
            while (st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (IOException  e){
                    throw new Exception(e.toString());
                }
            }
            return st.nextToken();
        }

        String nextLine() throws Exception{
            String str = "";
            try{
                str = br.readLine();
            }catch (IOException e){
                throw new Exception(e.toString());
            }
            return str;
        }
    }
}
