<template>
  <div>
      <p class="title">推荐歌单</p>
      <!-- <van-button type="primary">主要按钮</van-button> -->
      <div>
        <van-row gutter="6">
        <van-col span="8" v-for="obj in reList" :key="obj.id">
          <van-image
          fit="cover"
          :src="obj.picUrl"/>
          <p class="song_name">{{obj.name}}</p>
        </van-col>
      </van-row>
      </div>
      <p class="title">最新音乐</p>
      <van-cell center v-for="obj in songList" :key="obj.id" 
      :title="obj.name" :label="obj.song.artists[0].name + ' - ' + obj.name" is-link>
      <!-- 使用 title 插槽来自定义标题 -->
        <template #right-icon>
          <van-icon name="play-circle-o" size="0.6rem" />
        </template>
      </van-cell>
  </div>
</template>

<script>
import { recommendMusicAPI } from '../../api'
import { newMusic } from '../../api/Home'
export default {
  data(){
    return {
      reList:[],
      songList:[],
    }
  },
  async created(){
    const res =await recommendMusicAPI({
      limit:6
    })
    console.log(res)
    this.reList=res.data.result;
    const res2 = await newMusic({
      limit:20
    })
    this.songList = res2.data.result;
    console.log(res2)
  }
}
</script>

<style scoped>
/* 标题 */
.title {
  padding: 0.266667rem 0.24rem;
  margin: 0 0 0.24rem 0;
  background-color: #eee;
  color: #333;
  font-size: 15px;
}
/* 推荐歌单 - 歌名 */
.song_name {
  font-size: 0.346667rem;
  padding: 0 0.08rem;
  margin-bottom: 0.266667rem;
  word-break: break-all;
  text-overflow: ellipsis;
  display: -webkit-box; /** 对象作为伸缩盒子模型显示 **/
  -webkit-box-orient: vertical; /** 设置或检索伸缩盒对象的子元素的排列方式 **/
  -webkit-line-clamp: 2; /** 显示的行数 **/
  overflow: hidden; /** 隐藏超出的内容 **/
}
</style>