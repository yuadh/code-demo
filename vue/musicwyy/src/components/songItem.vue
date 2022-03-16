<template>
        <van-cell
          center
          :title='name'
          :label="author + ' - ' + name "
        >
          <template #right-icon>
            <van-icon name="play-circle-o" size="0.6rem"/>
          </template>
        </van-cell>
</template>

<script>
export default {
    props:{
        author:String,
        name:String,
        id:Number,
    }
}
</script>


<style scoped>
/* 给单元格设置底部边框 */
.van-cell {
  border-bottom: 1px solid lightgray;
}
</style>