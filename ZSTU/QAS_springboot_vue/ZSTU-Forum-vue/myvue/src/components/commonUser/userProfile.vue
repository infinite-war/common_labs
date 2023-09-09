<template>
  <div style="background-color:#FCFCFC;font-family:'宋体';height:100%;">
    <div>
      <my-bread level1='个人中心' level2='修改密码' :level3="levelName"></my-bread>
    </div>
    <div style="margin-top:25px;margin-left:80px;">
      <el-row :gutter="10">
        <el-col :span="2">
          <div style="background-color:#FFEBCD;width:60px;height:60px;display:inline-block;border-radius:50%;overflow:hidden;">
            <el-image :src="src" style="width:60px;height:60px;"></el-image>
          </div>
          <div style="margin-top:5px;margin-left:6px;"><span>{{formLabelAlign.realName}}</span></div>
          <div style="margin-top:50px;margin-left:1px;"><el-button style="font-size:15px;color:#4D4D4D;"  @click="infomationClick()">个人信息<span style="color:#B0E0E6;" v-show="infomationShow" class="el-icon-s-promotion"></span></el-button></div>
          <div style="margin-top:50px;margin-left:1px;"><el-button style="font-size:15px;color:#4D4D4D;"  @click="passwordClick()">修改密码<span style="color:#B0E0E6;" v-show="passwordShow" class="el-icon-s-promotion"></span></el-button></div>
          <div style="margin-top:50px;margin-left:1px;"><el-button style="font-size:15px;color:#4D4D4D;"  @click="infoChangeClick()">修改信息<span style="color:#B0E0E6;" v-show="infoChangeShow" class="el-icon-s-promotion"></span></el-button></div>
        </el-col>

        <el-col :span="21">
          <el-row :gutter="10" style="margin-top:20px;">
            <el-col :span="2"><div style="text-align:right;"><span>ID：</span></div></el-col>
            <el-col :span="2">{{formLabelAlign.id}}</el-col>
          </el-row>
          <!-- 个人信息 -->
          <el-row v-show="infomationShow">
            <el-card style="margin-top: 30px; margin-left: 70px;">
              <el-row>
                <el-col :span="10">
                  <el-row :gutter="12" style="margin-top:20px;">
                    <el-col :span="8"><div style="text-align:left;"><span>用户名：</span></div></el-col>
                    <el-col :span="10">{{formLabelAlign.nickName}}</el-col>
                  </el-row>

                  <el-row :gutter="12" style="margin-top:20px;">
                    <el-col :span="8"><div style="text-align:left;"><span>性别：</span></div></el-col>
                    <el-col :span="10">
                      <div v-if="formLabelAlign.gender===1">女</div>
                      <div v-else>男</div>
                    </el-col>
                  </el-row>

                  <el-row :gutter="12" style="margin-top:30px;">
                    <el-col :span="8"><div style="text-align:left;"><span>论坛等级：{{formLabelAlign.level}}</span></div></el-col>
                    <el-col :span="8">发帖数：{{formLabelAlign.published}}</el-col>
                    <el-col :span="8">获赞数：{{formLabelAlign.likes}}</el-col>
                  </el-row>

                  <el-row :gutter="12" style="margin-top:30px;">
                    <el-col :span="8"><div style="text-align:left;"><span>学院：</span></div></el-col>
                    <el-col :span="8">{{formLabelAlign.college}}</el-col>
                  </el-row>

                  <el-row :gutter="12" style="margin-top:30px;">
                    <el-col :span="8"><div style="text-align:left;"><span>手机号：</span></div></el-col>
                    <el-col :span="8">{{formLabelAlign.phoneNumber}}</el-col>
                  </el-row>
                  <el-row :gutter="12" style="margin-top:30px;">
                    <el-col :span="8"><div style="text-align:left;"><span>电子邮箱：</span></div></el-col>
                    <el-col :span="8">{{formLabelAlign.email}}</el-col>
                  </el-row>
                  <el-row :gutter="12" style="margin-top:30px;">
                    <el-col :span="8"><div style="text-align:left;"><span>生日：</span></div></el-col>
                    <el-col :span="8">{{formLabelAlign.birthday}}</el-col>
                  </el-row>
                  <el-row :gutter="12" style="margin-top:30px;">
                    <el-col :span="8"><div style="text-align:left;"><span>介绍：</span></div></el-col>
                    <el-col :span="8">{{formLabelAlign.introduction}}</el-col>
                  </el-row>
                </el-col>

              </el-row>
            </el-card>
          </el-row>
          <!-- 修改密码 -->
          <el-row v-show="passwordShow">
            <el-card style="margin-top: 30px; margin-left: 50px">
              <el-form :model="personalForm">
                <el-row :gutter="12" style="margin-top:20px;">
                  <el-col :span="6">
                    <div style="text-align:right;"><span>账号：</span></div>
                  </el-col>
                  <el-col :span="5">
                    <el-form-item prop="account">
                      <el-input type="text" v-model="personalForm.account" placeholder="请输入您的账号" ></el-input>
                    </el-form-item>
                  </el-col>
                </el-row>
<!--                <el-row :gutter="12" style="margin-top:1px;">-->
<!--                  <el-col :span="6">-->
<!--                    <div style="text-align:right;"><span>手机号：</span></div>-->
<!--                  </el-col>-->
<!--                  <el-col :span="5">-->
<!--                    <el-form-item prop="phone_num">-->
<!--                      <el-input type="text" v-model="personalForm.phone_num" placeholder="绑定的手机号" ></el-input>-->
<!--                    </el-form-item>-->
<!--                  </el-col>-->
<!--                </el-row>-->
                <el-row :gutter="12" style="margin-top:1px;">
                  <el-col :span="6">
                    <div style="text-align:right;"><span>旧密码：</span></div>
                  </el-col>
                  <el-col :span="5">
                    <el-form-item prop="password1">
                      <el-input type="password" show-password v-model="personalForm.oldpassword" placeholder="请输入旧密码" ></el-input>
                    </el-form-item>
                  </el-col>
                </el-row>
                <el-row :gutter="12" style="margin-top:1px;">
                  <el-col :span="6">
                    <div style="text-align:right;"><span>新密码：</span></div>
                  </el-col>
                  <el-col :span="5">
                    <el-form-item prop="password1">
                      <el-input type="password" show-password v-model="personalForm.password1" placeholder="请输入新的密码" ></el-input>
                    </el-form-item>
                  </el-col>
                </el-row>
                <el-row :gutter="12" style="margin-top:1px;">
                  <el-col :span="6">
                    <div style="text-align:right;"><span>确认密码：</span></div>
                  </el-col>
                  <el-col :span="5">
                    <el-form-item prop="password2">
                      <el-input type="password" show-password v-model="personalForm.password2" placeholder="请再次输入新的密码" ></el-input>
                    </el-form-item>
                  </el-col>
                </el-row>
<!--                <el-row :gutter="12" style="margin-top:1px;">-->
<!--                  <el-col :span="6">-->
<!--                    <div style="text-align:right;"><span>验证码：</span></div>-->
<!--                  </el-col>-->
<!--                  <el-col :span="5">-->
<!--                    <el-form-item prop="verification">-->
<!--                      <el-input type="text" v-model="personalForm.verification" placeholder="验证码" ></el-input>-->
<!--                    </el-form-item>-->
<!--                  </el-col>-->
<!--                  <el-col :span="2">-->
<!--                    <el-button type="primary" plain round size="medium" @click="sendMsg()" :disabled="isDisabled">{{ buttonName }}</el-button>-->
<!--                  </el-col>-->
<!--                </el-row>-->
                <el-row :gutter="12" style="margin-top:10px;">
                  <el-col :span="17" style="text-align:center;">
                    <el-button type="primary" plain round size="medium" @click="submit()">修改</el-button>
                  </el-col>
                </el-row>
              </el-form>
            </el-card>
          </el-row>
          <!--个人信息修改-->
          <el-row v-show="infoChangeShow">
            <user/>
          </el-row>
        </el-col>
      </el-row>
    </div>

    <div>

    </div>
  </div>
</template>
<script>

import zstulogo from '../../assets/zstu-logo.png'
import user from "./user";

export default {
  name:'userProfile',
  components: {
    user
  },
  data(){
    return {
      src:zstulogo,
      levelName:'',
      isCollapse:false,
      infomationShow:true,
      passwordShow:false,
      infoChangeShow:false,
      buttonName:"发送短信",
      isDisabled:false,
      time:60,
      personalForm:{
        account:"",
        phone_num:"",
        verification:"",
        oldpassword:"",
        password1:"",
        password2:"",
      },

      labelPosition: 'right',
      formLabelAlign: {
        id:this.$store.state.localid,
        realName:'',
        nickName:'',
        level:'',
        published:'',
        likes:'',
        gender:'',
        college:'',
        phoneNumber:'',
        email:'',
        birthday:'',
        introduction:'',
      },
      rules: {
        name: [
          { required: false, message: '请输入姓名', trigger: 'blur' },
          { min: 2, max: 5, message: '长度在 2 到 5 个字符', trigger: 'blur' }
        ],
        region: [
          { required: true, message: '请输入学院', trigger: 'change' }
        ],
        date1: [
          { type: 'date', required: false, message: '请输入日期', trigger: 'change' }
        ],
        date2: [
          { type: 'date', required: true, message: '请选择时间', trigger: 'change' }
        ],
        type: [
          { type: 'array', required: true, message: '请至少选择一个活动性质', trigger: 'change' }
        ],
        resource: [
          { required: true, message: '请选择活动资源', trigger: 'change' }
        ],
        desc: [
          { required: true, message: '请填写活动形式', trigger: 'blur' }
        ],
        number:[
          {required:false,message:'输入11位电话',trigger:'change'}
        ]
      }
    }
  },

  created() {
    this.getInfos()
  },

  methods:{
    handleOpen(key, keyPath) {
      console.log(key, keyPath)
      console.log(key)
      console.log(keyPath)
    },
    handleClose(key, keyPath) {
      // console.log(key, keyPath);
    },

    infomationClick(){    //显示个人信息页面
      this.infomationShow = true;
      this.passwordShow = false;
      this.infoChangeShow = false;
    },

    passwordClick(){     //显示密码修改页面
      this.infomationShow = false;
      this.passwordShow = true;
      this.infoChangeShow=false;
    },

    infoChangeClick(){     //显示个人信息修改页面
      this.infomationShow = false;
      this.passwordShow = false;
      this.infoChangeShow=true;
    },

    sendMsg() {    //时间按钮
      let me = this;
      me.isDisabled = true;
      let interval = window.setInterval(function() {
        me.buttonName = "(" + me.time + ")秒"
        --me.time;
        if(me.time < 0) {
          me.buttonName = "重新发送"
          me.time = 60
          me.isDisabled = false
          window.clearInterval(interval)
        }
      }, 1000);
      //获取短信验证码
      // this.$http.get('/?phone_num=' + this.personalForm.phone_num).then(res => {
      //     this.$message.success("短信已发送,请查收")
      // })
    },
    submit(){  //提交
      if(this.personalForm.account === ""){
        this.$message.warning("账号不能为空")
      }else if(this.personalForm.oldpassword === ""){
        this.$message.warning("旧密码不能为空")
      }else if(this.personalForm.password1 === ""){
        this.$message.warning("新密码不能为空")
      }else if(this.personalForm.password2 === ""){
        this.$message.warning("确认密码不能为空")
      }else {
        if (this.personalForm.password1 === this.personalForm.password2) {
          const self = this;
          if (self.$store.state.localid !== '' && self.$store.state.localid !== null) {
            let newpwd = this.personalForm.password1;
            self.$axios({
              // method: 'put',
              // url: 'user/password?userId=' + this.personalForm.account + '&oldPassword=' + this.personalForm.oldpassword + '&newPassword=' + newpwd

              method: 'put',
              url: '/user/password',
              headers:{
                "token":self.$store.state.token
              },
              data: {
                userId: this.personalForm.account,
                oldPassword: this.personalForm.oldpassword,
                newPassword: this.personalForm.password1
              }

            }).then(res => {
              console.log(res);
              this.$message.success("修改成功，请重新登录");
              this.$store.commit("saveLocalid", '')
              this.$store.commit("saveNickname", '')
              this.$store.commit("saveToken", '')
              this.ifIdNotExisted = true;
              this.isAdmin = false;
              window.localStorage.removeItem("");
              this.$router.push('/login');
            })
            // this.$router.push("userProfile")
            // const params = {
            //     account:this.personalForm.account,
            //     phone_num:this.personalForm.phone_num,
            //     password1:this.personalForm.password1,
            //     password2:this.personalForm.password2,
            //     verification:this.personalForm.verification,
            // }
            // console.log(params)
            // this.$http.post('',params).then(res => {
            //     console.log(res)
            // })
          } else {
            this.$message.warning("两次输入的密码不一致,请重新输入")
          }
        }
      }
      // if(this.personalForm.account === ""){
      //   this.$message.warning("账号不能为空")
      // }else if(this.personalForm.phone_num === ""){
      //   this.$message.warning("手机号不能为空")
      // }else if(this.personalForm.password1 === ""){
      //   this.$message.warning("新密码不能为空")
      // }else if(this.personalForm.password2 === ""){
      //   this.$message.warning("确认密码不能为空")
      // }else if(this.personalForm.verification === ""){
      //   this.$message.warning("验证码不能为空")
      // }else{
      //   if(this.personalForm.password1 === this.personalForm.password2){
      //     this.$message.success("修改成功")
      //     this.$router.push("userProfile")
      //     // const params = {
      //     //     account:this.personalForm.account,
      //     //     phone_num:this.personalForm.phone_num,
      //     //     password1:this.personalForm.password1,
      //     //     password2:this.personalForm.password2,
      //     //     verification:this.personalForm.verification,
      //     // }
      //     // console.log(params)
      //     // this.$http.post('',params).then(res => {
      //     //     console.log(res)
      //     // })
      //
      //   }else{
      //     this.$message.warning("两次输入的密码不一致,请重新输入")
      //   }
      //
      // }
    },


    getInfos() {
      const self = this;
      if (self.$store.state.localid !== '' && self.$store.state.localid !== null) {
        self.$axios({
          method: 'get',
          url: 'user/'+self.$store.state.localid
        })
          .then(res => {
            console.log(res)
            self.formLabelAlign.birthday = res.data.data.birthday
            self.formLabelAlign.college = res.data.data.college
            self.formLabelAlign.level=res.data.data.level
            self.formLabelAlign.published=res.data.data.published
            self.formLabelAlign.likes=res.data.data.likes
            //id为前端静态库里面存储的，不用接受后端返回值
            self.formLabelAlign.id = res.data.data.userId
            self.formLabelAlign.email = res.data.data.email
            self.formLabelAlign.introduction = res.data.data.introduction
            self.formLabelAlign.nickName = res.data.data.nickname
            self.formLabelAlign.phoneNumber = res.data.data.phone
            self.formLabelAlign.realName = res.data.data.realName
            self.formLabelAlign.gender = res.data.data.gender

          })
      }
      else{
        alert("未登录无法查看个人信息，请先登录")
        this.$router.push("/index")

      }
    },

    onSubmit() {
      const self = this;
      if (this.$store.state.localid !== '') {
        if(this.vaildPhonenumber()===false) {
          alert("请重新正确填写")
        }
        self.$axios({
          method: 'post',
          url: '/modify/my-information',
          data: {
            // id: self.formLabelAlign.id,
            email:self.formLabelAlign.email,
            realName: self.formLabelAlign.realName,
            nickName: self.formLabelAlign.nickName,
            college: self.formLabelAlign.college,
            phoneNumber: self.formLabelAlign.phoneNumber,
            birthday: self.formLabelAlign.birthday,
            introduction: self.formLabelAlign.introduction
          }
        })
          .then(res => {
            if(res.data.status===200) {
              console.log(res)
              alert(res.data.message)
            }
            else{
              console.log(res)
              alert(res.data.message)
            }
          })
          .catch(err => {
            alert(err);
          })
      }


    },
    //验证手机号
    vaildPhonenumber(){
      if(this.formLabelAlign.phoneNumber!=null) {
        var length1 = this.formLabelAlign.phoneNumber.length;
      }
      if(length1>11) {
        alert("手机号输入错误")
        return false;
      }
      else{
        return true;
      }
    }


    //
  }
}
</script>

<style>
.name{ text-align: right; }
.value{ text-align: left; }
</style>
