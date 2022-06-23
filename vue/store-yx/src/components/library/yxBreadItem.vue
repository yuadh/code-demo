<template>
  <div class="yx-bread-item">
    <RouterLink v-if="to" :to="to"><slot/></RouterLink>
    <span v-else><slot/></span>
  </div>
</template> 

<script>
export default {
  props:{
    to:{
      type:[String,Object],
      default:""
    }
  }
}
</script>

<style>

</style>