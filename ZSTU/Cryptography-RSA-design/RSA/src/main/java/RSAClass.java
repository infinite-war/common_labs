import com.sun.imageio.plugins.common.BogusColorSpace;
import org.junit.Test;
import java.math.*;
import java.util.Random;

public class RSAClass {

    // const
    static BigInteger zero = new BigInteger("0");
    static BigInteger one = new BigInteger("1");
    static BigInteger two = new BigInteger("2");


    //扩展欧几里得算法   complete
    // gcd(a,b)=a*x+b*y
    // java无法传入指针
    // 这里使用数组模拟。    array[0]=x   array[1]=y
    // gcd(a,b)=a*array[0]+b*array[1]

    public static BigInteger exgcd(BigInteger a,BigInteger b,BigInteger[] array){
        //if(a.compareTo(b)<0) return exgcd(b,a,array);
        //BigInteger m=0,n=1;
        BigInteger m=new BigInteger("0");
        BigInteger n=new BigInteger("1");
        //System.out.println("gcd("+a+","+b+")\n");
        //System.out.println("= "+a+"*"+array[0]+"+"+b+"*"+array[1]+"\n");
        while(b.compareTo(zero)>0){
            BigInteger d=a.divide(b);   //d=a/b
            BigInteger t;
            // =a*array[0]+b*array[1]

            t=m; m=array[0].add(d.negate().multiply(t)); array[0]=t;//t=m; m=array[0]-d*t; array[0]=t;
            t=n; n=array[1].add(d.negate().multiply(t)); array[1]=t;//t=n; n=array[1]-d*t; array[1]=t;
            t=a.mod(b); a=b; b=t;  // t=a%b; a=b; b=t
            //System.out.println("= "+a+"*"+array[0]+"+"+b+"*"+array[1]+"\n");
        }
        return a;
    }
    @Test
    public void testexgcd(){
        BigInteger a=new BigInteger("4001"),p=new BigInteger("2689");
        BigInteger[] array={new BigInteger("1"),new BigInteger("0")};

        System.out.println(exgcd(a,p,array));
    }

    //计算乘法逆元   complete
    //  a*x mod p=1   已知a、p，求x
    //  x放在array[0]进行输出
    public static BigInteger inv(BigInteger a,BigInteger p){
        BigInteger[] array={new BigInteger("1"),new BigInteger("0")};
        if(exgcd(a,p,array).equals(one)){
            //System.out.println(array[0]+"  "+array[1]);
            array[0]=array[0].mod(p);  //array[0]%=p;
            return array[0].compareTo(zero)>0?array[0]:array[0].add(p);//return array[0]>=0 ? array[0]:array[0]+p;
        }
        else return new BigInteger("-1");  //-1代表不存在对应的乘法逆元
    }
    @Test
    public void testinv(){
//        BigInteger a=new BigInteger("3");
//        BigInteger b = new BigInteger("11");
        BigInteger a=new BigInteger("49615");
        BigInteger b = new BigInteger("4563");
        System.out.println(inv(a,b));
    }


    //快速积运算  complete
    // 计算 (a*b)%mod
    public static BigInteger qmul(BigInteger a,BigInteger b,BigInteger mod){
        BigInteger ans=new BigInteger("0");
        while(b.compareTo(zero)>0){
            if(b.and(one).equals(one)){    //if((b&1)==1)
                ans=ans.add(a).mod(mod);   //ans=(ans+a)%mod;
            }
            a=a.add(a).mod(mod);           //a=(a+a)%mod;
            b=b.shiftRight(1);             //b>>=1;
        }
        return ans;
    }
    //快速模幂算法   complete
    public static BigInteger qmod(BigInteger a,BigInteger p,BigInteger mod){
        BigInteger ans=new BigInteger("1");
        a=a.mod(mod); //a%=mod;
        while(p.compareTo(zero)>0){         //p>0
            if(p.and(one).equals(one)){  //p为奇数，则需要拿出一个a，指数-1成为偶数后，再将指数右移一位
                ans=ans.multiply(a).mod(mod); //ans=(ans*a)%mod;  ans在整个计算过程中都会比mod小，不需要额外进行取模操作
            }
            a=a.multiply(a).mod(mod);  //a=(a*a)%mod;
            p=p.shiftRight(1);         //p>>=1;  p右移一位
        }
        return ans;
    }
    @Test
    public void testqmod(){
        //BigInteger a=3,p=197,mod=101;
        BigInteger a=new BigInteger("24801");
        BigInteger p=new BigInteger("6249");
        BigInteger x=new BigInteger("49993");
        System.out.println(x);
        System.out.println(qmod(a,p,x));
    }



    //大素数判断算法
    public static boolean millerRabin(BigInteger num){
        if(num.equals(two)) return true;    // num==2
        else if(num.compareTo(two)<0 || num.and(one).equals(zero)) return false;  //(num<2 || (num&1)==0

        int judgeTime=10;  //随机挑10个数进行判定，可以定义判断的次数
        BigInteger m=num.add(one);   //m=num-1;
        BigInteger t=zero;
        //计算 num-1=m*(2^t) 的m和t
        while(m.and(one).equals(zero)){     // m&1==0
            m=m.shiftRight(1);  //m>>=1;
            t=t.add(one);   //t++
        }

        int numLen=num.add(one.negate()).shiftRight(1).bitLength();
        for(int i=1;i<=judgeTime;i++){
            //[2,num-1]中的随机数a
            //BigInteger a=(BigInteger)(Math.random().(num.add(two.negate())).add(two));
            BigInteger a=new BigInteger((i-1)%numLen+1,new Random());
            //System.out.println(a);
            //计算 a^m % num
            BigInteger x=qmod(a,m,num),y=x;

            for(int j=0;j<t.intValue();j++){
                //y=qmul(x,x,num);  //计算(x*x)%num
                y=qmod(x,two,num);
                //不满足二次探测定理，也就是y==1了但是x并不等于1或者n-1，那么n就一定不是质数
                if(y.equals(one) && !x.equals(one) && !x.equals(num.add(one.negate()))){   //y==1 && x!=1 && x!=num-1
                    return false;
                }
                x=y;
            }
            //子循环结束后，y仍不为1，则num不是素数
            if(!x.equals(one)) return false;   //x!=1
        }
        return true;
    }

//    public boolean commonJudge(BigInteger num){
//        if(num.equals(two) || num.equals(two.add(one))) return true;   //num==2 || num==3
//        else if(num.compareTo(two)<0 || num.and(one).equals(zero)) return false;   //num<2 || (num&1)==0
//
//        for(BigInteger i=3;i<=Math.sqrt(num);i+=2){
//            if(num%i==0) return false;
//        }
//        return true;
//    }
    @Test
    public void testMR(){
        System.out.println(millerRabin(new BigInteger("219959")));
        //System.out.println(commonJudge(49993));
    }



    public static void main(String[] args) {

        //随机生成两个素数p,q。

        int SIZE=200;
        BigInteger p = new BigInteger(SIZE, 15, new Random());
        //System.out.println(p.isProbablePrime(15));
        BigInteger q = new BigInteger(SIZE, 15, new Random());

        System.out.println("两个随机素数:"+"\n  p="+p+"\n  q="+q);

        //计算n和ф(n)
        BigInteger n=p.multiply(q); //n=p*q;
        BigInteger fn=(p.add(one.negate())).multiply(q.add(one.negate()));//fn=(p-1)*(q-1);
        System.out.println("n="+n+" \n ф(n)="+fn);

        //明文m  m<n
        //long m=(long)(Math.random()*n);
        BigInteger m= new BigInteger(SIZE-1, 1, new Random());
        System.out.println("明文m:"+m);

        //long e=(long)(Math.random()*(n-1)+1);
        BigInteger e;
        do {
            e = new BigInteger(2 * SIZE, new Random());
        } while ((e.compareTo(fn) != 1)
                || (e.gcd(fn).compareTo(BigInteger.valueOf(1)) != 0));

        //利用乘法逆元确定解密钥d
        BigInteger d=inv(e,fn);
        System.out.println("解密钥d:"+d);
        //将明文m加密生成密文c
        BigInteger c=qmod(m,e,n);
        System.out.println("生成的密文c:"+c);
        //将密文c解密位明文m
        BigInteger ans=qmod(c,d,n);
        System.out.println("解密获取明文ans:"+ans);
    }
}
