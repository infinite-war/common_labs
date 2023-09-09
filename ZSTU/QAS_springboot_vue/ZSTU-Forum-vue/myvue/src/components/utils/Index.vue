<template>

  <el-container class="home-contaner">
    <!--    //头部-->
    <el-header>
      <div>
        <a href="/">
          <el-image :src="require('../../assets/zstu-logo.png')" style="height: 100%">
          </el-image>
        </a>
      </div>
      <div>

       <el-menu  class="el-menu-demo"
                 mode="horizontal"
                 @select="handleSelect"
                 background-color="#102f6d" text-color="#fff"
                 active-text-color="#ffd04b"
                 :router="true">

          <el-menu-item index="/welcome">首页</el-menu-item>
          <el-submenu index="2">
            <template slot="title">帖子</template>
            <el-menu-item index="/releasepost">发布新帖</el-menu-item>
            <el-menu-item v-for="item in this.$store.state.homepageClass"
                          :key="item.typeId"
                          @click="chooseItem(item.typeId)"
            >
              {{item.home}}
            </el-menu-item>
          </el-submenu>
          <el-menu-item index="/userProfile" >个人信息</el-menu-item>
          <el-menu-item v-if="isAdmin === true" index="adminProfile">后台管理</el-menu-item>
       </el-menu>
      </div>
      <!--      点击登录则跳转到登录页面-->
      <div>
        <el-button v-if="ifIdNotExisted === true"  @click="login" class="Login">
          <p style="color: #ffffff;">登录</p>
        </el-button>
        <el-button v-else-if="ifIdNotExisted === false"  @click="logout">
          <p style="color: #ffffff">退出</p>
        </el-button>
      </div>

    </el-header>

    <el-container>
<!--&lt;!&ndash;            取消侧边栏&ndash;&gt;-->
<!--&lt;!&ndash;      //侧边栏&ndash;&gt;-->
<!--            <el-aside width="200px"  v-if="adminProfileJudge">-->
<!--              <el-col :span="20">-->

<!--                <el-menu-->
<!--                  default-active="2"-->
<!--                  class="el-menu-vertical-demo"-->
<!--                  @open="handleOpen"-->
<!--                  @close="handleClose"-->
<!--                  background-color="Transparent"-->
<!--                  text-color="#000000"-->
<!--                  active-text-color="T#67C23A"-->

<!--                  :router="true">-->
<!--                &lt;!&ndash;侧边栏以index属性路由跳转&ndash;&gt;-->
<!--                  <el-menu-item index="1" >-->
<!--                    <i class="el-icon-document"></i>-->
<!--                    <span slot="title">用户管理</span>-->
<!--                  </el-menu-item>-->

<!--&lt;!&ndash;                  <el-submenu index="1">&ndash;&gt;-->
<!--&lt;!&ndash;                    <template slot="title">&ndash;&gt;-->
<!--&lt;!&ndash;                      <i class="el-icon-location"></i>&ndash;&gt;-->
<!--&lt;!&ndash;                      <span>用户管理</span>&ndash;&gt;-->
<!--&lt;!&ndash;                    </template>&ndash;&gt;-->
<!--&lt;!&ndash;                    <el-menu-item-group>&ndash;&gt;-->
<!--&lt;!&ndash;                      <el-menu-item index="1-1">选项1</el-menu-item>&ndash;&gt;-->
<!--&lt;!&ndash;                      <el-menu-item index="1-2">选项2</el-menu-item>&ndash;&gt;-->
<!--&lt;!&ndash;                      <el-menu-item index="1-3">选项3</el-menu-item>&ndash;&gt;-->
<!--&lt;!&ndash;                      <el-menu-item index="1-4">选项4</el-menu-item>&ndash;&gt;-->

<!--&lt;!&ndash;                    </el-menu-item-group>&ndash;&gt;-->
<!--&lt;!&ndash;                  </el-submenu>&ndash;&gt;-->

<!--                  <el-menu-item index="2" >-->
<!--                    <i class="el-icon-document"></i>-->
<!--                    <span slot="title">文章管理</span>-->
<!--                  </el-menu-item>-->

<!--                </el-menu>-->

<!--              </el-col></el-aside>-->



<!--            //主页面-->
      <el-main>
        <!--    调用LoadingIcon预加载-->
        <!--        路由占位符-->
        <!--        渲染主页面-->

        <LoadingIcon v-if="loading"></LoadingIcon>
        <router-view v-else></router-view>

      </el-main>

    </el-container>

    <GoTop></GoTop>
  </el-container>

</template>

<script>
import GoTop from "./GoTop";
import LoadingIcon from "./LoadingIcon";
export default {
  data() {
    return {
      ifIdNotExisted: false,
      isAdmin: false,
      loading: false
    }
  },
  components: {
    GoTop,
    LoadingIcon
  },
  name: "Home",
  methods: {
    login() {
      this.$router.push('/login')
    },
    chooseItem(id) {
      this.$router.push('/homepageone?typeId=' + id + '&page=1');
      setTimeout(function () {
        window.location.reload();
      }, 100);
    },
    //每次刷新页面时就调用islogin，服务器便发送用户id
    islogin() {
      const self = this
      self.$axios({
        method: "get",
        //url一律要再次修改
        url: "/user"
      })
        .then(result => {         //存储用户nickname
          if (result.data.flag === true) {
            this.loading = false
            this.$store.commit("saveLocalid", result.data.data.userId)
            this.$store.commit("saveNickname", result.data.data.nickname)
            this.$store.commit("saveRole", result.data.data.role==="1")
            this.isAdmin=(result.data.data.role==="1")
            this.ifIdNotExisted = false;
          } else {
            // alert("index页面的islogin执行失败")
            // alert(result.data)
            //alert(result.data.message)
          }
          //alert(result.data.id)
        })
    },
    //退出向服务器发送请求，成功则将用户在本地信息删除
    logout() {
      const self = this;
      //清空userid，nickname，token这些可以和后端交互的基本信息
      this.$store.commit("saveLocalid", '')
      this.$store.commit("saveNickname", '')
      this.$store.commit("saveToken", '')
      this.ifIdNotExisted = true;
      this.isAdmin=false;
      window.localStorage.removeItem("");
      this.$notify.success('退出账号成功')
      //console.log(res)
      this.$router.push('/welcome');
    },
    chooseIfNotExisted() {
      // alert(this.$store.state.localid)
      this.ifIdNotExisted = (this.$store.state.token === '' || this.$store.state.token === null);
    },
  },

  //每次刷新页面调用islogin确认登录状态
  created() {
    //防止刷新页面时localid丢失
    if (sessionStorage.getItem("store")) {
      this.$store.replaceState(
        Object.assign(
          {},
          this.$store.state,
          JSON.parse(sessionStorage.getItem("store"))
        )
      );
      sessionStorage.removeItem("store")
    }

    //在页面刷新时将vuex里的信息保存到sessionStorage里
    window.addEventListener("beforeunload", () => {
      sessionStorage.setItem("store", JSON.stringify(this.$store.state));
    });

    //!!注意先调用index的created，再调用welcome的created，先父后子
    //若是刷新页面的话，这个页面的localid就没了，而且vue无论如何都先执行 this.chooseIfNotExisted()，虽然我用islogin修改localid，
    //但并不能同步刷新登录按钮，表明vue先渲染组件再执行发送信息的函数。只要用户不自动刷新页面，就没事

    this.chooseIfNotExisted()
    this.islogin()
  },

  computed:{
    adminProfileJudge:function(){
      const curRoute = window.location.href;
      const sArray = curRoute.split('/');
      return sArray[sArray.length-1].substr(0,5) === 'admin';
    }
  }
}

</script>

<style scoped>
.el-main{
  padding: 0;
}
.el-header{
  background-color: #102f6d;

  display: flex;
  justify-content: space-between;
  color: antiquewhite;
  font-size: 20px;
}
.el-aside{
  width: 150px;
  background-color: #FFFFFF;
}
.el-main{
  background-color: #FFFFFF;
}
.home-contaner{
  height: 100%;
}
.el-button{
  background: #102f6d;
  width: 100px;
  border: none;
  font-size: 15px;
  text-align:center;
  font-family:"宋体"

}
#buttonIN{
  left: 80%;
}
.Login{
  width: 100px;
  height: 100%;
  text-align: match-parent;
}

/*.el-menu{*/
/*  width: 100px;*/
/*}*/
/*.el-menu-item{*/
/*  width: 100px;*/
/*}*/
/*.el-submenu{*/
/*  background-color: Transparent;*/
/*}*/
/*.el-menu-item{*/
/*  background-color: Transparent;*/
/*}*/
</style>

