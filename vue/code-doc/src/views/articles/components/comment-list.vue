<template>
  <van-list
   v-model="loading"
   :finished="finished"
   finished-text="已显示全部评论"
   :error="error"
   error-text="加载失败,请点击重试"
   :immediate-check="false"
   @load="loadComments">
   <!-- immediate是否在初始化是立即执行onLoad -->
    <commentItem/>
  </van-list>
</template>

<script>
import commentItem from "./comment-item.vue"
import {getArtCommentsAPI} from '@/api/index'
export default {
    components:{
        commentItem
    },
    props:{
      artId:{
        type:[Number,String,Object],
        required:true
      },
      list:{
        type:Array,
        default:()=>[]
      },
      type:{
        type:String,
        // validator(value){
        //   return ['a','c'].includes(value)
        // },
        default:'a'
      }
    },
    data(){
      return{
        loading:false,
        finished:false,
        offset:null,//偏移量,记录的是获取最后评论的id
        limit:10,
        error:false
      }
    },
    created(){
      this.loading = true
      this.loadComments()
    },
    methods:{
      async loadComments(){
        try{
          // 1.发送请求
          const {data} = await getArtCommentsAPI({
            type:this.type,
            source:this.artId.toString(),
            offset:this.offset,
            limit:15
          })
          // 2.接收数据,装载数组
          const {results} = data.data
          console.log(data.data)
          this.list.push(...results)
          this.$emit('success-loadComments',data.data)
          this.loading = false

          // 除了初次加载页面时会自动加载本函数,在下拉评论列表时也会触发此函数
          if(results.length){//判断是否还有数据
            this.offset = data.data.last.id
          }else{
            this.finished = true
          }
        }catch(err){
          console.log(err)
          this.error=true
          this.loading = false
        }
      }
    }

}
</script>

<style>

</style>