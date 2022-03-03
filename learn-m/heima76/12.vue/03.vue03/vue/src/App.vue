<template>
  <div>
    <input type="checkbox" v-model="obj" >
    <p>{{ strs | toUp |tobreak('|','-')}}</p>
    <input  v-model="full" />
    <ul id="v-for-object" class="demo">
      <li v-for="(value, index) in arr" :key="index">
        {{ value.name }}
        <input type="text"  />
      </li>
    </ul>
    <button @click="addE">新增一个标签</button>
  </div>
</template>
<script>
export default {
  data() {
    return {
      obj:true,
      strs: "yuadh",
      arr: [
        {
          id: 1,
          name: "y",
        },
        {
          id: 2,
          name: "d",
        },
        {
          id: 3,
          name: "h",
        },
        {
          id: 4,
          name: "s",
        },
        {
          id: 5,
          name: "w",
        },
      ],
    };
  },
  methods: {
    reBtn() {
      this.arr.reverse();
      console.log(this);
    },
    suBtn() {
      this.arr = this.arr.slice(0, 3);
    },
    upBtn() {
      this.$set(this.arr, 0, 250);
    },
    addE() {
      this.arr.splice(1, 0, { id: 8, name: "o" });
    },
  },
  filters: {
    reserves(val) {
      return val.reverse();
    },
    toUp(val) {
      return val.toUpperCase();
    },
    toDown(val) {
      return val.toLowerCase();
    },
    tobreak(val, syn,test) {
      return val.split("").reverse().join(syn+test)
    },
  },
  computed: {
    full:{
      set(val){

      },
      get(){
        return "test"
      }
    }
  }
};
</script>
<style>
</style>