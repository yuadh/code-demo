<template>
  <homePanel title="新鲜好物" subTitle="新鲜出炉，品质保证">
    <template #right>
      <yxMore/>
    </template>
  </homePanel>
</template>

<script>
import homePanel from './homePanel.vue'
import yxMore from '@/components/library/yxMore.vue'
export default {
  components: {
    homePanel,
    yxMore
  }
}
</script>

<style>

</style>