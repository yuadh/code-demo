<template>
  <div class="yxSkeleton" :style="{width,height}" :class="{shan:animated}">
    <div class="block" :style="{backgroundColor:bg}"></div>
  </div>
</template>

<script>
export default {
  props: {
    width:{
      type:String,
      default:'100px'
    },
    height:{
      type:String,
      default:'100px'
    },
    animated:{
      type:Boolean,
      default:false
    },
    bg:{
      type:String,
      default:'#efefef'
    }
  }
}
</script>

<style lang="less" scoped>
  .yxSkeleton{
		display:inline-block;
		overflow:hidden;
		vertical-align:middle;
		position:relative;
    .block{
      width: 100%;
      height: 100%;
      border-radius: 2px;
    }
	}
	.shan{
		&::after{
      content:"";
      position:absolute;
      animation:yuadh 1.5s ease 0s infinite;
      top: 0;
      width:50%;
      height:100%;
      /* Rotate div */
      background:linear-gradient(
        to left,
        rgba(255,255,255,0)0,
        rgba(255,255,255,0.3)50%,
        rgba(255,255,255,0)100%
      );
      //border:1px solid red;
      transform:skewX(-45deg);
    }
	}
	@keyframes yuadh{
		0%{
			left:-100%;
		}
		100%{
			left:140%;
		}
	}
</style>