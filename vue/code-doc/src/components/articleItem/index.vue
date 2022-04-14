<template>
  <div>
      <van-cell 
       class="article-item"
       :to="{name:'article',params:{articleId:article.art_id}}"
      >
        <div slot="title" class="title">{{article.title}}</div>
        <div slot="label" class="" >
            <!-- 三张图片需要显示样式 -->
            <div v-if="article.cover.type===3" class="cover-warp">
                <div 
                 v-for="(img,index) in article.cover.images"
                 :key="index"
                 class="cover-item">
                    <van-image
                     class="cover-item-img"
                     fit="cover"
                     :src="img"
                    />
                </div>
            </div>
            <div class="label-info-warp">
                <span>{{article.aut_name}}</span>
                <span>{{ article.comm_count }}评论</span>
                <span>{{ article.pubdate | relativeTime }}</span>
            </div>
        </div>
        <van-image
         class="right-cover"
         slot="default"
         v-if="article.cover.type===1"
         fit="cover"
         :src="article.cover.images[0]"
        />
      </van-cell>
  </div>
</template>

<script>
import {getArtTextAPI} from '@/api/index'
export default {
    props:{
        article:{
            type:[String,Object],
            required:true
        }
    },
    created(){
        
    },
    methods:{
        
    }
}
</script>

<style scoped lang="less">
.article-item{
    .title{
        font-size: 32px;
        color:#3a3a3a;
    }
    .van-cell__title{ //将 cell 单元格中的左侧title内容布局修改为上下布局
        display: flex;
        flex-direction: column;
        justify-content: space-between;
    }
    .van-cell__value{
        flex: unset;//布局取消
        width: 232px;
        height: 146px;
        padding-left: 25px;
    }
    .right-cover{
        width: 100%;
        height: 146px;
    }
    .label-info-warp span{
        font-size: 22px;
        color: #b4b4b4;
        margin-right: 25px;
    }
    .cover-warp{
        display: flex;
        padding: 30px 0;
        .cover-item{
            flex: 1;
            height: 146px;
            &:not(:last-child){//伪类选择器 取消最后一个的右内边距
                padding-right: 4px;
            }
            .cover-item-img{
                width: 100%;
                height: 146px;
            }
        }
    }
}   
</style>