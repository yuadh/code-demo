<template>
  <div class="profile-container">
    <van-nav-bar
     class="doc-nav-bar"
     title="个人信息"
     left-arrow
     @click-left="$router.back()"
    />
    <input
     type="file"
     ref = 'file'
     hidden
     @change="toLoadPhoto"
     />
    <van-cell
     @click="$refs.file.click()"
     title="头像"
     center
     class="photo-cell" 
     is-link>
        <van-image
         class="avatar"
         fit="cover"
         round
         :src="dat.photo"
        /> 
    </van-cell>
    <van-cell
     @click="isUpdateNameShow=true" 
     title="昵称"
     :value="dat.name" 
     is-link />
    <van-cell 
     @click="isUpdateGenderShow=true"
     title="性别"
     :value="dat.gender===0?'男':'女'" 
     is-link />
    <van-cell 
     @click="isUpdateBirthdayShow=true"
     title="生日" 
     :value="dat.birthday"
     is-link />

    <!-- 修改个人信息弹出层 -->
    <!-- 修改昵称 -->
    <van-popup 
      v-model="isUpdateNameShow" 
      position="bottom" 
      :style="{ height: '100%' }">
        <updataName
         v-model="dat.name"
         @close="isUpdateNameShow=false"
        /> 
    </van-popup>
    <!-- 修改姓名 -->
    <van-popup 
      v-model="isUpdateGenderShow" 
      position="bottom" 
    >
        <updataGender
         v-model="dat.gender"
         @close="isUpdateGenderShow=false"
        /> 
    </van-popup>
    <!-- 修改生日 -->
    <van-popup 
      v-model="isUpdateBirthdayShow" 
      position="bottom" 
    >
        <updataBrithday
         v-model="dat.birthday"
         @close="isUpdateBirthdayShow=false"
        /> 
    </van-popup>
    <!-- 修改头像 纯客户端的裁剪处理 base64格式上传 -->
    <van-popup 
      closeable
      v-model="isUpdatePhotoShow" 
      position="bottom" 
      :style="{ height: '100%' }"
    >
        <updataPhoto
         v-if="isUpdatePhotoShow"
         :img = "img"
         @close = "isUpdatePhotoShow = false"
         @updataPhoto="dat.photo=$event"
        />
    </van-popup>
  </div>
</template>

<script>
import {getUserProfileAPI} from '@/api/index'
import updataName from './components/updataName'
import updataGender from './components/updataGender'
import updataBrithday from './components/updataBrithday'
import updataPhoto from './components/updataPhoto'
export default {
    components:{
        updataName,
        updataGender,
        updataBrithday,
        updataPhoto
    },
    data(){
        return{
            dat:"",
            isUpdateNameShow: false,
            isUpdateGenderShow: false,
            isUpdateBirthdayShow: false,
            isUpdatePhotoShow: false,
            img:null,
        }
    },
    created(){
        this.loadUserProfile();
    },
    methods: {
        async loadUserProfile(){
            try{
                const {data}  = await getUserProfileAPI()
                this.dat = data.data;
                console.log(this.dat)
            }catch(error){
                console.log(error)
            }
        },
        toLoadPhoto(){
            const file = this.$refs.file.files[0];
            this.img = window.URL.createObjectURL(file)
            console.log(this.img)
            this.isUpdatePhotoShow = true 
            //情况文件框
            this.$refs.file.value = ""
        }
    }
}
</script>

<style scoped lang="less">
.profile-container{
    .avatar{
        width: 60px;
        height: 60px;
    }
    .photo-cell {
        .van-cell__value {
            display: flex;
            flex-direction: row-reverse;//将内容的起始方向改变
        }
    }
    .van-popup{
         background-color: #f5f7f9;
    }
}
</style>