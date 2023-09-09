import com.sun.imageio.plugins.common.BogusColorSpace;
import org.junit.Test;
import java.math.*;
import java.util.Random;

public class RSAClassLong {

    //扩展欧几里得算法   complete
    // gcd(a,b)=a*x+b*y
    // java无法传入指针
    // 这里使用数组模拟。    array[0]=x   array[1]=y
    // gcd(a,b)=a*array[0]+b*array[1]

    public static long exgcd(long a,long b,long[] array){
        long m=0;
        long n=1;
        //System.out.println("gcd("+a+","+b+")\n");
        //System.out.println("= "+a+"*"+array[0]+"+"+b+"*"+array[1]+"\n");
        while(b>0){
            long d=a/b;
            long t;

            t=m; m=array[0]-d*t; array[0]=t;
            t=n; n=array[1]-d*t; array[1]=t;
            t=a%b; a=b; b=t;
            //System.out.println("= "+a+"*"+array[0]+"+"+b+"*"+array[1]+"\n");
        }
        return a;
    }
    @Test
    public void testexgcd(){
        long a=4001,p=2689;
        long[] array={1,0};

        System.out.println(exgcd(a,p,array));
    }

    //计算乘法逆元   complete
    //  a*x ≡ 1 mod p   已知a、p，求x
    //  x放在array[0]进行输出
    public static long inv(long a,long p){
        long[] array={1,0};
        if(exgcd(a,p,array)==1){
            //System.out.println(array[0]+"  "+array[1]);
            array[0]%=p;
            return array[0]>=0 ? array[0]:array[0]+p;
        }
        else return -1;  //-1代表不存在对应的乘法逆元
    }
    @Test
    public void testinv(){
        long a = 49615;
        long b =4563;
        System.out.println(inv(a,b));
    }


    //快速积运算  complete
    // 计算 (a*b)%mod
    public static long qmul(long a,long b,long mod){
        long ans=0;
        while(b>0){
            if((b&1)==1){
                ans=(ans+a)%mod;
            }
            a=(a+a)%mod;
            b>>=1;
        }
        return ans;
    }
    //快速模幂算法   complete
    public static long qmod(long a,long p,long mod){
        long ans=1;
        a%=mod;
        while(p>0){
            if((p&1)==1){  //p为奇数，则需要拿出一个a，指数-1成为偶数后，再将指数右移一位
                ans=(ans*a)%mod;  //ans在整个计算过程中都会比mod小，不需要额外进行取模操作
            }
            a=(a*a)%mod;
            p>>=1;  //p右移一位
        }
        return ans;
    }
    @Test
    public void testqmod(){
        //long a=3,p=197,mod=101;
        long a=24801;
        long p=6249;
        long x=49993;
        System.out.println(x);
        System.out.println(qmod(a,p,x));
    }



    //大素数判断算法
    public static boolean millerRabin(long num){
        if(num==2) return true;
        else if(num<2 || (num&1)==0) return false;

        int judgeTime=100;  //随机挑100个数进行判定，可以定义判断的次数
        long m=num-1;
        long t=0;
        //计算 num-1=m*(2^t) 的m和t
        while((m&1)==0) {
            m >>= 1;
            t++;
        }

        for(int i=1;i<=judgeTime;i++){
            //[2,num-1]中的随机数a
            long a=(long)(Math.random()*(num-2)%num+2);
            //System.out.println(a);
            //计算 a^m % num
            long x=qmod(a,m,num),y=x;

            for(int j=0;j<t;j++){
                //y=qmul(x,x,num);  //计算(x*x)%num
                y=qmod(x,2,num);
                //不满足二次探测定理，也就是y==1了但是x并不等于1或者n-1，那么n就一定不是质数
                if(y==1 && x!=1 && x!=num-1){
                    return false;
                }
                x=y;
            }
            //子循环结束后，y仍不为1，则num不是素数
            if(x!=1) return false;
        }
        return true;
    }
    @Test
    public void testMR(){
        //System.out.println(millerRabin(219959));
        //System.out.println(commonJudge(49993));
        System.out.println(millerRabin(11));
    }

    public static void main(String[] args) {

        //随机生成两个素数p,q
        long p=(long)(Math.random()*100000L+2);
        long q=(long)(Math.random()*100000L+2);
        while(!millerRabin(p)){
            p=(long)(Math.random()*100000L+2);
        }
        while(!millerRabin(q)){
            q=(long)(Math.random()*100000L+2);
        }
        System.out.println("两个随机素数:"+"p="+p+" , q="+q);

        //计算n和ф(n)
        long n=p*q;
        long fn=(p-1)*(q-1);
        System.out.println("n="+n+" , ф(n)="+fn);

        //明文
        long m=(long)(Math.random()*n);
        System.out.println("明文:"+m);


        long e=(long)(Math.random()*(n-1)+1);
        while(exgcd(e,fn,new long[]{1,0})!=1){
            e=(long)(Math.random()*(n-1)+1);
        }
        System.out.println("e:"+e);

        //利用乘法逆元确定解密钥d
        long d=inv(e,fn);
        System.out.println("解密钥:"+d);
        //将明文m加密生成密文c
        long c=qmod(m,e,n);
        System.out.println("生成的密文c:"+c);
        //将密文c解密位明文m
        long ans=qmod(c,d,n);
        System.out.println("解密获取明文m:"+ans);
    }

}